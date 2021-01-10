#ifndef STOUCHNFC_H
#define STOUCHNFC_H

#include "SThreadNFC.h"
#include "../build/SGlobal.h"

#include <QDialog>


class QLabel;
class QString;
class QButtonGroup;
class QFileSystemWatcher;

class SLabel;
class SVTumbler;
class SToolButton;


class STouchNFC : public QDialog
{
    Q_OBJECT

public:
    explicit STouchNFC(QWidget *parent = 0);
    ~STouchNFC();

    // Function members
    void play();
    void stop();
    void pause();
    void setCloseable(const bool closeable = false);
    void setMode(const SThreadNFC::NFC mode = SThreadNFC::NFC::Read);
    void setValue(const int value);
    int getValue() const;
    bool up();
    bool down();
    int minimumValue() const;
    int maximumValue() const;
    bool unidirectional() const;
    bool bidirectional() const;
    int direction() const;

protected:
    void showEvent(QShowEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalReturn();
    void signalOptions();
    void signalRun(const bool run);

public slots:
    void slotRun(const bool run);

private slots:
    void slotDataTransfer(const int value);
    void slotReadSettings();
    void slotError();

private:
    // Function members
    void setupWidget();
    void setupLayout();
    void updateWidget();
    void setConnect();
    void restyleUI();

    void getDirection();
    bool keyboard();
    void transferTarget();
    void playThread();
    void pauseThread();
    void stopThread();
    void initInfo();
    void resetInfo();
    void resetMembers();
    void retranslateUI();
    void setMessage(const QString title, const QString text, const int time = 0);
    QString setElidedText(const QLabel *label, const QString &text, const Qt::TextElideMode elide = Qt::ElideRight);
    QString setHtmlText(const QString topText, const QString bottomText, const QString unit = "");

    // Data members
    bool m_running = false;
    bool m_session = false;
    bool m_closeable = false;
    int m_minValue = 0;
    int m_maxValue = 0;
    int m_direction = 0;
    int m_up = 0;
    int m_down = 0;
    int m_value = -1;
    int m_target = -1;
    SThreadNFC::NFC m_mode = SThreadNFC::NFC::Read;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    // Qt members
    QLabel * labelTitle = nullptr;
    QLabel * labelValue = nullptr;
    QLabel * labelTarget = nullptr;
    QLabel * labelDirection = nullptr;
    QButtonGroup * buttonGroup = nullptr;
    QFileSystemWatcher * fileSystemWatcher = nullptr;

    // Sentenz members
    SLabel * header = nullptr;
    SThreadNFC * threadNFC = nullptr;
    SVTumbler * touchTumbler = nullptr;
    SToolButton * buttonStop = nullptr;
    SToolButton * buttonPlay = nullptr;
    SToolButton * buttonDigits = nullptr;
};

#endif // STOUCHNFC_H
