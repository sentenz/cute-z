#ifndef STOUCHFLICKABLELIST_H
#define STOUCHFLICKABLELIST_H

#include "SFlickable.h"
#include "../build/SGlobal.h"

#include <QWidget>
#include <QSvgWidget>
#include <QDialog>

class QPixmap;
class QEvent;
class QTimer;
class QTimeLine;
class QPoint;
class QFileSystemWatcher;


class STouchFlickableList
        : public QWidget
        , public SFlickable
{
    Q_OBJECT

public:
    enum class Shape {
        None = 0,
        Round,
        Rounded,
        Rect,
        Full
    };

    explicit STouchFlickableList(QWidget *parent = nullptr);
    ~STouchFlickableList();

    void setEmpty();
    void setTopic(const QString &topic);
    void setTopic(const QString &topic, const int &index);
    void setText(const QString &text, const QString &sub = "");
    void setText(const QString &text, const int &index);
    void setText(const QString &text, const QString &sub, const int &index);
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

    void setPixmap(const QString &pixmap);
    void setTextAlignment(const Qt::AlignmentFlag &flag);
    void setOpacity(const double opacity);
    void setOffset(const int &offset);
    void setItemHeight(const int height);
    void setHideable(const bool &hideable = false);
    void setCloseable(const bool &closeable = false);
    void setCheckable(const bool &checkable = false);
    void setSelectable(const bool &selectable = false);
    void setRepeatable(const bool &repeatable = false, const bool &gradient = false, const double transparency = 0.5);
    double getOpacity() const;

    void setFontSize(const int &size = 16, const bool bold = false);
    void setFontSizeParamter(const int &size = 16, const bool bold = false);
    void setEmptySlotColor(const QColor &color = ::GlobalColorBase);
    void setTopicBackgroundColor(const QColor &color = ::GlobalColorBase);
    void setBaseColor(const QColor &color = Qt::black);
    void setContrastColor(const QColor &color = ::GlobalColorContrast);
    void setHighlightColor(const QColor &color = ::GlobalColorHighlight);
    void setFontTextColor(const QColor &color = ::GlobalColorText);
    void resetFontWidth();
    QColor getBackgroundColor() const;

    int getIndex() const;
    void setContent(const QString &text);
    // TODO
    QString getContent() const;

    void removeIndex(const int &index);

    int size() const;

    void enableAnimation(const bool animate = false, const Qt::Edge &edge = Qt::LeftEdge);
    void enableDrawLine(const bool draw = false);
    void setShape(const Shape &shape = Shape::None, const bool enable = true);

    bool isAccepted();

protected:
    // reimplement from SFlickable
    virtual QPoint scrollOffset() const;
    // reimplement from SFlickable
    virtual void setScrollOffset(const QPoint &offset);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void focusOutEvent(QFocusEvent* event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
    void changeEvent(QEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:
    void signalCurrentIndex(const int index);
    void signalCurrentContent(const QString content);
    void signalCurrentIndexContent(const int index, const QString content);

private slots:
    void slotClose();
    void slotUnsetHighlight();
    void slotEmitCurrentIndex();
    void slotReadSettings();

private:
    /// Function members
    void setupLayout();
    void updateWidget();
    void setConnect();
    int index(QMouseEvent *event);
    void closeGesture(QMouseEvent *event);
    void paintPixmap(QPainter &painter, const int i);
    void paintShape(QPainter &painter, const QRect &rect, const int i);
    QPixmap changePixmapColor(const QString &source, const QColor &color);
    int showAnimation();
    int closeAnimation();
    void beginTimeLine(const int duration, const int frames);
    void endTimeLine();

    /// Data members
    int m_y = 0;
    int m_begin = 0;
    int m_end = 0;
    int m_index = -1;
    int m_maxIndex = 0;
    int m_offset = 0;
    int m_height = 0;
    int m_itemHeight = ::GlobalWindowSize.height() < ::GlobalWindowSize.width() ? ::GlobalWindowSize.height()/8 : ::GlobalWindowSize.width()/10;
    int m_fontWidth = 0;
    int m_highlightIndex = -1;
    int m_selectIndex = -1;
    int m_frames = 0;
    double m_opacity = 1.0;
    double m_transparency = 0.5;
    bool m_animate = false;
    bool m_check = false;
    bool m_hide = false;
    bool m_close = false;
    bool m_gesture = false;
    bool m_repeat = false;
    bool m_gradient = false;
    bool m_accept = false;
    bool m_drawline = false;
    bool m_shapeEnabled = false;

    /// Qt members
    Shape m_shape = Shape::None;
    Shape m_shapeDefault = Shape::None;
    QPoint m_delta;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorHighlight = ::GlobalColorHighlight;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorEmpty = Qt::transparent;
    QColor m_colorTopic = Qt::transparent;
    QFont m_fontText = QFont(::GlobalFont, 16);
    QFont m_fontParamter = QFont(::GlobalFont, 16);
    Qt::AlignmentFlag m_alignmentFlag;
    Qt::Edge m_edge = Qt::LeftEdge;
    QVector<int> m_indexEmpty;
    QVector<int> m_indexTopic;
    QVector<int> m_indexNoline;
    QStringList m_widgetNames;
    QStringList m_widgetSubText;
    QStringList m_widgetParameter;
    QStringList m_sourcePixmap;
    QList<QPixmap> m_widgetPixmap;
    QTimer *m_hideTimer = nullptr;
    QTimeLine *m_timeLine = nullptr;
    QFileSystemWatcher *fileSystemWatcher = nullptr;
};

#endif /// STOUCHFLICKABLELIST_H
