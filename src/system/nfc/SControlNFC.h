#ifndef SCONTROLNFC_H
#define SCONTROLNFC_H

#include "../build/SGlobal.h"
#include <QDialog>

class QLabel;
class QString;
class QPushButton;
class QVBoxLayout;
class QStackedWidget;

class SEngine;
class STouchNFC;


class SControlNFC : public QDialog
{
    Q_OBJECT

public:
    explicit SControlNFC(QWidget *parent = 0);
    ~SControlNFC();

    void stop();
    void pause();
    bool isRunning() const;

protected:
    void changeEvent(QEvent *event);

signals:
    void signalReturn();
    void signalOptions();
    void signalRun(const bool run);

private slots:
    void slotRun(const bool run);

private:
    // Function members
    void setupWidget();
    void setupLayout();
    void setConnect();
    void setDirectionForward();
    void setDirectionBackward();
    void setDirectionNeutral();
    void retranslateUI();

    // Data members
    bool m_running = false;

    // Sentenz members
    SEngine *engine = nullptr;
    STouchNFC *touchNFC = nullptr;
};

#endif /// SCONTROLNFC_H
