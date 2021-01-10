#include "SSlider.h"

#include <QEvent>
#include <QDebug>


SSlider::SSlider(QWidget *parent)
    : QtMaterialSlider(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SSlider::~SSlider()
{
}

void
SSlider::setupProperty()
{
}

void
SSlider::setupWidget()
{
    this->setOrientation(Qt::Horizontal);
    this->setUseThemeColors(false);
    this->setThumbColor(this->m_colorHighlight);
    this->setTrackColor(this->m_colorContrast);
}

void
SSlider::restyleUI()
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
        this->setThumbColor(this->m_colorHighlight);
    }
    /* Highlight color */
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
        this->setTrackColor(this->m_colorContrast);
    }
    /* Text color */
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
    this->update();
}

void
SSlider::changeEvent(QEvent * event)
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
