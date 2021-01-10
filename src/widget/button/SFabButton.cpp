#include "SFabButton.h"

#include <QEvent>
#include <QDebug>


SFabButton::SFabButton(const QIcon &icon, QWidget *parent)
    : QtMaterialFloatingActionButton(icon, parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SFabButton::~SFabButton()
{
}

void
SFabButton::setupProperty()
{
//    this->setFocus();
//    this->setFocusPolicy(Qt::StrongFocus);
//    this->setAutoDefault(true);
//    this->setDefault(true);
}

void
SFabButton::setupWidget()
{
    this->setCorner(Qt::BottomRightCorner);
    this->setRippleStyle(Material::CenteredRipple);
    this->setUseThemeColors(false);
    this->setBackgroundColor(this->m_colorHighlight);
    this->setForegroundColor(this->m_colorText);
    this->setDisabledBackgroundColor(this->m_colorContrast);
    this->setDisabledForegroundColor(this->m_colorText.darker());
//    this->m_fab->setXOffset(ui->horizontalOffsetSpinBox->value());
//    this->m_fab->setYOffset(ui->verticalOffsetSpinBox->value());
//    this->m_fab->setMini(ui->miniCheckBox->isChecked());
}

void
SFabButton::restyleUI()
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
        this->setDisabledBackgroundColor(this->m_colorContrast);
    }
    /* Highlight color */
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
        this->setBackgroundColor(this->m_colorHighlight);
    }
    /* Text color */
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
        this->setForegroundColor(this->m_colorText);
        this->setDisabledForegroundColor(this->m_colorText.darker());
    }
    this->update();
}

void
SFabButton::changeEvent(QEvent * event)
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
