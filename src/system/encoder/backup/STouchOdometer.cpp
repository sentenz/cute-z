#include "STouchOdometer.h"
#include "SOdometer.h"
#include "../build/SGlobal.h"
#include "../device/SEngine.h"
#include "../database/SDatabase.h"
#include "../keyboard/STouchKeyboard.h"
#include "../effect/SGraphicsGlowEffect.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>


STouchOdometer::STouchOdometer(QWidget *parent) : QDialog(parent)
{
    this->resize(::GlobalWindowSize);
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_UnderMouse, false);
    this->setMouseTracking(true);

    this->setUpWidget();
    this->setUpGUI();
    this->setConnect();

    #ifdef S_LOGGER
    this->loggerWave.setFilename("wave");
    this->loggerPhase.setFilename("phase");
    this->loggerUnwrap.setFilename("unwrap");
    #endif
}

STouchOdometer::~STouchOdometer()
{
    if (odometer != nullptr)
    {
        delete odometer;
        odometer = nullptr;
    }
    if (engine != nullptr)
    {
        delete engine;
        engine = nullptr;
    }
    if (touchKeyboard != nullptr)
    {
        delete touchKeyboard;
        touchKeyboard = nullptr;
    }
}

void STouchOdometer::setUpWidget()
{
    /// TIMER
    timer = new QTimer(this);

    /// ODOMETER
    odometer = new SOdometer;

    /// ENGINE
    engine = new SEngine(BUS::Wire1);

    /// KEYBOARD
    touchKeyboard = new STouchKeyboard;
    touchKeyboard->setTitle(tr("Length [m]"));
    touchKeyboard->setDescriptionText(tr("The length must be\n\ninbetween 0.0 m and 1000.0 m"));
    touchKeyboard->setRange(0.0, 1000.0);
    touchKeyboard->setMaximumDigit(7);
    touchKeyboard->setDatatyp("double");

    /// LABELS
    labelTextID = new QLabel(tr("ID:"), this);
    labelTextID->setVisible(false);
    labelTextID->setStyleSheet("QLabel { font: 14pt " + ::GlobalFont + "; color: rgba(0,128,240); background: transparent; }");

    labelID = new QLabel(this);
    labelID->setVisible(false);
    labelID->setAlignment(Qt::AlignCenter);
    labelID->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    labelID->setStyleSheet("QLabel { font: 20pt " + ::GlobalFont + "; color: rgba(0,128,240); background: transparent; }");

    labelTextOrder = new QLabel(tr("Order:"), this);
    labelTextOrder->setVisible(false);
    labelTextOrder->setStyleSheet("QLabel { font: 14pt " + ::GlobalFont + "; color: rgba(0,128,240); background: transparent; }");

    labelOrder = new QLabel(this);
    labelOrder->setVisible(false);
    labelOrder->setAlignment(Qt::AlignCenter);
    labelOrder->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    labelOrder->setStyleSheet("QLabel { font: 20pt " + ::GlobalFont + "; color: rgba(0,128,240); background: transparent; }");

    labelTextMeasured = new QLabel(tr("Measured:"), this);
    labelTextMeasured->setVisible(false);
    labelTextMeasured->setStyleSheet("QLabel { font: 14pt " + ::GlobalFont + "; color: rgba(0,128,240); background: transparent; }");

    labelMeasured = new QLabel(this);
    labelMeasured->setVisible(false);
    labelMeasured->setAlignment(Qt::AlignCenter);
    labelMeasured->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    labelMeasured->setStyleSheet("QLabel { font: 20pt " + ::GlobalFont + "; color: rgba(0,128,240); background: transparent; }");

    labelValues = new QLabel(this);
    labelValues->setVisible(false);
    labelValues->setAlignment(Qt::AlignCenter);
    labelValues->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    labelValues->setStyleSheet("QLabel { font: 50pt " + ::GlobalFont + "; color: " + ::GlobalTextColor + "; background: transparent; }");

    /// BUTTONS
    buttonStart = new QPushButton(this);
    buttonStart->setDefault(true);
    buttonStart->setCheckable(true);
    buttonStart->setVisible(false);
    buttonStart->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    buttonStart->setStyleSheet(formStyleSheetString("start", "play_1"));

    buttonCorrect = new QPushButton(tr("Correct"), this);
    buttonCorrect->setCheckable(true);
    buttonCorrect->setVisible(false);
    buttonCorrect->setAutoExclusive(true);
    buttonCorrect->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    buttonCorrect->setStyleSheet(formStyleSheetString("correct"));

    buttonCancel = new QPushButton(tr("Cancel"), this);
    buttonCancel->setCheckable(true);
    buttonCancel->setVisible(false);
    buttonCancel->setAutoExclusive(true);
    buttonCancel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    buttonCancel->setStyleSheet(formStyleSheetString("cancel"));

    buttonCircle = new QPushButton(this);
    buttonCircle->setIcon(QIcon(QPixmap(":/images/keyboard.svg")));
    buttonCircle->setIconSize(QSize(150,150));
    buttonCircle->setCheckable(true);
    buttonCircle->setAutoExclusive(true);
    buttonCircle->setFixedSize(QSize(200, 200));
    buttonCircle->move(800/2 - buttonCircle->width()/2, 480/2 - buttonCircle->height()/2);
    buttonCircle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    buttonCircle->setStyleSheet(formStyleSheetString("eclipse"));
    SGraphicsGlowEffect *glow = new SGraphicsGlowEffect();
    glow->setColor(QColor(0,128,240));
    glow->setBlurRadius(15);
    glow->setStrength(1);
    buttonCircle->setGraphicsEffect(glow);
}

