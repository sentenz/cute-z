#include "STouchSensor.h"
#include "../build/SGlobal.h"
#include "../flickable/STouchFlickableList.h"
#include "../keyboard/STouchKeyboard.h"
#include "../button/SReturnButton.h"

#include <QApplication>
#include <QSettings>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>


STouchSensor::STouchSensor(QWidget *parent) : QDialog(parent)
{
    #ifdef S_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setWindowState(Qt::WindowFullScreen);
    #else
    this->resize(QSize(800,480));
    #endif
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
}

STouchSensor::~STouchSensor()
{
    if (settings != nullptr)
    {
        delete settings;
        settings = nullptr;
    }
    if (touchKeyboard != nullptr)
    {
        delete touchKeyboard;
        touchKeyboard = nullptr;
    }
    if (touchFlickable != nullptr)
    {
        delete touchFlickable;
        touchFlickable = nullptr;
    }
}

void STouchSensor::setupWidget()
{
    /// Label
    labelTitle = new QLabel(tr("Sensor"), this);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setStyleSheet("QLabel { font: " + ::GlobalLabelTextFont + "; color: " + ::GlobalTextColor + "; background: transparent; }");
    labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    /// BUTTON
    backButton = new SReturnButton(this);

    /// FLICKABLE
    touchFlickable = new STouchFlickableList;
    touchFlickable->setWindowState(Qt::WindowFullScreen);
    touchFlickable->setBackgroundColor(QColor(::GlobalBackgroundColor));
    touchFlickable->setFontTextColor(QColor(::GlobalSystemColor));
    touchFlickable->setRowHeight(this->height()/11);
    touchFlickable->setCheckable(true);
    touchFlickable->setTopic(tr("Digital Filter"));
    touchFlickable->setText(tr("Order"));
    touchFlickable->setParameter(filterOrder);
    touchFlickable->setText(tr("Cutoff Coefficient fc"));
    touchFlickable->setParameter(filterCutFreqC);
    touchFlickable->setText(tr("Cutoff Coefficient f1"));
    touchFlickable->setParameter(filterCutFreq1);
    touchFlickable->setText(tr("Cutoff Coefficient f2"));
    touchFlickable->setParameter(filterCutFreq2);
    touchFlickable->setTopic(tr("Activation Function"));
    touchFlickable->setText(tr("Threshold"));
    touchFlickable->setParameter(threshold);

    this->slotReadSettings();
}

