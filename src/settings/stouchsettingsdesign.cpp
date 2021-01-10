#include "stouchsettingsdesign.h"
#include "../keyboard/STouchColorKeyboard.h"
#include "../widget/list/SList.h"
#include "../util/dialog/SRadioDialog.h"
#include "../util/dialog/SAppBar.h"

#include <QApplication>
#include <QFileSystemWatcher>
#include <QSettings>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>


STouchSettingsDesign::STouchSettingsDesign(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->slotReadSettings();
}

STouchSettingsDesign::~STouchSettingsDesign()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void STouchSettingsDesign::setupWidget()
{
    // File watcher
    fileSystemWatcher = new QFileSystemWatcher(this);
    fileSystemWatcher->addPath(::GlobalConfigPathSettings);
    fileSystemWatcher->addPath(::GlobalConfigFileSettings);

    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);

    /* Swipe list */
    this->list = new SList;
    this->list->addTitle(tr("Touch UI"));
    this->list->addSlot(QIcon(),
                     tr("Color Mode"),
                     tr("Change color mode."),
                     tr("Dark"),
                     QChar(0x276F));
    this->list->divider();
    this->list->addSlot(QIcon(),
                     tr("Base Color"),
                     tr("Change base color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorBase.red()).arg(this->m_colorBase.green()).arg(this->m_colorBase.blue()),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Contrast Color"),
                     tr("Change contrast color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorContrast.red()).arg(this->m_colorContrast.green()).arg(this->m_colorContrast.blue()),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Highlight Color"),
                     tr("Change highlight color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorHighlight.red()).arg(this->m_colorHighlight.green()).arg(this->m_colorHighlight.blue()),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Text Color"),
                     tr("Change text color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorText.red()).arg(this->m_colorText.green()).arg(this->m_colorText.blue()),
                     QChar(0x276F));
    this->list->divider();
    this->list->addSlot(QIcon(),
                     tr("Item Shape"),
                     tr("Change items shape."),
                     "",
                     QChar(0x276F));
    this->list->divider();
    this->list->addTitle(tr("Navigation Bar UI"));
    this->list->addSlot(QIcon(),
                     tr("Base Color"),
                     tr("Change base color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorBase.red()).arg(this->m_colorBase.green()).arg(this->m_colorBase.blue()),
                     QChar(0x276F));

    switch (this->m_colorMode)
    {
    case 0:
        this->list->setItem(0, tr("Dark"), SList::Item::Info);
        break;

    case 1:
        this->list->setItem(0, tr("Light"), SList::Item::Info);
        break;

    default:
        break;
    }

    // Set item shape
    switch (this->m_itemShape)
    {
    case 0:
        this->list->setItem(5, tr("Default"), SList::Item::Info);
        break;

    case 1:
        this->list->setItem(5, tr("Base"), SList::Item::Info);
        break;

    case 2:
        this->list->setItem(5, tr("Contrast"), SList::Item::Info);
        break;

    case 3:
        this->list->setItem(5, tr("Round"), SList::Item::Info);
        break;

    case 4:
        this->list->setItem(5, tr("Rounded"), SList::Item::Info);
        break;

    case 5:
        this->list->setItem(5, tr("Rect"), SList::Item::Info);
        break;

    default:
        break;
    }

    this->slotReadSettings();
}

void STouchSettingsDesign::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->appBar, 1);
    mainLayout->addWidget(this->list->list(), 9);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchSettingsDesign::setConnect()
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
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchSettingsDesign::slotReadSettings);
}

