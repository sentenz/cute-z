#ifndef STOUCHREGISTRATION_H
#define STOUCHREGISTRATION_H

#include <QDialog>

class QShowEvent;

class SAnimation;


class STouchRegistration : public QDialog
{
    Q_OBJECT

public:
    explicit STouchRegistration(QWidget *parent = 0);
    ~STouchRegistration();

    bool isVerified();

protected:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalShowed();
    void signalClosed();


private slots:
    void slotCheckSerialnumber();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    uint64_t getMAC();
    void writeSettings();
    void readSettings();

    uint64_t sn = 0;
    bool verification = false;

    SAnimation *animation = nullptr;
};

#endif /// STOUCHREGISTRATION_H
