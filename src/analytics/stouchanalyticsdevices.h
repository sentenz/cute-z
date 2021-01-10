#ifndef STOUCHANALYTICSDEVICES_H
#define STOUCHANALYTICSDEVICES_H

#include "../build/SGlobal.h"
#include <QColor>
#include <QDialog>

class QTimer;

class STouchFlickableList;


class STouchAnalyticsDevices : public QDialog
{
    Q_OBJECT

public:
    explicit STouchAnalyticsDevices(QWidget *parent = 0);
    ~STouchAnalyticsDevices();

    void setBaseColor(const QColor &color);
    void setContrastColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setHighlightColor(const QColor &color);

protected:
    void changeEvent(QEvent *event);
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);

signals:

private slots:
    void slotUpdateWidgeds();

private:
    void setupLayout();
    void setConnect();
    void retranslateUI();
    bool checkI2C(const int &addr);

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QTimer *timer = nullptr;

    STouchFlickableList *touchFlickable = nullptr;
};

#endif /// STOUCHANALYTICSDEVICES_H
