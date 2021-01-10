#ifndef STOUCHFLICKABLELIST_H
#define STOUCHFLICKABLELIST_H

#include "SFlickable.h"
#include "../build/SGlobal.h"

#include <QWidget>

class QPixmap;
class QEvent;
class QTimer;
class QPoint;
class QGestureEvent;
class QSwipeGesture;


class STouchFlickableList : public QWidget, public SFlickable
{
    Q_OBJECT

public:
    explicit STouchFlickableList(QWidget *parent = 0);
    ~STouchFlickableList();

    void setEmpty();
    void setTopic(const QString &topic);
    void setTopic(const QString &topic, const int &index);
    void setText(const QString &text);
    void setText(const QString &text, const int &index);
    QString getText(const int &index) const;

    void setParameter(const int &param);
    void setParameter(const uint64_t &param);
    void setParameter(const double &param);
    void setParameter(const QString &param);
    void setParameter(const int &param, const int &index);
    void setParameter(const uint64_t &param, const int &index);
    void setParameter(const double &param, const int &index);
    void setParameter(const QString &param, const int &index);
    QString getParameter(const int &index) const;

    void setPixmap(const QPixmap &pix);
    void setTextAlignment(const Qt::AlignmentFlag &alignmentFlag);
    void setOpacity(const double opacity);
    void setOffset(const int &offset);
    void setRowHeight(const int height);
    void setScaleIcon(const double scale = 1.0);
    void setCheckable(const bool &checkable = false);
    void setSelectable(const bool &selectable = false);
    void setHideable(const bool &hideable = false);
    double getOpacity() const;

    void setFontSize(const int &size = 16, const bool bold = false);
    void setFontSizeParamter(const int &size = 14, const bool bold = false);
    void setEmptyColor(const QColor &color = QColor(17,19,11));
    void setTopicColor(const QColor &color = QColor(197,199,191,50));
    void setBackgroundColor(const QColor &color = Qt::black);
    void setHighlightColor(const QColor &color = QColor(197,199,191,50));
    void setSelectColor(const QColor &color = QColor(0,128,240));
    void setFontTopicColor(const QColor &color = QColor(220,220,220));
    void setFontTextColor(const QColor &color = QColor(245,245,245));
    void setFontParameterColor(const QColor &color = QColor(245,245,245));
    void setParameterColor(const QColor &color = QColor(245,245,245));
    void setWindowWidth(const int width);
    void setWindowHeight(const int height);
    QColor getBackgroundColor() const;

    void setIndexOf(const int &index);
    void setIndexOf(const QString &text);
    int getIndex() const;

    int size() const;

    void enableAnimation(const bool animate = false, const Qt::Edge &edge = Qt::LeftEdge);
    void enableDrawLine(const bool drawline = false, const QColor &color = QColor(220,20,60));

protected:
    // reimplement from SFlickable
    virtual QPoint scrollOffset() const;
    // reimplement from SFlickable
    virtual void setScrollOffset(const QPoint &offset);

protected:
    void paintEvent(QPaintEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void focusOutEvent(QFocusEvent* event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
    bool event(QEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalCurrentIndex(const int index);

private slots:
    void slotClose();
    void slotUnsetHighlight();
    void slotEmitCurrentIndex();

private:
    void setupGUI();
    int index(QMouseEvent *event);
    void closeGesture(QMouseEvent *event);
    int showAnimation();
    int closeAnimation();
    bool gestureEvent(QGestureEvent *event);
    void swipeTriggered(QSwipeGesture *gesture);

    bool m_animate = false;
    bool m_drawline = false;
    bool m_checkable = false;
    bool m_selectable = false;
    bool m_hideable = false;
    bool m_gesture = false;
    bool m_loop = false;
    int m_y = 0;
    int m_index = -1;
    int m_maxIndex = 0;
    int m_begin = 0;
    int m_end = 0;
    int m_height = 0;
    int m_set_height = 0;
    int m_init_height = 0;
    int m_offset = 0;
    int m_highlight = -1;
    int m_highlightIndex = -1;
    int m_selectedIndex = -1;
    double m_scale_icon = 1.0;
    double m_opacity = 1.0;

    QPoint m_delta;
    QColor empty_color = QColor(17,19,11);
    QColor topic_color = QColor(197,199,191,50);
    QColor background_color = Qt::black;
    QColor line_color = QColor(220,20,60);
    QColor highlight_color = QColor(197,199,191,50);
    QColor selected_color = QColor(0,128,240);
    QColor font_topic_color = QColor(220,220,220);
    QColor font_text_color = QColor(245,245,245);
    QColor font_parameter_color = QColor(245,245,245);
    QFont font_size = QFont(::GlobalFont, 16);
    QFont font_size_param = QFont(::GlobalFont, 14);
    Qt::AlignmentFlag alignmentFlag;
    Qt::Edge edge = Qt::LeftEdge;
    QVector<int> m_indexEmpty;
    QVector<int> m_indexTopic;
    QVector<int> m_indexNoline;
    QStringList m_widgetNames;
    QStringList m_widgetParameter;
    QList<QPixmap> m_widgetPixmap;
    QTimer *hideTimer = nullptr;
};

#endif /// STOUCHFLICKABLELIST_H
