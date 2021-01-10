#ifndef SVIEWHISTORYOPTIONS_H
#define SVIEWHISTORYOPTIONS_H

#include "../build/SGlobal.h"
#include "../widget/base/SBaseDialog.h"

#include <QBasicTimer>

class QTimerEvent;

class SLabel;
class SList;


class SViewHistoryOptions : public SBaseDialog
{
    Q_OBJECT

public:
    explicit SViewHistoryOptions(QWidget * parent = nullptr);
    ~SViewHistoryOptions();

protected:
    void timerEvent(QTimerEvent * event);
    void changeEvent(QEvent * event);

signals:
    void signalReturn();
    void signalOption();
    void signalId(const int id);

private slots:
    void slotList(const QString &content);

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

#endif /* SVIEWHISTORYOPTIONS_H */
