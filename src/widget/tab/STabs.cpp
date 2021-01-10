#include "STabs.h"

#include <QEvent>
#include <QDebug>


STabs::STabs(QWidget *parent)
    : QtMaterialTabs(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

STabs::~STabs()
{
}

void
STabs::setupProperty()
{
}

void
STabs::setupWidget()
{
    QFont font("Roboto", 20, QFont::Medium);
    font.setCapitalization(QFont::AllUppercase);
    this->setFont(font);
    this->setBackgroundColor(this->m_colorContrast);
    this->setTextColor(this->m_colorText);
    this->setInkColor(this->m_colorHighlight);
}

void
STabs::restyleUI()
{
    /* Base color */
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
    }
    /* Contrast color */
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
        this->setBackgroundColor(this->m_colorContrast);
    }
    /* Highlight color */
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
    /* Text color */
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
        this->setTextColor(this->m_colorText);
    }
    this->update();
}

void
STabs::changeEvent(QEvent * event)
{
    switch (event->type())
    {
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
