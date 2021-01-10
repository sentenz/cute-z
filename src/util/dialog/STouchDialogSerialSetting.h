#ifndef STOUCHDIALOGSERIALSETTING_H
#define STOUCHDIALOGSERIALSETTING_H

#include "../build/SGlobal.h"

#include <QDialog>

class QString;
class QPushButton;

class STouchFlickableList;


class STouchDialogSerialSetting : public QDialog
{
    Q_OBJECT

public:
    explicit STouchDialogSerialSetting(QWidget *parent = 0);
    ~STouchDialogSerialSetting();

    void setText(const QString &text);
    void setOpacity(const double opacity);
    void setBaseColor(const QColor &color = Qt::black);
    bool isAccepted();

protected:
    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent *event);
    void changeEvent(QEvent *event);

signals:

private slots:
    void slotFlickEvent(const int &index);
    void slotAccept();
    void slotClose();

private:
    void setupWidget();
    void setupGUI();
    void setConnect();
    void retranslateUI();
    QString formStyleSheetString(const QString &style = "");
    void setInternVisible(bool visible);
    void setSerialCommunication(const int &index);
    void removeSerialCommunication();
    void setSerialGeneric(const int &index);
    QString setKeyboard(QString title, int min, int max, int digits);
    void setGPIO();
    void setUART();
    void setI2C();
    void setSPI();
    void setOneWire();
    void setUSB();
    void setBluetooth();
    void setEthernet();
    void setWiFi();

    enum class Serial
    {
        GPIO = 0,
        UART,
        I2C,
        SPI,
        OneWire,
        USB,
        Bluetooth,
        Ethernet,
        WiFi
    } serial;

    bool accepted = false;
    double m_opacitiy = 0.9;

    QColor background_color = QColor(::GlobalColorBase);
    QPushButton *buttonAccept = nullptr;
    QPushButton *buttonCancel = nullptr;

    STouchFlickableList *touchFlickable = nullptr;
};

#endif /// STOUCHDIALOGSERIALSETTING_H
