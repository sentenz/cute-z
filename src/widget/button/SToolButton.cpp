#include "SToolButton.h"

#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QTimeLine>
#include <QPainter>
#include <QEvent>
#include <QDebug>


SToolButton::SToolButton(QWidget * parent) : QToolButton(parent)
{
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setCheckable(true);

    this->setupLayout();
    this->setTheme(Style::None);
    this->restyleUI();
}

SToolButton::~SToolButton()
{
}

void
SToolButton::setupLayout()
{
    this->m_timeLine = new QTimeLine(500, this);
    this->m_timeLine->setFrameRange(0, 100);
    this->m_frameFactor = 1.0 / 100.0;
}

void
SToolButton::setConnect()
{
    connect(this->m_timeLine, SIGNAL(frameChanged(int)), this, SLOT(update()));
}

void
SToolButton::shape(const Shape &shape)
{
    this->m_shape = shape;
    this->update();
}

void
SToolButton::setImage(const QString &image, const double scale)
{
    this->m_image = image;
    this->m_scale = qBound(0.0, scale, 1.0);
    this->updateIcon();
    this->update();
}

void
SToolButton::setTheme(const Style &style)
{
    this->m_style = style;
    this->setStyleSheet(this->formStyleSheet(style));
}


QPixmap
SToolButton::changePixmapColor(const QString &source, const QColor &color)
{
    QImage srcImage(source);
    QImage dstImage(srcImage.size(), QImage::Format_ARGB32_Premultiplied);
    dstImage.fill(color);
    QPainter painter(&dstImage);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(srcImage.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.fillRect(srcImage.rect(), color);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.drawImage(0, 0, srcImage);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.fillRect(srcImage.rect(), Qt::transparent);

    return QPixmap::fromImage(dstImage);
}

//void
//SToolButton::mouseMoveEvent(QMouseEvent *event)
//{
//    QToolButton::mouseMoveEvent(event);
//}

void
SToolButton::mousePressEvent(QMouseEvent *event)
{
    if (this->m_shape != Shape::None && this->m_timeLine->state() == QTimeLine::NotRunning)
    {
        this->m_timeLine->start();
    }

    QToolButton::mousePressEvent(event);
}

void
SToolButton::mouseReleaseEvent(QMouseEvent *event)
{
    QToolButton::mouseReleaseEvent(event);
}

void
SToolButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    this->paintItem(&painter, event->rect());
    painter.setBrush(Qt::NoBrush);
    painter.end();

    QToolButton::paintEvent(event);
}

void
SToolButton::paintItem(QPainter* painter,
                     const QRect &rect)
{
    this->paintPixmap(painter, rect);
    this->paintShape(painter, rect);
}