void STouchSensor::setupGUI()
{
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(backButton, 0, Qt::AlignLeft);
    titleLayout->addWidget(labelTitle);
    titleLayout->setContentsMargins(0,0,this->backButton->width(),0);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(touchFlickable);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(layout);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void STouchSensor::setConnect()
{
    /// FLICKABLE
    connect(touchFlickable, &STouchFlickableList::signalCurrentIndex, this, &STouchSensor::slotFlickEvent);
}

void STouchSensor::slotFlickEvent(const int &index)
{
    this->hide();

    bool write = false;

    if (touchKeyboard != nullptr)
    {
        delete touchKeyboard;
        touchKeyboard = nullptr;
    }

    switch (index)
    {
        case 1: /// Filter order
        {
            touchKeyboard = new STouchKeyboard;
            touchKeyboard->setTitle(tr("Filter order"));
            touchKeyboard->setDescriptionText(tr("The filter order should be higher than 1"));
            touchKeyboard->setRange(2, INT_MAX);
            touchKeyboard->setMaximumDigit(2);
            touchKeyboard->exec();

            if (touchKeyboard->isAccepted())
            {
                this->filterOrder = touchKeyboard->getNumber();
                touchFlickable->setParameter(filterOrder, index);

                write = true;
            }

            delete touchKeyboard;
            touchKeyboard = nullptr;
        }
            break;
        case 2: /// Cutoff Coefficient fc
        {
            touchKeyboard = new STouchKeyboard;
            touchKeyboard->setTitle(tr("Cutoff Coefficient fc"));
            touchKeyboard->setDescriptionText(tr("The cutoff coefficient should be\n\ninbetween 0 and 1"));
            touchKeyboard->setRange(0.0, 1.0);
            touchKeyboard->setMaximumDigit(7);
            touchKeyboard->setDatatyp("double");
            touchKeyboard->exec();

            if (touchKeyboard->isAccepted())
            {
                this->filterCutFreqC = touchKeyboard->getNumber();
                touchFlickable->setParameter(filterCutFreqC, index);

                write = true;
            }

            delete touchKeyboard;
            touchKeyboard = nullptr;
        }
            break;
        case 3: /// Cutoff Coefficient f1
        {
            touchKeyboard = new STouchKeyboard;
            touchKeyboard->setTitle(tr("Cutoff Coefficient f1"));
            touchKeyboard->setDescriptionText(tr("The cutoff coefficient should be\n\ninbetween 0 and 1"));
            touchKeyboard->setRange(0.0, 1.0);
            touchKeyboard->setMaximumDigit(7);
            touchKeyboard->setDatatyp("double");
            touchKeyboard->exec();

            if (touchKeyboard->isAccepted())
            {
                this->filterCutFreq1 = touchKeyboard->getNumber();
                touchFlickable->setParameter(filterCutFreq1, index);

                write = true;
            }

            delete touchKeyboard;
            touchKeyboard = nullptr;
        }
            break;
        case 4: /// Cutoff Coefficient f2
        {
            touchKeyboard = new STouchKeyboard;
            touchKeyboard->setTitle(tr("Cutoff Coefficient f2"));
            touchKeyboard->setDescriptionText(tr("The cutoff coefficient should be\n\ninbetween 0 and 1"));
            touchKeyboard->setRange(0.0, 1.0);
            touchKeyboard->setMaximumDigit(7);
            touchKeyboard->setDatatyp("double");
            touchKeyboard->exec();

            if (touchKeyboard->isAccepted())
            {
                this->filterCutFreq2 = touchKeyboard->getNumber();
                touchFlickable->setParameter(filterCutFreq2, index);

                write = true;
            }

            delete touchKeyboard;
            touchKeyboard = nullptr;
        }
            break;
        case 6: /// Procedure Pulse
        {
            touchKeyboard = new STouchKeyboard;
            touchKeyboard->setTitle(tr("Threshold"));
            touchKeyboard->setDescriptionText(tr("The threshold value should be higher as 0"));
            touchKeyboard->setRange(1.e-6, 1.e6);
            touchKeyboard->setDatatyp("double");
            touchKeyboard->exec();

            if (touchKeyboard->isAccepted())
            {
                this->threshold = touchKeyboard->getNumber().toDouble();
                touchFlickable->setParameter(threshold, index);

                write = true;
            }

            delete touchKeyboard;
            touchKeyboard = nullptr;
        }
            break;
        default:
            break;
    }

    if (write)
    {
        this->slotWriteSettings();
    }

    this->show();
}

void STouchSensor::slotWriteSettings()
{
    settings = new QSettings(::GlobalSettingDir + ::GlobalSettingSettings, QSettings::IniFormat);
    settings->beginGroup("custom/systems");

    /// VALUE AREA
    ///
    settings->setValue("filterOrder", this->filterOrder);
    settings->setValue("filterCutFreqC", QString::number(this->filterCutFreqC.toDouble(), 'f', 5));
    settings->setValue("filterCutFreq1", QString::number(this->filterCutFreq1.toDouble(), 'f', 5));
    settings->setValue("filterCutFreq2", QString::number(this->filterCutFreq2.toDouble(), 'f', 5));
    settings->setValue("threshold", this->threshold);

    settings->sync();
    settings->endGroup();

    delete settings;
    settings = nullptr;
}

void STouchSensor::slotReadSettings()
{    
    settings = new QSettings(::GlobalSettingDir + ::GlobalSettingSettings, QSettings::IniFormat);
    if (settings->contains("custom/systems/filterOrder"))
    {
        settings->beginGroup("custom/systems");
    }
    else
    {
        settings->beginGroup("default/systems");
    }

    /// VALUE AREA
    ///
    this->filterOrder = settings->value("filterOrder", 0).toString();
    touchFlickable->setParameter(filterOrder, 1);

    this->filterCutFreqC = settings->value("filterCutFreqC", QString::number(0.0, 'f', 5)).toString();
    touchFlickable->setParameter(filterCutFreqC, 2);

    this->filterCutFreq1 = settings->value("filterCutFreq1", QString::number(0.0, 'f', 5)).toString();
    touchFlickable->setParameter(filterCutFreq1, 3);

    this->filterCutFreq2 = settings->value("filterCutFreq2", QString::number(0.0, 'f', 5)).toString();
    touchFlickable->setParameter(filterCutFreq2, 4);

    this->threshold = settings->value("threshold", 0.0).toDouble();
    touchFlickable->setParameter(threshold, 6);

    settings->sync();
    settings->endGroup();

    delete settings;
    settings = nullptr;
}

void STouchSensor::retranslateUI()
{
    labelTitle->setText(tr("Sensor"));
    touchFlickable->setTopic(tr("Digital Filter"), 0);
    touchFlickable->setText(tr("Order"), 1);
    touchFlickable->setText(tr("Cutoff Coefficient fc"), 2);
    touchFlickable->setText(tr("Cutoff Coefficient f1"), 3);
    touchFlickable->setText(tr("Cutoff Coefficient f2"), 4);
    touchFlickable->setTopic(tr("Activation Function"), 5);
    touchFlickable->setText(tr("Threshold"), 6);
}

void STouchSensor::changeEvent(QEvent* event)
{
    switch(event->type())
    {
        case QEvent::LanguageChange:
            retranslateUI();
            break;
        case QEvent::LocaleChange:
            break;
        default:
            break;
    }

    QWidget::changeEvent(event);
}
