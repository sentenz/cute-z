#include "STouchEncoder.h"
#include "../history/SViewHistoryOptions.h"
#include "../history/SPresenterHistoryOdometer.h"
#include "../settings/systems/stouchsettingssystemencoder.h"
#include "../keyboard/STouchKeyboard.h"
#include "../database/SDatabaseOdometer.h"
#include "../widget/wheel/SVTumbler.h"
#include "../widget/layout/SHScrollArea.h"
#include "../widget/button/SToolButton.h"
#include "../widget/label/SLabel.h"
#include "../widget/button/SFabButton.h"
#include "../util/dialog/SAppBar.h"
#include "../util/dialog/SInfoBar.h"
#include "../util/dialog/STextDialog.h"

#include <QApplication>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QException>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QMutex>
#include <QPen>
#include <QRectF>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QFontDatabase>
#ifdef S_DEBUG_SYSTEM
#include <QDebug>
#endif

#include <cmath>


STouchEncoder::STouchEncoder(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("STouchEncoder");
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
    this->setWindowModality(Qt::WindowModal);
    this->setMouseTracking(true);
    this->setModal(true);
    this->activateWindow();
    this->raise();

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->slotReadSettings();
}

STouchEncoder::~STouchEncoder()
{
    if (this->threadEncoder != nullptr)
    {
        delete this->threadEncoder;
        this->threadEncoder = nullptr;
    }
    if (this->buttonDigits != nullptr)
    {
        delete this->buttonDigits;
        this->buttonDigits = nullptr;
    }
    if (this->buttonPlay != nullptr)
    {
        delete this->buttonPlay;
        this->buttonPlay = nullptr;
    }
    if (this->buttonStop != nullptr)
    {
        delete this->buttonStop;
        this->buttonStop = nullptr;
    }
}

void STouchEncoder::setupWidget()
{
    /* File watcher */
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalConfigPathSettings);

    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);
    this->appBar->addIcon(QtMaterialTheme::icon("action", "history"));
    this->appBar->addIcon(QtMaterialTheme::icon("action", "settings"));

    /* Info bar */
    this->infoBar = new SInfoBar(this);
    this->infoBar->addText(this->html(QChar(0x2015), tr("ID")));
    this->infoBar->addText(this->html(QChar(0x2015), tr("Length")));


    int t_height = ::GlobalWindowSize.height() > ::GlobalWindowSize.width() ? ::GlobalWindowSize.height() : ::GlobalWindowSize.width();
    this->touchTumbler = new SVTumbler(false, this);
    this->touchTumbler->setItemHeight(t_height * 0.2);
    this->touchTumbler->setFontSize(100);
    this->touchTumbler->enableHighlight(false);
    this->touchTumbler->setItems(QStringList() << "0");

    this->labelFloat = new QLabel(this);
    this->labelFloat->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    this->labelFloat->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->labelFloat->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->labelFloat->setStyleSheet("QLabel { font: 28pt; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelFloat->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));


    // Buttons
    this->buttonStop = new SToolButton;
    this->buttonStop->setCheckable(true);
    this->buttonStop->setIconSize(QSize(100, 100));
    this->buttonStop->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->buttonStop->setImage(":/images/ic_stop_white_128dp.svg");

    this->buttonPlay = new SToolButton;
    this->buttonPlay->setCheckable(true);
    this->buttonPlay->setIconSize(QSize(175, 175));
    this->buttonPlay->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->buttonPlay->setImage(":/images/ic_play_arrow_white_128dp.svg");

    this->buttonDigits = new SToolButton;
    this->buttonDigits->setCheckable(true);
    this->buttonDigits->setIconSize(QSize(75, 75));
    this->buttonDigits->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->buttonDigits->setImage(":/images/ic_dialpad_white_128dp.svg");


    /* Fab */
    this->m_fabStop = new SFabButton(QtMaterialTheme::icon("av", "stop"), this);
    this->m_fabStop->setCorner(Qt::BottomLeftCorner);
    this->m_fabStop->setFixedSize(QSize(80, 80));
    this->m_fabStop->setIconSize(QSize(60, 60));
    this->m_fabStop->setFixedRippleRadius(76);
    this->m_fabStop->setYOffset(this->height() * 0.3);
    this->m_fabStop->setXOffset(this->width() * 0.1);

    this->m_fabPad = new SFabButton(QtMaterialTheme::icon("communication", "dialpad"), this);
    this->m_fabPad->setCorner(Qt::BottomRightCorner);
    this->m_fabPad->setFixedSize(QSize(80, 80));
    this->m_fabPad->setIconSize(QSize(60, 60));
    this->m_fabPad->setFixedRippleRadius(76);
    this->m_fabPad->setYOffset(this->height() * 0.3);
    this->m_fabPad->setXOffset(this->width() * 0.1);
}

