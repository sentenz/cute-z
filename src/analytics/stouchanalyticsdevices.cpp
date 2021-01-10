#include "stouchanalyticsdevices.h"
#include "../swipe/list/STouchFlickableList.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QTimer>
#include <QFocusEvent>
#include <QDebug>


STouchAnalyticsDevices::STouchAnalyticsDevices(QWidget *parent) : QDialog(parent)
{
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //this->setAttribute(Qt::WA_OpaquePaintEvent, true);
    //setAttribute(Qt::WA_PaintOnScreen, true);
    //this->activateWindow();
    //this->setWindowState(Qt::WindowActive);
    //this->raise();
    //this->showNormal();

    this->setupLayout();
    this->setConnect();
}

STouchAnalyticsDevices::~STouchAnalyticsDevices()
{
    if (touchFlickable != nullptr)
    {
        delete touchFlickable;
        touchFlickable = nullptr;
    }
}

void STouchAnalyticsDevices::setupLayout()
{
    /// TIMER
    timer = new QTimer(this);

    /// I2C DEVICES
    touchFlickable = new STouchFlickableList;
    touchFlickable->setFontSize(14);
    touchFlickable->setFontSizeParamter(13);
    touchFlickable->enableDrawLine(false);
    touchFlickable->setTopic(tr("Sensors"));
    touchFlickable->setText(tr("Magnetic"));
    touchFlickable->setParameter(QChar(0x20DD));
    touchFlickable->setText(tr("Temperature"));
    touchFlickable->setParameter(QChar(0x20DD));
    touchFlickable->setTopic(tr("Control Board"));
    touchFlickable->setText(tr("Relays"));
    touchFlickable->setParameter(QChar(0x20DD));
    touchFlickable->setText(tr("ADC Channals"));
    touchFlickable->setParameter(QChar(0x20DD));
    touchFlickable->setText(tr("EEPROM"));
    touchFlickable->setParameter(QChar(0x20DD));


    /// LAYOUTS
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(touchFlickable);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setStyleSheet("border-width: 0px;");
    setLayout(mainLayout);
}

void STouchAnalyticsDevices::setConnect()
{
   connect(timer, &QTimer::timeout, this, &STouchAnalyticsDevices::slotUpdateWidgeds);
}

void STouchAnalyticsDevices::slotUpdateWidgeds()
{
    /// I2C DEVICES
    /// Magnetic Sensor
    if (checkI2C(0x1E))
        touchFlickable->setParameter(QString(QChar(0x2B24)).leftJustified(10, '\t'), 1);
    else
        touchFlickable->setParameter(QChar(0x20DD), 1);
    /// Temperature Sensor
    if (checkI2C(-1))
        touchFlickable->setParameter(QString(QChar(0x2B24)).leftJustified(10, '\t'), 2);
    else
        touchFlickable->setParameter(QChar(0x20DD), 2);
    /// Relays
    if (checkI2C(0x20))
        touchFlickable->setParameter(QString(QChar(0x2B24)).leftJustified(10, '\t'), 4);
    else
        touchFlickable->setParameter(QChar(0x20DD), 4);
    /// ADC Channals
    if (checkI2C(0x68))
        touchFlickable->setParameter(QString(QChar(0x2B24)).leftJustified(10, '\t'), 5);
    else
        touchFlickable->setParameter(QChar(0x20DD), 5);
    /// EEPROM
    if (checkI2C(0x50))
        touchFlickable->setParameter(QString(QChar(0x2B24)).leftJustified(10, '\t'), 6);
    else
        touchFlickable->setParameter(QChar(0x20DD), 6);
}

bool STouchAnalyticsDevices::checkI2C(const int &addr)
{
    Q_UNUSED(addr);

    return false;
}

void STouchAnalyticsDevices::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event)

    static bool activate = false;

    if (!activate)
    {
        activate = true;
    }
    else
    {
        if (!timer->isActive())
        {
            this->slotUpdateWidgeds();

            timer->start(200);
        }
    }
}

void STouchAnalyticsDevices::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);

    if (timer->isActive())
    {
        timer->stop();
    }
}

void
STouchAnalyticsDevices::setBaseColor(const QColor &color)
{
    this->m_colorBase = color;
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->update();
}

void
STouchAnalyticsDevices::setContrastColor(const QColor &color)
{
    this->m_colorContrast = color;
    this->update();
}

void
STouchAnalyticsDevices::setTextColor(const QColor &color)
{
    this->m_colorText = color;
    this->update();
}

void
STouchAnalyticsDevices::setHighlightColor(const QColor &color)
{
    this->m_colorHighlight = color;
    this->update();
}

void STouchAnalyticsDevices::retranslateUI()
{
    int iter = 0;
    touchFlickable->setTopic(tr("Sensors"), iter++);
    touchFlickable->setText(tr("Magnetic"), iter++);
    touchFlickable->setText(tr("Temperature"), iter++);
    touchFlickable->setTopic(tr("Control Board"), iter++);
    touchFlickable->setText(tr("Relays"), iter++);
    touchFlickable->setText(tr("ADC Channals"), iter++);
    touchFlickable->setText(tr("EEPROM"), iter++);
}

void STouchAnalyticsDevices::changeEvent(QEvent* event)
{
    switch (event->type())
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
