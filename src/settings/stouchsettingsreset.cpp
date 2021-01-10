#include "stouchsettingsreset.h"
#include "../util/dialog/STextDialog.h"
#include "../keyboard/STouchScreenlock.h"
#include "../widget/list/SList.h"
#include "../util/dialog/SAppBar.h"

#include <QApplication>
#include <QFile>
#include <QSettings>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


STouchSettingsReset::STouchSettingsReset(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchSettingsReset::~STouchSettingsReset()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void STouchSettingsReset::setupWidget()
{
    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);

    /* Swipe list */
    this->list = new SList;
    this->list->addSlot(QIcon(),
                     tr("System settings"),
                     tr("Resets individually set system parameters to the default setting."),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Passcode settings"),
                     tr("Resets individually set system parameters to the default setting."),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Design settings"),
                     tr("Resets individually set design changes to the default setting."),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Factory settings"),
                     tr("Resets all individually set parameters to the default setting."),
                     tr(""),
                     QChar(0x276F));
}

void STouchSettingsReset::setupLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->appBar, 1);
    mainLayout->addWidget(this->list->list(), 9);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchSettingsReset::setConnect()
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
}

void STouchSettingsReset::slotList(const int index)
{
    switch (index)
    {
    case 0:
        this->removeSettings(::GlobalConfigFileSettings, "custom/system");
        break;

    case 1:
        this->removeSettings(::GlobalConfigFileSettings, "custom/code");
        break;

    case 2:
        this->removeSettings(::GlobalConfigFileSettings, "custom/design");
        break;

    case 3:
        this->removeSettings(::GlobalConfigFileSettings, "custom");
        break;

    default:
        break;
    }
}

void STouchSettingsReset::removeFile(const QString &path, const QString &name)
{
    this->hide();

    STouchScreenlock touchScreenlock(this);
    touchScreenlock.setRole(STouchScreenlock::Role::Appropriate);
    touchScreenlock.enableSymbols(true);
    touchScreenlock.exec();

    if (touchScreenlock.isAccepted())
    {
        STextDialog dialog(this);
        dialog.setTitle(tr("Reset"));
        dialog.setAcceptButton(tr("Delete"));
        dialog.setDescription(tr("Remove the initialization."));
        dialog.exec();

        if (dialog.isAccepted())
        {
            QFile file(path + name);

            if (!file.open(QIODevice::ReadWrite))
            {
                return;
            }

            file.flush();
            file.close();
            file.remove();
        }
    }

    this->show();
}

void STouchSettingsReset::removeSettings(const QString &file, const QString &group)
{
    QSettings settings(file, QSettings::IniFormat);
    if (settings.childGroups().contains(group.split("/").front()))
    {
        STouchScreenlock touchScreenlock(this);
        touchScreenlock.setRole(STouchScreenlock::Role::Appropriate);
        touchScreenlock.enableSymbols(true);
        touchScreenlock.exec();

        if (touchScreenlock.isAccepted())
        {
            STextDialog dialog(this);
            dialog.setTitle(tr("Reset"));
            dialog.setAcceptButton(tr("Reset"));

            if (group.split("/").size() != 1)
            {
                QString string;
                if (!QString::compare(group.split("/").back(), "code"))
                {
                    string = tr("code");
                }
                else if (!QString::compare(group.split("/").back(), "system"))
                {
                    string = tr("system");
                }

                dialog.setDescription(tr("Delete all %1 settings.\nReturn to factory defaults.").arg(string));
            }
            else
            {
                dialog.setDescription(tr("Delete all custom settings.\nReturn to factory defaults."));
            }
            dialog.exec();

            if (dialog.isAccepted())
            {
                settings.remove(group);
                settings.sync();
            }
        }
    }
}

void STouchSettingsReset::retranslateUI()
{
    /* App bar */
    this->appBar->setText(this->m_title);

    /* Swipe list */
    int t_iter = 0;
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("System settings"),
                     tr("Resets individually set system parameters to the default setting."),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Passcode settings"),
                     tr("Resets individually set system parameters to the default setting."),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Design settings"),
                     tr("Resets individually set design changes to the default setting."),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Factory settings"),
                     tr("Resets all individually set parameters to the default setting."),
                     tr(""),
                     QChar(0x276F));
}

void
STouchSettingsReset::restyleUI()
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
STouchSettingsReset::changeEvent(QEvent * event)
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
