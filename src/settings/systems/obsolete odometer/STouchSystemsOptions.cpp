#include "STouchSystemsOptions.h"
#include "../build/SGlobal.h"
#include "../flickable/STouchFlickableList.h"
#include "../effect/SGraphicsGlowEffect.h"
#include "../button/SReturnButton.h"

#include <QApplication>
#include <QLabel>
#include <QSettings>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


STouchSystemsOptions::STouchSystemsOptions(QWidget *parent) : QDialog(parent)
{
    #ifdef S_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setWindowState(Qt::WindowFullScreen);
    #else
    this->resize(QSize(800,480));
    #endif
    this->setStyleSheet("background-color: " + ::GlobalBackgroundColor + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
}

STouchSystemsOptions::~STouchSystemsOptions()
{
    if (settings != nullptr)
    {
        delete settings;
        settings = nullptr;
    }
    if (touchFlickable1 != nullptr)
    {
        delete touchFlickable1;
        touchFlickable1 = nullptr;
    }
    if (touchFlickable2 != nullptr)
    {
        delete touchFlickable2;
        touchFlickable2 = nullptr;
    }
    if (touchFlickable3 != nullptr)
    {
        delete touchFlickable3;
        touchFlickable3 = nullptr;
    }
}

void STouchSystemsOptions::setupWidget()
{   
    /// BUTTON
    backButton = new SReturnButton(this);

    /// Label
    labelTitle = new QLabel(tr("Options"), this);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setStyleSheet("QLabel { font: " + ::GlobalLabelTextFont + "; color: " + ::GlobalTextColor + "; background: transparent; }"); // font-variant: small-caps;
    labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    /// FLICKABLE 1
    flickTitle1 = new QLabel(tr("Procedure"), this);
    flickTitle1->setAlignment(Qt::AlignCenter);
    flickTitle1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    flickTitle1->setStyleSheet(this->formStyleSheetString("label"));
    flickTitle1->setContentsMargins(0,10,0,10);
    SGraphicsGlowEffect *glow1 = new SGraphicsGlowEffect;
    glow1->setColor(QColor(::GlobalSystemColor));
    glow1->setBlurRadius(1);
    glow1->setStrength(1);
    flickTitle1->setGraphicsEffect(glow1);

    touchFlickable1 = new STouchFlickableList;
    touchFlickable1->setWindowState(Qt::WindowFullScreen);
    touchFlickable1->setBackgroundColor(QColor(::GlobalBackgroundColor));
    touchFlickable1->setSelectColor(QColor(0,130,255,100));
    touchFlickable1->setRowHeight(this->height()/10.5);
    touchFlickable1->setTextAlignment(Qt::AlignCenter);
    touchFlickable1->setFontSize(14);
    touchFlickable1->setCheckable(true);
    touchFlickable1->setSelectable(true);
    touchFlickable1->setText(QChar(0x26AB));
    touchFlickable1->setText(QChar(0x26AA));

    /// FLICKABLE 2
    flickTitle2 = new QLabel(tr("Filter Type"), this);
    flickTitle2->setAlignment(Qt::AlignCenter);
    flickTitle2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    flickTitle2->setStyleSheet(this->formStyleSheetString("label"));
    flickTitle2->setContentsMargins(0,10,0,10);
    SGraphicsGlowEffect *glow2 = new SGraphicsGlowEffect;
    glow2->setColor(QColor(::GlobalSystemColor));
    glow2->setBlurRadius(1);
    glow2->setStrength(1);
    flickTitle2->setGraphicsEffect(glow2);

    touchFlickable2 = new STouchFlickableList;
    touchFlickable2->setWindowState(Qt::WindowFullScreen);
    touchFlickable2->setBackgroundColor(QColor(::GlobalBackgroundColor));
    touchFlickable2->setSelectColor(QColor(0,130,255,100));
    touchFlickable2->setRowHeight(this->height()/10.5);
    touchFlickable2->setTextAlignment(Qt::AlignCenter);
    touchFlickable2->setFontSize(14);
    touchFlickable2->setCheckable(true);
    touchFlickable2->setSelectable(true);
    touchFlickable2->setText(tr("Low Pass"));
    touchFlickable2->setText(tr("High Pass"));
    touchFlickable2->setText(tr("Band Pass"));
    touchFlickable2->setText(tr("Band Stop"));

    /// FLICKABLE 3
    flickTitle3 = new QLabel(tr("Sample Rate"), this);
    flickTitle3->setAlignment(Qt::AlignCenter);
    flickTitle3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    flickTitle3->setStyleSheet(this->formStyleSheetString("label"));
    flickTitle3->setContentsMargins(0,10,0,10);
    SGraphicsGlowEffect *glow3 = new SGraphicsGlowEffect;
    glow3->setColor(QColor(::GlobalSystemColor));
    glow3->setBlurRadius(1);
    glow3->setStrength(1);
    flickTitle3->setGraphicsEffect(glow3);

    touchFlickable3 = new STouchFlickableList;
    touchFlickable3->setWindowState(Qt::WindowFullScreen);
    touchFlickable3->setBackgroundColor(QColor(::GlobalBackgroundColor));
    touchFlickable3->setSelectColor(QColor(0,130,255,100));
    touchFlickable3->setRowHeight(this->height()/10.5);
    touchFlickable3->setTextAlignment(Qt::AlignCenter);
    touchFlickable3->setFontSize(14);
    touchFlickable3->setCheckable(true);
    touchFlickable3->setSelectable(true);
    touchFlickable3->setText(QString::number(300).append(" Hz"));
    touchFlickable3->setText(QString::number(560).append(" Hz"));
    touchFlickable3->setText(QString::number(1000).append(" Hz"));

    this->slotReadSettings();
}

void STouchSystemsOptions::setupGUI()
{
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(backButton, 0, Qt::AlignLeft);
    titleLayout->addWidget(labelTitle);
    titleLayout->setContentsMargins(0,0,this->backButton->width(),0);

    QVBoxLayout *flickLayout1 = new QVBoxLayout;
    flickLayout1->addWidget(flickTitle1);
    flickLayout1->addSpacing(height()/20);
    flickLayout1->addWidget(touchFlickable1);

    QVBoxLayout *flickLayout2 = new QVBoxLayout;
    flickLayout2->addWidget(flickTitle2);
    flickLayout2->addSpacing(height()/20);
    flickLayout2->addWidget(touchFlickable2);

    QVBoxLayout *flickLayout3 = new QVBoxLayout;
    flickLayout3->addWidget(flickTitle3);
    flickLayout3->addSpacing(height()/20);
    flickLayout3->addWidget(touchFlickable3);

    QHBoxLayout *subLayout = new QHBoxLayout;
    subLayout->addLayout(flickLayout1);
    subLayout->addSpacing(width()/16);
    subLayout->addLayout(flickLayout2);
    subLayout->addSpacing(width()/16);
    subLayout->addLayout(flickLayout3);
    subLayout->setContentsMargins(width()/16,height()/16,width()/16,height()/16);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(subLayout);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void STouchSystemsOptions::setConnect()
{
    /// FLICKABLE
    connect(touchFlickable1, &STouchFlickableList::signalCurrentIndex, this, &STouchSystemsOptions::slotFlickEvent1);
    connect(touchFlickable2, &STouchFlickableList::signalCurrentIndex, this, &STouchSystemsOptions::slotFlickEvent2);
    connect(touchFlickable3, &STouchFlickableList::signalCurrentIndex, this, &STouchSystemsOptions::slotFlickEvent3);
}

void STouchSystemsOptions::slotFlickEvent1(const int &index)
{
    switch (index)
    {
        case 0: /// pulse
        {
            this->procedure = "pulse";
        }
            break;
        case 1: /// phase
        {
            this->procedure = "phase";
        }
            break;
        default:
            break;
    }

    this->slotWriteSettings();
}

void STouchSystemsOptions::slotFlickEvent2(const int &index)
{
    switch (index)
    {
        case 0: /// low
        {
            this->filterType = "low";
        }
            break;
        case 1: /// high
        {
            this->filterType = "high";
        }
            break;
        case 2: /// pass
        {
            this->filterType = "pass";
        }
            break;
        case 3: /// stop
        {
            this->filterType = "stop";
        }
            break;
        default:
            break;
    }

    this->slotWriteSettings();
}

void STouchSystemsOptions::slotFlickEvent3(const int &index)
{
    switch (index)
    {
        case 0: /// 300 Hz
        {
            this->samplerate = 300;
        }
            break;
        case 1: /// 560 Hz
        {
            this->samplerate = 560;
        }
            break;
        case 2: /// 1000 Hz
        {
            this->samplerate = 1000;
        }
            break;
        default:
            break;
    }

    this->slotWriteSettings();
}


void STouchSystemsOptions::slotWriteSettings()
{
    settings = new QSettings(::GlobalSettingDir + ::GlobalSettingSettings, QSettings::IniFormat);
    settings->beginGroup("custom/systems");

    /// VALUE AREA
    ///
    settings->setValue("procedure", this->procedure);
    settings->setValue("filterType", this->filterType);
    settings->setValue("samplerate", this->samplerate);

    settings->sync();
    settings->endGroup();

    delete settings;
    settings = nullptr;
}

void STouchSystemsOptions::slotReadSettings()
{
    settings = new QSettings(::GlobalSettingDir + ::GlobalSettingSettings, QSettings::IniFormat);
    if (settings->contains("custom/systems/filterType"))
    {
        settings->beginGroup("custom/systems");
    }
    else
    {
        settings->beginGroup("default/systems");
    }

    /// VALUE AREA
    ///
    QString text;

    text = settings->value("procedure", "phase").toString();
    this->procedure = text;
    if (!text.compare("pulse"))
    {
        touchFlickable1->setIndexOf(0);
    }
    else if (!text.compare("phase"))
    {
        touchFlickable1->setIndexOf(1);
    }

    text = settings->value("filterType", "pass").toString();
    this->filterType = text;
    if (!text.compare("low"))
    {
        touchFlickable2->setIndexOf(0);
    }
    else if (!text.compare("high"))
    {
        touchFlickable2->setIndexOf(1);
    }
    else if (!text.compare("pass"))
    {
        touchFlickable2->setIndexOf(2);
    }
    else if (!text.compare("stop"))
    {
        touchFlickable2->setIndexOf(3);
    }

    text = settings->value("samplerate", 1000).toString();
    this->samplerate = text.toInt();
    if (!text.compare("300"))
    {
        touchFlickable3->setIndexOf(0);
    }
    else if (!text.compare("560"))
    {
        touchFlickable3->setIndexOf(1);
    }
    else if (!text.compare("1000"))
    {
        touchFlickable3->setIndexOf(2);
    }

    /// CLOSE AREA
    ///
    settings->sync();
    settings->endGroup();

    delete settings;
    settings = nullptr;
}

QString STouchSystemsOptions::formStyleSheetString(const QString &style)
{
    QString styleButton;

    if (!style.compare("label"))
    {
        styleButton =
        "\
            QLabel { font: 14pt " + ::GlobalFont + "; color: " + ::GlobalTextColor + "; background-color: rgba(255,255,255,20); border-top: 1px solid rgba(0,130,255,40); border-bottom: 1px solid rgba(0,130,255,40); border-right: none; border-left: none; } \
        ";
    }

    return styleButton;
}

void STouchSystemsOptions::retranslateUI()
{
    labelTitle->setText(tr("Options"));
    flickTitle1->setText(tr("Procedure"));
    touchFlickable1->setText(tr("Pulse"), 0);
    touchFlickable1->setText(tr("Phase"), 1);
    flickTitle2->setText(tr("Filter Type"));
    touchFlickable2->setText(tr("Low Pass"), 0);
    touchFlickable2->setText(tr("High Pass"), 1);
    touchFlickable2->setText(tr("Band Pass"), 2);
    touchFlickable2->setText(tr("Band Stop"), 3);
    flickTitle3->setText(tr("Sample Rate"));
}

void STouchSystemsOptions::changeEvent(QEvent* event)
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
