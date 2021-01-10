#include "STouchHome.h"
#include "../widget/list/SList.h"
#include "../util/dialog/SAppBar.h"

#include <QApplication>
#include <QStackedWidget>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>


STouchHome::STouchHome(QWidget *parent)
    : QDialog(parent)
{
    this->setObjectName("STouchHome");
    /// Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_AcceptTouchEvents);

    this->setupWidget();
    this->setConnect();
}

STouchHome::~STouchHome()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void STouchHome::setupWidget()
{
    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "menu"), this->m_title, this);
    this->appBar->addIcon(QtMaterialTheme::icon("navigation", "more_vert"));

    /* Swipe list */
    this->list = new SList;
    this->list->addBox(QIcon(":/images/office_green.svg"),
                    tr("Control Panel"),
                    tr("Recursive search is disabled by passing FALSE as the third argument."),
                       "",
                       "");
    this->list->spacer();
    this->list->addBox(QIcon(":/images/codelabs_green.svg"),
                    tr("Paternoster"),
                    tr("Description Thanks for reply. I appreciate it if you verify my edit.thanks agai."),
                       "",
                       "");
    this->list->spacer();
    this->list->addBox(QIcon(":/images/sandbox_green.svg"),
                    tr("Odometer"),
                    tr("This returns only the descendants that inherit QListBox."),
                       "",
                       "");

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->appBar, 1);
    mainLayout->addWidget(this->list->list(), 9);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchHome::setConnect()
{
    /* App bar */
    connect(this->appBar,&SAppBar::signalClicked, [this] (int n) {
        switch (n) {
        case 0:
            emit this->signalDrawer();
            break;

        case 1:
            emit this->signalOption();
            break;

        default:
            break;
        }
    });
    /* Swipe list */
    connect(this->list, SIGNAL(signalReleased(int)), this, SIGNAL(signalReleased(int)));
}

void STouchHome::retranslateUI()
{
    /* App bar */
    this->appBar->setText(this->m_title);

    // Swipe list
    int t_iter = 0;
    this->list->setBox(t_iter++,
                       QIcon(),
                    tr("Control Panel"),
                    tr("Recursive search is disabled by passing FALSE as the third argument."),
                       "",
                       "");
    this->list->setBox(t_iter++,
                       QIcon(),
                    tr("Paternoster"),
                    tr("Description Thanks for reply. I appreciate it if you verify my edit.thanks agai."),
                       "",
                       "");
    this->list->setBox(t_iter++,
                       QIcon(),
                    tr("Odometer"),
                    tr("This returns only the descendants that inherit QListBox."),
                       "",
                       "");
}

void
STouchHome::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    }
}

void
STouchHome::changeEvent(QEvent * event)
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
