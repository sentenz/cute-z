#ifndef SCOLORSQUARE_H
#define SCOLORSQUARE_H

#include <QWidget>
#include <QPen>

class SColorSquare : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor main_color READ getColor WRITE setColor)
    Q_PROPERTY(QColor selected_color READ selectedColor)
    Q_PROPERTY(QPen cursor_pen READ cursorPen WRITE setCursorPen)
    Q_PROPERTY(int cursor_diameter READ cursorDiameter WRITE setCursorDiameter)

public:
    explicit SColorSquare(QWidget *parent = nullptr);
    explicit SColorSquare(const QColor &color, QWidget *parent = nullptr);
    ~SColorSquare();

    /// public members
    QColor getColor() const;
    QColor selectedColor() const;
    QPen cursorPen() const;
    int cursorDiameter() const;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:
    void colorSelected(const QColor &color);

public slots:
    void setMode(const int mode);
    void setColor(const QColor &color);
    void setCursorPen(const QPen &pen);
    void setCursorDiameter(const int diameter);

private:
    /// private membres
    void updateGradientImage();
    void updateSelectedColor();

    bool m_tracking;
    int m_cursor_diameter;
    int m_mode = 0;

    QColor m_main_color;
    QColor m_selected_color;
    QImage m_gradient_image;
    QPen m_cursor_pen;
    QPoint m_cursor_position;
};

#endif /// SCOLORSQUARE_H
