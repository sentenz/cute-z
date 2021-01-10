#ifndef STOUCHHISTORY_H
#define STOUCHHISTORY_H

#include "../build/SGlobal.h"

#include <QDialog>
#include <QBasicTimer>

class QTimerEvent;

class SLabel;
class SList;
class SAnimatedStackedWidget;


class STouchHistory : public QDialog
{
    Q_OBJECT

public:
    explicit STouchHistory(QWidget * parent = 0);
    ~STouchHistory();

protected:
    void timerEvent(QTimerEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

private slots:
    void slotList(const QString &content);
    void slotReturn();

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

    QBasicTimer basicTimer;

    SLabel * header = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHHISTORY_H
