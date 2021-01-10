#include "SPushButton.h"

#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QTimeLine>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QEvent>
#include <QDebug>


SPushButton::SPushButton(QWidget * parent)
    : QPushButton(parent)
{
    this->setFocusPolicy(Qt::NoFocus);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setCheckable(false);
    this->setAutoExclusive(true);

    this->setupWidget();
    this->setConnect();
    this->stylesheet(Style::None);
    this->slotReadSettings();
    this->restyleUI();
}

SPushButton::SPushButton(const QString & text,
                         QWidget * parent)
    : QPushButton(parent),
      m_text(text)
{
    this->setText(text);
    this->setFocusPolicy(Qt::NoFocus);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setCheckable(false);
    this->setAutoExclusive(true);

    this->setupWidget();
    this->setConnect();
    this->stylesheet(Style::None);
    this->slotReadSettings();
    this->restyleUI();
}

SPushButton::SPushButton(const QIcon & icon,
                         const QString & text,
                         QWidget * parent)
    : QPushButton(parent),
      m_text(text)
{
    this->setIcon(icon);
    this->setText(text);
    this->setFocusPolicy(Qt::NoFocus);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setCheckable(false);
    this->setAutoExclusive(true);

    this->setupWidget();
    this->setConnect();
    this->stylesheet(Style::None);
    this->slotReadSettings();
    this->restyleUI();
}

SPushButton::~SPushButton()
{
}

void
SPushButton::setupWidget()
{
    // File watcher
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalConfigPathSettings);

    // Time line
    this->m_timeLine = new QTimeLine(500, this);
    this->m_timeLine->setFrameRange(0, 255);
}

void
SPushButton::setConnect()
{
    // File watcher
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &SPushButton::slotReadSettings);
    // Time line
    connect(this->m_timeLine, SIGNAL(frameChanged(int)), this, SLOT(update()));
}

void
SPushButton::shape(const Shape &shape, const bool dynamic)
{
    this->stylesheet(Style::Transparent);
    this->m_shape = shape;
    this->m_dynamicShape = dynamic;
    this->m_shapeDefault = this->m_shape;
    this->slotReadSettings();
    update();
}

void
SPushButton::setImage(const QString &image, const double scale)
{
    this->m_image = image;
    this->m_scale = qBound(0.0, scale, 1.0);
    this->updateIcon();
    update();
}

void
SPushButton::setFontSize(const int size)
{
    this->m_fontSize = size;
    this->setStyleSheet(this->formStyleSheet(this->m_style));
}

void
SPushButton::setAnimationDuration(const int duration)
{
    this->m_duration = duration;
}

void
SPushButton::setAnimationPressDuration(const int duration)
{
    this->m_durationPress = duration;
}

void
SPushButton::setAnimationReleaseDuration(const int duration)
{
    this->m_durationReleas = duration;
}

void
SPushButton::beginTimeLine(const int duration,
                           const int frames)

{
    switch (this->m_shape)
    {
    case Shape::None:
        break;

    case Shape::Transparent:
    case Shape::Base:
    case Shape::Contrast:
    case Shape::Round:
    case Shape::Rounded:
    case Shape::Rect:
    case Shape::Circle:
    {
        if (this->m_timeLine->state() == QTimeLine::NotRunning)
        {
            this->m_currentFrame = frames;
            this->m_timeLine->setDuration(duration);
            this->m_timeLine->setFrameRange(0, frames);
            this->m_timeLine->start();
        }
    }
        break;

    case Shape::RadialGradient:
    {
        if (this->m_timeLine->state() == QTimeLine::NotRunning)
        {
            this->m_timeLine->setDuration(400);
            this->m_timeLine->setFrameRange(0, 100);
            this->m_frameFactor = 1.0 / 100.0;
            this->m_timeLine->start();
        }
    }
        break;
    }
}

