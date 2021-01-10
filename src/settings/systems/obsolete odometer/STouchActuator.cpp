#include "STouchActuator.h"
#include "../build/SGlobal.h"
#include "../flickable/STouchFlickableList.h"
#include "../keyboard/STouchKeyboard.h"
#include "../button/SReturnButton.h"

#include <QApplication>
#include <QFileSystemWatcher>
#include <QSettings>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>


STouchActuator::STouchActuator(QWidget *parent) : QDialog(parent)
{
    #ifdef S_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setWindowState(Qt::WindowFullScreen);
    #else
    this->resize(QSize(800,480));
    #endif
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setUpGUI();
    this->setConnect();
}

STouchActuator::~STouchActuator()
{
    if (settings != nullptr)
    {
        delete settings;
        settings = nullptr;
    }
    if (touchKeyboard != nullptr)
    {
        delete touchKeyboard;
        touchKeyboard = nullptr;
    }
    if (touchFlickable != nullptr)
    {
        delete touchFlickable;
        touchFlickable = nullptr;
    }
}

void STouchActuator::setUpGUI()
{
    /*
    fileSystemWatcher = new QFileSystemWatcher(this);
    fileSystemWatcher->addPath(::GlobalSettingDir + ::GlobalSettingSettings);
    */

    /// Label
    labelTitle = new QLabel(tr("Actuator"), this);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setStyleSheet("QLabel { font: " + ::GlobalLabelTextFont + "; color: " + ::GlobalTextColor + "; background: transparent; }");
    labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    /// BUTTON
    backButton = new SReturnButton(this);

    /// FLICKABLE
    touchFlickable = new STouchFlickableList;
    touchFlickable->setWindowState(Qt::WindowFullScreen);
    touchFlickable->setBackgroundColor(QColor(::GlobalBackgroundColor));
    touchFlickable->setFontTextColor(QColor(::GlobalSystemColor));
    touchFlickable->setRowHeight(this->height()/11);
    touchFlickable->setCheckable(true);
    touchFlickable->setTopic(tr("Odometer"));
    touchFlickable->setText(tr("Magnet Resolution"));
    touchFlickable->setParameter(resolution);
    touchFlickable->setText(tr("Diameter"));
    touchFlickable->setParameter(diameter + " m");

    this->slotReadSettings();

    /// LAYOUTS
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(backButton, 0, Qt::AlignLeft);
    titleLayout->addWidget(labelTitle);
    titleLayout->setContentsMargins(0,0,this->backButton->width(),0);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(touchFlickable);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(layout);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void STouchActuator::setConnect()
{
    /// FLICKABLE
    connect(touchFlickable, &STouchFlickableList::signalCurrentIndex, this, &STouchActuator::slotFlickEvent);
    /// WATCHER
    //connect(fileSystemWatcher, &QFileSystemWatcher::fileChanged, this, &STouchActuator::slotReadSettings);
}

void STouchActuator::slotFlickEvent(const int &index)
{
    this->hide();

        bool write = false;

        if (touchKeyboard != nullptr)
        {
            delete touchKeyboard;
            touchKeyboard = nullptr;
        }

        switch (index)
        {
            case 1: /// Magnet Resolution
            {
                touchKeyboard = new STouchKeyboard;
                touchKeyboard->setTitle(tr("Magnet Resolution"));
                touchKeyboard->setDescriptionText(tr("The magnet resolution should be higher than 0"));
                touchKeyboard->setRange(1, INT_MAX);
                touchKeyboard->setMaximumDigit(4);
                touchKeyboard->exec();

                if (touchKeyboard->isAccepted())
                {
                    this->resolution = touchKeyboard->getNumber();
                    touchFlickable->setParameter(resolution, index);

                    write = true;
                }

                delete touchKeyboard;
                touchKeyboard = nullptr;
            }
                break;
            case 2: /// Diameter
            {
                touchKeyboard = new STouchKeyboard;
                touchKeyboard->setTitle(tr("Diameter [m]"));
                touchKeyboard->setDescriptionText(tr("The diameter should be higher than 0"));
                touchKeyboard->setRange(1.e-4, 1.e4);
                touchKeyboard->setMaximumDigit(6);
                touchKeyboard->setDatatyp("double");
                touchKeyboard->exec();

                if (touchKeyboard->isAccepted())
                {
                    this->diameter = touchKeyboard->getNumber();
                    touchFlickable->setParameter(diameter + " m", index);

                    write = true;
                }

                delete touchKeyboard;
                touchKeyboard = nullptr;
            }
                break;
            default:
                break;
        }

        if (write)
        {
            this->slotWriteSettings();
        }

    this->show();
}

void STouchActuator::slotWriteSettings()
{
    settings = new QSettings(::GlobalSettingDir + ::GlobalSettingSettings, QSettings::IniFormat);
    settings->beginGroup("custom/systems");
    settings->setValue("resolution", resolution);
    settings->setValue("diameter", QString::number(diameter.toDouble(), 'f', 4));
    settings->sync();
    settings->endGroup();

    delete settings;
    settings = nullptr;
}

void STouchActuator::slotReadSettings()
{
    settings = new QSettings(::GlobalSettingDir + ::GlobalSettingSettings, QSettings::IniFormat);
    if (settings->contains("custom/systems/diameter"))
    {
        settings->beginGroup("custom/systems");
    }
    else
    {
        settings->beginGroup("default/systems");
    }

    this->resolution = settings->value("resolution", 0).toString();
    touchFlickable->setParameter(resolution, 1);

    this->diameter = settings->value("diameter", QString::number(0.0, 'f', 4)).toString();
    touchFlickable->setParameter(diameter + " m", 2);

    settings->sync();
    settings->endGroup();

    delete settings;
    settings = nullptr;
}


void STouchActuator::retranslateUI()
{
    labelTitle->setText(tr("Actuator"));
    touchFlickable->setTopic(tr("Odometer"), 0);
    touchFlickable->setText(tr("Magnet Resolution"), 1);
    touchFlickable->setText(tr("Diameter"), 2);
}

void STouchActuator::changeEvent(QEvent* event)
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
