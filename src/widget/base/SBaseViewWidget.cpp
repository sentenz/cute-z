#include "SBaseView.h"
#include "../widget/label/SLabel.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QEvent>


SBaseView::SBaseView(QWidget * parent) :
    QDialog(parent)
{
    this->setObjectName("SBaseView");
    this->setupProperty();
    this->restyleUI();
}

SBaseView::~SBaseView()
{
}

void
SBaseView::setupProperty()
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
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();
    this->setFocus();
}

void
SBaseView::closeable(const bool closeable)
{
    this->m_closeable = closeable;
}

bool
SBaseView::closeable() const
{
    return this->m_closeable;
}

void
SBaseView::restyleUI()
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
SBaseView::changeEvent(QEvent * event)
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