void STouchOdometer::setUpGUI()
{
    QHBoxLayout *layoutLevel_1 = new QHBoxLayout;
    layoutLevel_1->addWidget(labelTextID, 0, Qt::AlignLeft);
    layoutLevel_1->addWidget(labelID, 10, Qt::AlignRight);
    layoutLevel_1->addSpacing(width()/20);
    layoutLevel_1->addWidget(labelTextOrder, 5, Qt::AlignLeft);
    layoutLevel_1->addWidget(labelOrder, 10, Qt::AlignRight);
    layoutLevel_1->addSpacing(width()/20);
    layoutLevel_1->addWidget(labelTextMeasured, 5, Qt::AlignLeft);
    layoutLevel_1->addWidget(labelMeasured, 10, Qt::AlignRight);
    layoutLevel_1->setContentsMargins(width()/40,0,width()/40,0);

    QVBoxLayout *layoutLevel_2 = new QVBoxLayout;
    layoutLevel_2->addWidget(labelValues);
    layoutLevel_2->setAlignment(Qt::AlignCenter);

    QHBoxLayout *layoutLevel_31 = new QHBoxLayout;
    layoutLevel_31->addWidget(buttonStart);
    QHBoxLayout *layoutLevel_32 = new QHBoxLayout;
    layoutLevel_32->addWidget(buttonCancel);
    layoutLevel_32->addStretch();
    layoutLevel_32->addWidget(buttonCorrect);
    QVBoxLayout *layoutLevel_3 = new QVBoxLayout;
    layoutLevel_3->addLayout(layoutLevel_31);
    layoutLevel_3->addLayout(layoutLevel_32);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layoutLevel_1);
    mainLayout->addLayout(layoutLevel_2);
    mainLayout->addLayout(layoutLevel_3);
    mainLayout->setStretch(0,1);
    mainLayout->setStretch(1,6);
    mainLayout->setStretch(2,5);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void STouchOdometer::setConnect()
{
    /// KEYBORD
    connect(touchKeyboard, &STouchKeyboard::signalNumbersChanged, this, &STouchOdometer::slotSetValue);
    /// BUTTONS
    connect(buttonCircle, &QPushButton::released, this, &STouchOdometer::slotCircleButton);
    connect(buttonStart, &QPushButton::toggled, this, &STouchOdometer::slotStartButton);
    connect(buttonCorrect, &QPushButton::released, this, &STouchOdometer::slotCorrectButton);
    connect(buttonCancel, &QPushButton::released, this, &STouchOdometer::slotReset);
    /// ODOMETER
    connect(timer, &QTimer::timeout, this, &STouchOdometer::slotStartOdometer);
    connect(odometer, &SOdometer::start, this, &STouchOdometer::slotForward);
    connect(odometer, &SOdometer::stop, this, &STouchOdometer::slotNeutral);
}

void STouchOdometer::slotSetValue(QString text)
{
    if (!text.isEmpty())
    {
        order = text.toDouble();
        odoValue = order  - odoMeasured;

        if (!std::signbit(odoValue))
        {
            forward = true;
            backward = false;
        }
        else
        {
            forward = false;
            backward = true;
        }

        /// LABEL
        labelOrder->setText(tr("%1").arg(order, 0, 'f', 3, ' ').append(tr(" m")));
    }
}