void STouchEncoder::setupLayout()
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(buttonStop, 0, Qt::AlignCenter);
    buttonLayout->addWidget(buttonPlay, 0, Qt::AlignCenter);
    buttonLayout->addWidget(buttonDigits, 0, Qt::AlignCenter);
    buttonLayout->setSpacing(0);
    buttonLayout->setMargin(0);
    buttonLayout->setContentsMargins(0, 0, 0, 0);
    // Widget
    QWidget *widget = new QWidget;
    widget->setLayout(buttonLayout);
    // Scroll Area
    SHScrollArea *scrollArea = new SHScrollArea;
    scrollArea->setWidget(widget);

    QVBoxLayout *labelLayout = new QVBoxLayout;
    labelLayout->addStretch(1);
    labelLayout->addWidget(this->touchTumbler, 5);
    labelLayout->addWidget(this->labelFloat, 1);
    labelLayout->addStretch(1);
    labelLayout->setAlignment(Qt::AlignCenter);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->appBar, 1);
    mainLayout->addWidget(this->infoBar, 1);
    mainLayout->addLayout(labelLayout, 4);
    mainLayout->addWidget(scrollArea, 3);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);

    /* Parent must be set after the layout is placed. */
    this->m_fabStop->setParent(this);
    this->m_fabPad->setParent(this);
}

void STouchEncoder::setConnect()
{
    /* App bar */
    connect(this->appBar,&SAppBar::signalClicked, [this](int n) {
        switch (n) {
        case 0:
        {
            emit this->signalReturn();
        }
            break;

        case 1:
        {
            SViewHistoryOptions viewHistoryOptions(this);
            viewHistoryOptions.closeable(true);
            SPresenterHistoryOdometer presenterHistoryOdometer(&viewHistoryOptions, this);
            presenterHistoryOdometer.create();
        }
            break;

        case 2:
        {
            STouchSettingsSystemEncoder touchSettingsSystemEncoder(this);
            touchSettingsSystemEncoder.setCloseable(true);
            touchSettingsSystemEncoder.exec();
        }
            break;

        default:
            break;
        }
    });

    // File watcher
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchEncoder::slotReadSettings);
    // Buttons
    connect(this->buttonStop, &SToolButton::pressed, [this] {
        // Workaround: button doesn't set back on its own
        this->buttonPlay->setChecked(false);
        // Workaround: button doesn't set on its own
        this->buttonStop->setChecked(true);
        // Unlack the GPIOs of the e-motor in the SControlEncoder.
        emit this->signalRun(false);
        this->stopThread();
        // Save interrupted order.
        if (this->m_session)
        {
            this->setDatabase(false);
        }
        // Reset
        this->resetMembers();
    });
    connect(this->buttonStop, &SToolButton::released, [this] {
        // Workaround: button doesn't set back on its own
        this->buttonStop->setChecked(false);
    });
    connect(this->buttonPlay, &SToolButton::released, [this] {
        if (this->m_target <= 0.0 && this->m_cumulate <= 0.0)
        {
            // Workaround: button doesn't set back on its own
            this->buttonPlay->setChecked(false);
            this->buttonDigits->click();
            return;
        }

        if (this->buttonPlay->isChecked())
        {
#ifdef S_DEBUG_SYSTEM
            qDebug() << "STouchEncoder::setConnect play button";
#endif
            // Start the thread
            this->playThread();
        }
        else // Pause
        {
#ifdef S_DEBUG_SYSTEM
            qDebug() << "STouchEncoder::setConnect pause button";
#endif
            // Pause the thread
            // Note: It is better to run the thread throughout the session
            // to measure the delays when you disable the e-motor. Only
            // unlack the GPIOs of the e-motor in the SControlEncoder.
#ifdef S_DEBUG_SYSTEM
            // To avoid crashes in debug mode.
            this->pauseThread();
#endif
            // Unlack the GPIOs of the e-motor in the SControlEncoder.
            emit this->signalRun(false);
        }
    });
    connect(this->buttonDigits, &SToolButton::pressed, [this] {
        // Workaround: button doesn't set on its own
        this->buttonDigits->setChecked(true);
    });
    connect(this->buttonDigits, &SToolButton::released, [this] {
        // Workaround: doesn't set back from allon
        this->buttonDigits->setChecked(false);
        // Pause the thread for new entry
        this->pause();

        // Set new entry, else continue
        if (this->keyboard())
        {
            // Info board for ID & Target value
            this->initInfo();
        }
    });
    /* Fab */
    connect(this->m_fabPad, &QtMaterialFloatingActionButton::clicked, [this] {
        /* Pause the thread */
        this->pause();
        /* Set new value */
        if (this->keyboard())
        {
            /* Update info board */
            this->initInfo();
        }
    });
}