void STouchSettingsDesign::slotList(const int index)
{
    bool t_write = false;

    switch (index)
    {
    case 0: // Color mode
    {
        SRadioDialog radioDialog(this);
        radioDialog.setTitle(tr("Color Mode"));
        radioDialog.setAcceptButton(tr("Accept"));
        radioDialog.setRejectButton(tr("Close"));
        radioDialog.addText(tr("Dark"));
        radioDialog.addText(tr("Light"));
        radioDialog.setIndex(this->m_colorMode);
        radioDialog.exec();
        if (radioDialog.isAccepted())
        {
            this->m_colorMode = radioDialog.index();
            switch (this->m_colorMode)
            {
            case 0:
                this->m_colorBase = ::GlobalColorBase;
                this->m_colorContrast = ::GlobalColorContrast;
                this->m_colorHighlight = ::GlobalColorHighlight;
                this->m_colorText = ::GlobalColorText;
                this->m_colorBar = ::GlobalColorBase;
                break;

            case 1:
                this->m_colorBase = QColor("#ffffff");
                this->m_colorContrast = QColor("#d9d9d9");
                this->m_colorHighlight = QColor("#5a57fe");
                this->m_colorText = ::GlobalColorBase;
                this->m_colorBar = QColor("#ffffff");
                break;

            default:
                break;
            }

            t_write = true;
        }
    }
        break;

    case 1: // Base color
    {
        STouchColorKeyboard touchColorKeyboard(this);
        touchColorKeyboard.setTitle(tr("Base Color"));
        touchColorKeyboard.setBaseColor(this->m_colorBase);
        touchColorKeyboard.setContrastColor(this->m_colorContrast);
        touchColorKeyboard.setHighlightColor(this->m_colorHighlight);
        touchColorKeyboard.setTextColor(this->m_colorText);
        touchColorKeyboard.setColor(this->m_colorBase);
        touchColorKeyboard.exec();
        if (touchColorKeyboard.isAccepted())
        {
            this->m_colorBase = touchColorKeyboard.getColor().name();
            t_write = true;
        }
    }
        break;

    case 2: // Contrast color
    {
        STouchColorKeyboard touchColorKeyboard(this);
        touchColorKeyboard.setTitle(tr("Contrast Color"));
        touchColorKeyboard.setBaseColor(this->m_colorBase);
        touchColorKeyboard.setContrastColor(this->m_colorContrast);
        touchColorKeyboard.setHighlightColor(this->m_colorHighlight);
        touchColorKeyboard.setTextColor(this->m_colorText);
        touchColorKeyboard.setColor(this->m_colorContrast);
        touchColorKeyboard.exec();
        if (touchColorKeyboard.isAccepted())
        {
            this->m_colorContrast = touchColorKeyboard.getColor().name();
            t_write = true;
        }
    }
        break;

    case 3: // Highlight color
    {
        STouchColorKeyboard touchColorKeyboard(this);
        touchColorKeyboard.setTitle(tr("Highlight Color"));
        touchColorKeyboard.setBaseColor(this->m_colorBase);
        touchColorKeyboard.setContrastColor(this->m_colorContrast);
        touchColorKeyboard.setHighlightColor(this->m_colorHighlight);
        touchColorKeyboard.setTextColor(this->m_colorText);
        touchColorKeyboard.setColor(this->m_colorHighlight);
        touchColorKeyboard.exec();
        if (touchColorKeyboard.isAccepted())
        {
            this->m_colorHighlight = touchColorKeyboard.getColor().name();
            t_write = true;
        }
    }
        break;

    case 4: // Text color
    {
        STouchColorKeyboard touchColorKeyboard(this);
        touchColorKeyboard.setTitle(tr("Text Color"));
        touchColorKeyboard.setBaseColor(this->m_colorBase);
        touchColorKeyboard.setContrastColor(this->m_colorContrast);
        touchColorKeyboard.setHighlightColor(this->m_colorHighlight);
        touchColorKeyboard.setTextColor(this->m_colorText);
        touchColorKeyboard.setColor(this->m_colorText);
        touchColorKeyboard.exec();
        if (touchColorKeyboard.isAccepted())
        {
            this->m_colorText = touchColorKeyboard.getColor().name();
            t_write = true;
        }
    }
        break;

    case 5: // Item shape
    {
        SRadioDialog radioDialog(this);
        radioDialog.setTitle(tr("Color Mode"));
        radioDialog.setAcceptButton(tr("Accept"));
        radioDialog.setRejectButton(tr("Close"));
        radioDialog.addText(tr("Default"));
        radioDialog.addText(tr("Base"));
        radioDialog.addText(tr("Contrast"));
        radioDialog.addText(tr("Round"));
        radioDialog.addText(tr("Rect"));
        radioDialog.addText(tr("Rect"));
        radioDialog.addText(tr("Rect"));
        radioDialog.addText(tr("Rect"));
        radioDialog.addText(tr("Rect"));
        radioDialog.addText(tr("Rect"));
        radioDialog.addText(tr("Rect"));
        radioDialog.addText(tr("Rect"));
        radioDialog.addText(tr("Default"));
        radioDialog.addText(tr("Default"));
        radioDialog.setIndex(this->m_colorMode);
        radioDialog.exec();
        if (radioDialog.isAccepted())
        {
            this->m_itemShape = radioDialog.index();
            t_write = true;
        }
    }
        break;

    case 6: // Bar color
    {
        STouchColorKeyboard touchColorKeyboard(this);
        touchColorKeyboard.setTitle(tr("Bar Color"));
        touchColorKeyboard.setBaseColor(this->m_colorBase);
        touchColorKeyboard.setContrastColor(this->m_colorContrast);
        touchColorKeyboard.setHighlightColor(this->m_colorHighlight);
        touchColorKeyboard.setTextColor(this->m_colorText);
        touchColorKeyboard.setColor(this->m_colorBar);
        touchColorKeyboard.exec();
        if (touchColorKeyboard.isAccepted())
        {
            this->m_colorBar = touchColorKeyboard.getColor().name();
            t_write = true;
        }
    }
        break;

    default:
        break;
    }

    if (t_write)
    {
        this->slotWriteSettings();
    }
}

