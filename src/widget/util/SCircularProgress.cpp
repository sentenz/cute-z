#include "SCircularProgress.h"

#include <QEvent>
#include <QDebug>


SCircularProgress::SCircularProgress(QWidget *parent)
    : QtMaterialCircularProgress(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SCircularProgress::~SCircularProgress()
{
}

void
SCircularProgress::setupProperty()
{
}

void
SCircularProgress::setupWidget()
{
    this->setProgressType(Material::IndeterminateProgress);
    this->setColor(this->m_colorHighlight);
}

void
SCircularProgress::restyleUI()
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
        this->setColor(this->m_colorHighlight);
    }
    /* Text color */
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
    this->update();
}

void
SCircularProgress::changeEvent(QEvent * event)
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