void
SToolButton::paintShape(QPainter * painter,
                        const QRect & rect)
{
    switch(this->m_shape)
    {
    case Shape::Base:
    {
        painter->fillRect(rect, m_colorBase);
    }
        break;

    case Shape::Contrast:
    {
        painter->fillRect(rect, m_colorContrast);
    }
        break;

    case Shape::ColorHSV:
    {
        QConicalGradient conical(this->rect().center(), 0);
        conical.setColorAt(0.0, QColor(255, 0, 0));
        conical.setColorAt(0.1, QColor(255, 255, 0));
        conical.setColorAt(0.3, QColor(0, 255, 0));
        conical.setColorAt(0.5, QColor(0, 255, 255));
        conical.setColorAt(0.7, QColor(0, 0, 255));
        conical.setColorAt(0.9, QColor(255, 0, 255));
        conical.setColorAt(1.0, QColor(255, 0, 0));

        painter->setPen(Qt::transparent);
        painter->setBrush(conical);
        painter->drawEllipse(this->rect().center(), this->rect().center().ry(), this->rect().center().ry());
        if (this->isChecked())
        {
            painter->setBrush(Qt::NoBrush);
            painter->setPen(QPen(this->m_colorText,  4));
            painter->drawEllipse(this->rect().center(), this->rect().center().ry() - 2, this->rect().center().ry() - 2);
        }
    }
        break;

    case Shape::ColorRGB:
    {
        QConicalGradient conical(this->rect().center(), 0);
        conical.setAngle(-30);
        conical.setColorAt(0, Qt::red);
        conical.setColorAt(0.333, Qt::red);
        conical.setColorAt(0.334, Qt::green);
        conical.setColorAt(0.666, Qt::green);
        conical.setColorAt(0.667, Qt::blue);
        conical.setColorAt(1, Qt::blue);

        painter->setPen(Qt::transparent);
        painter->setBrush(conical);
        painter->drawEllipse(this->rect().center(), this->rect().center().ry(), this->rect().center().ry());
        if (this->isChecked())
        {
            painter->setBrush(Qt::NoBrush);
            painter->setPen(QPen(this->m_colorText,  4));
            painter->drawEllipse(this->rect().center(), this->rect().center().ry() - 2, this->rect().center().ry() - 2);
        }
    }
        break;

    case Shape::ColorSW:
    {
        QConicalGradient conical(this->rect().center(), 90);
        conical.setColorAt(0.000, QColor("#F0F0F0"));
        conical.setColorAt(0.500, QColor("#000000"));
        conical.setColorAt(1.000, QColor("#F0F0F0"));

        painter->setPen(Qt::transparent);
        painter->setBrush(conical);
        painter->drawEllipse(this->rect().center(), this->rect().center().ry(), this->rect().center().ry());
        if (this->isChecked())
        {
            painter->setBrush(Qt::NoBrush);
            painter->setPen(QPen(this->m_colorText,  4));
            painter->drawEllipse(this->rect().center(), this->rect().center().ry() - 2, this->rect().center().ry() - 2);
        }
    }
        break;

    case Shape::Circle:
    {
        if (!this->isChecked())
        {
            painter->setBrush(Qt::NoBrush);
            painter->setPen(QPen(this->m_colorText,  3));
            painter->drawEllipse(this->rect().center(), this->rect().center().ry() - 2, this->rect().center().ry() - 2);
        }
        else if (this->isChecked())
        {
            painter->setBrush(QBrush(this->m_colorText));
            painter->drawEllipse(this->rect().center(), this->rect().center().ry() - 2, this->rect().center().ry() - 2);
        }
    }
        break;

    case Shape::RadialGradient:
    {
        if (this->m_timeLine->state() == QTimeLine::Running)
        {
            qreal frame = this->m_timeLine->currentFrame();
            int radius = this->height() < this->width() ? this->rect().center().ry() : this->rect().center().rx();
            QColor t_colorHighlight = this->m_colorHighlight;
            t_colorHighlight.setAlphaF(1 - frame * this->m_frameFactor);
            QColor t_colorBase = this->m_colorBase;
            QRadialGradient gradient(this->rect().center(), radius);
            gradient.setColorAt(0.0, t_colorHighlight);
            gradient.setColorAt(qBound(0.001, frame * this->m_frameFactor, 1.0), t_colorHighlight);
            gradient.setColorAt(qBound(0.0, 0.001 + frame * this->m_frameFactor, 1.0), t_colorBase);
            gradient.setColorAt(1, t_colorBase);
            painter->fillRect(this->rect(), gradient);
        }
    }
        break;

    case Shape::RectRadialGradient:
    {
        if (this->m_timeLine->state() == QTimeLine::Running)
        {
            qreal frame = this->m_timeLine->currentFrame();
            int radius = this->height() < this->width() ? this->rect().center().ry() : this->rect().center().rx();
            QColor color = this->m_colorHighlight;
            color.setAlphaF(frame * this->m_frameFactor);
            QRadialGradient gradient(this->rect().center(), radius);
            gradient.setColorAt(0.0, color);
            gradient.setColorAt(qBound(0.001, frame * this->m_frameFactor, 1.0), color);
            gradient.setColorAt(qBound(0.0, 0.001 + frame * this->m_frameFactor, 1.0), this->m_colorHighlight);
            gradient.setColorAt(1, this->m_colorHighlight);
            painter->fillRect(this->rect(), gradient);
        }
    }
        break;
    }
}

void
SToolButton::paintPixmap(QPainter* painter,
                          const QRect &rect)
{
//    if (!this->m_image.isNull())
//    {
//        QRect t_rect;
//        if (this->toolButtonStyle() == Qt::ToolButtonTextUnderIcon)
//        {
//            t_rect = rect.adjusted(0, 0, 0, -rect.height() * 0.3);
//        }
//        else
//        {
//            t_rect = rect;
//        }

//        if (this->isCheckable())
//        {
//            if (this->isChecked())
//            {
//                QIcon(this->m_listPixmap[1].scaled(t_rect.width() * this->m_scale, t_rect.height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation)).paint(painter, t_rect);
//            }
//            else
//            {
//                QIcon(this->m_listPixmap[0].scaled(t_rect.width() * this->m_scale, t_rect.height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation)).paint(painter, t_rect);
//            }
//        }
//        else
//        {
//            if (this->isDown())
//            {
//                QIcon(this->m_listPixmap[1].scaled(t_rect.width() * this->m_scale, t_rect.height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation)).paint(painter, t_rect);
//            }
//            else
//            {
//                QIcon(this->m_listPixmap[0].scaled(t_rect.width() * this->m_scale, t_rect.height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation)).paint(painter, t_rect);
//            }
//        }

//        if (this->toolButtonStyle() == Qt::ToolButtonTextUnderIcon)
//        {
//            painter->setPen(this->m_colorText);
//            painter->drawText(rect.adjusted(0, rect.height() * 0.7, 0, -rect.height() * 0.1), Qt::AlignCenter, this->text());
//            painter->setPen(Qt::NoPen);
//        }
//    }
}