void STouchSettingsDesign::slotWriteSettings()
{
    // Write custom colors only from this place!
    // The colors need a amount of time till the new values are written.
    // Therefore take care to change the colors in a function befor
    // the StyleChange event is gonna emited.
    ::GlobalColorCustomText = this->m_colorText;
    ::GlobalColorCustomContrast = this->m_colorContrast;
    ::GlobalColorCustomHighlight = this->m_colorHighlight;
    ::GlobalColorCustomBase = this->m_colorBase;

    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
    settings.beginGroup("custom/design");
    settings.setValue("color_mode", this->m_colorMode);
    settings.setValue("color_base", this->m_colorBase.name());
    settings.setValue("color_contrast", this->m_colorContrast.name());
    settings.setValue("color_highlight", this->m_colorHighlight.name());
    settings.setValue("color_text", this->m_colorText.name());
    settings.setValue("color_bar", this->m_colorBar.name());
    settings.setValue("item_shape", this->m_itemShape);
    settings.sync();
    settings.endGroup();
}

void STouchSettingsDesign::slotReadSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
    if (!QStringList(settings.allKeys().filter("custom/design", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/design");
    }
    else if (!QStringList(settings.allKeys().filter("default/design", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/design");
    }

    // Set color mode
    this->m_colorMode = settings.value("color_mode", 0).toInt();

    // Set colors
    this->m_colorBase = QColor(settings.value("color_base").toString());
    this->m_colorContrast = QColor(settings.value("color_contrast").toString());
    this->m_colorHighlight = QColor(settings.value("color_highlight").toString());
    this->m_colorText = QColor(settings.value("color_text").toString());

    // Set item shape
    this->m_itemShape = settings.value("item_shape", 0).toInt();

    // Set color bar
    this->m_colorBar = QColor(settings.value("color_bar").toString());

    settings.sync();
    settings.endGroup();

    // Update widgets
    this->updateWidget();
}

void
STouchSettingsDesign::updateWidget()
{
    // Set color mode
    this->list->setItem(0,
                     this->m_colorMode ? tr("Light") : tr("Dark"),
                     SList::Item::Info);

    // Set colors
    this->list->setItem(1,
                     tr("rgb(%1, %2, %3)").arg(this->m_colorBase.red()).arg(this->m_colorBase.green()).arg(this->m_colorBase.blue()),
                     SList::Item::Info);
    ::GlobalColorCustomBase = this->m_colorBase;

    this->list->setItem(2,
                     tr("rgb(%1, %2, %3)").arg(this->m_colorContrast.red()).arg(this->m_colorContrast.green()).arg(this->m_colorContrast.blue()),
                     SList::Item::Info);
    ::GlobalColorCustomContrast = this->m_colorContrast;

    this->list->setItem(3,
                     tr("rgb(%1, %2, %3)").arg(this->m_colorHighlight.red()).arg(this->m_colorHighlight.green()).arg(this->m_colorHighlight.blue()),
                     SList::Item::Info);
    ::GlobalColorCustomHighlight = this->m_colorHighlight;

    this->list->setItem(4,
                     tr("rgb(%1, %2, %3)").arg(this->m_colorText.red()).arg(this->m_colorText.green()).arg(this->m_colorText.blue()),
                     SList::Item::Info);
    ::GlobalColorCustomText = this->m_colorText;

    // Workaround: Emit StyleChange signal event.
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");

    //  Set item shape
    switch (this->m_itemShape)
    {
    case 0:
        this->list->setItem(5, tr("Default"), SList::Item::Info);
        break;

    case 1:
        this->list->setItem(5, tr("Base"), SList::Item::Info);
        break;

    case 2:
        this->list->setItem(5, tr("Contrast"), SList::Item::Info);
        break;

    case 3:
        this->list->setItem(5, tr("Round"), SList::Item::Info);
        break;

    case 4:
        this->list->setItem(5, tr("Rounded"), SList::Item::Info);
        break;

    case 5:
        this->list->setItem(5, tr("Rect"), SList::Item::Info);
        break;

    default:
        break;
    }

    // TODO: Set color bar.
    // Try to use restyleUI() function in STouchBar.cpp to catch the
    // color change.
    this->list->setItem(6,
                     tr("rgb(%1, %2, %3)").arg(this->m_colorBase.red()).arg(this->m_colorBase.green()).arg(this->m_colorBase.blue()),
                     SList::Item::Info);
}

void STouchSettingsDesign::retranslateUI()
{
    /* App bar */
    this->appBar->setText(this->m_title);

    /* Swipe list */
    int t_iter = 0;
    this->list->setTitle(t_iter++, tr("Touch UI"));
    this->list->setTitle(t_iter++, tr("Navigation Bar UI"));

    t_iter = 0;
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Color Mode"),
                     tr("Change color mode."),
                     this->m_colorMode ? tr("Light") : tr("Dark"),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Base Color"),
                     tr("Change base color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorBase.red()).arg(this->m_colorBase.green()).arg(this->m_colorBase.blue()),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Contrast Color"),
                     tr("Change contrast color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorContrast.red()).arg(this->m_colorContrast.green()).arg(this->m_colorContrast.blue()),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Highlight Color"),
                     tr("Change highlight color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorHighlight.red()).arg(this->m_colorHighlight.green()).arg(this->m_colorHighlight.blue()),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Text Color"),
                     tr("Change text color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorText.red()).arg(this->m_colorText.green()).arg(this->m_colorText.blue()),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Item Shape"),
                     tr("Change items shape."),
                     "",
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Base Color"),
                     tr("Change base color."),
                     tr("rgb(%1, %2, %3)").arg(this->m_colorBase.red()).arg(this->m_colorBase.green()).arg(this->m_colorBase.blue()),
                     QChar(0x276F));
}

void
STouchSettingsDesign::restyleUI()
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

void STouchSettingsDesign::changeEvent(QEvent* event)
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
