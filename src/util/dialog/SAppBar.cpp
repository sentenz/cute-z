#include "SAppBar.h"
#include "../widget/label/SLabel.h"
#include "../widget/button/SIconButton.h"
#include "../components/qtmaterialappbar.h"

#include <QtWidgets/QVBoxLayout>
#include <QButtonGroup>
#include <QEvent>


SAppBar::SAppBar(const QString &text, QWidget *parent)
    : QWidget(parent),
      m_label(new SLabel(text)),
      m_buttonGroup(new QButtonGroup),
      m_appBar(new QtMaterialAppBar)
{
    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

SAppBar::SAppBar(const QIcon &icon, const QString &text, QWidget *parent)
    : QWidget(parent),
      m_icon(icon),
      m_label(new SLabel(text)),
      m_buttonGroup(new QButtonGroup),
      m_appBar(new QtMaterialAppBar)
{
    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->restyleUI();
}

SAppBar::~SAppBar()
{
    foreach(QAbstractButton * button, this->m_buttonGroup->buttons())
    {
        this->m_buttonGroup->removeButton(button);
        delete button;
    }
}

void
SAppBar::setupWidget()
{
    this->m_label->setTheme(SLabel::Theme::Transparent);
    this->m_label->fontSize(20);
//    this->m_label->setFont(QFont("Roboto", 18, QFont::Normal));
    this->m_label->setContentsMargins(6, 0, 0, 0);

    if (this->m_icon.isNull())
    {
    }

    SIconButton *button = new SIconButton(this->m_icon);
    button->setIconSize(QSize(36, 36));
    button->setColor(this->m_colorText);
    button->setFixedWidth(42);

    this->m_appBar->appBarLayout()->addWidget(button);
    this->m_appBar->appBarLayout()->addWidget(this->m_label);
    this->m_appBar->appBarLayout()->addStretch(1);
    this->m_appBar->setUseThemeColors(false);
    this->m_appBar->setBackgroundColor(this->m_colorContrast);

    this->m_buttonGroup->addButton(button, this->m_counter++);
}

void
SAppBar::setupLayout()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(this->m_appBar);
    layout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(layout);
}

void
SAppBar::setConnect()
{
    QObject::connect(this->m_buttonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), [this](const int index) {
        emit this->signalClicked(index);
    });
}

void
SAppBar::addIcon(const QIcon &icon)
{
    SIconButton *button = new SIconButton(icon);
    button->setIconSize(QSize(36, 36));
    button->setColor(this->m_colorText);
    button->setFixedWidth(42);

    this->m_appBar->appBarLayout()->addWidget(button);
    this->m_appBar->appBarLayout()->addSpacing(16);

    this->m_buttonGroup->addButton(button, this->m_counter++);
}

void
SAppBar::setText(const QString &text)
{
    this->m_label->setText(text);
}

void
SAppBar::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
        this->m_appBar->setBackgroundColor(this->m_colorContrast);
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
SAppBar::changeEvent(QEvent * event)
{
    switch (event->type())
    {
    case QEvent::StyleChange:
        this->restyleUI();
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}
