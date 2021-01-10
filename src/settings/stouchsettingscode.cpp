#include "stouchsettingscode.h"
#include "../keyboard/STouchKeyboard.h"
#include "../keyboard/STouchScreenlock.h"
#include "../widget/list/SList.h"
#include "../util/dialog/STouchDialogTumbler.h"
#include "../util/dialog/STextDialog.h"
#include "../util/dialog/SAppBar.h"

#include <QApplication>
#include <QFileSystemWatcher>
#include <QSettings>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


STouchSettingsCode::STouchSettingsCode(QWidget *parent)
    : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchSettingsCode::~STouchSettingsCode()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void STouchSettingsCode::setupWidget()
{
    // File watcher
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalConfigPathSettings);
    this->fileSystemWatcher->addPath(::GlobalConfigFileSettings);

    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);

    /* Swipe list */
    this->list = new SList;
    this->list->addTitle(tr("User"));
    this->list->addSlot(QIcon(),
                     tr("Code"),
                     tr("Four digit user code."),
                     tr("Enable"),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Change code"),
                     tr(""),
                     tr(""),
                     tr(""));
    this->list->divider();
    this->list->addTitle(tr("Operator"));
    this->list->addSlot(QIcon(),
                     tr("Code"),
                     tr("Six digit user code."),
                     tr("Enable"),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Change code"),
                     tr(""),
                     tr(""),
                     tr(""));
    this->list->divider();
    this->list->addTitle(tr("Timers"));
    this->list->addSlot(QIcon(),
                     tr("Screen lock"),
                     tr("Timer until the screen lock becomes active."),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Screen saver"),
                     tr("Timer until the screen saver becomes active."),
                     tr(""),
                     QChar(0x276F));

    this->m_snackbar.setParent(this);

    this->slotReadSettings();
}

void STouchSettingsCode::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->appBar, 1);
    mainLayout->addWidget(this->list->list(), 9);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchSettingsCode::setConnect()
{
    /* App bar */
    connect(this->appBar, &SAppBar::signalClicked, [this](int n) {
        switch (n) {
        case 0:
            emit this->signalReturn();
            break;

        default:
            break;
        }
    });

    /* Swipe list */
    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));

    /* File watcher */
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchSettingsCode::slotReadSettings);
}

void STouchSettingsCode::slotList(const int index)
{
    bool t_write = false;
    this->hide();

    int t_iter = 0;
    if (index == t_iter++) // User on/off
    {
        t_write = this->setActivation(index);
    }
    else if (index == t_iter++) // User chnage code
    {
        if (!this->m_userCode.isEmpty())
        {
            t_write = this->setCode(index);
        }
        else
        {
            this->m_snackbar.addMessage(tr("User disabled!"));
        }

    }
    else if (index == t_iter++) // Operator on/off
    {
        t_write = this->setActivation(index);
    }
    else if (index == t_iter++) // Operator chnage code
    {
        if (!this->m_operatorCode.isEmpty())
        {
            t_write = this->setCode(index);
        }
        else
        {
            this->m_snackbar.addMessage(tr("Operator disabled!"));
        }
    }
    this->show();

    if (index == t_iter++ && !this->m_userCode.isEmpty()) // Screen Lock
    {
        t_write = this->setScreenlockTime();
    }
    else if (index == t_iter++) // screen saver time
    {
        t_write = this->setScreensaverTime();
    }

    if (t_write)
    {
        this->slotWriteSettings();
    }
}

