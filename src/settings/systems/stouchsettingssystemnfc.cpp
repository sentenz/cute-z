#include "stouchsettingssystemnfc.h"
#include "../system/nfc/STouchNFC.h"
#include "../keyboard/STouchScreenlock.h"
#include "../keyboard/STouchKeyboard.h"
#include "../util/dialog/SRadioDialog.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QFileSystemWatcher>
#include <QSettings>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


STouchSettingsSystemNFC::STouchSettingsSystemNFC(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchSettingsSystemNFC::~STouchSettingsSystemNFC()
{
    if (this->header != nullptr)
    {
        delete this->header;
        this->header = nullptr;
    }
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void STouchSettingsSystemNFC::setupWidget()
{
    // File watcher
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalConfigPathSettings);

    // Header
    this->header = new SLabel;
    this->header->header(tr("Paternoster"), 0x0276E);

    // Swipe list
    this->list = new SList;
    this->list->addTitle(tr("NFC Transponder"));
    this->list->addSlot(QIcon(),
                     tr("Write to Transponder"),
                     tr("Write a new value."),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Read from Transponder"),
                     tr("Read value."),
                     tr(""),
                     QChar(0x276F));
    this->list->divider();
    this->list->addTitle(tr("NFC Controller"));
    this->list->addSlot(QIcon(),
                     tr("Minimum Value"),
                     tr("Define the minimum value of your application."),
                     QString::number(this->m_minValue),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Maximum Value"),
                     tr("Define the maximum value of your application."),
                     QString::number(this->m_maxValue),
                     QChar(0x276F));
    this->list->divider();
    this->list->addTitle(tr("Peripheral Units"));
    this->list->addSlot(QIcon(),
                     tr("Electrical Engine Direction"),
                     tr("Drive of the electrical engine."),
                     this->m_direction == 0 ? tr("Unidirectional") : tr("Bidirectional"),
                     QChar(0x276F));

    this->slotReadSettings();
}

void STouchSettingsSystemNFC::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addWidget(this->list->list(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchSettingsSystemNFC::setConnect()
{
    // Lists
    connect(this->header, &SLabel::signalReleased, [this] (int n) {
        switch (n) {
        case 0:
        {
            emit this->signalReturn();

            if (this->m_closeable)
            {
                this->close();
            }
        }
            break;

        case 1:
            break;

        default:
            break;
        }
    });
    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));
    // File watcher
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchSettingsSystemNFC::slotReadSettings);
}

void STouchSettingsSystemNFC::slotList(const int index)
{
    bool t_write = false;

    switch (index)
    {
    case 0: // Write Transponder
    {
        STouchNFC touchNFC;
        touchNFC.setMode(SThreadNFC::NFC::Write);
        touchNFC.setCloseable(true);
        touchNFC.exec();
    }
        break;

    case 1: // Read Transponder
    {
        STouchNFC touchNFC;
        touchNFC.setMode(SThreadNFC::NFC::Read);
        touchNFC.setCloseable(true);
        touchNFC.exec();
    }
        break;

    case 2: // Min. Value
    {
        STouchKeyboard touchKeyboard(this);
        touchKeyboard.setTitle(tr("Min. Value"));
        touchKeyboard.setDescriptionText(tr("Input value must be in the range of %1 to %2.").arg(0).arg(this->m_maxValue), STouchKeyboard::Dialog::Warning);
        touchKeyboard.setRange(0, this->m_maxValue);
        touchKeyboard.exec();
        if (touchKeyboard.isAccepted())
        {
            this->m_minValue = touchKeyboard.getNumber().toInt();

            t_write = true;
        }
    }
        break;

    case 3: // Max. Value
    {
        STouchKeyboard touchKeyboard(this);
        touchKeyboard.setTitle(tr("Max. Value"));
        touchKeyboard.setDescriptionText(tr("Input value must be in the range of %1 to %2.").arg(this->m_minValue).arg(255), STouchKeyboard::Dialog::Warning);
        touchKeyboard.setRange(this->m_minValue, 255);
        touchKeyboard.exec();
        if (touchKeyboard.isAccepted())
        {
            this->m_maxValue = touchKeyboard.getNumber().toInt();

            t_write = true;
        }
    }
        break;

    case 4: // Direction
    {
        SRadioDialog radioDialog(this);
        radioDialog.setTitle(tr("Direction of Rotation"));
        radioDialog.setAcceptButton(tr("Accept"));
        radioDialog.setRejectButton(tr("Close"));
        radioDialog.addText(tr("Unidirectional"));
        radioDialog.addText(tr("Bidirectional"));
        radioDialog.setIndex(this->m_direction);
        radioDialog.exec();
        if (radioDialog.isAccepted())
        {
            this->m_direction = radioDialog.index();
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

void
STouchSettingsSystemNFC::setCloseable(const bool closeable)
{
    this->m_closeable = closeable;
}

void STouchSettingsSystemNFC::slotWriteSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
    settings.beginGroup("custom/system/nfc");
    settings.setValue("minValue", this->m_minValue);
    settings.setValue("maxValue", this->m_maxValue);
    settings.setValue("direction", this->m_direction);
    settings.sync();
    settings.endGroup();
}

void STouchSettingsSystemNFC::slotReadSettings()
{    
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
    if (!QStringList(settings.allKeys().filter("custom/system/nfc", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/system/nfc");
    }
    else if (!QStringList(settings.allKeys().filter("default/system/nfc", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/system/nfc");
    }

    this->m_minValue = settings.value("minValue", 0).toInt();
    this->list->setItem(2, QString::number(this->m_minValue), SList::Item::Info);

    this->m_maxValue = settings.value("maxValue", 255).toInt();
    this->list->setItem(3, QString::number(this->m_maxValue), SList::Item::Info);

    this->m_direction = settings.value("direction", 0).toInt();
    this->list->setItem(4, this->m_direction == 0 ? tr("Unidirectional") : tr("Bidirectional"), SList::Item::Info);

    settings.sync();
    settings.endGroup();
}

void STouchSettingsSystemNFC::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Paternoster"));


    // Swipe list
    this->list->setTitle(t_iter++, tr("NFC Transponder"));
    this->list->setTitle(t_iter++, tr("NFC Controller"));
    this->list->setTitle(t_iter++, tr("Peripheral Units"));

    t_iter = 0;
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Write to Transponder"),
                     tr("Write a new value."),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Read from Transponder"),
                     tr("Read value."),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Minimum Value"),
                     tr("Define the minimum value of your application."),
                     QString::number(this->m_minValue),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Maximum Value"),
                     tr("Define the maximum value of your application."),
                     QString::number(this->m_maxValue),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Electrical Engine Direction"),
                     tr("Drive of the electrical engine."),
                     this->m_direction == 0 ? tr("Unidirectional") : tr("Bidirectional"),
                     QChar(0x276F));
}

void
STouchSettingsSystemNFC::restyleUI()
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
STouchSettingsSystemNFC::changeEvent(QEvent * event)
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

void
STouchSettingsSystemNFC::showEvent(QShowEvent * event)
{
    Q_UNUSED(event);

    if (this->m_closeable)
    {
        STouchScreenlock touchScreenlock(this);
        touchScreenlock.setRole(STouchScreenlock::Role::Appropriate);
        touchScreenlock.enableSymbols(true);
        touchScreenlock.exec();

        if (!touchScreenlock.isAccepted())
        {
            emit this->signalReturn();
            this->close();
        }
    }
}
