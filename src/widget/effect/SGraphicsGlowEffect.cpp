#include "SGraphicsGlowEffect.h"

#include <QtMath>

SGraphicsGlowEffect::SGraphicsGlowEffect(QObject *parent) : QGraphicsEffect(parent)
{
}

void SGraphicsGlowEffect::setColor(QColor value)
{
    this->m_color = value;
    update();
}

void SGraphicsGlowEffect::setStrength(int value)
{
    this->m_strength = value;
    update();
}

void SGraphicsGlowEffect::setBlurRadius(qreal value)
{
    this->m_blurRadius = value;
    this->m_extent =  qCeil(value + 10);
    updateBoundingRect();
}

QColor SGraphicsGlowEffect::color() const
{
    return this->m_color;
}

int SGraphicsGlowEffect::strength() const
{
    return this->m_strength;
}

qreal SGraphicsGlowEffect::blurRadius() const
{
    return this->m_blurRadius;
}

QRectF SGraphicsGlowEffect::boundingRectFor(const QRectF &rect) const
{
    return QRect(rect.left() - this->m_extent, rect.top() - this->m_extent, rect.width() + 2 * this->m_extent, rect.height() + 2 * this->m_extent);
}

void SGraphicsGlowEffect::draw(QPainter *painter)
{
    painter->setRenderHint(QPainter::HighQualityAntialiasing);

    QPoint offset;
    QPixmap source = sourcePixmap(Qt::LogicalCoordinates, &offset);
    QPixmap glow;

    QGraphicsColorizeEffect *colorize = new QGraphicsColorizeEffect;
    colorize->setColor(this->m_color);
    colorize->setStrength(1);
    glow = applyEffectToPixmap(source, colorize, 0);

    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(this->m_blurRadius);
    glow = applyEffectToPixmap(glow, blur, this->m_extent);

    for (int i = 0; i < this->m_strength; ++i)
    {
        painter->drawPixmap(offset - QPoint(this->m_extent, this->m_extent), glow);
    }

    drawSource(painter);

    painter->end();
}

QPixmap SGraphicsGlowEffect::applyEffectToPixmap(QPixmap src, QGraphicsEffect *effect, int extent)
{
    if (src.isNull())
    {
        return QPixmap();
    }

    if (!effect)
    {
        return src;
    }

    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(src);
    item.setGraphicsEffect(effect);
    scene.addItem(&item);

    QSize size = src.size() + QSize(extent * 2, extent * 2);

    QPixmap res(size.width(), size.height());
    res.fill(Qt::transparent);

    QPainter p(&res);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    scene.render(&p, QRectF(), QRectF(-extent, -extent, size.width(), size.height()));

    return res;
}
