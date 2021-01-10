#include "STouchTools.h"
#include "../keyboard/STouchCalculator.h"
#include "../widget/layout/SHScrollArea.h"
#include "../widget/label/SLabel.h"
#include "../widget/stacked/SAnimatedStackedWidget.h"

#include <QApplication>
#include <QTimer>
#include <QPushButton>
#include <QToolButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIcon>
#include <QPropertyAnimation>
#include <QDebug>


STouchTools::STouchTools(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

STouchTools::~STouchTools()
{
    if (this->header != nullptr)
    {
        delete this->header;
        this->header = nullptr;
    }
    if (this->touchCalculator != nullptr)
    {
        delete this->touchCalculator;
        this->touchCalculator = nullptr;
    }
}

void STouchTools::setupWidget()
{
    // Header
    this->header = new SLabel;
    this->header->header(tr("Calculator"), 0x0276E);

    // Calculator
    this->touchCalculator = new STouchCalculator(this);
    this->touchCalculator->setMode("math");

    // Stack widgets
    this->stackedWidget = new SAnimatedStackedWidget(this);
    stackedWidget->setCurrentIndex(0);
    stackedWidget->addWidget(this->touchCalculator);
}

void STouchTools::setupLayout()
{
    // Buttons
    QIcon icon0;
    icon0.addPixmap(QPixmap(":/images/calculator.png"), QIcon::Normal, QIcon::Off);
    icon0.addPixmap(QPixmap(":/images/calculator.png"), QIcon::Active, QIcon::On);
    QToolButton *buttonLevel0 = new QToolButton;
    buttonLevel0->setIcon(icon0);
    buttonLevel0->setIconSize(QSize(this->width()/8, this->height()/8));
    //buttonLevel0->setText(tr("Calculater"));
    //buttonLevel0->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    buttonLevel0->setStyleSheet(this->formStyleSheetString("tool"));
    buttonLevel0->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    buttonLevel0->setCheckable(true);
    buttonLevel0->setChecked(true);

    /*
    QIcon icon1;
    icon1.addPixmap(QPixmap(":/images/screen_1.svg"), QIcon::Normal, QIcon::Off);
    icon1.addPixmap(QPixmap(":/images/screen_2.svg"), QIcon::Active, QIcon::On);
    QToolButton *buttonLevel1 = new QToolButton(this);
    buttonLevel1->setIcon(icon1);
    buttonLevel1->setIconSize(QSize(this->width()/8, this->height()/8));
    buttonLevel1->setText(tr("Temperature"));
    buttonLevel1->setStyleSheet(formStyleSheetString("tool"));
    buttonLevel1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    buttonLevel1->setCheckable(true);

    QIcon icon2;
    icon2.addPixmap(QPixmap(":/images/screen_1.svg"), QIcon::Normal, QIcon::Off);
    icon2.addPixmap(QPixmap(":/images/screen_2.svg"), QIcon::Active, QIcon::On);
    QToolButton *buttonLevel2 = new QToolButton(this);
    buttonLevel2->setIcon(icon2);
    buttonLevel2->setIconSize(QSize(this->width()/8, this->height()/8));
    buttonLevel2->setText(tr("Inputs"));
    buttonLevel2->setStyleSheet(formStyleSheetString("tool"));
    buttonLevel2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //buttonLevel2->setPopupMode(QToolButton::InstantPopup);
    buttonLevel2->setCheckable(true);
    */

    // Collect buutons
    int iter = 0;
    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->addButton(buttonLevel0);
    this->buttonGroup->setId(buttonLevel0, iter++);
    this->buttonGroup->setExclusive(true);

    // Layout Button
    QHBoxLayout * buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(buttonLevel0);
    buttonLayout->setSpacing(0);
    buttonLayout->setMargin(0);
    buttonLayout->setContentsMargins(0,0,0,0);
    // Widget
    QWidget * widget = new QWidget;
    widget->setLayout(buttonLayout);
    // Scroll Area
    SHScrollArea * scrollArea = new SHScrollArea(this);
    scrollArea->setWidget(widget);

    if (buttonLayout->count() <= 1)
    {
        scrollArea->setVisible(false);
    }

    // Main Layout
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addWidget(this->stackedWidget, 10);
    mainLayout->addWidget(scrollArea, 0, Qt::AlignBottom);
    mainLayout->setSpacing(0);
    //mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0,0,0,0);

    this->setLayout(mainLayout);
}

void STouchTools::setConnect()
{
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
    connect(this->buttonGroup, SIGNAL(buttonClicked(int)), this->stackedWidget, SLOT(slideIn(int)));
}

QString STouchTools::formStyleSheetString(const QString &style)
{
    QString styleButton = "";

    if (!style.compare("tool"))
    {
        styleButton =
        "\
            QToolButton { padding-top: 5px; font: 12pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; background-color: transparent; border: none; } \
            QToolButton:checked { padding-top: 5px; font: 12pt " + ::GlobalFont + "; color: " + ::GlobalColorHighlight.name() + "; background-color: transparent; border: none; } \
        ";
    }
    else if (!style.compare("button"))
    {
        styleButton =
        "\
            QPushButton { font: 30pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; background: transparent; border: none; } \
            QPushButton:pressed { font: 30pt " + ::GlobalFont + "; color: " + ::GlobalColorHighlight.name() + "; background: transparent; border: none; } \
        ";

    }

     /*
    const QString styleButton
    ("\
        QToolButton { qproperty-icon: url(:/images/" + icon + "_1.svg); icon-size: 80px 80px; padding-top: 10px; font: 12pt; color: rgb(155,155,155); background-color: transparent; border: none; } \
        QToolButton:default { qproperty-icon: url(:/images/" + icon + "_1.svg); icon-size: 80px 80px; padding-top: 10px; font: 12pt; color: rgb(155,155,155); background-color: transparent; border: none; } \
        QToolButton:checked { qproperty-icon: url(:/images/" + icon + "_2.svg); icon-size: 80px 80px; padding-top: 10px; font: 12pt; color: #0080F0; background-color: transparent; border: none; } \
    ");
     */

    return styleButton;
}

void STouchTools::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Calculator"));

    this->buttonGroup->button(t_iter++)->setText(tr("Calculater"));
}

void
STouchTools::restyleUI()
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
STouchTools::changeEvent(QEvent * event)
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
