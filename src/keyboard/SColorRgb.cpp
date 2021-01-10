#include "SColorRgb.h"
#include "../widget/label/SLabel.h"
#include "../widget/slider/SSlider.h"


#include <QApplication>
#include <QVBoxLayout>
#include <QString>


SColorRgb::SColorRgb(QWidget * parent)
    : QDialog(parent)
{
    /// Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

SColorRgb::~SColorRgb()
{
}

void
SColorRgb::setupWidget()
{    
    // Labels
    this->labelR = new SLabel(tr("R"), this);
    this->labelR->setTheme(SLabel::Theme::Base);

    this->labelG = new SLabel(tr("G"), this);
    this->labelG->setTheme(SLabel::Theme::Base);

    this->labelB = new SLabel(tr("B"), this);
    this->labelB->setTheme(SLabel::Theme::Base);

    // Sliders
    this->sliderR = new SSlider(this);
    this->sliderR->setRange(0, 255);

    this->sliderG = new SSlider(this);
    this->sliderG->setRange(0, 255);

    this->sliderB = new SSlider(this);
    this->sliderB->setRange(0, 255);
}

void
SColorRgb::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch(1);
    mainLayout->addWidget(this->labelR);
    mainLayout->addWidget(this->sliderR);
    mainLayout->addStretch(1);
    mainLayout->addWidget(this->labelG);
    mainLayout->addWidget(this->sliderG);
    mainLayout->addStretch(1);
    mainLayout->addWidget(this->labelB);
    mainLayout->addWidget(this->sliderB);
    mainLayout->addStretch(1);

    this->setLayout(mainLayout);
}

void
SColorRgb::setConnect()
{
    connect(this->sliderR, &SSlider::valueChanged, this, &SColorRgb::slotIndexR);
    connect(this->sliderG, &SSlider::valueChanged, this, &SColorRgb::slotIndexG);
    connect(this->sliderB, &SSlider::valueChanged, this, &SColorRgb::slotIndexB);
}

QColor
SColorRgb::getColor() const
{
    return this->m_color;
}

void
SColorRgb::setColor(const QColor color)
{
    this->m_color = color;
    this->sliderR->setValue(color.red());
    this->sliderG->setValue(color.green());
    this->sliderB->setValue(color.blue());

    this->signalColorChanged(color);
}

void
SColorRgb::slotColorChanged(const QColor &color)
{
    this->m_color = color;
    this->setColor(color);
}

void
SColorRgb::slotIndexR(const int index)
{
    this->m_color.setRed(index);
    emit this->signalColorChanged(this->m_color);
}

void
SColorRgb::slotIndexG(const int index)
{
    this->m_color.setGreen(index);
    emit this->signalColorChanged(this->m_color);
}

void
SColorRgb::slotIndexB(const int index)
{
    this->m_color.setBlue(index);
    emit this->signalColorChanged(this->m_color);
}

void
SColorRgb::retranslateUI()
{
    this->labelR->setText(tr("R"));
    this->labelG->setText(tr("G"));
    this->labelB->setText(tr("B"));
}

void
SColorRgb::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
}

void
SColorRgb::changeEvent(QEvent* event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        this->retranslateUI();

    case QEvent::StyleChange:
        this->restyleUI();
        break;

        break;
    case QEvent::LocaleChange:

        break;
    default:
        break;
    }

    QWidget::changeEvent(event);
}
