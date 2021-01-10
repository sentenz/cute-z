#include "SRaisedButton.h"

#include <QEvent>
#include <QDebug>


SRaisedButton::SRaisedButton(QWidget * parent)
    : QtMaterialFlatButton(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SRaisedButton::SRaisedButton(const QString & text,
                             QWidget * parent)
    : QtMaterialFlatButton(parent)
{
    this->setText(text);

    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SRaisedButton::SRaisedButton(const QIcon & icon,
                             QWidget * parent)
    : QtMaterialFlatButton(parent)
{
    this->setIcon(icon);

    this->setupProperty();
    this->setupWidget();
    this->restyleUI();
}

SRaisedButton::SRaisedButton(const QIcon & icon,
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

SRaisedButton::~SRaisedButton()
{
}

void
SRaisedButton::setupProperty()
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void
SRaisedButton::setupWidget()
{
    this->setFontSize(20);
    this->setRippleStyle(Material::PositionedRipple);
    this->setHaloVisible(false);
    this->setUseThemeColors(false);
//    this->setRole(Material::Primary);
//    this->setOverlayStyle(Material::TintedOverlay);
//    this->applyPreset(Material::FlatPreset);
//    this->applyPreset(Material::CheckablePreset);
    this->setBackgroundMode(Qt::OpaqueMode);
    this->setBackgroundColor(this->m_colorContrast);
    this->setForegroundColor(this->m_colorText);

    this->setDisabledMode(false);
}

void
SRaisedButton::setDisabledMode(const bool disabled)
{
    this->m_disabled = disabled;

    if (disabled)
    {
        this->setDisabledBackgroundColor(this->backgroundColor());
        this->setDisabledForegroundColor(this->foregroundColor() == QColor(0, 0, 0) ? ::GlobalColorContrast.lighter(350) : this->foregroundColor().darker());
    }
    else
    {
        this->setDisabledBackgroundColor(this->backgroundColor());
        this->setDisabledForegroundColor(this->foregroundColor());
    }
}


void
SRaisedButton::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
        this->setBackgroundColor(this->m_colorContrast);
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
SRaisedButton::changeEvent(QEvent * event)
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
