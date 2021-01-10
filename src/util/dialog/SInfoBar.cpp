#include "SInfoBar.h"
#include "../widget/label/SLabel.h"
#include "../components/qtmaterialappbar.h"

#include <QtWidgets/QVBoxLayout>
#include <QEvent>


SInfoBar::SInfoBar(QWidget *parent)
    : QWidget(parent),
      m_appBar(new QtMaterialAppBar)
{
    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->restyleUI();
}

SInfoBar::~SInfoBar()
{
    this->clear();
}

void
SInfoBar::setupWidget()
{
    this->m_appBar->setUseThemeColors(false);
    this->m_appBar->setBackgroundColor(this->m_colorContrast);
}

void
SInfoBar::setupLayout()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(this->m_appBar);
    layout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(layout);
}

void
SInfoBar::setConnect()
{
}

void
SInfoBar::addText(const QString &text)
{
    SLabel *label = new SLabel(text);
    label->setTheme(SLabel::Theme::Transparent);
    label->setAlignment(Qt::AlignCenter);
    label->fontSize(20);
//    this->m_label->setFont(QFont("Roboto", 18, QFont::Normal));
    label->setContentsMargins(6, 0, 0, 0);

    this->m_appBar->appBarLayout()->addWidget(label);
    this->m_appBar->appBarLayout()->setAlignment(Qt::AlignCenter);

    this->m_list.push_back(label);
}

void
SInfoBar::setText(const int index, const QString &text)
{
    this->m_list.at(index)->setText(text);
}

void
SInfoBar::clear()
{
    if (!this->m_list.isEmpty())
    {
        this->m_list.erase(this->m_list.begin(), this->m_list.end());
    }
}

void
SInfoBar::restyleUI()
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
SInfoBar::changeEvent(QEvent * event)
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
