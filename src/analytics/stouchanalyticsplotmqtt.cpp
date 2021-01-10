#include "stouchanalyticsplotmqtt.h"
#include "../iot/mqtt/SMqtt.h"

#ifdef S_QT
#include "../plot/SPlot.h"
#else
#include "../plot/SPlotQwt.h"
#endif

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QJsonObject>
#include <QTimer>
#include <QVector>
#include <QEvent>
#include <QFocusEvent>
#include <QLabel>
#include <QDebug>

#include <fcntl.h>


STouchAnalyticsPlotMqtt::STouchAnalyticsPlotMqtt(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("STouchAnalyticsPlotMqtt");
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setFocusPolicy(Qt::StrongFocus);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchAnalyticsPlotMqtt::~STouchAnalyticsPlotMqtt()
{
    if (this->plot != nullptr)
    {
        delete this->plot;
        this->plot = nullptr;
    }
    if (this->mqtt != nullptr)
    {
        delete this->mqtt;
        this->mqtt = nullptr;
    }
}

void STouchAnalyticsPlotMqtt::setupWidget()
{
    /// Plot
    ///
    #ifdef S_QT
    this->plot = new SPlot;
    #else
    this->plot = new SPlotQwt;
    #endif
    this->plot->setVisbleAxisX(false);
    this->plot->setRangeAxisX(0, 100);
    //this->plot->setCheckable(true);
    this->plot->setFreeRun(true);

    this->mqtt = new SMqtt("Client1");
    this->mqtt->setAuthentication("client", "client@mqtt");
    this->mqtt->setSecurity("/etc/mosquitto/certs/ca.pem");
    this->mqtt->setClient("sentenz", 8883);

    this->labelID = new QLabel(this);
    this->labelID->setAlignment(Qt::AlignCenter);
    this->labelID->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->labelID->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    this->labelID->setStyleSheet("QLabel { font: 16pt; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelID->setText(this->setHtmlText(tr("ID"), QChar(0x2015)));

    this->labelValue = new QLabel(this);
    this->labelValue->setAlignment(Qt::AlignCenter);
    this->labelValue->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->labelValue->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    this->labelValue->setStyleSheet("QLabel { font: 16pt; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelValue->setText(this->setHtmlText(tr("Value"), QChar(0x2015)));

    this->labelTemperature = new QLabel(this);
    this->labelTemperature->setAlignment(Qt::AlignCenter);
    this->labelTemperature->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->labelTemperature->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    this->labelTemperature->setStyleSheet("QLabel { font: 16pt; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelTemperature->setText(tr("<p style=\"line-height:140%\">°C<br><big><b>%1</b></big></p>").arg(""));
    this->labelTemperature->setText(this->setHtmlText(tr("°C"), QChar(0x2015)));
}

void STouchAnalyticsPlotMqtt::setupLayout()
{
    QHBoxLayout *infoLayout = new QHBoxLayout;
    infoLayout->addWidget(this->labelID, Qt::AlignBottom | Qt::AlignHCenter);
    infoLayout->addWidget(this->labelValue, Qt::AlignBottom | Qt::AlignHCenter);
    infoLayout->addWidget(this->labelTemperature, Qt::AlignBottom | Qt::AlignHCenter);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(infoLayout, 2);
    mainLayout->addWidget(this->plot, 5);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(mainLayout);
    setStyleSheet("border-width: 0px;");
}

void STouchAnalyticsPlotMqtt::setConnect()
{
    connect(this->mqtt, &SMqtt::signalConnected, this, &STouchAnalyticsPlotMqtt::slotConnected);
    connect(this->mqtt, &SMqtt::signalDisconnected, this, &STouchAnalyticsPlotMqtt::slotDisconnected);
    connect(this->mqtt, &SMqtt::signalMessageReceived, this, &STouchAnalyticsPlotMqtt::slotMessageReceived);
}

void STouchAnalyticsPlotMqtt::slotConnected(const bool connected)
{
    if (connected)
    {
        this->mqtt->subscribing("device/sensor", 0);
    }
}

void STouchAnalyticsPlotMqtt::slotDisconnected(const bool disconnected)
{
    if (disconnected)
    {
        this->mqtt->unsubscribing("device/sensor");

        /// Clear
        this->plot->clear();
        this->labelID->setText(this->setHtmlText(tr("ID"), QChar(0x2015)));
        this->labelValue->setText(this->setHtmlText(tr("Value"), QChar(0x2015)));
        this->labelTemperature->setText(this->setHtmlText(tr("°C"), QChar(0x2015)));
    }
}

void STouchAnalyticsPlotMqtt::slotMessageReceived(const QString message)
{
    QJsonObject json = this->mqtt->getJson(message);
    this->labelID->setText(this->setHtmlText(tr("ID"), json["ID"].toString()));
    this->labelValue->setText(this->setHtmlText(tr("Value"), json["Value"].toString()));
    this->labelTemperature->setText(this->setHtmlText(tr("°C"), json["Temperature"].toString()));

    /// Set data.
    this->plot->setUpdate(json["Value"].toDouble());
}

QString
STouchAnalyticsPlotMqtt::setHtmlText(const QString upperText,
                       const QString lowerText)
{
    QString text = tr("<p style=\"line-height:140%\">%1<br><big>%2</big></p>").arg(upperText, lowerText);
    return text;
}

void
STouchAnalyticsPlotMqtt::setBackgroundColor(const QColor &color)
{
    this->m_colorBase = color;
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->plot->setBackgroundColor(color);
    this->update();
}

void
STouchAnalyticsPlotMqtt::setContrastColor(const QColor &color)
{
    this->m_colorContrast = color;
    this->plot->setContrastColor(color);
    this->update();
}

void
STouchAnalyticsPlotMqtt::setTextColor(const QColor &color)
{
    this->m_colorText = color;
    this->plot->setTextColor(color);
    this->labelID->setStyleSheet("QLabel { font: 16pt; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelValue->setStyleSheet("QLabel { font: 16pt; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelTemperature->setStyleSheet("QLabel { font: 16pt; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->update();
}

void
STouchAnalyticsPlotMqtt::setHighlightColor(const QColor &color)
{
    this->m_colorHighlight = color;
    this->plot->setHighlightColor(color);
    this->update();
}

void STouchAnalyticsPlotMqtt::retranslateUI()
{
}

void STouchAnalyticsPlotMqtt::changeEvent(QEvent* event)
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
