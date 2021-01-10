#ifndef SGRAPHICSGLOWEFFECT_H
#define SGRAPHICSGLOWEFFECT_H

#include <QGraphicsEffect>
#include <QGraphicsBlurEffect>
#include <QGraphicsColorizeEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>

/**
 * @brief SGraphicsGlowEffect Example
 * SGraphicsGlowEffect * glow = new SGraphicsGlowEffect;
 * glow->setBlurRadius(1);
 * glow->setStrength(1);
 * this->buttonReboot->setGraphicsEffect(glow);
 */


class SGraphicsGlowEffect : public QGraphicsEffect
{
public:
    explicit SGraphicsGlowEffect(QObject *parent = 0);

    QRectF boundingRectFor(const QRectF &rect) const;

    void setColor(QColor value= QColor(255, 255, 255));
    void setStrength(int value = 3);
    void setBlurRadius(qreal value = 5.0);

    int strength() const;
    qreal blurRadius() const;
    QColor color() const;

protected:
    void draw(QPainter *painter);

private:
    static QPixmap applyEffectToPixmap(QPixmap src, QGraphicsEffect *effect, int extent);

    int m_extent = 5;
    int m_strength = 3;
    qreal m_blurRadius = 5.0;
    QColor m_color = QColor(255, 255, 255);
};

#endif /// SGRAPHICSGLOWEFFECT_H
