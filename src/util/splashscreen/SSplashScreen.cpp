#include "SSplashScreen.h"
#include "../widget/button/SIconButton.h"

#include <QApplication>
#include <QIcon>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QRect>
#include <QColor>
#include <QPaintEvent>
#include <QVBoxLayout>


SSplashScreen::SSplashScreen(QWidget *parent)
    : QSplashScreen(parent),
      m_movie(""),
      m_pixmap("")
{
    this->setupProperty();
    this->setupWidget();
    this->setConnect();
    this->restyleUI();
}

SSplashScreen::SSplashScreen(QWidget *parent, const QPixmap &pixmap)
    : QSplashScreen(parent),
      m_pixmap(pixmap)
{
    this->setupProperty();
    this->setupWidget();
    this->setConnect();
    this->restyleUI();
}

SSplashScreen::SSplashScreen(QWidget *parent, const QString &fileName)
    : QSplashScreen(parent),
      m_movie(fileName)
{
    this->setupProperty();
    this->setupWidget();
    this->setConnect();
    this->restyleUI();
}

void SSplashScreen::setupProperty()
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
    this->setStyleSheet("background: " + ::GlobalColorBase.name() + ";");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::SplashScreen);
}

void SSplashScreen::setupWidget()
{
    if (this->m_movie.isValid())
    {
        this->m_movie.start();
    }
    else if (this->m_pixmap.isNull())
    {
        this->m_icon = new SIconButton(QIcon(":/images/sentenz.svg"), this);
        this->m_icon->setIconSize(QSize(this->size()));
        this->m_icon->setColor(::GlobalColorCustomText);
        this->m_icon->setAttribute(Qt::WA_TransparentForMouseEvents);

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addStretch();
        mainLayout->addWidget(this->m_icon);
        mainLayout->addStretch();

        this->setLayout(mainLayout);
    }
}

void SSplashScreen::setConnect()
{
    if (this->m_movie.isValid())
    {
        connect(&this->m_movie, SIGNAL(updated(QRect)), this, SLOT(slotFrameUpdate()));
    }
}

void SSplashScreen::slotFrameUpdate()
{
    this->setPixmap(this->m_movie.currentPixmap());
    update();
}

void SSplashScreen::clear()
{
    QPixmap pixmap(::GlobalWindowSize);
    pixmap.fill(::GlobalColorBase);

    this->m_pixmap = pixmap;
    this->update();
}

void SSplashScreen::paintEvent(QPaintEvent *event)
{
    if (this->m_movie.isValid())
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
        painter.drawPixmap(this->m_movie.frameRect(), this->m_movie.currentPixmap());
        painter.end();
    }
    else if (!this->m_pixmap.isNull())
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
        QIcon(this->m_pixmap.scaledToWidth(::GlobalWindowSize.width(), Qt::SmoothTransformation)).paint(&painter, event->rect());
        painter.end();
    }
}

void SSplashScreen::drawContents(QPainter *painter)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, true);
    painter->setBackgroundMode (Qt::OpaqueMode);    // Qt::TransparentMode
    painter->setBrush(::GlobalColorCustomBase);
}

void
SSplashScreen::restyleUI()
{
    this->setStyleSheet("background-color: " + ::GlobalColorCustomBase.name() + ";");
}

void
SSplashScreen::changeEvent(QEvent* event)
{
    switch(event->type())
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
