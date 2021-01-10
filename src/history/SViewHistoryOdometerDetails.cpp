#include "SViewHistoryOdometerDetails.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFocusEvent>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QEvent>
#include <QHash>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QDebug>


SViewHistoryOdometerDetails::SViewHistoryOdometerDetails(QWidget *parent) : QDialog(parent)
{
    // Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();
    this->setFocus();

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->updateWidget();
    this->restyleUI();
}

SViewHistoryOdometerDetails::~SViewHistoryOdometerDetails()
{
    if (this->header != nullptr)
    {
        delete this->header;
        this->header = nullptr;
    }
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void SViewHistoryOdometerDetails::setupWidget()
{
    // Database
    this->database.create("database_encoder.db", ::GlobalConfigPathDatabase);

    // Header
    this->header = new SLabel;
    this->header->header(tr("Odometer history"), 0x0276E, 0x2315);
    this->header->setTheme(SLabel::Theme::Contrast);

    // Info board
    this->labelTotalTime = new SLabel(this);
    this->labelTotalTime->setAlignment(Qt::AlignCenter);
    this->labelTotalTime->setText(this->setHtmlText(QChar(0x2015), tr("Total time")));
    this->labelTotalTime->setTheme(SLabel::Theme::Contrast);
    this->labelTotalTime->fontSize(24);

    this->labelTotalLength = new SLabel(this);
    this->labelTotalLength->setAlignment(Qt::AlignCenter);
    this->labelTotalLength->setText(this->setHtmlText(QChar(0x2015), tr("Total length")));
    this->labelTotalLength->setTheme(SLabel::Theme::Contrast);
    this->labelTotalLength->fontSize(24);

    this->labelTotalOrders = new SLabel(this);
    this->labelTotalOrders->setAlignment(Qt::AlignCenter);
    this->labelTotalOrders->setText(this->setHtmlText(QChar(0x2015), tr("Total orders")));
    this->labelTotalOrders->setTheme(SLabel::Theme::Contrast);
    this->labelTotalOrders->fontSize(24);

    // Swipe list
    this->list = new SList;
    this->list->enableScrollBar(true);
}

void SViewHistoryOdometerDetails::setupLayout()
{
    QHBoxLayout * totalLayout = new QHBoxLayout;
    totalLayout->addWidget(this->labelTotalTime, Qt::AlignCenter);
    totalLayout->addWidget(this->labelTotalLength, Qt::AlignCenter);
    totalLayout->addWidget(this->labelTotalOrders, Qt::AlignCenter);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addLayout(totalLayout, 2);
    mainLayout->addWidget(this->list->list(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void SViewHistoryOdometerDetails::setConnect()
{
    /* Header */
    connect(this->header, &SLabel::signalReleased, [this](int n) {
        switch (n) {
        case 0:
        {
            emit this->signalReturn();

            if (this->m_closeable)
            {
                this->close();
            }
        }
            break;

        case 1:
            break;

        default:
            break;
        }
    });
    /* Swipe list */
    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));
    /* Database stream */
    connect(&this->database, &SDatabaseOdometer::signalStream, this, &SViewHistoryOdometerDetails::slotAppendList);
}

void
SViewHistoryOdometerDetails::setCloseable(const bool closeable)
{
    this->m_closeable = closeable;
}

QString
SViewHistoryOdometerDetails::setHtmlText(const QString topText,
                                     const QString bottomText,
                                     const QString unit)
{
    QString text = tr("<p style=\"line-height: 140%\"><span style=\"font-size: 22pt\">%1</span> <sup><span style=\"font-size: 20pt\">%3</span></sup><br><span style=\"font-size: 16pt\">%2</span></p>").arg(topText, bottomText, unit);
//    QString text = tr("<p style=\"line-height: 140%; font-size: 20pt\"><font size='+2'>%1</font> <font size='+0'><sup>%3</sup></font><br><font size='-2'>%2</font></p>").arg(topText, bottomText, unit);
    return text;
}

void
SViewHistoryOdometerDetails::updateWidget()
{
    auto t_hash = this->database.statistics();

    // Info board
    this->labelTotalTime->setText(this->setHtmlText(QTime::fromMSecsSinceStartOfDay(t_hash.value("time").toLongLong()).toString("hh:mm"), tr("Total time"), "h"));
//    this->labelTotalLength->setText(this->setHtmlText(QString::number(this->database.getTotalLength()), tr("Total length"), "m"));
//    this->labelTotalOrders->setText(this->setHtmlText(QString::number(this->database.getTotalOrders()), tr("Total orders")));

    /* Stream the measurements from the database and set at to list over signal/slot. */
    this->database.stream(50);
}

void
SViewHistoryOdometerDetails::slotAppendList(QHash<QString, QString> hash)
{
    // Swipe list
    this->list->addSlot(QIcon(hash.value("complete").toInt() ? ":/images/ic_check_circle_blue_128dp.svg" : ":/images/ic_warning_red_128dp.svg"),
                           tr("%1 %2").arg(hash.value("date")).arg(hash.value("time")),
                           tr("<p style=\"font-size: 14pt\">Ordered %1 <sup>%3</sup><br>Measuered %2 <sup>%3</sup></p>").arg(hash.value("length")).arg(hash.value("measured")).arg("m"),
                           tr("<p style=\"font-size: 14pt\">ID %1</p>").arg(hash.value("id")),
                           QChar(0x276F));
}

void
SViewHistoryOdometerDetails::slotList(const int index)
{
    if (index == this->database.quantity())
    {
        this->list->clear();
        this->database.stream(50);
    }
}

void
SViewHistoryOdometerDetails::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Odometer history"));

    // Info board
//    this->labelTotalTime->setText(this->setHtmlText(QString::number(this->database.getTotalTime()), tr("Total time"), "h"));
//    this->labelTotalLength->setText(this->setHtmlText(QString::number(this->database.getTotalLength()), tr("Total length"), "m"));
//    this->labelTotalOrders->setText(this->setHtmlText(QString::number(this->database.getTotalOrders()), tr("Total orders")));

    t_iter = 0;
}

void
SViewHistoryOdometerDetails::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
}

void
SViewHistoryOdometerDetails::changeEvent(QEvent * event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        this->retranslateUI();
        break;

    case QEvent::StyleChange:
        this->restyleUI();
        break;

    case QEvent::LocaleChange:
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}