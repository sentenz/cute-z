#ifndef STOUCHSYSTEMOPTIONS_H
#define STOUCHSYSTEMOPTIONS_H

#include <QDialog>

class QLabel;
class QSettings;

class STouchFlickableList;
class SReturnButton;


class STouchSystemsOptions : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSystemsOptions(QWidget *parent = 0);
    ~STouchSystemsOptions();

    SReturnButton *backButton = nullptr;

protected:
    void changeEvent(QEvent *event);

signals:

private slots:
    void slotFlickEvent1(const int &index);
    void slotFlickEvent2(const int &index);
    void slotFlickEvent3(const int &index);
    void slotWriteSettings();
    void slotReadSettings();

private:
    void setupWidget();
    void setupGUI();
    void setConnect();
    void retranslateUI();
    QString formStyleSheetString(const QString &style = "");

    QString procedure = "";
    QString filterType = "";
    int samplerate = 0;

    QLabel *labelTitle = nullptr;
    QLabel *flickTitle1 = nullptr;
    QLabel *flickTitle2 = nullptr;
    QLabel *flickTitle3 = nullptr;

    STouchFlickableList *touchFlickable1 = nullptr;
    STouchFlickableList *touchFlickable2 = nullptr;
    STouchFlickableList *touchFlickable3 = nullptr;

    QSettings *settings = nullptr;
};

#endif /// STOUCHSYSTEMOPTIONS_H
