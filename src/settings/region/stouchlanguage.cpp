#include "stouchlanguage.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QLocale>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QEvent>
#include <QDebug>


STouchLanguage::STouchLanguage(QWidget *parent) : QDialog(parent)
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

STouchLanguage::~STouchLanguage()
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

void STouchLanguage::setupWidget()
{
    // File watcher
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalConfigPathLanguage);

    // Header
    this->header = new SLabel;
    this->header->header(tr("Language"), 0x0276E);

    // Swipe list
    this->list = new SList;
    this->list->addSlot(QIcon(),
                     tr("English"),
                     "English",
                     "",
                     QChar(0x25FC));
    this->list->addSlot(QIcon(),
                     tr("German"),
                     "Deutsch",
                     "",
                     QChar(0x25FB));

//    this->touchFlickable->setText(tr("Italian"), "Italiano");
//    this->touchFlickable->setParameter(QChar(0x25FC));
//    this->touchFlickable->setText(tr("Dutch"), "Nederlands");
//    this->touchFlickable->setParameter(QChar(0x25FC));
//    this->touchFlickable->setText(tr("Polish"), "Polski");
//    this->touchFlickable->setParameter(QChar(0x25FC));
//    this->touchFlickable->setText(tr("Danish"), "Danks");
//    this->touchFlickable->setParameter(QChar(0x25FC));
//    this->touchFlickable->setText(tr("Estonia"), "Eesti");
//    this->touchFlickable->setParameter(QChar(0x25FC));
//    this->touchFlickable->setText(tr("Maltese"), "Malti");
//    this->touchFlickable->setParameter(QChar(0x25FC));
//    this->touchFlickable->setText(tr("Swedish"), "Svenska");
//    this->touchFlickable->setParameter(QChar(0x25FC));
//    this->touchFlickable->setText(tr("Basque"), "Euskara");
//    this->touchFlickable->setParameter(QChar(0x25FC));
}

void STouchLanguage::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addWidget(this->list->list(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchLanguage::setConnect()
{
    // Lists
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));
    // File watcher
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchLanguage::slotReadSettings);
}

void STouchLanguage::slotList(const int index)
{
    bool t_write = false;

    switch (index)
    {
    case 0:
    {
        this->language = "en_EN";
        t_write = true;
    }
        break;

    case 1:
    {
        this->language = "de_DE";
        t_write = true;
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

void STouchLanguage::slotWriteSettings()
{
    QSettings settings(::GlobalConfigFileLanguage, QSettings::IniFormat);
    settings.beginGroup("custom/region");
    settings.setValue("language", this->language);
    settings.sync();
    settings.endGroup();
}

void STouchLanguage::slotReadSettings()
{
    QSettings settings(::GlobalConfigFileLanguage, QSettings::IniFormat);

    if (!QStringList(settings.allKeys().filter("custom/region", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/region");
    }
    else if (!QStringList(settings.allKeys().filter("default/region", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/region");
    }

    this->language = settings.value("language", "en_EN").toString();

    settings.sync();
    settings.endGroup();

    // Load Language
    this->loadLanguage(this->language);
}

void STouchLanguage::loadLanguage(const QString &language)
{
    // Set all Symbols.
    this->list->setItems(QChar(0x25FB), SList::Item::Symbol);

    qApp->removeTranslator(&translator);
    if (!language.compare("en_EN"))
    {
        translator.load("build-en_EN", ::GlobalConfigPathLanguage);
        QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
        this->list->setItem(0, QChar(0x25FC), SList::Item::Symbol);
    }
    else if (!language.compare("de_DE"))
    {
        translator.load("build-de_DE", ::GlobalConfigPathLanguage);
        QLocale::setDefault(QLocale(QLocale::German, QLocale::Germany));
        this->list->setItem(1, QChar(0x25FC), SList::Item::Symbol);
    }
    qApp->installTranslator(&translator);
}

void STouchLanguage::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Language"));

    // Swipe list
    this->list->setItem(t_iter++, tr("English"), SList::Item::Text);
    this->list->setItem(t_iter++, tr("German"), SList::Item::Text);
}

void
STouchLanguage::restyleUI()
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
STouchLanguage::changeEvent(QEvent * event)
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
