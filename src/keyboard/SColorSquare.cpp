#include "SColorSquare.h"

#include <QMouseEvent>
#include <QPainter>
#include <QColor>


const int defaut_diameter = 15;

SColorSquare::SColorSquare(QWidget *parent)
    : QWidget(parent),
      m_cursor_diameter(defaut_diameter),
      m_cursor_position(rect().center()),
      m_tracking(false)
{
    this->setAttribute(Qt::WA_OpaquePaintEvent);
    this->setMouseTracking(true);
}

SColorSquare::SColorSquare(const QColor &color, QWidget *parent)
    : QWidget(parent), m_main_color(color),
      m_cursor_diameter(defaut_diameter),
      m_cursor_position(rect().center()),
      m_tracking(false)
{
    this->setAttribute(Qt::WA_OpaquePaintEvent);
    this->setMouseTracking(true);
    this->updateGradientImage();
}

SColorSquare::~SColorSquare()
{
}

QColor SColorSquare::getColor() const
{
    return this->m_main_color;
}

QColor SColorSquare::selectedColor() const
{
    return this->m_selected_color;
}

QPen SColorSquare::cursorPen() const
{
    return this->m_cursor_pen;
}

int SColorSquare::cursorDiameter() const
{
    return this->m_cursor_diameter;
}

void SColorSquare::mouseMoveEvent(QMouseEvent *event)
{
    if (this->m_tracking && rect().contains(event->pos()))
    {
        this->m_cursor_position = event->pos();
        this->updateSelectedColor();
    }
}

void SColorSquare::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->m_tracking = true;
        this->m_cursor_position = event->pos();
        this->updateSelectedColor();
    }
}

void SColorSquare::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->m_tracking = false;
        this->m_cursor_position = event->pos();
        this->updateSelectedColor();
    }
}

void SColorSquare::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.drawImage(this->rect(), this->m_gradient_image);

    this->m_cursor_pen.setColor((this->m_cursor_position.y() > (this->height()/3)) ? Qt::white : Qt::black);
    this->m_cursor_pen.setWidth(3);
    painter.setPen(this->m_cursor_pen);
    painter.setBrush(QBrush(Qt::NoBrush));
    painter.drawEllipse(this->m_cursor_position, this->m_cursor_diameter, this->m_cursor_diameter);
}

void SColorSquare::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    this->m_cursor_position = this->rect().center();
    this->updateGradientImage();
}

void SColorSquare::setMode(const int mode)
{
    this->m_mode = mode;
    this->updateGradientImage();
}

void SColorSquare::setColor(const QColor &color)
{
    this->m_main_color = color;
    this->updateGradientImage();
}

void SColorSquare::setCursorPen(const QPen &pen)
{
    this->m_cursor_pen = pen;
    this->update();
}

void SColorSquare::setCursorDiameter(const int diameter)
{
    this->m_cursor_diameter = diameter;
    this->update();
}

void SColorSquare::updateGradientImage()
{
    switch (this->m_mode)
    {
    case 1: // Color Conical Gradient
    {
        QPixmap pixmap(size());
        QPainter painter(&pixmap);
        painter.setRenderHints(QPainter::Antialiasing);
        painter.setPen(QPen(Qt::NoPen));

        QConicalGradient conicalGradient(this->rect().center(), 0);
        conicalGradient.setColorAt(0.0, QColor(255, 0, 0));
        conicalGradient.setColorAt(0.1, QColor(255, 255, 0));
        conicalGradient.setColorAt(0.3, QColor(0, 255, 0));
        conicalGradient.setColorAt(0.5, QColor(0, 255, 255));
        conicalGradient.setColorAt(0.7, QColor(0, 0, 255));
        conicalGradient.setColorAt(0.9, QColor(255, 0, 255));
        conicalGradient.setColorAt(1.0, QColor(255, 0, 0));

        painter.setBrush(QBrush(conicalGradient));
        painter.drawRect(this->rect());

        this->m_gradient_image = pixmap.toImage();
    }
        break;

    case 2: // Gray Conical Gradient
    {
        QPixmap pixmap(size());
        QPainter painter(&pixmap);
        painter.setRenderHints(QPainter::Antialiasing);
        painter.setPen(QPen(Qt::NoPen));

        QConicalGradient conicalGradient(this->rect().center(), 90);
        conicalGradient.setColorAt(0.000, QColor("#F0F0F0"));
        conicalGradient.setColorAt(0.500, QColor("#000000"));
        conicalGradient.setColorAt(1.000, QColor("#F0F0F0"));

        painter.setBrush(QBrush(conicalGradient));
        painter.drawRect(this->rect());

        this->m_gradient_image = pixmap.toImage();
    }
        break;

//    case 0: // HSV Color Linear Gradient
//    {
//        if (m_gradient_image.rect() != rect())
//        {
//            m_gradient_image = QImage(size(), QImage::Format_RGB32);
//        }

//        float h = m_main_color.hsvHueF();
//        for (int s = 0; s < width(); ++s)
//        {
//            for (int v = 0; v < height(); ++v)
//            {
//                QColor color = QColor::fromHsvF(h, 1.0 * s / (width() - 1), 1.0 - (1.0 * v / (height() - 1)));
//                m_gradient_image.setPixel(s, v, color.rgb());
//            }
//        }
//    }
//        break;

//    case 1: // Gray Linear Gradient
//    {
//        QPixmap pixmap(size());
//        QPainter painter(&pixmap);
//        painter.setPen(QPen(Qt::NoPen));

//        QLinearGradient h_gradient(QPointF(1.0, 0.0), QPointF(width(), 0.0));
//        h_gradient.setColorAt(0, Qt::white);
//        h_gradient.setColorAt(1, m_main_color);
//        painter.setBrush(QBrush(h_gradient));
//        painter.drawRect(rect());

//        QLinearGradient v_gradient(QPointF(1.0, 0.0), QPointF(0.0, height()));
//        v_gradient.setColorAt(0, Qt::transparent);
//        v_gradient.setColorAt(1, Qt::black);
//        painter.setBrush(QBrush(v_gradient));
//        painter.drawRect(rect());

//        m_gradient_image = pixmap.toImage();
//    }
//        break;

    default:
        break;
    }

    this->updateSelectedColor();
}

void SColorSquare::updateSelectedColor()
{
    this->m_selected_color = this->m_gradient_image.pixel(m_cursor_position);
    emit this->colorSelected(this->m_selected_color);
    this->update();
}
