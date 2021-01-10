#ifndef STOUCHANALYTICSINPUTS_H
#define STOUCHANALYTICSINPUTS_H

#include "../build/SGlobal.h"

#include <QDialog>

class QTimer;
class QEvent;

class SList;


class STouchAnalyticsInputs : public QDialog
{
    Q_OBJECT

public:
    explicit STouchAnalyticsInputs(QWidget *parent = 0);
    ~STouchAnalyticsInputs();

protected:
    void changeEvent(QEvent *event);
    void focusInEvent(QFocusEvent *event);
    void focusOutEvent(QFocusEvent *event);

signals:

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

    SList * list = nullptr;
};

#endif // STOUCHANALYTICSINPUTS_H
