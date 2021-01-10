#include "STouchDialogSerialSetting.h"
#include "../build/SGlobal.h"
#include "../swipe/list/STouchFlickableList.h"
#include "../keyboard/STouchKeyboard.h"

#include <QApplication>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QPropertyAnimation>
#include <QDebug>


STouchDialogSerialSetting::STouchDialogSerialSetting(QWidget *parent) : QDialog(parent)
{
    /// Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowModality(Qt::WindowModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();
    this->setWindowOpacity(1.0);

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
}

STouchDialogSerialSetting::~STouchDialogSerialSetting()
{
    if (this->touchFlickable != nullptr)
    {
        delete this->touchFlickable;
        this->touchFlickable = nullptr;
    }
}

void STouchDialogSerialSetting::setupWidget()
{
    /// Flickable
    ///
    this->touchFlickable = new STouchFlickableList;
    this->touchFlickable->setBaseColor(::GlobalColorBase);
    this->touchFlickable->enableDrawLine(true);
    this->touchFlickable->setCheckable(true);
    this->touchFlickable->setText(tr("Serial Communication"));
    this->touchFlickable->setParameter(QChar(0x276F));

    /// Buttons
    ///
    this->buttonAccept = new QPushButton(tr("Accept"), this);
    this->buttonAccept->setStyleSheet(formStyleSheetString("transparent"));
    this->buttonAccept->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->buttonCancel = new QPushButton(tr("Cancel"), this);
    this->buttonCancel->setStyleSheet(formStyleSheetString("transparent"));
    this->buttonCancel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void STouchDialogSerialSetting::setupGUI()
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(this->buttonCancel);
    buttonLayout->addStretch();
    buttonLayout->addWidget(this->buttonAccept);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->touchFlickable, 7);
    mainLayout->addLayout(buttonLayout, 1);

    this->setLayout(mainLayout);
}

void STouchDialogSerialSetting::setConnect()
{
    /// Buttons
    ///
    connect(this->buttonAccept, &QPushButton::released, this, &STouchDialogSerialSetting::slotAccept);
    connect(this->buttonCancel, &QPushButton::released, this, &STouchDialogSerialSetting::slotClose);
    /// Flickable
    ///
    connect(this->touchFlickable, &STouchFlickableList::signalCurrentIndex, this, &STouchDialogSerialSetting::slotFlickEvent);
}

void STouchDialogSerialSetting::slotFlickEvent(const int &index)
{
    switch (index)
    {
        case 0:
        {
            this->setSerialCommunication(index);
        }
            break;
        default:
        {
            this->setSerialGeneric(index);
        }
            break;
    }
}

void STouchDialogSerialSetting::setSerialCommunication(const int &index)
{
    /// Remove previous serial communication
    ///
    this->removeSerialCommunication();

    /// Select serial communication
    ///
    STouchFlickableList *touchFlickableSerial = new STouchFlickableList(this);
    touchFlickableSerial->setFontSize(18);
    touchFlickableSerial->setFixedSize(this->size());
    touchFlickableSerial->setRepeatable(true, true, 0.45);
    touchFlickableSerial->setCheckable(true);
    touchFlickableSerial->setCloseable(true);
    touchFlickableSerial->setTextAlignment(Qt::AlignCenter);
    touchFlickableSerial->setText("GPIO");
    touchFlickableSerial->setText("UART");
    touchFlickableSerial->setText("I2C");
    touchFlickableSerial->setText("SPI");
    touchFlickableSerial->setText("1-Wire");
    touchFlickableSerial->setText("USB");
    touchFlickableSerial->setText("Bluetooth");
    touchFlickableSerial->setText("Ethernet");
    touchFlickableSerial->setText("WiFi");
    touchFlickableSerial->show();

    /// Settings of serial communication
    ///
    if (touchFlickableSerial->isAccepted())
    {
        /// Flickable
        ///
        this->touchFlickable->setParameter(touchFlickableSerial->getContent(), index);

        this->serial = static_cast<Serial>(touchFlickableSerial->getIndex());

        switch (this->serial)
        {
            case Serial::GPIO:
            {
                this->setGPIO();
            }
                break;
            case Serial::UART:
            {
                this->setUART();
            }
                break;
            case Serial::I2C:
            {
                this->setI2C();
            }
                break;
            case Serial::SPI:
            {
                this->setSPI();
            }
                break;
            case Serial::OneWire:
            {
                this->setOneWire();
            }
                break;
            case Serial::USB:
            {
                this->setUSB();
            }
                break;
            case Serial::Bluetooth:
            {
                this->setBluetooth();
            }
                break;
            case Serial::Ethernet:
            {
                this->setEthernet();
            }
                break;
            case Serial::WiFi:
            {
                this->setWiFi();
            }
                break;
            default:
                break;
        }
    }

    /// Delete
    ///
    if (touchFlickableSerial != nullptr)
    {
        delete touchFlickableSerial;
        touchFlickableSerial = nullptr;
    }
}

void STouchDialogSerialSetting::setSerialGeneric(const int &index)
{
    QString text = this->touchFlickable->getText(index);

    if (text.contains("generic", Qt::CaseInsensitive))
    {
        /// Visible
        this->setInternVisible(false);

        /// Address
        QString value1 = this->setKeyboard(text + " [dex]", 0x00, 0xFFFF, 6);
        if (value1.isEmpty())
        {
            /// Visible
            this->setInternVisible(true);

            return;
        }

        /// Value
        QString value2 = this->setKeyboard(tr("Generic Value [dex]"), 0x00, 0xFFFF, 6);
        if (value2.isEmpty())
        {
            /// Visible
            this->setInternVisible(true);

            return;
        }

        this->touchFlickable->setText(text + " " + value1, index);
        this->touchFlickable->setParameter(value2, index);

        /// Set new generic segister
        if (this->touchFlickable->getParameter(this->touchFlickable->size()-1).compare(QChar(0x276F)) != 0)
        {
            this->touchFlickable->setText(tr("Generic Register Address"));
            this->touchFlickable->setParameter(QChar(0x276F));
        }

        /// Visible
        this->setInternVisible(true);
    }
    else
    {
        QString value = this->setKeyboard(text + " [dex]", 0x00, 0xFFFF, 6);

        if (!value.isEmpty())
        {
            this->touchFlickable->setParameter(value, index);
        }
    }
}

