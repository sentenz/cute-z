#include "SCheckBox.h"

#include <QEvent>
#include <QDebug>


SCheckBox::SCheckBox(QWidget *parent)
    : QtMaterialCheckBox(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SCheckBox::~SCheckBox()
{
}

void
SCheckBox::setupProperty()
{
}

void
SCheckBox::setupWidget()
{
    this->setUseThemeColors(false);
    this->setLabelPosition(QtMaterialCheckable::LabelPositionRight);
    this->setTextColor(this->m_colorText);
    this->setCheckedColor(this->m_colorHighlight);
    this->setUncheckedColor(this->m_colorText);
    this->setDisabledColor(this->m_colorContrast.darker());
}

void
SCheckBox::restyleUI()
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
        this->setDisabledColor(this->m_colorContrast.darker());
    }
    /* Highlight color */
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
        this->setCheckedColor(this->m_colorHighlight);
    }
    /* Text color */
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
        this->setUncheckedColor(this->m_colorText);
        this->setTextColor(this->m_colorText);
    }
    this->update();
}

void
SCheckBox::changeEvent(QEvent * event)
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
