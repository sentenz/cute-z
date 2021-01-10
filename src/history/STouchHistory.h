#ifndef STOUCHHISTORY_H
#define STOUCHHISTORY_H

#include "../build/SGlobal.h"

#include <QWidget>
#include <QBasicTimer>

class QTimerEvent;

class SAppBar;
class SList;


class STouchHistory : public QWidget
{
    Q_OBJECT

public:
    explicit STouchHistory(QWidget * parent = nullptr);
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

    /* Qt members */
    QString m_title = tr("History");
    QBasicTimer basicTimer;

    /* UI menbers */
    SAppBar * appBar = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHHISTORY_H
