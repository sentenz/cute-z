#ifndef SVIEWHISTORYODOMETER_H
#define SVIEWHISTORYODOMETER_H

#include "../widget/base/SBaseDialog.h"

#include <QHash>
#include <QWidget>

class QEvent;

class SAppBar;
class SInfoBar;
class SList;
class SFabButton;


class SViewHistoryOdometer : public SBaseDialog
{
    Q_OBJECT

public:
    explicit SViewHistoryOdometer(QWidget * parent = nullptr);
    ~SViewHistoryOdometer();

    void title(const QString text);
    QString title() const;

    void quantity(const int value);
    int quantity() const;

protected:
    void showEvent(QShowEvent * event);

signals:
    void signalReturn();
    void signalOption(const int index);
    void signalStream(const int quantity);
    void signalStatistics();

private slots:
    void slotStream(QHash<QString, QString> hash);
    void slotStatistics(QHash<QString, QString> hash);
    void slotClearHistory();
    void slotList();

private:
    /* Funtion members */
    void setupWidget();
    void updateWidget();
    void setupLayout();
    void setConnect();

    QString html(const QString top, const QString bottom, const QString unit = "");

    /* Data members */
    int m_quantity = 50;

    /* Qt members */
    QString m_title = tr("History");

    /* UI menbers */
    SAppBar * appBar = nullptr;
    SInfoBar * infoBar = nullptr;
    SList * list = nullptr;
    SFabButton * m_fab = nullptr;
};

#endif /* SVIEWHISTORYODOMETER_H */
