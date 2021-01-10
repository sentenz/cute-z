#include "SCentral.h"
#include "../system/encoder/SControlEncoder.h"
#include "../system/nfc/SControlNFC.h"
#include "../system/panel/STouchPanel.h"
#include "../settings/stouchsettings.h"
#include "../keyboard/STouchScreenlock.h"
#include "../tool/STouchHome.h"
#include "../util/dialog/STouchDialogScreensaver.h"
#include "../util/dialog/STouchDialogBoot.h"
#include "../util/dialog/SNavigationDrawer.h"
#include "../widget/stacked/SAnimatedStackedWidget.h"
#include "../widget/util/SSnackbar.h"

#include <QApplication>
#include <QPoint>
#include <QObject>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QDate>
#include <QString>
#include <QVBoxLayout>
#include <QEvent>
#include <QTimer>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QDebug>


SCentral::SCentral(QWidget *parent): QMainWindow(parent)
{
    this->setObjectName("SCenter");
    /// Disables cursor
    if (!::GlobalDefinesCursor)
    {
        QApplication::setOverrideCursor(Qt::BlankCursor);
    }
    /// Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->setFixedSize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setMouseTracking(true);

    qApp->installEventFilter(this);

    this->slotWriteSettings();
    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->slotReadSettings();

    // TODO: Ckeck it on rpi
    // Show the main UI for a smooth transition from splashscreen to screenlock on the very first boot
    // hide() is in contructor
    // show() is in setLock()
    this->hide();
}

SCentral::~SCentral()
{
    if (this->touchHome != nullptr)
    {
        delete this->touchHome;
        this->touchHome = nullptr;
    }
    if (this->touchScreenlock != nullptr)
    {
        delete this->touchScreenlock;
        this->touchScreenlock = nullptr;
    }
    if (this->touchSettings != nullptr)
    {
        delete this->touchSettings;
        this->touchSettings = nullptr;
    }
    if (::GlobalDefinesEncoder)
    {
        if (this->controlEncoder != nullptr)
        {
            /// Go sure the Application stopped
            this->controlEncoder->stop();

            delete this->controlEncoder;
            this->controlEncoder = nullptr;
        }
    }
    if (::GlobalDefinesNfc)
    {
        if (this->controlNFC != nullptr)
        {
            /// Go sure the Application stopped
            this->controlNFC->stop();

            delete this->controlNFC;
            this->controlNFC = nullptr;
        }
    }
    if (::GlobalDefinesPanel)
    {
        if (this->touchPanel != nullptr)
        {
            delete this->touchPanel;
            this->touchPanel = nullptr;
        }
    }
}

void SCentral::setupWidget()
{
    /* File watcher */
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalConfigPathSettings);

    /* App - Encoder */
    if (::GlobalDefinesEncoder)
    {
        this->controlEncoder = new SControlEncoder;
    }

    /* App - NFC */
    if (::GlobalDefinesNfc)
    {
        this->controlNFC = new SControlNFC;
    }

    /* App - Panel */
    if (::GlobalDefinesPanel)
    {
        this->touchPanel = new STouchPanel;
    }

    /* Home */
    this->touchHome = new STouchHome;

    /* Settings */
    this->touchSettings = new STouchSettings;

    /* Sreen lock */
    this->touchScreenlock = new STouchScreenlock(this);
    this->touchScreenlock->enableSymbols(true, false);

    /* Animated stacked widget */
    this->stackedWidget = new SAnimatedStackedWidget(this);
    this->stackedWidget->setDuration(400);
    this->stackedWidget->setAnimation(QEasingCurve::InQuad);
    if (::GlobalDefinesEncoder)
    {
        this->stackedWidget->addWidget(this->controlEncoder);
    }
    if (::GlobalDefinesNfc)
    {
        this->stackedWidget->addWidget(this->controlNFC);
    }
    if (::GlobalDefinesPanel)
    {
        this->stackedWidget->addWidget(this->touchPanel);
    }
    this->stackedWidget->addWidget(this->touchSettings);
    this->stackedWidget->addWidget(this->touchHome);
    this->stackedWidget->setCurrentWidget(this->touchHome);
    this->stackedWidget->setContentsMargins(0, 0, 0, 0);

    /* Navigation drawer*/
    this->m_drawer = new SNavigationDrawer(this);

    /* Snackbar */
    this->m_snackbar = new SSnackbar(this);
}