void STouchEncoder::stop()
{
    // Button stop for reset to return init
    this->buttonStop->click();
}

void STouchEncoder::pause()
{
    if (this->buttonPlay->isChecked())
    {
        // Emit play button to pause thread
        this->buttonPlay->click();
    }
}

void
STouchEncoder::playThread()
{
    if (this->threadEncoder == nullptr)
    {
        // Init
        this->threadEncoder = new SThreadEncoder;
        if (this->threadEncoder != nullptr)
        {
            // New session begins
            this->m_session = true;
            // Start elapsed timer
            this->timer.start();
            // Establish connetions
            connect(this->threadEncoder, &SThreadEncoder::signalRun, this, &STouchEncoder::signalRun);
            connect(this->threadEncoder, &SThreadEncoder::signalData, this, &STouchEncoder::slotDataTransfer);
            connect(this->threadEncoder, &SThreadEncoder::signalError, this, &STouchEncoder::slotErrorMessage);
            // Restart thread
            this->threadEncoder->resume();
        }
    }
    else
    {
        // Restart thread
        this->threadEncoder->resume();
    }
}

void
STouchEncoder::pauseThread()
{
    if (this->threadEncoder != nullptr)
    {
        // Thread pause
        this->threadEncoder->pause();
    }
}

void
STouchEncoder::stopThread()
{
    if (this->threadEncoder != nullptr)
    {
        // Thread stop
        this->threadEncoder->stop();
        // Delete object for new session
        delete this->threadEncoder;
        this->threadEncoder = nullptr;
    }

    // Close app for analyse functions for example.
    if (this->m_closeable)
    {
        this->close();
    }
}

void STouchEncoder::initInfo()
{
    if (std::signbit(this->m_target))
    {
        return;
    }

    /* Get ID from Database */
    SDatabaseOdometer * database = new SDatabaseOdometer("database_encoder.db", ::GlobalConfigPathDatabase);
    /* Set ID to info bar */
    this->infoBar->setText(0, this->html(QString::number(database->getNextID()), tr("ID")));
    database->deleteLater();
    database = nullptr;
}

