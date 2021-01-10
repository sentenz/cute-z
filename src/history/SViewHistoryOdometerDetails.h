#ifndef SVIEWHISTORYODOMETERDETAILS_H
#define SVIEWHISTORYODOMETERDETAILS_H

#include "../build/SGlobal.h"
#include "../database/SDatabaseOdometer.h"

#include <QDialog>
#include <QHash>

class QEvent;

class SLabel;
class SList;


class SViewHistoryOdometerDetails : public QDialog
{
    Q_OBJECT

public:
    explicit SViewHistoryOdometerDetails(QWidget *parent = nullptr);
    ~SViewHistoryOdometerDetails();

    void setCloseable(const bool closeable);

protected:
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

private slots:
    void slotList(const int index);
    void slotAppendList(QHash<QString, QString> hash);

private:
    // Funtion members
    void setupWidget();
    void updateWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    QString setHtmlText(const QString topText, const QString bottomText, const QString unit = "");

    // Data members
    bool m_closeable = false;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QTimer * timer = nullptr;

    SDatabaseOdometer database;

    // UI menbers
    SLabel * header = nullptr;
    SLabel * labelTotalTime = nullptr;
    SLabel * labelTotalLength = nullptr;
    SLabel * labelTotalOrders = nullptr;
    SList * list = nullptr;
};

#endif /* SVIEWHISTORYODOMETERDETAILS_H */
