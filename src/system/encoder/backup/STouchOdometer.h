#ifndef STOUCHODOMETER_H
#define STOUCHODOMETER_H

#include <QDialog>

#ifdef S_LOGGER
#include "SLogger.h"
#endif

class QLabel;
class QPushButton;
class QVBoxLayout;
class QString;
class QKeyEvent;
class QTimer;

class SOdometer;
class SEngine;
class SDatabase;
class STouchKeyboard;


class STouchOdometer : public QDialog
{
    Q_OBJECT

public:
    explicit STouchOdometer(QWidget *parent = 0);
    ~STouchOdometer();

protected:
    void changeEvent(QEvent *event);

signals:

private slots:
    void slotCircleButton();
    void slotStartButton();
    void slotCorrectButton();
    void slotReset();
    void slotSetValue(QString text);
    void slotForward();
    void slotBackward();
    void slotNeutral();
    void slotStartOdometer();
    void slotStopOdometer();

private:
    void setUpWidget();
    void setUpGUI();
    void setConnect();
    void retranslateUI();
    QString formStyleSheetString(const QString &style, const QString &icon = QString(""));

    QTimer *timer = nullptr;
    QLabel *labelTextID = nullptr;
    QLabel *labelID = nullptr;
    QLabel *labelTextOrder = nullptr;
    QLabel *labelOrder = nullptr;
    QLabel *labelTextMeasured = nullptr;
    QLabel *labelMeasured = nullptr;
    QLabel *labelValues = nullptr;
    QPushButton *buttonStart = nullptr;
    QPushButton *buttonCancel = nullptr;
    QPushButton *buttonCorrect = nullptr;
    QPushButton *buttonCircle = nullptr;

    int status = 0;
    bool forward = true;
    bool backward = false;
    double order = 0.0;
    double odoValue = 0.0;
    double odoMeasured = 0.0;

    SOdometer *odometer = nullptr;
    SEngine *engine = nullptr;
    SDatabase *database = nullptr;
    STouchKeyboard *touchKeyboard = nullptr;

    #ifdef S_LOGGER
    SLogger loggerWave;
    SLogger loggerPhase;
    SLogger loggerUnwrap;
    #endif
};

#endif /// STOUCHODOMETER_H