bool
STouchSettingsCode::setActivation(const int index)
{
    bool t_write = false;

    if ((!this->m_userCode.isEmpty() && (index == 0)) || (!this->m_operatorCode.isEmpty() && (index == 2)))
    {
        // Disable Code
        STouchScreenlock touchScreenlock(this);
        if (index == 2) // Operator
        {
            touchScreenlock.setRole(STouchScreenlock::Role::Operator);
        }
        touchScreenlock.enableSymbols(true);
        touchScreenlock.exec();
        if (touchScreenlock.isAccepted())
        {
            this->show();
            STextDialog dialog(this);
            dialog.setTitle(tr("Passcode"));
            if (index == 0) // User
            {
                dialog.setDescription(tr("Disable user code."));
            }
            else if (index == 2) // Operator
            {
                dialog.setDescription(tr("Disable operator code."));
            }
            dialog.setAcceptButton(tr("Accept"));
            dialog.setRejectButton(tr("Close"));
            dialog.exec();
            if (dialog.isAccepted())
            {
                t_write = true;

                if (index == 0) // User
                {
                    this->m_userCode = "";
                    this->m_screenLock = 5;
                }
                else if (index == 2) // Operator
                {
                    this->m_operatorCode = "";
                }
            }
        }
    }
    else // Change Change
    {

        QString firstNumbers;
        QString secondNumbers;

        tryAgain:
        STouchKeyboard touchKeyboard1(this);
        if (index == 0) /// User
        {
            touchKeyboard1.setTitle(tr("Enter your new User Code"));
            touchKeyboard1.setSecurityMode(true);
        }
        else if (index == 2) /// Operator
        {
            touchKeyboard1.setTitle(tr("Enter your new Operator Code"));
            touchKeyboard1.setSecurityMode(true, 6);
        }
        touchKeyboard1.exec();
        if (touchKeyboard1.isAccepted())
        {
            firstNumbers = touchKeyboard1.getNumber();
        }
        else
        {
            return false;
        }

        STouchKeyboard touchKeyboard2(this);
        if (index == 0) /// User
        {
            touchKeyboard2.setTitle(tr("Verify your new User Code"));
            touchKeyboard2.setSecurityMode(true);
        }
        else if (index == 2) /// Operator
        {
            touchKeyboard2.setTitle(tr("Verify your new Operator Code"));
            touchKeyboard2.setSecurityMode(true, 6);
        }
        touchKeyboard2.exec();
        if (touchKeyboard2.isAccepted())
        {
            secondNumbers = touchKeyboard2.getNumber();
        }
        else
        {
            return false;
        }

        if (!firstNumbers.compare(secondNumbers))
        {
            t_write = true;

            if (index == 0) /// User
            {
                this->m_snackbar.addMessage(tr("User Code activated!"));
            }
            else if (index == 2) /// Operator
            {
                this->m_snackbar.addMessage(tr("Operator Code activated!"));
            }

            if (index == 0) /// User
            {
                this->m_userCode = firstNumbers;
                this->m_screenLock = 5;
            }
            else if (index == 2) /// Operator
            {
                this->m_operatorCode = firstNumbers;
            }
        }
        else
        {
            STextDialog dialog(this);
            dialog.setTitle(tr("Passcode"));
            if (index == 0) /// User
            {
                dialog.setDescription(tr("User code no match."));
            }
            else if (index == 2) /// Operator
            {
                dialog.setDescription(tr("Operator code no match."));
            }
            dialog.setAcceptButton(tr("Retry"));
            dialog.setRejectButton(tr("Close"));
            dialog.exec();
            if (dialog.isAccepted())
            {
                firstNumbers.clear();
                secondNumbers.clear();

                goto tryAgain;
            }
        }
    }

    return t_write;
}