void SCentral::setupLayout()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(this->stackedWidget);
    layout->setContentsMargins(0, 0, 0, 0);

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);

//    this->setLayout(mainLayout);
    this->setCentralWidget(widget);
}

void SCentral::setConnect()
{
    /* File watcher */
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &SCentral::slotReadSettings);

    /* Apps - Prevent screen lock when an application is running */
    connect(this->controlNFC, &SControlNFC::signalRun, [this](const bool run) { this->m_appActive = run; });
    connect(this->controlEncoder, &SControlEncoder::signalRun, [this](const bool run) { this->m_appActive = run; });

    /* Navigation */
    connect(this->touchHome, &STouchHome::signalDrawer, this->m_drawer, &SNavigationDrawer::exec);
    connect(this->touchHome, &STouchHome::signalOption, [this] {
        this->stackedWidget->slideIn(this->touchSettings, SAnimatedStackedWidget::Direction::RightToLeft);
    });
    connect(this->touchHome, &STouchHome::signalReleased, [this](const int index) {
        switch (index)
        {
        case 0:
            if (::GlobalDefinesPanel)
            {
                this->stackedWidget->slideIn(this->touchPanel, SAnimatedStackedWidget::Direction::RightToLeft);
            }
            break;

        case 1:
            if (::GlobalDefinesNfc)
            {
                this->stackedWidget->slideIn(this->controlNFC, SAnimatedStackedWidget::Direction::RightToLeft);
            }
            break;

        case 2:
            if (::GlobalDefinesEncoder)
            {
                this->stackedWidget->slideIn(this->controlEncoder, SAnimatedStackedWidget::Direction::RightToLeft);
            }
            break;

        default:
            break;
        }
    });
    connect(this->m_drawer, &SNavigationDrawer::signalReleased, [this] (const int index) {
        switch (index)
        {
        case 1:
            this->stackedWidget->slideIn(this->touchHome, SAnimatedStackedWidget::Direction::RightToLeft);
            break;

        case 2:
            if (::GlobalDefinesPanel)
            {
                this->stackedWidget->slideIn(this->touchPanel, SAnimatedStackedWidget::Direction::RightToLeft);
            }
            break;

        case 3:
            if (::GlobalDefinesNfc)
            {
                this->stackedWidget->slideIn(this->controlNFC, SAnimatedStackedWidget::Direction::RightToLeft);
            }
            break;

        case 4:
            if (::GlobalDefinesEncoder)
            {
                this->stackedWidget->slideIn(this->controlEncoder, SAnimatedStackedWidget::Direction::RightToLeft);
            }
            break;

        case 5:
            this->stackedWidget->slideIn(this->touchSettings, SAnimatedStackedWidget::Direction::RightToLeft);
            break;

        case 6:
            this->setLock();
            break;

        case 7:
        {
            STouchDialogBoot touchDialogBoot(this);
            touchDialogBoot.exec();
        }
            break;

        default:
            break;
        }

        emit this->m_drawer->signalClose();
    });

    /* Return */
    connect(this->touchPanel, &STouchPanel::signalReturn, [this] {
        this->stackedWidget->slideIn(this->touchHome, SAnimatedStackedWidget::Direction::RightToLeft);
    });
    connect(this->controlEncoder, &SControlEncoder::signalReturn, [this] {
        if (::GlobalDefinesEncoder)
        {
            // Sets the Application to pause, when you leave the widget window
            this->controlEncoder->pause();
        }
        this->stackedWidget->slideIn(this->touchHome, SAnimatedStackedWidget::Direction::RightToLeft);
    });
    connect(this->controlNFC, &SControlNFC::signalReturn, [this] {
        if (::GlobalDefinesNfc)
        {
            // Sets the Application to pause, when you leave the widget window
            this->controlNFC->pause();
        }
        this->stackedWidget->slideIn(this->touchHome, SAnimatedStackedWidget::Direction::RightToLeft);
    });
    connect(this->touchSettings, &STouchSettings::signalReturn, [this] {
        this->stackedWidget->slideIn(this->touchHome, SAnimatedStackedWidget::Direction::RightToLeft);
    });
}

