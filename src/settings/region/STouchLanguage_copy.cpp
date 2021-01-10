#include "stouchlanguage.h"
#include "../build/SGlobal.h"
#include "../../flickable/list/STouchFlickableList.h"
#include "../button/SReturnButton.h"

#include <QApplication>
#include <QLabel>
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
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
}

STouchLanguage::~STouchLanguage()
{
    if (this->settings != nullptr)
    {
        delete this->settings;
        this->settings = nullptr;
    }
    if (this->touchFlickable != nullptr)
    {
        delete this->touchFlickable;
        this->touchFlickable = nullptr;
    }
}

void STouchLanguage::setupWidget()
{
    /// WATCHER
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalSettingDir + ::GlobalSettingConfig);
    this->fileSystemWatcher->addPath(::GlobalSettingDir + ::GlobalSettingConfigSettings);

    /// Label
    this->labelTitle = new QLabel(tr("Language"), this);
    this->labelTitle->setAlignment(Qt::AlignCenter);
    this->labelTitle->setStyleSheet("QLabel { font: " + ::GlobalLabelTextFont + "; color: " + ::GlobalBrightTextColor + "; background: transparent; }"); // font-variant: small-caps;
    this->labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    /// BUTTON
    this->backButton = new SReturnButton(this);

    int t_height = ::GlobalWindowSize.height() < ::GlobalWindowSize.width() ? ::GlobalWindowSize.height() : ::GlobalWindowSize.width();
    /// Flickable
    this->touchFlickable = new STouchFlickableList;
    this->touchFlickable->setRowHeight(t_height/8);
    this->touchFlickable->setBackgroundColor(QColor(::GlobalBackgroundColor));
    this->touchFlickable->setFontSizeParamter(25);
    this->touchFlickable->setCheckable(true);
    this->touchFlickable->setText(tr("English"));
    this->touchFlickable->setParameter("");
    this->touchFlickable->setText(tr("German"));
    this->touchFlickable->setParameter("");

    this->slotReadSettings();
}

void STouchLanguage::setupGUI()
{
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(this->backButton, 0, Qt::AlignLeft);
    titleLayout->addWidget(this->labelTitle);
    titleLayout->setContentsMargins(0,0,this->backButton->width(),0);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(this->touchFlickable);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(layout);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void STouchLanguage::setConnect()
{
    /// FLICKABLE
    connect(this->touchFlickable, &STouchFlickableList::signalCurrentIndex, this, &STouchLanguage::slotFlickEvent);
    /// WATCHER
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchLanguage::slotReadSettings);
    connect(this->fileSystemWatcher, &QFileSystemWatcher::fileChanged, this, &STouchLanguage::slotReadSettings);
}

void STouchLanguage::slotFlickEvent(const int &index)
{
    switch (index)
    {
        case 0:
            this->language = "en_EN";
            break;
        case 1:
            this->language = "de_DE";
            break;
        default:
            break;
    }

    this->slotWriteSettings();
}

void STouchLanguage::slotWriteSettings()
{
    this->settings = new QSettings(::GlobalSettingDir + ::GlobalSettingConfigSettings, QSettings::IniFormat);
    this->settings->beginGroup("custom/region");
    this->settings->setValue("language", this->language);
    this->settings->sync();
    this->settings->endGroup();
    delete this->settings;
    this->settings = nullptr;

    /// Load Language
    this->loadLanguage(this->language);
}

void STouchLanguage::slotReadSettings()
{
    this->settings = new QSettings(::GlobalSettingDir + ::GlobalSettingConfigSettings, QSettings::IniFormat);

    if (!QStringList(this->settings->allKeys().filter("custom/region", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("custom/region");
    }
    else if (!QStringList(this->settings->allKeys().filter("default/region", Qt::CaseInsensitive)).isEmpty())
    {
        this->settings->beginGroup("default/region");
    }

    /// LANGUAGE
    this->language = this->settings->value("language", "en_EN").toString();

    this->settings->sync();
    this->settings->endGroup();

    delete this->settings;
    this->settings = nullptr;

    /// Load Language
    this->loadLanguage(this->language);
}

void STouchLanguage::loadLanguage(const QString &language)
{
    for (int i = 0; i < this->touchFlickable->size(); ++i)
    {
        this->touchFlickable->setParameter("", i);
    }

    qApp->removeTranslator(&translator);
    if (!language.compare("en_EN"))
    {
        translator.load("build-en_EN", ::GlobalSettingDir + ::GlobalSettingLanguages);
        QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
        this->touchFlickable->setParameter(QChar(0x26AB), 0);
    }
    else if (!language.compare("de_DE"))
    {
        translator.load("build-de_DE", ::GlobalSettingDir + ::GlobalSettingLanguages);
        QLocale::setDefault(QLocale(QLocale::German, QLocale::Germany));
        this->touchFlickable->setParameter(QChar(0x26AB), 1);
    }
    qApp->installTranslator(&translator);
}

void STouchLanguage::retranslateUI()
{
    this->labelTitle->setText(tr("Language"));
    this->touchFlickable->setText(tr("English"), 0);
    this->touchFlickable->setText(tr("German"), 1);
}

void STouchLanguage::changeEvent(QEvent* event)
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
