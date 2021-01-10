#ifndef STOUCHBAR_H
#define STOUCHBAR_H

#include "../build/SGlobal.h"

#include <QDialog>

class QPoint;
class QTimer;
class QColor;
class QButtonGroup;


class STouchBar : public QDialog
{
    Q_OBJECT

public:
    explicit STouchBar(QWidget *parent = nullptr);
    ~STouchBar();

    void setDock(const Qt::Edge &edge = Qt::BottomEdge);
    void setHideable(const bool &hide = false);
    void setOpacity(const double opacity);
    double getOpacity() const;
    int setDisabledButton(const int &index, const bool &disable = false);

protected:
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void focusOutEvent(QFocusEvent* event);
    void changeEvent(QEvent *event);

signals:
    void signalClicked(const int index);
    void signalCurrentIndex(const int index);
    void signalCurrentContent(const QString content);
    void signalCurrentIndexContent(const int index, const QString content);

public slots:
    void fadeOut();

private slots:
    void slotClose();
    void slotButtonReleased(const int index);
    void slotButtonPressed(const int index);

private:
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    void gesture(QMouseEvent *event);
    int showAnimation();
    int closeAnimation();

    /// Data members
    bool m_hide = false;
    bool m_hiding = false;
    bool m_gesture = false;
    double m_opacity = 1.0;

    /// Qt members
    Qt::Edge m_edge = Qt::BottomEdge;
    QPoint m_delta;
    QTimer *m_hideTimer = nullptr;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QButtonGroup *buttonGroup = nullptr;
};

#endif /// STOUCHBAR_H