bool SCentral::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type())
    {
    case QEvent::TouchBegin:
    case QEvent::TouchCancel:
    case QEvent::TouchEnd:
    case QEvent::TouchUpdate:
    case QEvent::ActivationChange:
    {
        if (this->isVisible())
        {
            this->setLockTimer();
        }

        // FIXME: Crashes on rpi
//        QTouchEvent * mouseEvent = static_cast<QTouchEvent *>(event);
//        qDebug() << "touchPoints()" << mouseEvent->touchPoints().count();
//        if (mouseEvent->touchPoints().count() > 1)
//        {
//            return true;
//        }

    }
        break;

    case QEvent::MouseButtonPress:
    {
        if (!obj->objectName().compare("SCenter") || !obj->objectName().compare("STouchFlickableList") || !obj->objectName().compare("Generic"))
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            this->m_delta = new QPoint(mouseEvent->pos());
        }
    }
        break;

    case QEvent::MouseButtonRelease:
    {
        if (this->m_delta != nullptr)
        {
            delete this->m_delta;
            this->m_delta = nullptr;
        }
    }
        break;

    case QEvent::MouseMove: /// Gesture Event
    {
        if (!obj->objectName().compare("SCenter") || !obj->objectName().compare("STouchFlickableList") || !obj->objectName().compare("Generic"))
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

            if (this->m_delta != nullptr)
            {
                this->showGesture(mouseEvent);
            }
        }
    }
        break;

    default:
        break;
    }

    return false;
}

void SCentral::showGesture(QMouseEvent *event)
{
    // Work around QGestureEvent
    //
    // Horisontal Swipe
    if (abs(this->m_delta->y() - event->pos().y()) < 30)
    {
        // Emit show gesture from left to right
        if (event->pos().x() > 0 && event->pos().x() < this->width()/8)
        {
            if (this->m_delta->x() - event->pos().x() < -30)
            {
                // Show process
            }
        }
        // Emit show gesture from right to left
        else if (event->pos().x() < this->width() && event->pos().x() > this->width() - this->width()/8)
        {
            if (this->m_delta->x() - event->pos().x() > 30)
            {
                // Show process
            }
        }
    }
    // Vertival Swipe
    if (event->pos().y() > this->height() - this->height()/6 && event->pos().y() < this->height())
    {
        // Emit show gesture from bottom to top
        if (abs(this->m_delta->x() - event->pos().x()) < 20)
        {
            if (this->m_delta->y() - event->pos().y() > 20)
            {
//                if (!this->touchBar->isVisible())
//                {
//                    this->touchBar->show();
//                }
            }
        }
    }
}

void SCentral::setLockTimer()
{
    /// Screen Lock
    if (this->m_screenLockTime > 0 && !this->touchScreenlock->isVisible() && this->m_screenLockEnabled)
    {
        this->basicTimerLock.start(this->m_screenLockTime*60*1000, this);
    }
    else
    {
        this->basicTimerLock.stop();
    }

    /// Screen Saver
    if (this->m_screenSaverTime > 0 && !this->basicTimerLock.isActive())
    {
        this->basicTimerScreensaver.start(this->m_screenSaverTime*60*1000, this);
    }
    else
    {
        this->basicTimerScreensaver.stop();
    }
}

void SCentral::timerEvent(QTimerEvent *event)
{
    /// Lock Timer
    if (event->timerId() == this->basicTimerLock.timerId())
    {
        this->basicTimerLock.stop();

        if (!this->m_appActive)
        {
            this->setLock();
        }
    }

    /// Screensaver Timer
    if (event->timerId() == this->basicTimerScreensaver.timerId())
    {
        this->basicTimerScreensaver.stop();

        if (!this->m_appActive)
        {
            this->setScreensaver();
        }
    }
}

