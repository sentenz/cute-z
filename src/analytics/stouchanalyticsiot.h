#ifndef STOUCHANALYTICSIOT_H
#define STOUCHANALYTICSIOT_H

#include "../build/SGlobal.h"

#include <QDialog>

class QEvent;

class SList;


class STouchAnalyticsIot : public QDialog
{
    Q_OBJECT

public:
    explicit STouchAnalyticsIot(QWidget *parent = 0);
    ~STouchAnalyticsIot();

protected:
    void changeEvent(QEvent *event);
    void focusInEvent(QFocusEvent *event);

signals:

private slots:

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    SList * list = nullptr;
};

#endif // STOUCHANALYTICSIOT_H
