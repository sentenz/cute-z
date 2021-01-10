#ifndef STOUCHDATETIME_H
#define STOUCHDATETIME_H

#include "../build/SGlobal.h"

#include <QLCDNumber>

class QEvent;

class SLabel;
class SList;


class STouchDateTime : public QLCDNumber
{
    Q_OBJECT

public:
    explicit STouchDateTime(QWidget *parent = nullptr);
    ~STouchDateTime();

protected:
    void changeEvent(QEvent *event);
    void focusOutEvent(QFocusEvent *event);
    void paintEvent(QPaintEvent *event);

signals:
    void signalReturn();

private slots:
    void slotUpdateWidgeds();

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

    QTimer * timer = nullptr;

    SLabel * header = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHDATETIME_H
