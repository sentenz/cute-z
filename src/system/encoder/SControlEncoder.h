#ifndef SCONTROLENCODER_H
#define SCONTROLENCODER_H

#include "../build/SGlobal.h"
#include <QDialog>

class QLabel;
class QString;
class QPushButton;
class QVBoxLayout;
class QStackedWidget;

class SEngine;
class STouchEncoder;


class SControlEncoder : public QDialog
{
    Q_OBJECT

public:
    explicit SControlEncoder(QWidget *parent = 0);
    ~SControlEncoder();

    void stop();
    void pause();
    bool isRunning() const;

protected:
    void changeEvent(QEvent *event);

signals:
    void signalReturn();
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
    SEngine * engine = nullptr;
    STouchEncoder * touchEncoder = nullptr;
};

#endif /// SCONTROLENCODER_H
