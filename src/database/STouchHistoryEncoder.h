#ifndef STOUCHHISTORYENCODER_H
#define STOUCHHISTORYENCODER_H

#include "../build/SGlobal.h"
#include "../database/SDatabase.h"

#include <QDialog>
#include <QHash>

class QEvent;

class SLabel;
class SList;


class STouchHistoryEncoder : public QDialog
{
    Q_OBJECT

public:
    explicit STouchHistoryEncoder(QWidget *parent = nullptr);
    ~STouchHistoryEncoder();

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

    SDatabase database;

    // UI menbers
    SLabel * header = nullptr;
    SLabel * labelTotalTime = nullptr;
    SLabel * labelTotalLength = nullptr;
    SLabel * labelTotalOrders = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHHISTORYENCODER_H
