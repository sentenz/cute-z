#include "stouchsettingssystem.h"
#include "systems/stouchsettingssystemnfc.h"
#include "systems/stouchsettingssystemencoder.h"
#include "../keyboard/STouchScreenlock.h"
#include "../widget/list/SList.h"
#include "../widget/stacked/SAnimatedStackedWidget.h"
#include "../util/dialog/SAppBar.h"

#include <QApplication>
#include <QTimerEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>


STouchSettingsSystem::STouchSettingsSystem(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchSettingsSystem::~STouchSettingsSystem()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
    if (::GlobalDefinesNfc)
    {
        if (this->touchSettingsSystemNFC != nullptr)
        {
            delete this->touchSettingsSystemNFC;
            this->touchSettingsSystemNFC = nullptr;
        }
    }
    if (::GlobalDefinesEncoder)
    {
        if (this->touchSettingsSystemEncoder != nullptr)
        {
            delete this->touchSettingsSystemEncoder;
            this->touchSettingsSystemEncoder = nullptr;
        }
    }
}

void STouchSettingsSystem::setupWidget()
{
    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);

    /* Swipe list */
    this->list = new SList;
    if (::GlobalDefinesNfc)
    {
        this->list->addSlot(QIcon(),
                         tr("Paternoster"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
    if (::GlobalDefinesEncoder)
    {
        this->list->addSlot(QIcon(),
                         tr("Odometer"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }

    // NFC
    if (::GlobalDefinesNfc)
    {
        this->touchSettingsSystemNFC = new STouchSettingsSystemNFC;
    }

    // Encoder
    if (::GlobalDefinesEncoder)
    {
        this->touchSettingsSystemEncoder = new STouchSettingsSystemEncoder;
    }
}

void STouchSettingsSystem::setupLayout()
{
    QVBoxLayout * subLayout = new QVBoxLayout;
    subLayout->addWidget(this->appBar, 1);
    subLayout->addWidget(this->list->list(), 9);
    subLayout->setSpacing(0);
    subLayout->setContentsMargins(0, 0, 0, 0);

    QWidget  *widget = new QWidget(this);
    widget->setLayout(subLayout);

    this->stackedWidget = new SAnimatedStackedWidget(this);
    this->stackedWidget->addWidget(widget);
    if (::GlobalDefinesNfc)
    {
        this->stackedWidget->addWidget(this->touchSettingsSystemNFC);
    }
    if (::GlobalDefinesEncoder)
    {
        this->stackedWidget->addWidget(this->touchSettingsSystemEncoder);
    }

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->stackedWidget);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchSettingsSystem::setConnect()
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
    connect(this->list, SIGNAL(signalReleased(QString)), this, SLOT(slotList(QString)));

    /* Subwidgets */
    if (::GlobalDefinesNfc)
    {
        connect(this->touchSettingsSystemNFC, &STouchSettingsSystemNFC::signalReturn, this, &STouchSettingsSystem::slotReturn);
    }
    if (::GlobalDefinesEncoder)
    {
        connect(this->touchSettingsSystemEncoder, &STouchSettingsSystemEncoder::signalReturn, this, &STouchSettingsSystem::slotReturn);
    }
}

void STouchSettingsSystem::slotList(const QString &content)
{
    this->basicTimer.start(20 * 60 * 1000, this);

    STouchScreenlock touchScreenlock(this);
    touchScreenlock.setRole(STouchScreenlock::Role::Appropriate);
    touchScreenlock.enableSymbols(true);
    touchScreenlock.exec();

    if (touchScreenlock.isAccepted())
    {
        if (!content.compare(tr("Paternoster")))
        {
            if (::GlobalDefinesNfc)
            {
                this->stackedWidget->slideIn(this->touchSettingsSystemNFC);
            }
        }
        else if (!content.compare(tr("Odometer")))
        {
            if (::GlobalDefinesEncoder)
            {
                this->stackedWidget->slideIn(this->touchSettingsSystemEncoder);
            }
        }
    }
}

void STouchSettingsSystem::slotReturn()
{
    this->basicTimer.stop();
    this->stackedWidget->slideIn(0);
}

void STouchSettingsSystem::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->basicTimer.timerId())
    {
        emit this->slotReturn();
    }
}

void STouchSettingsSystem::retranslateUI()
{
    /* App bar */
    this->appBar->setText(this->m_title);

    /* Swipe list */
    int t_iter = 0;
    if (::GlobalDefinesNfc)
    {
        this->list->setSlot(t_iter++,
                            QIcon(),
                         tr("Paternoster"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
    if (::GlobalDefinesEncoder)
    {
        this->list->setSlot(t_iter++,
                            QIcon(),
                         tr("Odometer"),
                         tr(""),
                         tr(""),
                         QChar(0x276F));
    }
}

void
STouchSettingsSystem::restyleUI()
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
STouchSettingsSystem::changeEvent(QEvent * event)
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