void STouchEncoder::resetInfo()
{
    this->labelFloat->setText(QString(tr("%1").arg(this->m_cumulate, 0, 'f', this->m_precision, ' ').split(".").at(1) + this->m_unit).split("", QString::SkipEmptyParts).join(QChar(0x2001)).prepend(QChar(0x002C)));
    this->infoBar->setText(0, this->html(QChar(0x2015), tr("ID")));
    this->infoBar->setText(1, this->html(QChar(0x2015), tr("Length")));
}

void STouchEncoder::resetMembers()
{
    this->m_session = false;
    this->m_oneshot = false;
    this->m_cumulate = -0.0;
    this->m_target = -0.0;
    this->resetInfo();
    this->touchTumbler->setItems(QStringList() << "0");
    this->touchTumbler->setCurrentIndex(0);
}

bool STouchEncoder::keyboard()
{
    bool t_accepted = false;

    STouchKeyboard touchKeyboard(this);
    touchKeyboard.setTitle(tr("Input Length [%1]").arg(this->m_unit));
    touchKeyboard.setDescriptionText(tr("The input value must be in the range of %1 to %2").arg(0.0).arg(INT_MAX), STouchKeyboard::Dialog::Information);
    touchKeyboard.setRange(0.0, (double) INT_MAX);
    //touchKeyboard.setMaximumDigit(QString::number(this->maximumValue()).length());
    touchKeyboard.setDatatype(STouchKeyboard::Datatype::Double);
    touchKeyboard.exec();
    if (touchKeyboard.isAccepted())
    {
        // Set target value
        this->m_target = touchKeyboard.getNumber().toDouble();
        // Set info label for target
        this->infoBar->setText(1, this->html(tr("%1 ").arg(this->m_target, 0, 'f', this->m_precision, ' '), tr("Length"), this->m_unit));

        // Workaround for m_up
        this->up();
        // Workaround for m_down
        this->down();
        // Oneshoot value
        this->m_oneshot = false;
        // Return value
        t_accepted = true;
    }
    else
    {
        // Return value
        t_accepted = false;
    }

    return t_accepted;
}

void STouchEncoder::slotRun(const bool run)
{
    this->m_running = run;
}

double STouchEncoder::circumference(const double angle)
{
    if (this->m_clockwise == 0)
    {
        return  angle * (this->m_diameter * M_PI) / 360.0;
    }
    else
    {
        return  -angle * (this->m_diameter * M_PI) / 360.0;
    }
}

void STouchEncoder::slotDataTransfer(const double value)
{
    if (std::signbit(this->m_target))
    {
        return;
    }

    // Calculate driven length about the measuered encoder phase
    this->m_cumulate += this->circumference(value);

    // Update current value of tumbler
    this->touchTumbler->scrollToContent(QString::number((int) floor(this->m_cumulate)), 300);
    // Update float values
    this->labelFloat->setText(QString(tr("%1").arg(this->m_cumulate, 0, 'f', this->m_precision, ' ').split(".").at(1) + this->m_unit).split("", QString::SkipEmptyParts).join(QChar(0x2001)).prepend(QChar(0x002C)));

    if ((this->m_up && this->m_cumulate >= this->m_target) || (this->m_down && this->m_cumulate <= this->m_target))
    {
        if (!this->m_oneshot)
        {
            // Set oneshot
            this->m_oneshot = true;
            // Pause button
            this->pause();
            // Timer delay
            if (!std::signbit(this->m_cumulate))
            {
                QTimer::singleShot(500, this, &STouchEncoder::slotDialogMessage);
            }
        }
    }
}

void STouchEncoder::slotDialogMessage()
{
    STextDialog dialog(this);
    dialog.setTitle(tr("Order"));
    dialog.setDescription(tr("%1 m ").arg(this->m_cumulate, 0, 'f', this->m_precision, ' '));
    dialog.setAcceptButton(tr("Accept"));
    dialog.setRejectButton(tr("Correct"));
    dialog:
    dialog.exec();

    if (dialog.isAccepted())
    {
        // Clear session.
        this->m_session = false;
        // Save finished order.
        for (int i = 0; i<1000; ++i)
        this->setDatabase(true);
        // Button stop for reset to return init
        this->stop();
    }
    else
    {
        // Keyboard
        if (this->keyboard())
        {
            // Info board for ID & Target value
            this->initInfo();
        }
        else
        {
            goto dialog;
        }
    }
}

