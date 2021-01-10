#ifndef SPUSHBUTTON_H
#define SPUSHBUTTON_H

#include "../build/SGlobal.h"
#include <QWidget>
#include <QIcon>
#include <QString>
#include <QColor>
#include <QPushButton>

class QTimeLine;
class QFileSystemWatcher;


class SPushButton : public QPushButton
{
    Q_OBJECT

public:
    enum class Shape {
        None = 0,
        Base,
        Contrast,
        Rect,
        Round,
        Rounded,
        Frame,
        Circle,
        RadialGradient,
        Transparent,
    };

    enum class Style {
        None = 0,
        Base,
        Contrast,
        Text,
        Highlight,
        FilledRoundedRect,
        FilledRoundRect,
        Rect,
        Transparent,
    };

    explicit SPushButton(QWidget * parent = nullptr);
    explicit SPushButton(const QString & text, QWidget * parent = nullptr);
    explicit SPushButton(const QIcon & icon, const QString & text, QWidget * parent = nullptr);
    ~SPushButton();

    void setImage(const QString &image, const double scale = 1.0);
    void setFontSize(const int size);
    void shape(const Shape &shape = Shape::None, const bool dynamic = false);
    void stylesheet(const Style &style = Style::None);
    void setAnimationDuration(const int duration = 1);
    void setAnimationPressDuration(const int duration = 1);
    void setAnimationReleaseDuration(const int duration = 1);

protected:
    //    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void changeEvent(QEvent *event);

private slots:
    void slotReadSettings();

private:
    void setupWidget();
    void setConnect();
    void restyleUI();
    void paintItem(QPainter &painter, const QRect &rect);
    void paintShape(QPainter &painter, const QRect &rect);
    void updateIcon();
    void beginTimeLine(const int duration, const int frames);
    void endTimeLine(const int duration, const int frames);
    QPixmap changePixmapColor(const QString &source, const QColor &color);
    QString formStyleSheet(const Style &style);

    bool m_pressed = false;
    bool m_released = false;
    bool m_dynamicShape = false;
    double m_frameFactor = 0.0;
    double m_scale = 1.0;
    int m_fontSize = 0;
    int m_duration = 1;
    int m_durationPress = 1;
    int m_durationReleas = 1;
    int m_frames = 255;
    int m_currentFrame = 255;

    Style m_style = Style::None;
    Shape m_shape = Shape::None;
    Shape m_shapeDefault = Shape::None;
    QString m_image;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;
    QString m_text = "";
    QTimeLine *m_timeLine = nullptr;
    QFileSystemWatcher *fileSystemWatcher = nullptr;
};

#endif /// SPUSHBUTTON_H