QString STouchDialogSerialSetting::setKeyboard(QString title, int min, int max, int digits)
{
    QString value = "";

    /// Keyboard
    ///
    STouchKeyboard *touchKeyboard = new STouchKeyboard(this);
    touchKeyboard->setTitle(title);
    touchKeyboard->setDescriptionText(tr("The input value must be\n\nin the range of %1 to %2").arg(min).arg(max));
    touchKeyboard->setRange(min, max);
    touchKeyboard->setMaximumDigit(digits);
    touchKeyboard->setDatatype(STouchKeyboard::Datatype::Int);
    touchKeyboard->exec();

    if (touchKeyboard->isAccepted())
    {
        value = QString::number(touchKeyboard->getNumber().toInt(), 16).toUpper().prepend("0x");
    }

    /// Delete Keyboard
    ///
    if (touchKeyboard != nullptr)
    {
        delete touchKeyboard;
        touchKeyboard = nullptr;
    }

    return value;
}

void STouchDialogSerialSetting::setGPIO()
{

}

void STouchDialogSerialSetting::setUART()
{

}

void STouchDialogSerialSetting::setI2C()
{
    this->touchFlickable->setText(tr("Connection Address"));
    this->touchFlickable->setParameter(QChar(0x276F));
    this->touchFlickable->setText(tr("Register Address"));
    this->touchFlickable->setParameter(QChar(0x276F));
    this->touchFlickable->setText(tr("Generic Register Address"));
    this->touchFlickable->setParameter(QChar(0x276F));
}

void STouchDialogSerialSetting::setSPI()
{

}

void STouchDialogSerialSetting::setOneWire()
{

}

void STouchDialogSerialSetting::setUSB()
{

}

void STouchDialogSerialSetting::setBluetooth()
{

}

void STouchDialogSerialSetting::setEthernet()
{

}

void STouchDialogSerialSetting::setWiFi()
{

}

void STouchDialogSerialSetting::slotAccept()
{
    this->accepted = true;
    this->slotClose();
}

bool STouchDialogSerialSetting::isAccepted()
{
    return this->accepted;
}

void STouchDialogSerialSetting::setText(const QString &text)
{
    this->touchFlickable->setText(text);
    this->touchFlickable->setParameter(QChar(0x276F));
}

void STouchDialogSerialSetting::setOpacity(const double opacity)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_OpaquePaintEvent);

    this->m_opacitiy = opacity;
    this->touchFlickable->setOpacity(opacity);
    this->setWindowOpacity(opacity);
    this->update();
}

void STouchDialogSerialSetting::setBaseColor(const QColor &color)
{
    this->background_color = color;
    this->touchFlickable->setBaseColor(color);
    this->update();
}

void STouchDialogSerialSetting::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.fillRect(event->rect(), this->background_color);
    painter.end();
}

void STouchDialogSerialSetting::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationFastTimeIn);
    animation->setStartValue(0);
    animation->setEndValue(this->m_opacitiy);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void STouchDialogSerialSetting::slotClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationFastTimeOut);
    animation->setStartValue(this->m_opacitiy);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

    QTimer::singleShot(::GlobalAnimationTimeOut, this, SLOT(close()));
}

void STouchDialogSerialSetting::retranslateUI()
{
    /// Flickable
    ///
    this->touchFlickable->setText(tr("Serial Communication"), 0);

    /// Buttons
    ///
    this->buttonAccept->setText(tr("Accept"));
    this->buttonCancel->setText(tr("Cancel"));
}

void STouchDialogSerialSetting::changeEvent(QEvent* event)
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

QString STouchDialogSerialSetting::formStyleSheetString(const QString &style)
{
    QString styleButton;

    if (!style.compare("blue"))
    {
        styleButton =
        "\
            QPushButton           { font: 18pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; background-color: " + ::GlobalColorContrast.name() + "; border: none; } \
            QPushButton:pressed   { font: 18pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; background-color: " + ::GlobalColorHighlight.name() + "; border: none; } \
            QPushButton:disabled  { font: 18pt " + ::GlobalFont + "; color: #404040; background: " + ::GlobalColorContrast.name() + "; border: none; } \
        ";
    }
    else if (!style.compare("transparent"))
    {
        styleButton =
        "\
            QPushButton           { font: 17pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; background-color: transparent; border: none; } \
            QPushButton:pressed   { font: 17pt " + ::GlobalFont + "; color: " + ::GlobalColorHighlight.name() + "; background-color: transparent; border: none; } \
            QPushButton:disabled  { font: 17pt " + ::GlobalFont + "; color: #404040; background: transparent; border: none; } \
        ";
    }

    return styleButton;
}

void STouchDialogSerialSetting::setInternVisible(bool visible)
{
    this->touchFlickable->setVisible(visible);
    this->buttonAccept->setVisible(visible);
    this->buttonCancel->setVisible(visible);
}

void STouchDialogSerialSetting::removeSerialCommunication()
{
    int size = this->touchFlickable->size();

    for (int i = size-1; i > 0; --i)
    {
        this->touchFlickable->removeIndex(i);
    }
}