void STouchEncoder::slotErrorMessage()
{
    // Pause button clicked
    this->pause();

    // Dialog
    STextDialog * dialog = new STextDialog(this);
    dialog->setTitle(tr("Error"));
    dialog->setDescription(tr("Communication could not be established."));
    dialog->setAcceptButton(tr("Accept"));
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void STouchEncoder::setDatabase(const bool completed)
{
    SDatabaseOdometer * database = new SDatabaseOdometer("database_encoder.db", ::GlobalConfigPathDatabase, this);
    database->process(QString::number(this->m_target, 'f', this->m_precision),
                      QString::number(this->m_cumulate, 'f', this->m_precision),
                      completed,
                      timer.restart());
    database->deleteLater();
    database = nullptr;
}

void STouchEncoder::setCloseable(const bool closeable)
{
    this->m_closeable = closeable;
}

bool STouchEncoder::up()
{
    this->m_down = false;
    this->m_up = !std::signbit(this->m_target - this->m_cumulate);
    return this->m_up;
}

bool STouchEncoder::down()
{
    this->m_down = std::signbit(this->m_target - this->m_cumulate);
    this->m_up = false;
    return this->m_down;
}

int STouchEncoder::minimumValue() const
{
    return this->m_minValue;
}

int STouchEncoder::maximumValue() const
{
    return this->m_maxValue;
}

void STouchEncoder::slotReadSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);

    if (!QStringList(settings.allKeys().filter("custom/system/encoder", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/system/encoder");
    }
    else if (!QStringList(settings.allKeys().filter("default/system/encoder", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/system/encoder");
    }

    this->m_clockwise = settings.value("clockwise", 0).toInt();
    this->m_diameter = settings.value("diameter", 0.0).toDouble();
    this->m_precision = settings.value("precision", 0).toInt();

    settings.sync();
    settings.endGroup();

    // Update Widgets with the loaded settings
    this->updateWidget();
}

void
STouchEncoder::updateWidget()
{
    this->labelFloat->setText(QString(tr("%1").arg(this->m_cumulate, 0, 'f', this->m_precision, ' ').split(".").at(1) + this->m_unit).split("", QString::SkipEmptyParts).join(QChar(0x2001)).prepend(QChar(0x002C)));
}

QString
STouchEncoder::elided(const QLabel *label,
                             const QString &text,
                             const Qt::TextElideMode elide)
{
    QFontMetrics t_metrics(label->font());
    return t_metrics.elidedText(text, elide, label->width() - 2);
}


QString
STouchEncoder::html(const QString topText,
                    const QString bottom,
                    const QString unit)
{
    QString text = tr("<p style=\"line-height: 140%\"><span style=\"font-size: 22pt\">%1</span> <sup><span style=\"font-size: 20pt\">%3</span></sup><br><span style=\"font-size: 16pt\">%2</span></p>").arg(topText, bottom, unit);
    return text;
}

void
STouchEncoder::setTitle(const QString text)
{
    this->m_title = text;
    this->appBar->setText(this->m_title);
}

QString
STouchEncoder::title() const
{
    return this->m_title;
}

void STouchEncoder::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
}

void STouchEncoder::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
}

void STouchEncoder::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
}

void STouchEncoder::retranslateUI()
{
    this->appBar->setText(this->m_title);
    this->initInfo();
}

void
STouchEncoder::restyleUI()
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
        this->labelFloat->setStyleSheet("QLabel { font: 28pt; color: " + this->m_colorText.name() + "; background: transparent; }");
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
}

void
STouchEncoder::changeEvent(QEvent* event)
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
