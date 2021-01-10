#ifndef STOUCHACTUATOR_H
#define STOUCHACTUATOR_H

#include <QDialog>

class QLabel;
class QSettings;
class QFileSystemWatcher;

class STouchKeyboard;
class STouchFlickableList;
class SReturnButton;


class STouchActuator : public QDialog
{
    Q_OBJECT

public:
    explicit STouchActuator(QWidget *parent = 0);
    ~STouchActuator();

    SReturnButton *backButton = nullptr;

protected:
    void changeEvent(QEvent *event);

signals:

private slots:
    void slotFlickEvent(const int &index);
    void slotWriteSettings();
    void slotReadSettings();

private:
    void setUpGUI();
    void setConnect();
    void retranslateUI();

    QLabel *labelTitle = nullptr;
    QString resolution = "";
    QString diameter = "";

    QSettings *settings = nullptr;
    //QFileSystemWatcher *fileSystemWatcher = nullptr;

    STouchKeyboard *touchKeyboard = nullptr;
    STouchFlickableList *touchFlickable = nullptr;
};

#endif /// STOUCHSETTINGSACTUATOR_H
