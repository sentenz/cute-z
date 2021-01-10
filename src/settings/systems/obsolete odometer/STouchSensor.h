#ifndef STOUCHSENSOR_H
#define STOUCHSENSOR_H

#include <QDialog>

class QLabel;
class QSettings;

class STouchKeyboard;
class STouchFlickableList;
class SReturnButton;


class STouchSensor : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSensor(QWidget *parent = 0);
    ~STouchSensor();

    SReturnButton *backButton = nullptr;

protected:
    void changeEvent(QEvent *event);

signals:

private slots:
    void slotFlickEvent(const int &index);
    void slotWriteSettings();
    void slotReadSettings();

private:
    void setupWidget();
    void setupGUI();
    void setConnect();
    void retranslateUI();

    QLabel *labelTitle = nullptr;
    QString filterOrder = "";
    QString filterCutFreqC = "";
    QString filterCutFreq1 = "";
    QString filterCutFreq2 = "";
    double threshold = 0.0;

    QSettings *settings = nullptr;

    STouchKeyboard *touchKeyboard = nullptr;
    STouchFlickableList *touchFlickable = nullptr;
};

#endif /// STOUCHSENSOR_H
