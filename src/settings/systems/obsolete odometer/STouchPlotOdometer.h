#ifndef STOUCHPLOTODOMETER_H
#define STOUCHPLOTODOMETER_H

#include <QtGlobal>
#include <QDialog>
#include <QBasicTimer>

class QLabel;
class QTimerEvent;

#if QT_VERSION < QT_VERSION_CHECK(5, 7, 0)
    class SPlotQwt;
#else
    class SPlot;
#endif
class SReturnButton;


class STouchPlotOdometer : public QDialog
{
    Q_OBJECT

public:
    explicit STouchPlotOdometer(QWidget *parent = 0);
    ~STouchPlotOdometer();

    SReturnButton *backButton = nullptr;

protected:
    void timerEvent(QTimerEvent *event);
    void changeEvent(QEvent *event);

signals:

private slots:
    void slotBackEvent();

private:
    void setUpWidget();
    void setUpGUI();
    void setConnect();
    void retranslateUI();

    QVector<QPointF> readFile();

    QLabel *labelTitle = nullptr;
    QBasicTimer basicTimer;

    #if QT_VERSION < QT_VERSION_CHECK(5, 7, 0)
        SPlotQwt *plot = nullptr;
    #else
        SPlot *plot = nullptr;
    #endif
};

#endif /// STOUCHPLOTODOMETER_H
