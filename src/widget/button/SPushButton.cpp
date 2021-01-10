#include "SPushButton.h"

#include <QEvent>
#include <QDebug>


SPushButton::SPushButton(QWidget * parent)
    : QtMaterialFlatButton(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SPushButton::SPushButton(const QString & text,
                         QWidget * parent)
    : QtMaterialFlatButton(parent)
{
    this->setText(text);

    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SPushButton::SPushButton(const QIcon & icon,
                         QWidget * parent)
    : QtMaterialFlatButton(parent)
{
    this->setIcon(icon);

    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SPushButton::SPushButton(const QIcon & icon,
                         const QString & text,
                         QWidget * parent)
    : QtMaterialFlatButton(parent)
{
    this->setText(text);
    this->setIcon(icon);

    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SPushButton::~SPushButton()
{
}

void
SPushButton::setupProperty()
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void
SPushButton::setupWidget()
{
    this->setFontSize(20);
    this->setRippleStyle(Material::PositionedRipple);
    this->setHaloVisible(false);
    this->setUseThemeColors(false);
//    this->setRole(Material::Primary);
//    this->setOverlayStyle(Material::TintedOverlay);
//    this->applyPreset(Material::FlatPreset);
//    this->applyPreset(Material::CheckablePreset);
    this->setBackgroundMode(Qt::TransparentMode);
    this->setBackgroundColor(this->m_colorContrast);
    this->setForegroundColor(this->m_colorText);

    this->setDisabledMode(false);
}

void
SPushButton::setDisabledMode(const bool disabled)
{
    this->m_disabled = disabled;

    if (disabled)
    {
        this->setDisabledBackgroundColor(this->backgroundColor());
        this->setDisabledForegroundColor(this->m_colorContrast);
    }
    else
    {
        this->setDisabledBackgroundColor(this->backgroundColor());
        this->setDisabledForegroundColor(this->m_colorBase);
    }
}


void
SPushButton::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setDisabledForegroundColor(this->m_colorBase);
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
        if (this->backgroundMode() == Qt::OpaqueMode)
        {
            this->setBackgroundColor(this->m_colorContrast);
        }
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
        this->setForegroundColor(this->m_colorText);
    }
    this->setDisabledMode(this->m_disabled);

    this->update();
}

void
SPushButton::changeEvent(QEvent * event)
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
