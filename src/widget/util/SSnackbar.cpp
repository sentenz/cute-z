#include "SSnackbar.h"

#include <QEvent>
#include <QDebug>


SSnackbar::SSnackbar(QWidget *parent)
    : QtMaterialSnackbar(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SSnackbar::~SSnackbar()
{
}

void
SSnackbar::setupProperty()
{
}

void
SSnackbar::setupWidget()
{
//    QFont font("Roboto", 20, QFont::Medium);
//    font.setCapitalization(QFont::AllUppercase);
//    this->setFont(font);
    this->setUseThemeColors(false);
    this->setBackgroundColor(this->m_colorContrast);
    this->setTextColor(this->m_colorText);
}

void
SSnackbar::restyleUI()
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
SSnackbar::changeEvent(QEvent * event)
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
