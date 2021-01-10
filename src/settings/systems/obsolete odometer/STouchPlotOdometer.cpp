#include "STouchPlotOdometer.h"
#include "../build/SGlobal.h"
#include "../button/SReturnButton.h"

#if QT_VERSION < QT_VERSION_CHECK(5, 7, 0)
    #include "../plot/SPlotQwt.h"
#else
    #include "../plot/SPlot.h"
#endif

#include <QApplication>
#include <QTimerEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextStream>
#include <QFile>
#include <QVector>


STouchPlotOdometer::STouchPlotOdometer(QWidget *parent) : QDialog(parent)
{
    #ifdef S_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setWindowState(Qt::WindowFullScreen);
    #else
    this->resize(QSize(800,480));
    #endif
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setUpWidget();
    this->setUpGUI();
    this->setConnect();
}

STouchPlotOdometer::~STouchPlotOdometer()
{
    if (this->plot != nullptr)
    {
        delete this->plot;
        this->plot = nullptr;
    }
}

void STouchPlotOdometer::setUpWidget()
{
    /// LABEL
    this->labelTitle = new QLabel(tr("Odometer Initialization"), this);
    this->labelTitle->setAlignment(Qt::AlignCenter);
    this->labelTitle->setStyleSheet("QLabel { font: " + ::GlobalLabelTextFont + "; color: " + ::GlobalTextColor + "; background: transparent; }"); // font-variant: small-caps;
    this->labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    /// BUTTON
    this->backButton = new SReturnButton(this);

    /// PLOT
    #if QT_VERSION < QT_VERSION_CHECK(5, 7, 0)
        this->plot = new SPlotQwt;
    #else
        this->plot = new SPlot;
    #endif
    this->plot->setPlot(this->readFile());
}

void STouchPlotOdometer::setUpGUI()
{
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(this->backButton, 0, Qt::AlignLeft);
    titleLayout->addWidget(this->labelTitle);
    titleLayout->setContentsMargins(0,0,this->backButton->width(),0);

    QVBoxLayout *plotLayout = new QVBoxLayout;
    plotLayout->addWidget(this->plot);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(plotLayout);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void STouchPlotOdometer::setConnect()
{
}

QVector<QPointF> STouchPlotOdometer::readFile()
{
    QFile file(::GlobalSettingDir + ::GlobalSettingEWave);

    int x = 0;
    QVector<QPointF> points;

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            points.push_back(QPointF(++x, in.readLine().toDouble()));
        }

        file.flush();
        file.close();
    }

    return points;
}

void STouchPlotOdometer::slotBackEvent()
{
    this->basicTimer.stop();
}

void STouchPlotOdometer::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->basicTimer.timerId())
    {
        emit this->slotBackEvent();
    }
}

void STouchPlotOdometer::retranslateUI()
{
    this->labelTitle->setText(tr("Odometer Initialization"));
}

void STouchPlotOdometer::changeEvent(QEvent* event)
{
    switch(event->type())
    {
        case QEvent::LanguageChange:
            this->retranslateUI();
            break;
        case QEvent::LocaleChange:
            break;
        default:
            break;
    }

    QWidget::changeEvent(event);
}
