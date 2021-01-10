#include "SLinearProgress.h"

#include <QEvent>
#include <QDebug>


SLinearProgress::SLinearProgress(QWidget *parent)
    : QtMaterialProgress(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SLinearProgress::~SLinearProgress()
{
}

void
SLinearProgress::setupProperty()
{
}

void
SLinearProgress::setupWidget()
{
    this->setProgressType(Material::IndeterminateProgress);
    this->setProgressColor(this->m_colorHighlight);
    this->setBackgroundColor(this->m_colorContrast);
}

void
SLinearProgress::restyleUI()
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
        this->setProgressColor(this->m_colorHighlight);
    }
    /* Text color */
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
    this->update();
}

void
SLinearProgress::changeEvent(QEvent * event)
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
