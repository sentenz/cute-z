#include "stouchsettingssystemencoder.h"
#include "../keyboard/STouchScreenlock.h"
#include "../keyboard/STouchKeyboard.h"
#include "../util/dialog/STouchDialogTumbler.h"
#include "../util/dialog/SRadioDialog.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QFileSystemWatcher>
#include <QSettings>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


STouchSettingsSystemEncoder::STouchSettingsSystemEncoder(QWidget *parent)
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

STouchSettingsSystemEncoder::~STouchSettingsSystemEncoder()
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

void STouchSettingsSystemEncoder::setupWidget()
{
    // File watcher
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalConfigPathSettings);

    // Header
    this->header = new SLabel;
    this->header->header(tr("Odometer"), 0x0276E);

    // Swipe list
    this->list = new SList;
    this->list->addSlot(QIcon(),
                     tr("Direction of Rotation"),
                     tr("A clockwise or counter clockwise direction of the rotation."),
                     tr("CW"),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Diameter"),
                     tr("Diameter of the roll."),
                     QString::number(this->m_diameter) + " m",
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Precision"),
                     tr("Number of decimal places of the measurement."),
                     QString::number(this->m_precision),
                     QChar(0x276F));

    this->slotReadSettings();
}

void STouchSettingsSystemEncoder::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addWidget(this->list->list(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchSettingsSystemEncoder::setConnect()
{
    /* Header */
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
    /* Swipe list */
    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));
    /* File watcher */
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchSettingsSystemEncoder::slotReadSettings);
}

void STouchSettingsSystemEncoder::slotList(const int index)
{
    bool t_write = false;

    switch (index)
    {
    case 0: // Direction of Rotation
    {
        SRadioDialog radioDialog(this);
        radioDialog.setTitle(tr("Direction"));
        radioDialog.setAcceptButton(tr("Accept"));
        radioDialog.setRejectButton(tr("Close"));
        radioDialog.addText(tr("Clockwise"));
        radioDialog.addText(tr("Counterclockwise"));
        radioDialog.setIndex(this->m_clockwise);
        radioDialog.exec();
        if (radioDialog.isAccepted())
        {
            this->m_clockwise = radioDialog.index();
            t_write = true;
        }
    }
        break;

    case 1: // Diameter
    {
        STouchKeyboard touchKeyboard(this);
        touchKeyboard.setTitle(tr("Diameter [m]"));
        touchKeyboard.setDescriptionText(tr("Diameter value must be higher than 0.0."), STouchKeyboard::Dialog::Warning);
        touchKeyboard.setRange(1.e-4, 1.e4);
        touchKeyboard.setMaximumDigit(6);
        touchKeyboard.setDatatype(STouchKeyboard::Datatype::Double);
        touchKeyboard.exec();
        if (touchKeyboard.isAccepted())
        {
            this->m_diameter = touchKeyboard.getNumber().toDouble();

            t_write = true;
        }
    }
        break;

    case 2: // Precision
    {
        STouchDialogTumbler touchTumbler(this);
        touchTumbler.setTitleText(tr("Precision"));
        touchTumbler.setDescription(tr("digits"));
        touchTumbler.setItems(QStringList()
                              << QString::number(1)
                              << QString::number(2)
                              << QString::number(3)
                              << QString::number(4));
        touchTumbler.setCurrentContent(QString::number(this->m_precision));
        //touchTumbler.setFontSizeParamter(20);
        touchTumbler.exec();

        if (touchTumbler.isAccepted())
        {
            this->m_precision = touchTumbler.currentContent().toInt();

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
STouchSettingsSystemEncoder::setCloseable(const bool closeable)
{
    this->m_closeable = closeable;
}

void STouchSettingsSystemEncoder::slotWriteSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
    settings.beginGroup("custom/system/encoder");
    settings.setValue("clockwise", this->m_clockwise);
    settings.setValue("diameter", this->m_diameter);
    settings.setValue("precision", this->m_precision);
    settings.sync();
    settings.endGroup();
}

void STouchSettingsSystemEncoder::slotReadSettings()
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

    this->m_clockwise = settings.value("clockwise").toInt();
    this->m_diameter = settings.value("diameter", 0.0).toDouble();
    this->m_precision = settings.value("precision", 0).toInt();

    settings.sync();
    settings.endGroup();

    this->updateWidget();
}

void
STouchSettingsSystemEncoder::updateWidget()
{
    this->list->setItem(0, this->m_clockwise == 0 ? tr("CW") : tr("CCW"), SList::Item::Info);
    this->list->setItem(1, QString::number(this->m_diameter) + " m", SList::Item::Info);
    this->list->setItem(2, QString::number(this->m_precision), SList::Item::Info);
}

void STouchSettingsSystemEncoder::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Region"));

    // Swipe list
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Direction of Rotation"),
                     tr("A clockwise or counter clockwise direction of the rotation."),
                     this->m_clockwise == 0 ? tr("CW") : tr("CCW"),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Diameter"),
                     tr("Diameter of the roll."),
                     QString::number(this->m_diameter) + " m",
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                        QIcon(),
                     tr("Precision"),
                     tr("Number of decimal places of the measurement."),
                     QString::number(this->m_precision),
                     QChar(0x276F));
}

void
STouchSettingsSystemEncoder::restyleUI()
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
STouchSettingsSystemEncoder::changeEvent(QEvent * event)
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
STouchSettingsSystemEncoder::showEvent(QShowEvent * event)
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