void
SPushButton::endTimeLine(const int duration,
                         const int frames)
{
    if (this->m_shape != Shape::None && this->m_shape != Shape::RadialGradient)
    {
        if (this->m_timeLine->state() == QTimeLine::Running)
        {
            this->m_timeLine->setPaused(true);
            int t_duration = this->m_timeLine->currentTime() > 0 ? this->m_timeLine->currentTime() : duration;
            this->m_currentFrame = this->m_timeLine->currentFrame() > 0 ? this->m_timeLine->currentFrame() : frames;
            this->m_timeLine->setDuration(t_duration);
            this->m_timeLine->setFrameRange(0, this->m_currentFrame);
            this->m_timeLine->stop();
            this->m_timeLine->start();
        }
        else if (this->m_timeLine->state() == QTimeLine::NotRunning)
        {
            this->m_timeLine->start();
        }
    }

    QTimer::singleShot(this->m_timeLine->duration(), this, [this] {
        this->m_pressed = false;
        this->m_released = false;
    });
}

//void
//SPushButton::mouseMoveEvent(QMouseEvent *event)
//{
//    QPushButton::mouseMoveEvent(event);
//}

void
SPushButton::mousePressEvent(QMouseEvent *event)
{
    int t_duration = this->m_durationPress > 1 ? this->m_durationPress : this->m_duration;
    this->beginTimeLine(t_duration, this->m_frames);
    this->m_pressed = true;

    QPushButton::mousePressEvent(event);
}

void
SPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    int t_duration = this->m_durationReleas > 1 ? this->m_durationReleas : this->m_duration;
    this->endTimeLine(t_duration, this->m_frames);
    this->m_released = true;

    QPushButton::mouseReleaseEvent(event);
}

void
SPushButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    this->paintItem(painter, this->rect());
    painter.setBrush(Qt::NoBrush);
    painter.end();

    QPushButton::paintEvent(event);
}

void
SPushButton::paintItem(QPainter &painter,
                       const QRect &rect)
{
    this->paintShape(painter, rect);
}

