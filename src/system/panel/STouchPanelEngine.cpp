#include "STouchPanelEngine.h"
#include "../build/SGlobal.h"
#include "../device/SEngine.h"
#include "../widget/button/SRaisedButton.h"
#include "../util/dialog/SAppBar.h"

#include <QApplication>
#include <QButtonGroup>
#include <QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDebug>


STouchPanelEngine::STouchPanelEngine(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setMouseTracking(true);
    this->setAttribute(Qt::WA_AcceptTouchEvents, true);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchPanelEngine::~STouchPanelEngine()
{
    if (this->engine != nullptr)
    {
        delete this->engine;
        this->engine = nullptr;
    }
}

void STouchPanelEngine::setupWidget()
{
    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);

    /* Buttons */
    this->m_buttonUp = new SRaisedButton(QChar(0x25B2), this);
    this->m_buttonUp->setFontSize(30);
    this->m_buttonUp->applyPreset(Material::CheckablePreset);
    this->m_buttonUp->setCornerRound();
    this->m_buttonUp->setHaloVisible(true);
    this->m_buttonUp->setDisabledMode(true);

    this->m_buttonDown = new SRaisedButton(QChar(0x25BC), this);
    this->m_buttonDown->setFontSize(30);
    this->m_buttonDown->applyPreset(Material::CheckablePreset);
    this->m_buttonDown->setCornerRound();
    this->m_buttonDown->setHaloVisible(true);
    this->m_buttonDown->setDisabledMode(true);

    /* Peripheral inteface to e-engine */
    this->engine = new SEngine(BUS::GPIO);
}

void STouchPanelEngine::setupLayout()
{
    int t_verticalSize = ::GlobalWindowSize.height() > ::GlobalWindowSize.width() ? ::GlobalWindowSize.height()*0.225 : ::GlobalWindowSize.width()*0.0417;
    int t_horizontalSize = ::GlobalWindowSize.height() < ::GlobalWindowSize.width() ? ::GlobalWindowSize.height()*0.225 : ::GlobalWindowSize.width()*0.0417;

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->appBar);
    mainLayout->addWidget(this->m_buttonUp);
    mainLayout->addSpacing(t_horizontalSize);
    mainLayout->addWidget(this->m_buttonDown);
    mainLayout->setContentsMargins(t_horizontalSize, t_verticalSize, t_horizontalSize, t_verticalSize);

    setLayout(mainLayout);
}

void STouchPanelEngine::setConnect()
{
    /* App bar */
    connect(this->appBar,&SAppBar::signalClicked, [this] (int n) {
        switch (n) {
        case 0:
        {
            emit this->signalReturn();
        }
            break;

        default:
            emit this->signalOption(n);
            break;
        }
    });

    /* Buutons */
    connect(this->m_buttonUp, &SRaisedButton::clicked, [this]() {
        if (this->m_buttonUp->isChecked())
        {
            this->m_buttonUp->setAutoExclusive(false);
            this->m_buttonDown->setChecked(false);

            emit this->slotEngineUp();
        }
        else
        {
            this->m_buttonUp->setAutoExclusive(true);

            emit this->slotEngineStop();
        }
    });
    connect(this->m_buttonDown, &SRaisedButton::clicked, [this]() {
        if (this->m_buttonDown->isChecked())
        {
            this->m_buttonDown->setAutoExclusive(false);
            this->m_buttonUp->setChecked(false);

            emit this->slotEngineDown();
        }
        else
        {
            this->m_buttonDown->setAutoExclusive(true);

            emit this->slotEngineStop();
        }
    });
}

void STouchPanelEngine::slotEngineUp()
{
    this->engine->forward(Engine::EMotor);
}

void STouchPanelEngine::slotEngineStop()
{
    this->engine->neutral(Engine::EMotor);
}

void STouchPanelEngine::slotEngineDown()
{
    this->engine->backward(Engine::EMotor);
}

void
STouchPanelEngine::retranslateUI()
{
    /* App bar */
    this->appBar->setText(this->m_title);
}

void
STouchPanelEngine::restyleUI()
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
STouchPanelEngine::changeEvent(QEvent * event)
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
