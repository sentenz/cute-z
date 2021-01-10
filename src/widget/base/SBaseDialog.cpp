#include "SBaseDialog.h"
#include "../widget/label/SLabel.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QEvent>
#include <QShowEvent>
#include <QFrame>
#include <QRect>
#include <QPropertyAnimation>
#include <QDebug>


SBaseDialog::SBaseDialog(QWidget * parent) :
    QDialog(parent)
{
    this->setupProperty();
    this->restyleUI();
}

SBaseDialog::~SBaseDialog()
{
}

void
SBaseDialog::setupProperty()
{
    /* Window size for developing and emulating. */
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();
    this->setFocus();

    this->setObjectName("SBaseDialog");
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setContentsMargins(0, 0, 0, 0);
}

void
SBaseDialog::closeable(const bool boolean)
{
    this->m_closeable = boolean;
}

bool
SBaseDialog::closeable() const
{
    return this->m_closeable;
}

void
SBaseDialog::restyleUI()
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
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
}

void
SBaseDialog::changeEvent(QEvent * event)
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

void
SBaseDialog::showEvent(QShowEvent * event)
{
    QWidget::showEvent(event);
}

void
SBaseDialog::closeEvent(QCloseEvent * event)
{
    QWidget::closeEvent(event);
}