void
SPushButton::paintShape(QPainter &painter,
                        const QRect &rect)
{
    switch (this->m_shape)
    {
    case Shape::None:
        break;

    case Shape::Transparent:
    {
        painter.fillRect(rect, Qt::transparent);
        if (this->m_released && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_currentFrame - this->m_timeLine->currentFrame());
            painter.fillRect(rect, t_color);
        }
        else if (this->m_pressed && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            painter.fillRect(rect, t_color);
        }
    }
        break;

    case Shape::Base:
    {
        painter.fillRect(rect, this->m_colorBase);
        if (this->m_released && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_currentFrame - this->m_timeLine->currentFrame());
            painter.fillRect(rect, t_color);
        }
        else if (this->m_pressed && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            painter.fillRect(rect, t_color);
        }
    }
        break;

    case Shape::Contrast:
    {
        painter.fillRect(rect, this->isEnabled() ? this->m_colorContrast : this->m_colorContrast.darker());
        if (this->m_released && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_currentFrame - this->m_timeLine->currentFrame());
            painter.fillRect(rect, t_color);
        }
        else if (this->m_pressed && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            painter.fillRect(rect, t_color);
        }
    }
        break;

    case Shape::Rect:
    {
        painter.fillRect(rect.x() + 2, rect.y() + 2, rect.width() - 4, rect.height() - 4, this->isEnabled() ? this->m_colorContrast : this->m_colorContrast.darker());
        if (this->m_released && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_currentFrame - this->m_timeLine->currentFrame());
            painter.fillRect(rect.x() + 2, rect.y() + 2, rect.width() - 4, rect.height() - 4, t_color);
        }
        else if (this->m_pressed && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            painter.fillRect(rect.x() + 2, rect.y() + 2, rect.width() - 4, rect.height() - 4, t_color);
        }
    }
        break;

    case Shape::Round:
    {
        QPainterPath path;
        path.addRoundedRect(QRectF(rect.x() + 2, rect.y() + 2, rect.width() - 4, rect.height() - 4), (rect.height() - 4) * 0.5, (rect.height() - 4) * 0.5);
        painter.setPen(Qt::NoPen);
        painter.fillPath(path, this->m_colorContrast);
        painter.drawPath(path);
        if (this->m_released && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_currentFrame - this->m_timeLine->currentFrame());
            painter.fillPath(path, t_color);
            painter.drawPath(path);
        }
        else if (this->m_pressed && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            painter.fillPath(path, t_color);
            painter.drawPath(path);
        }
        painter.setPen(this->m_colorText);
    }
        break;

    case Shape::Rounded:
    {
        QPainterPath path;
        path.addRoundedRect(QRectF(rect.x() + 2, rect.y() + 2, rect.width() - 4, rect.height() - 4), (rect.height() - 4) * 0.1, (rect.height() - 4) * 0.1);
        painter.setPen(Qt::NoPen);
        painter.fillPath(path, this->m_colorContrast);
        painter.drawPath(path);
        if (this->m_released && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_currentFrame - this->m_timeLine->currentFrame());
            painter.fillPath(path, t_color);
            painter.drawPath(path);
        }
        else if (this->m_pressed && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            painter.fillPath(path, t_color);
            painter.drawPath(path);
        }
        painter.setPen(this->m_colorText);
    }
        break;

    case Shape::Circle:
    {
        int radius = this->height() < this->width() ? rect.center().ry() : rect.center().rx();
        // Opaque content is generally a lot faster to draw than translucent. The reason being that translucent
        // content needs blending and that the renderer can potentially optimize opaque content better.
        painter.setPen(QColor(0, 0, 0, 0));
        if (this->m_released && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_currentFrame - this->m_timeLine->currentFrame());
            painter.setBrush(QBrush(t_color));
            painter.drawEllipse(rect.center(), radius, radius);
        }
        else if (this->m_pressed && this->isEnabled())
        {
            QColor t_color = this->m_colorHighlight;
            t_color.setAlpha(this->m_timeLine->currentFrame());
            painter.setBrush(QBrush(t_color));
            painter.drawEllipse(rect.center(), radius, radius);
        }
        painter.setPen(this->m_colorText);
    }
        break;

    case Shape::Frame:
    {
        QPainterPath path;
        path.addRoundedRect(QRectF(rect.x() + 3, rect.y() + 3, rect.width() - 6, rect.height() - 6), (rect.height() - 6) * 0.1, (rect.height() - 6) * 0.1);
        painter.setPen(QPen(this->m_colorText, 2));
        painter.drawPath(path);
        if (this->m_released && this->isEnabled())
        {
            QPainterPath path;
            path.addRoundedRect(QRectF(rect.x() + 3, rect.y() + 3, rect.width() - 6, rect.height() - 6), (rect.height() - 6) * 0.1, (rect.height() - 6) * 0.1);
            painter.setPen(QPen(this->m_colorHighlight, 2));
            painter.drawPath(path);
        }
        else if (this->m_pressed && this->isEnabled())
        {
            QPainterPath path;
            path.addRoundedRect(QRectF(rect.x() + 3, rect.y() + 3, rect.width() - 6, rect.height() - 6), (rect.height() - 6) * 0.1, (rect.height() - 6) * 0.1);
            painter.setPen(QPen(this->m_colorHighlight, 2));
            painter.drawPath(path);
        }
        painter.setPen(this->m_colorText);
    }
        break;

    case Shape::RadialGradient:
    {
        if (this->m_timeLine->state() == QTimeLine::Running)
        {
            qreal frame = this->m_timeLine->currentFrame();
            int radius = this->height() < this->width() ? rect.center().ry() : rect.center().rx();
            QColor t_colorHighlight = this->m_colorHighlight;
            t_colorHighlight.setAlphaF(1 - frame * this->m_frameFactor);
            QColor t_colorBase = this->m_colorBase;
            QRadialGradient gradient(rect.center(), radius);
            gradient.setColorAt(0.0, t_colorHighlight);
            gradient.setColorAt(qBound(0.001, frame * this->m_frameFactor, 1.0), t_colorHighlight);
            gradient.setColorAt(qBound(0.0, 0.001 + frame * this->m_frameFactor, 1.0), t_colorBase);
            gradient.setColorAt(1, t_colorBase);
            painter.fillRect(rect, gradient);
        }
        painter.drawText(rect, Qt::AlignCenter, this->m_text);
    }
        break;
    }
}

