#ifndef STOOLBUTTON_H
#define STOOLBUTTON_H

#include "../build/SGlobal.h"

#include <QWidget>
#include <QIcon>
#include <QColor>
#include <QString>
#include <QToolButton>

class QTimeLine;
class QEvent;


class SToolButton : public QToolButton
{
    Q_OBJECT

public:
    enum class Shape {
        None = 0,
        Base,
        Contrast,
        Circle,
        RadialGradient,
        RectRadialGradient,
        Rect,
        RoundedRect,
        ColorHSV,
        ColorRGB,
        ColorSW,
    };

    enum class Style {
        None = 0,
        Base,
        Contrast,
        Highlight,
        Text,
        Transparent,
        FilledRect,
        FilledRoundedRect,
        FilledRoundRect,
        Orange,
        Rect,
        RoundedRect,
        ToolBarTop
    };

    explicit SToolButton(QWidget * parent = nullptr);
    ~SToolButton();

    void shape(const Shape & shape = Shape::None);
    void setImage(const QString & image, const double scale = 1.0);
    void setFontSize(const int size);
    void setTheme(const Style & style = Style::None);

protected:
//    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * event);
    void changeEvent(QEvent * event);

private slots:

private:
    void setupLayout();
    void setConnect();
    void restyleUI();
    void updateImage();
    void updateIcon();
    void paintItem(QPainter * painter, const QRect & rect);
    void paintShape(QPainter * painter, const QRect & rect);
    void paintPixmap(QPainter * painter, const QRect & rect);
    QPixmap changePixmapColor(const QString & source, const QColor & color);
    QString formStyleSheet(const Style & style);

    double m_frameFactor = 0.0;
    double m_scale = 1.0;
    int m_fontSize = 0;
    Shape m_shape = Shape::None;
    Style m_style = Style::None;
    QString m_image;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;
    QTimeLine *m_timeLine = nullptr;
    QList<QPixmap> m_listPixmap{QPixmap(""), QPixmap("")};
};

#endif /// STOOLBUTTON_H