bool
STouchSettingsCode::setCode(const int index)
{
    bool t_write = false;

    STouchScreenlock touchScreenlock(this);
    if (index == 3) /// Operator
    {
        touchScreenlock.setRole(STouchScreenlock::Role::Operator);
    }
    touchScreenlock.enableSymbols(true);
    touchScreenlock.exec();

    if (touchScreenlock.isAccepted())
    {
        QString firstNumbers;
        QString secondNumbers;

        tryAgain:
        STouchKeyboard touchKeyboard1(this);
        if (index == 1) /// User
        {
            touchKeyboard1.setTitle(tr("Enter your new User Code"));
            touchKeyboard1.setSecurityMode(true);
        }
        else if (index == 3) /// Operator
        {
            touchKeyboard1.setTitle(tr("Enter your new Operator Code"));
            touchKeyboard1.setSecurityMode(true, 6);
        }
        touchKeyboard1.exec();
        if (touchKeyboard1.isAccepted())
        {
            firstNumbers = touchKeyboard1.getNumber();
        }
        else
        {
            return false;
        }

        STouchKeyboard touchKeyboard2(this);
        if (index == 1) /// User
        {
            touchKeyboard2.setTitle(tr("Verify your new User Code"));
            touchKeyboard2.setSecurityMode(true);
        }
        else if (index == 3) // Operator
        {
            touchKeyboard2.setTitle(tr("Verify your new Operator Code"));
            touchKeyboard2.setSecurityMode(true, 6);
        }
        touchKeyboard2.exec();
        if (touchKeyboard2.isAccepted())
        {
            secondNumbers = touchKeyboard2.getNumber();
        }
        else
        {
            return false;
        }

        if (!firstNumbers.compare(secondNumbers))
        {
            t_write = true;

            if (index == 1) // User
            {
                this->m_snackbar.addMessage(tr("Operator Code changed!"));
            }
            else if (index == 3) // Operator
            {
                this->m_snackbar.addMessage(tr("Operator Code changed!"));
            }

            if (index == 1) // User
            {
                this->m_userCode = firstNumbers;
            }
            else if (index == 3) // Operator
            {
                this->m_operatorCode = firstNumbers;
            }
        }
        else
        {
            STextDialog dialog(this);
            dialog.setTitle(tr("Passcode"));
            if (index == 1) /// User
            {
                dialog.setDescription(tr("User code no match."));
            }
            else if (index == 3) /// Operator
            {
                dialog.setDescription(tr("Operator code no match."));
            }
            dialog.setAcceptButton(tr("Retry"));
            dialog.setRejectButton(tr("Close"));
            dialog.exec();

            if (dialog.isAccepted())
            {
                firstNumbers.clear();
                secondNumbers.clear();

                goto tryAgain;
            }
        }
    }

    return t_write;
}

bool
STouchSettingsCode::setScreenlockTime()
{
    bool t_write = false;

    STouchDialogTumbler touchTumbler(this);
    touchTumbler.setTitleText(tr("Screen lock"));
    touchTumbler.setDescription(tr("min"));
    QStringList items;
    for (int i = 0; i <= 60; ++i)
    {
        items << QString::number(i);
    }
    touchTumbler.setItems(items);
    touchTumbler.setCurrentIndex(this->m_screenLock);
    touchTumbler.exec();

    if (touchTumbler.isAccepted())
    {
        t_write = true;

        this->m_screenLock = touchTumbler.currentIndex();

        if (this->m_screenLock == 0)
        {
            this->m_snackbar.addMessage(tr("Screen lock disabled!"));
        }
    }

    return t_write;
}

bool STouchSettingsCode::setScreensaverTime()
{
    bool t_write = false;

    STouchDialogTumbler touchTumbler(this);
    touchTumbler.setTitleText(tr("Screen saver"));
    touchTumbler.setDescription(tr("min"));
    QStringList items;
    for (int i = 0; i <= 60; ++i)
    {
        items << QString::number(i);
    }
    touchTumbler.setItems(items);
    touchTumbler.setCurrentIndex(this->m_screenSaver);
    touchTumbler.exec();

    if (touchTumbler.isAccepted())
    {
        t_write = true;

        this->m_screenSaver = touchTumbler.currentIndex();

        if (this->m_screenSaver == 0)
        {
            this->m_snackbar.addMessage(tr("Screen saver disabled!"));
        }
    }

    return t_write;
}

void STouchSettingsCode::slotWriteSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
    settings.beginGroup("custom/code");
    settings.setValue("usercode", this->m_userCode);
    settings.setValue("operatorcode", this->m_operatorCode);
    settings.setValue("screenlock", this->m_screenLock);
    settings.setValue("screensaver", this->m_screenSaver);
    settings.sync();
    settings.endGroup();
}