void SCentral::setLock()
{
    if (!this->touchScreenlock->isVisible() && this->m_screenLockEnabled)
    {
        /* Window size for developing and emulating */
        this->touchScreenlock->show();
    }
    else if (!this->m_screenLockEnabled)
    {
        this->m_snackbar->addMessage(tr("Screen lock disabled!"));
    }

    // Show the main UI for a smooth transition from splashscreen to screenlock on the very first boot
    // hide() is in contructor
    // show() is in setLock()
    if (!this->m_init)
    {
        this->show();
        this->m_init = true;
    }
}

void SCentral::setScreensaver()
{
    if (!this->m_appActive)
    {
        this->m_appActive = true;
        STouchDialogScreensaver touchDialogScreensaver(this);
        touchDialogScreensaver.exec();
    }
    this->m_appActive = false;
}

void SCentral::slotWriteSettings()
{
    // Language
    {
        QSettings settings(::GlobalConfigFileLanguage, QSettings::IniFormat);

        // Default

        // Region
        settings.beginGroup("default/region");
        settings.setValue("language", "en_EN");
        settings.sync();
        settings.endGroup();
    }

    // General
    {
        QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);

        // Default

        // System - Encoder
        settings.beginGroup("default/system/encoder");
        settings.setValue("clockwise", 0);
        settings.setValue("diameter", 0.10);
        settings.setValue("precision", 3);
        settings.sync();
        settings.endGroup();
        // System - NFC
        settings.beginGroup("default/system/nfc");
        settings.setValue("minValue", 0);
        settings.setValue("maxValue", 255);
        settings.setValue("direction", 0);
        settings.sync();
        settings.endGroup();
        // Passcode
        settings.beginGroup("default/code");
        settings.setValue("usercode", "");
        settings.setValue("operatorcode", "");
        settings.setValue("screenlock", 5);
        settings.setValue("screensaver", 5);
        settings.sync();
        settings.endGroup();
        // Register
        settings.beginGroup("default/register");
        settings.setValue("sn", 0);
        settings.sync();
        settings.endGroup();
        // Design
        settings.beginGroup("default/design");
        settings.setValue("color_mode", 0);
        settings.setValue("color_base", ::GlobalColorBase.name());
        settings.setValue("color_contrast",  ::GlobalColorContrast.name());
        settings.setValue("color_highlight",  ::GlobalColorHighlight.name());
        settings.setValue("color_text",  ::GlobalColorText.name());
        settings.setValue("color_bar",  ::GlobalColorBase.name());
        settings.setValue("item_shape", 0);
        settings.sync();
        settings.endGroup();

        // Admin

        // Passcode
        settings.beginGroup("admin/code");
        settings.setValue("admincode", 11235813);
        settings.sync();
        settings.endGroup();
    }
}

void SCentral::slotReadSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);

    // Group Code

    if (!QStringList(settings.allKeys().filter("custom/code", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/code");
    }
    else if (!QStringList(settings.allKeys().filter("default/code", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/code");
    }

    // Setting members
    this->m_screenLockEnabled = settings.value("usercode").toString().isEmpty() ? false : true;
    this->m_screenLockTime = settings.value("screenlock", 0).toInt();
    this->m_screenSaverTime = settings.value("screensaver", 0).toInt();

    settings.sync();
    settings.endGroup();

    // Group Design

    if (!QStringList(settings.allKeys().filter("custom/design", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/design");
    }
    else if (!QStringList(settings.allKeys().filter("default/design", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/design");
    }

    // Set mode
    this->m_colorMode = settings.value("color_mode", 0).toInt();

    settings.sync();
    settings.endGroup();

    this->updateWidget();
}

void SCentral::updateWidget()
{
    QEvent event(QEvent::StyleChange);
    QApplication::sendEvent(this, &event);
    //QApplication::postEvent(this, &event);
    //QApplication::notify(this, &event);
    //QWidget::changeEvent(&event);
}

void SCentral::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    this->setLock();
}

void
SCentral::retranslateUI()
{
}

void
SCentral::restyleUI()
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
SCentral::changeEvent(QEvent* event)
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