void STouchOdometer::slotCircleButton()
{  
    /// ODOMETER
    if (!odometer->initOdometer())
    {
        return;
    }

    buttonCircle->setVisible(false);

    /// KEYBOARD
    touchKeyboard->exec();
    if (touchKeyboard->isAccepted())
    {
        /// DATABASE
        #ifdef S_EMBEDDED
        database = new SDatabase(QString("/home/pi/.config/sentenz").append("/database"));
        #else
        database = new SDatabase(qApp->applicationDirPath().append("/database"));
        #endif

        /// LABEL
        labelID->setText(tr("%1").arg(database->getNextID()));
        labelMeasured->setText(tr("%1").arg(odoMeasured, 0, 'f', 3, ' ').append(tr(" m")));
        labelValues->setText(tr("%1").arg(odoValue, 0, 'f', 3, ' ').append(tr(" m")));

        labelTextID->setVisible(true);
        labelTextOrder->setVisible(true);
        labelTextMeasured->setVisible(true);
        labelID->setVisible(true);
        labelOrder->setVisible(true);
        labelMeasured->setVisible(true);
        labelValues->setVisible(true);

        /// set start button status to play
        status = 0;

        /// BUTTON
        buttonStart->setStyleSheet(formStyleSheetString("start", "play_1"));
        buttonStart->setVisible(true);
        buttonCorrect->setVisible(true);
        buttonCancel->setVisible(true);

        #ifdef S_LOGGER
        this->loggerWave.start();
        this->loggerPhase.start();
        this->loggerUnwrap.start();
        #endif
    }
    else
    {
        buttonCircle->setVisible(true);
    }
}

void STouchOdometer::slotStartButton()
{
    switch (status)
    {
        case 0: /// start
        {
            if (order || odoMeasured)
            {
                /// set start button status to pause
                status = 1;

                /// TIMER
                ///
                /// brief: don't forget to adjust the timer in SPlot
                ///
                #ifdef S_EMBEDDED
                timer->start(0);
                #else
                timer->start(1);
                #endif

                if (forward)
                {
                    emit slotForward();
                }
                else if (backward)
                {
                    emit slotBackward();
                }

                /// BUTTON
                buttonStart->setStyleSheet(formStyleSheetString("play", "play_1"));
            }
        }
            break;
        case 1: /// pause
        {
            /// init start button
            status = 0;

            emit slotNeutral();

            /// TIMER
            QTimer::singleShot(1000, timer, SLOT(stop()));

            /// BUTTON
            buttonStart->setStyleSheet(formStyleSheetString("pause", "pause_1"));
        }
            break;
        case 2: /// finish
        {
            /// DATABASE
            database->saveMeasurement(order, odoMeasured);
            database->saveToAbolutLength(odoMeasured);
            delete database;
            database = nullptr;

            emit slotReset();
        }
            break;
        default:
            break;
    }

    if (status)
    {
        buttonCancel->setEnabled(false);
    }
}

void STouchOdometer::slotCorrectButton()
{
    emit slotNeutral();

    /// TIMER
    QTimer::singleShot(1000, timer, SLOT(stop()));

    /// KEYBOARD
    touchKeyboard->exec();
    if (touchKeyboard->isAccepted())
    {
        /// LABEL
        labelValues->setText(tr("%1").arg(odoValue, 8, 'f', 3, ' ').append(tr(" m")));

        /// set start button status to play/pause
        status = 0;

        /// BUTTON
        if (odoMeasured)
        {
            buttonStart->setStyleSheet(formStyleSheetString("pause", "play_pause"));
        }
    }
    else if (status == 1) /// pause
    {
        /// set start button status to play/pause
        status = 0;

        /// BUTTON
        buttonStart->setStyleSheet(formStyleSheetString("pause", "play_pause"));
    }
}

void STouchOdometer::slotReset()
{
    emit slotNeutral();

    /// TIMER
    QTimer::singleShot(1000, timer, SLOT(stop()));

    /// LABEL
    labelTextID->setVisible(false);
    labelTextOrder->setVisible(false);
    labelTextMeasured->setVisible(false);
    labelID->setVisible(false);
    labelOrder->setVisible(false);
    labelMeasured->setVisible(false);
    labelValues->setVisible(false);
    labelID->clear();
    labelOrder->clear();
    labelMeasured->clear();
    labelValues->clear();

    /// BUTTON
    buttonStart->setStyleSheet(formStyleSheetString("start", "play_1"));
    buttonStart->setVisible(false);
    buttonCorrect->setVisible(false);
    buttonCancel->setVisible(false);
    buttonCancel->setEnabled(true);
    buttonCircle->setVisible(true);

    /// ODOMETER
    status = 0;
    order = 0.0;
    odoValue = 0.0;
    odoMeasured = 0.0;
    forward = true;
    backward = false;
    odometer->reset();

    #ifdef S_LOGGER
    this->loggerWave.close();
    this->loggerPhase.close();
    this->loggerUnwrap.close();
    odometer->setUnwrap(0.0);
    #endif
}

