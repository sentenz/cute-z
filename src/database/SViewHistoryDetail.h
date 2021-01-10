#ifndef SVIEWHISTORYDETAIL_H
#define SVIEWHISTORYDETAIL_H

#include "../widget/base/SBaseDialog.h"

#include <QHash>
#include <QWidget>

class QEvent;

class SLabel;
class SList;


class SViewHistoryDetail : public SBaseDialog
{
    Q_OBJECT

public:
    explicit SViewHistoryDetail(QWidget * parent = nullptr);
    ~SViewHistoryDetail();

    void title(const QString text);
    QString title() const;

    void quantity(const int value);
    int quantity() const;

protected:
    void showEvent(QShowEvent * event);

signals:
    void signalReturn();
    void signalOption();
    void signalStream(const int quantity);
    void signalStatistics();

private slots:
    void slotStream(QHash<QString, QString> hash);
    void slotStatistics(QHash<QString, QString> hash);
    void slotClearHistory();
    void slotList(const int index);

private:
    /* Funtion members */
    void setupWidget();
    void updateWidget();
    void setupLayout();
    void setConnect();

    QString html(const QString top, const QString bottom, const QString unit = "");

    /* Data members */
    int m_quantity = 50;

    /* String members */
    QString m_title = tr("History");

    /* UI menbers */
    SLabel * labelStatisticsTime = nullptr;
    SLabel * labelStatisticsLength = nullptr;
    SLabel * labelStatisticsOrders = nullptr;

    SLabel * header = nullptr;
    SList * list = nullptr;
};

#endif /* SVIEWHISTORYDETAIL_H */