void
SPushButton::updateIcon()
{
    QIcon icon;
    icon.addPixmap(this->changePixmapColor(this->m_image, this->m_colorText).scaled(this->rect().width() * this->m_scale, this->rect().height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation), QIcon::Normal,   QIcon::Off);
    icon.addPixmap(this->changePixmapColor(this->m_image, this->m_colorHighlight).scaled(this->rect().width() * this->m_scale, this->rect().height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation), QIcon::Selected, QIcon::On);
    icon.addPixmap(this->changePixmapColor(this->m_image, this->m_colorHighlight).scaled(this->rect().width() * this->m_scale, this->rect().height() * this->m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation), QIcon::Active,   QIcon::On);
    this->setIcon(icon);
}

QPixmap
SPushButton::changePixmapColor(const QString &source, const QColor &color)
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

void
SPushButton::stylesheet(const Style &style)
{
    this->m_style = style;
    this->setStyleSheet(this->formStyleSheet(this->m_style));
}

QString
SPushButton::formStyleSheet(const Style &style)
{
    QString sheet = "";
    int fontSize = 0;

    switch (style)
    {
    case Style::None:
    {
        sheet = " \
                QPushButton          { color: transparent; background: transparent; background-color: transparent; border: none; } \
                QPushButton:pressed  { color: transparent; background: transparent; background-color: transparent; border: none; } \
                QPushButton:disabled { color: transparent; background: transparent; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Style::Base:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QPushButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorBase.name() + "; border: none; } \
                QPushButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; } \
                QPushButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: " + this->m_colorBase.name() + "; border: none; } \
                ";
    }
        break;

    case Style::Contrast:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QPushButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; } \
                QPushButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; } \
                QPushButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: " + this->m_colorContrast.name() + "; border: none; } \
                ";
    }
        break;

    case Style::Text:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QPushButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                QPushButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorHighlight.name() + "; background-color: transparent; border: none; } \
                QPushButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Style::Highlight:
    {
        fontSize = this->m_fontSize == 0 ? 26 : this->m_fontSize;
        sheet = " \
                QPushButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorHighlight.name() + "; background-color: transparent; border: none; } \
                QPushButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                QPushButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorContrast.darker().name() + "; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Style::FilledRoundedRect:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QPushButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.2) + "px; } \
                QPushButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.2) + "px; } \
                QPushButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: " + this->m_colorContrast.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.2) + "px; } \
                ";
    }
        break;

    case Style::FilledRoundRect:
    {
        fontSize = this->m_fontSize == 0 ? 24 : this->m_fontSize;
        sheet = " \
                QPushButton          { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                QPushButton:pressed  { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                QPushButton:checked  { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                QPushButton:toggled  { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorHighlight.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                QPushButton:disabled { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                ";
    }
        break;

    case Style::Rect:
    {
        fontSize = this->m_fontSize == 0 ? 26 : this->m_fontSize;
        sheet = " \
                QPushButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: 2px solid " + this->m_colorContrast.name() + "; } \
                QPushButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorHighlight.name() + "; background-color: transparent; border: 2px solid " + this->m_colorHighlight.name() + "; } \
                QPushButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorContrast.darker().name() + "; background-color: transparent; border: 2px solid " + this->m_colorContrast.name() + "; } \
                ";
    }
        break;

    case Style::Transparent:
    {
        fontSize = this->m_fontSize == 0 ? 26 : this->m_fontSize;
        sheet = " \
                QPushButton          { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                QPushButton:pressed  { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                QPushButton:disabled { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: transparent; background-color: transparent; border: none; } \
                ";
    }
        break;
    }

    return sheet;
}

void
SPushButton::slotReadSettings()
{
    if (this->m_dynamicShape)
    {
        QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);
        if (!QStringList(settings.allKeys().filter("custom/design", Qt::CaseInsensitive)).isEmpty())
        {
            settings.beginGroup("custom/design");
        }
        else if (!QStringList(settings.allKeys().filter("default/design", Qt::CaseInsensitive)).isEmpty())
        {
            settings.beginGroup("default/design");
        }

            int t_shape = settings.value("item_shape", 0).toInt();
            if (t_shape == 0)
            {
                this->m_shape = this->m_shapeDefault;
            }
            else
            {
                this->m_shape = static_cast<Shape>(t_shape);
            }

        settings.sync();
        settings.endGroup();
    }
}

void
SPushButton::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
        this->updateIcon();
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
        this->updateIcon();
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
        this->updateIcon();
    }
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
