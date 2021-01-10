#include "SNavigationDrawer.h"
#include "../widget/list/SList.h"
#include "../components/qtmaterialdrawer.h"

#include <QtWidgets/QVBoxLayout>
#include <QTimer>
#include <QEvent>
#include <QDebug>


SNavigationDrawer::SNavigationDrawer(QWidget *parent)
    : QDialog(parent),
      m_list(new SList),
      m_drawer(new QtMaterialDrawer)
{
    this->setupProperty();
    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

SNavigationDrawer::~SNavigationDrawer()
{
}


void
SNavigationDrawer::setupProperty()
{
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_OpaquePaintEvent);
}

void
SNavigationDrawer::setupWidget()
{
    /* Swipe list */
    this->m_list->addBanner(QIcon(":/images/sentenz.svg"),
                            tr("Sentenz"),
                            tr("Automation Evolution"));
    this->m_list->divider();
    this->m_list->addLine(QtMaterialTheme::icon("action", "home"),
                          tr("Home"));
    this->m_list->divider();
    this->m_list->addLine(QtMaterialTheme::icon("action", "view_stream"),
                          tr("Panel"));
    this->m_list->addLine(QtMaterialTheme::icon("action", "swap_vertical_circle"),
                          tr("Padernoster"));
    this->m_list->addLine(QtMaterialTheme::icon("action", "donut_small"),
                          tr("Odometer"));
    this->m_list->divider();
    this->m_list->addLine(QtMaterialTheme::icon("action", "settings"),
                          tr("Settings"));
    this->m_list->addLine(QtMaterialTheme::icon("action", "lock"),
                          tr("Screen lock"));
    this->m_list->addLine(QtMaterialTheme::icon("action", "power_settings_new"),
                          tr("Power"));


    /* Navigation drawer */
    this->m_drawer->setParent(this);
    this->m_drawer->setClickOutsideToClose(true);
    this->m_drawer->setOverlayMode(true);
    this->m_drawer->setDrawerWidth(this->width() * 0.7);
    this->m_drawer->setContentsMargins(10, 0, 0, 0);
}

void
SNavigationDrawer::setupLayout()
{
    /* Main layout */
    QVBoxLayout *drawerLayout = new QVBoxLayout(this);
    drawerLayout->addWidget(this->m_list->list());
    drawerLayout->setContentsMargins(0, 0, 0, 0);

    /* Set layout to drawer */
    this->m_drawer->setDrawerLayout(drawerLayout);
}

void
SNavigationDrawer::setConnect()
{
    QObject::connect(this->m_list, SIGNAL(signalReleased(int)), this, SIGNAL(signalReleased(int)));
    QObject::connect(this, &SNavigationDrawer::signalClose, [this]() {
        emit this->m_drawer->closeDrawer();
        QTimer::singleShot(220, this, &SNavigationDrawer::close);
    });
    QObject::connect(this->m_drawer, &QtMaterialDrawer::closedDrawer,  [this]() {
        QTimer::singleShot(220, this, &SNavigationDrawer::close);
    });
}

void
SNavigationDrawer::retranslateUI()
{
    int t_iter = 0;

    /* Swipe list */
    this->m_list->setBanner(t_iter++,
                          QIcon(),
                          "",
                          tr("Automation Evolution"));
    this->m_list->setLine(t_iter++,
                          QIcon(),
                          tr("Home"));
    this->m_list->setLine(t_iter++,
                          QIcon(),
                          tr("Panel"));
    this->m_list->setLine(t_iter++,
                          QIcon(),
                          tr("Padernoster"));
    this->m_list->setLine(t_iter++,
                          QIcon(),
                          tr("Odometer"));
    this->m_list->setLine(t_iter++,
                          QIcon(),
                          tr("Settings"));
    this->m_list->setLine(t_iter++,
                          QIcon(),
                          tr("Screen lock"));
    this->m_list->setLine(t_iter++,
                          QIcon(),
                          tr("Power"));
}

void
SNavigationDrawer::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
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
SNavigationDrawer::changeEvent(QEvent * event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        this->retranslateUI();
        break;

    case QEvent::StyleChange:
        this->restyleUI();
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}

void
SNavigationDrawer::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    this->m_drawer->openDrawer();
}