void STouchOdometer::slotStartOdometer()
{
    double value = 0.0;

    if (odometer->getValue(value))
    {
        if (forward)
        {
            odoValue -= value;
            odoMeasured += value;

            if (std::signbit(odoValue))
            {
                emit slotStopOdometer();
            }
        }
        else if (backward)
        {
            odoValue += value;
            odoMeasured -= value;

            if (!std::signbit(odoValue))
            {
                emit slotStopOdometer();
            }
        }

        labelValues->setText(tr("%1").arg(odoValue, 0, 'f', 3, ' ').append(tr(" m")));
        labelMeasured->setText(tr("%1").arg(odoMeasured, 0, 'f', 3, ' ').append(tr(" m")));

        if (order == 0.0 && fabs(odoMeasured) < 0.009)
        {
            buttonCancel->setEnabled(true);
        }

        #ifdef S_LOGGER
        this->loggerWave.set(odometer->getWave());
        this->loggerPhase.set(odometer->getPhase());
        this->loggerUnwrap.set(odometer->getUnwrap());
        #endif
    }
}

void STouchOdometer::slotStopOdometer()
{
    emit slotNeutral();

    /// TIMER
    QTimer::singleShot(1000, timer, SLOT(stop()));

    /// BUTTON
    if (order)
    {
        /// set start button status to finish
        status = 2;

        buttonStart->setStyleSheet(formStyleSheetString("finish", "done"));
    }
    else
    {
        /// init start button
        status = 0;

        buttonStart->setStyleSheet(formStyleSheetString("start", "play_1"));
    }
}

void STouchOdometer::slotForward()
{
    engine->forward(Engine::EMotor);
}

void STouchOdometer::slotBackward()
{
    engine->backward(Engine::EMotor);
}

void STouchOdometer::slotNeutral()
{
    engine->neutral(Engine::EMotor);
}

QString STouchOdometer::formStyleSheetString(const QString &style, const QString &icon)
{
    QString styleButton;

    if (!style.compare("start"))
    {
        styleButton =
        "\
            QPushButton { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background: transparent; border-top: 2px solid gray; border-bottom: 2px solid gray; border-right: none; border-left: none; } \
            QPushButton:default { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background: transparent; border-top: 2px solid gray; border-bottom: 2px solid gray; border-right: none; border-left: none; } \
            QPushButton:disabled { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background: transparent; border: border-top: 2px solid darkgray; border-bottom: 2px solid darkgray; border-right: none; border-left: none; } \
        ";
    }
    else if (!style.compare("play"))
    {
        styleButton =
        "\
            QPushButton { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background-color: rgba(0,128,240,200); border: 2px solid transparent; } \
        ";
    }
    else if (!style.compare("pause"))
    {
        styleButton =
        "\
            QPushButton { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background-color: rgba(240,128,128,200); border: 2px solid transparent; } \
        ";
    }
    else if (!style.compare("finish"))
    {
        styleButton =
        "\
            QPushButton { qproperty-icon: url(:/images/"+ icon +".svg); icon-size: 80px 80px; background-color: rgb(128,240,128,200); border: 2px solid transparent; }\
        ";
    }
    else if (!style.compare("cancel") || !style.compare("correct"))
    {
        styleButton =
        "\
            QPushButton:!pressed { font: 18pt " + ::GlobalFont + "; color: " + ::GlobalTextColor + "; background: transparent; border: none; } \
            QPushButton:pressed  { font: 18pt " + ::GlobalFont + "; color: rgba(0,128,240); background: transparent; border: none; } \
            QPushButton:disabled { font: 18pt " + ::GlobalFont + "; color: #454545; background: transparent; border: none; } \
        ";
    }
    else if (!style.compare("eclipse"))
    {
        styleButton =
        "\
            QPushButton:!pressed { font: 22pt; color: " + ::GlobalTextColor + "; background-color: " + ::GlobalBackgroundColor + "; border: none; border-radius: 100px; } \
            QPushButton:pressed  { font: 22pt; color: " + ::GlobalTextColor + "; background-color: rgba(0,128,240,80); border: none; border-radius: 100px; } \
        ";
    }

    return styleButton;
}

void STouchOdometer::retranslateUI()
{
    touchKeyboard->setTitle(tr("Length [m]"));
    touchKeyboard->setDescriptionText(tr("The length must be\n\ninbetween 0.0 m and 1000.0 m"));

    labelTextID->setText(tr("ID:"));
    labelTextOrder->setText(tr("Order:"));
    labelTextMeasured->setText(tr("Measured:"));

    buttonCorrect->setText(tr("Correct"));
    buttonCancel->setText(tr("Cancel"));
}

void STouchOdometer::changeEvent(QEvent* event)
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
