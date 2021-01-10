#include "SIconButton.h"

#include <QEvent>
#include <QDebug>


SIconButton::SIconButton(const QIcon &icon, QWidget *parent)
    : QtMaterialIconButton(icon, parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SIconButton::~SIconButton()
{
}

void
SIconButton::setupProperty()
{
}

void
SIconButton::setupWidget()
{
    this->setColor(this->m_colorText);
}

void
SIconButton::restyleUI()
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
        this->setColor(this->m_colorText);
    }
}

void
SIconButton::changeEvent(QEvent * event)
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