void
SToolButton::updateImage()
{
//    this->m_listPixmap.insert(0, this->changePixmapColor(this->m_image, this->m_colorText));
//    this->m_listPixmap.insert(1, this->changePixmapColor(this->m_image, this->m_colorHighlight));
}

void
SToolButton::updateIcon()
{
    QIcon icon;
    icon.addPixmap(this->changePixmapColor(this->m_image, this->m_colorText).scaled(this->rect().width() * this->m_scale, this->rect().height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation), QIcon::Normal,   QIcon::Off);
//    icon.addPixmap(this->changePixmapColor(this->m_image, this->m_colorHighlight).scaled(this->rect().width() * this->m_scale, this->rect().height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation), QIcon::Selected, QIcon::On);
    icon.addPixmap(this->changePixmapColor(this->m_image, this->m_colorHighlight).scaled(this->rect().width() * this->m_scale, this->rect().height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation), QIcon::Active,   QIcon::On);
    this->setIcon(icon);
}

void
SToolButton::setFontSize(const int size)
{
    this->m_fontSize = size;
}

QString
SToolButton::formStyleSheet(const Style &style)
{
    QString sheet = "";
    int fontSize = 0;

    switch (style)
    {
    case Style::Base:
        sheet = " \
                QToolButton          { background-color: " + this->m_colorBase.name() + "; border: none; } \
                ";
        break;

    case Style::Contrast:
        sheet = " \
                QToolButton          { background-color: " + this->m_colorContrast.name() + "; border: none; } \
                ";
        break;

    case Style::Highlight:
        sheet = " \
                QToolButton          { background-color: " + this->m_colorHighlight.name() + "; border: none; } \
                ";
        break;

    case Style::Text:
    {
        fontSize = this->m_fontSize == 0 ? 20 : this->m_fontSize;
        sheet = " \
                QToolButton          { text-align: left; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                QToolButton:pressed  { text-align: left; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorHighlight.name() + "; background-color: transparent; border: none; } \
                QToolButton:checked  { text-align: left; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorHighlight.name() + "; background-color: transparent; border: none; } \
                QToolButton:toggled  { text-align: left; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorHighlight.name() + "; background-color: transparent; border: none; } \
                QToolButton:disabled { text-align: left; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Style::FilledRect:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QToolButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; } \
                QToolButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; } \
                QToolButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: " + this->m_colorContrast.name() + "; border: none; } \
                ";
    }
        break;

    case Style::FilledRoundedRect:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QToolButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; border-radius: " + QString::number(this->rect().center().ry()) + "px; } \
                QToolButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; border-radius: " + QString::number(this->rect().center().ry()) + "px; } \
                QToolButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: " + this->m_colorContrast.name() + "; border: none; border-radius: " + QString::number(this->rect().center().ry()) + "px; } \
                ";
    }
        break;

    case Style::FilledRoundRect:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QPushButton          { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                QPushButton:pressed  { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                QPushButton:toggled  { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                QPushButton:disabled { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                ";
    }
        break;

    case Style::Orange:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QToolButton           { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; } \
                QToolButton:pressed   { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; } \
                QToolButton:disabled  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: " + this->m_colorContrast.name() + "; border: none; } \
                ";
    }
        break;

    case Style::Rect:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QToolButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: 2px solid transparent; } \
                QToolButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: 2px solid " + this->m_colorHighlight.name() + "; } \
                QToolButton:checked  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: 2px solid " + this->m_colorHighlight.name() + "; } \
                QToolButton:toggled  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: 2px solid " + this->m_colorHighlight.name() + "; } \
                QToolButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: transparent; border: 2px solid " + this->m_colorContrast.name() + "; } \
                ";
    }
        break;

    case Style::RoundedRect:
        break;

    case Style::Transparent:
    {
        fontSize = this->m_fontSize == 0 ? 26 : this->m_fontSize;
        sheet = " \
                QToolButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                QToolButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                QToolButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Style::ToolBarTop:
    {
        fontSize = this->m_fontSize == 0 ? 14 : this->m_fontSize;
        sheet = " \
                QToolButton         { font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border-bottom: 2px solid " + this->m_colorContrast.name() + "; } \
                QToolButton:pressed { font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border-bottom: 2px solid " + this->m_colorContrast.lighter().name() + "; } \
                QToolButton:checked { font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border-bottom: 2px solid " + this->m_colorHighlight.name() + "; } \
                ";
    }
        break;

    case Style::None:
        sheet = " \
                QToolButton          { color: transparent; background: transparent; background-color: transparent; border: none; } \
                QToolButton:pressed  { color: transparent; background: transparent; background-color: transparent; border: none; } \
                QToolButton:disabled { color: transparent; background: transparent; background-color: transparent; border: none; } \
                ";
        break;
    }

    return sheet;
}

void
SToolButton::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
        this->setStyleSheet(this->formStyleSheet(this->m_style));
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
        this->updateIcon();
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
        this->updateIcon();
    }
}

void
SToolButton::changeEvent(QEvent * event)
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