void STouchSettingsCode::slotReadSettings()
{
    // Settings
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
    if (!QStringList(settings.allKeys().filter("custom/code", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/code");
    }
    else if (!QStringList(settings.allKeys().filter("default/code", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/code");
    }

    this->m_userCode = settings.value("usercode").toString();
    this->m_operatorCode = settings.value("operatorcode").toString();
    this->m_screenLock = settings.value("screenlock").toInt();
    this->m_screenSaver = settings.value("screensaver").toInt();

    settings.sync();
    settings.endGroup();

    // Update widgets
    this->updateWidget();
}

void
STouchSettingsCode::updateWidget()
{
    // User code
    if (!this->m_userCode.isEmpty())
    {
        this->list->setItem(0, tr("Disable"), SList::Item::Info);
        this->list->setItem(1, QChar(0x276F), SList::Item::Symbol);
    }
    else
    {
        this->list->setItem(0, tr("Enable"), SList::Item::Info);
        this->list->setItem(1, "", SList::Item::Symbol);
    }

    // Operator code
    if (!this->m_operatorCode.isEmpty())
    {
        this->list->setItem(2, tr("Disable"), SList::Item::Info);
        this->list->setItem(3, QChar(0x276F), SList::Item::Symbol);
    }
    else
    {
        this->list->setItem(2, tr("Enable"), SList::Item::Info);
        this->list->setItem(3, "", SList::Item::Symbol);
    }

    // Sreen lock
    if (!this->m_screenLock || this->m_userCode.isEmpty())
    {
        this->list->setItem(4, tr("Off"), SList::Item::Info);
    }
    else
    {
        this->list->setItem(4, tr("%n Minute(s)", "", this->m_screenLock), SList::Item::Info);
    }

    // Sreen saver
    if (!this->m_screenSaver)
    {
        this->list->setItem(5, tr("Off"), SList::Item::Info);
    }
    else
    {
        this->list->setItem(5, tr("%n Minute(s)", "", this->m_screenSaver), SList::Item::Info);
    }
}

void STouchSettingsCode::retranslateUI()
{
    /* App bar */
    this->appBar->setText(this->m_title);

    /* Swipe list */
    this->list->setTitle(0, tr("User"));
    this->list->setTitle(1, tr("Operator"));
    this->list->setTitle(2, tr("Timers"));

    if (!this->m_userCode.isEmpty())
    {
        this->list->setSlot(0,
                         QIcon(),
                         tr("Code"),
                         tr("Four digit user code."),
                         tr("Disable"),
                         QChar(0x276F));
        this->list->setSlot(1,
                            QIcon(),
                         tr("Change code"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));

        if (!this->m_screenLock)
        {
            this->list->setItem(4, tr("Off"), SList::Item::Info);
        }
        else
        {
            this->list->setItem(4, tr("%n Minutes(s)", "", this->m_screenLock), SList::Item::Info);
        }
    }
    else
    {
        this->list->setSlot(0,
                            QIcon(),
                         tr("Code"),
                         tr("Four digit user code."),
                         tr("Enable"),
                         QChar(0x276F));
        this->list->setSlot(1,
                            QIcon(),
                         tr("Change code"),
                         tr(""),
                         tr(""),
                         tr(""));
        this->list->setSlot(4,
                            QIcon(),
                         tr("Screen lock"),
                         tr("Timer until the screen lock becomes active."),
                         tr("Off"),
                         QChar(0x276F));
    }

    if (!this->m_operatorCode.isEmpty())
    {
        this->list->setSlot(2,
                            QIcon(),
                         tr("Code"),
                         tr("Six digit user code."),
                         tr("Disable"),
                         QChar(0x276F));
        this->list->setSlot(3,
                            QIcon(),
                         tr("Change code"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
    else
    {
        this->list->setSlot(2,
                            QIcon(),
                         tr("Code"),
                         tr("Six digit user code."),
                         tr("Enable"),
                         QChar(0x276F));
        this->list->setSlot(3,
                            QIcon(),
                         tr("Change code"),
                         tr(""),
                         tr(""),
                         tr(""));
    }

    if (!this->m_screenSaver)
    {
        this->list->setSlot(5,
                            QIcon(),
                         tr("Screen saver"),
                         tr("Timer until the screen saver becomes active."),
                         tr("Off"),
                         QChar(0x276F));
    }
    else
    {
        this->list->setSlot(5,
                            QIcon(),
                         tr("Screen saver"),
                         tr("Timer until the screen saver becomes active."),
                         tr("%n Minutes(s)", "", this->m_screenSaver),
                         QChar(0x276F));
    }
}

void
STouchSettingsCode::restyleUI()
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
STouchSettingsCode::changeEvent(QEvent * event)
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
