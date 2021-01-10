#include "SSwitch.h"

#include <QEvent>
#include <QDebug>


SSwitch::SSwitch(QWidget *parent)
    : QtMaterialToggle(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SSwitch::~SSwitch()
{
}

void
SSwitch::setupProperty()
{
}

void
SSwitch::setupWidget()
{
    this->setOrientation(Qt::Horizontal);
    this->setUseThemeColors(false);
    this->setActiveColor(this->m_colorContrast);
    this->setInactiveColor(this->m_colorContrast.darker());
    this->setTrackColor(this->m_colorHighlight);
}

void
SSwitch::restyleUI()
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
        this->setActiveColor(this->m_colorContrast);
        this->setInactiveColor(this->m_colorContrast.darker());
    }
    /* Highlight color */
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
        this->setTrackColor(this->m_colorHighlight);
    }
    /* Text color */
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
    this->update();
}

void
SSwitch::changeEvent(QEvent * event)
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
