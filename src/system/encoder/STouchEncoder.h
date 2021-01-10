#ifndef STOUCHENCODER_H
#define STOUCHENCODER_H

#include "SThreadEncoder.h"
#include "../build/SGlobal.h"

#include <QDialog>
#include <QElapsedTimer>

class QLabel;
class QString;
class QFileSystemWatcher;

class SAppBar;
class SInfoBar;
class SLabel;
class SVTumbler;
class SToolButton;
class SFabButton;


class STouchEncoder : public QDialog
{
    Q_OBJECT

public:
    explicit STouchEncoder(QWidget *parent = 0);
    ~STouchEncoder();

    void setTitle(const QString text);
    QString title() const;

    // Function members
    bool up();
    bool down();
    void stop();
    void pause();
    void setValue(const int value);
    void setCloseable(const bool closeable = false);
    int getValue() const;
    int minimumValue() const;
    int maximumValue() const;

protected:
    void showEvent(QShowEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalReturn();
    void signalRun(const bool run);

public slots:
    void slotRun(const bool run);

private slots:
    void slotDataTransfer(const double value);
    void slotReadSettings();
    void slotDialogMessage();
    void slotErrorMessage();

private:
    // Function members
    void setupWidget();
    void setupLayout();
    void updateWidget();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    void playThread();
    void pauseThread();
    void stopThread();
    void initInfo();
    void resetInfo();
    void resetMembers();
    bool keyboard();
    double circumference(const double angle);
    void setDatabase(const bool completed);

    QString elided(const QLabel *label, const QString &text, const Qt::TextElideMode elide = Qt::ElideRight);
    QString html(const QString top, const QString bottom, const QString unit = "");

    // Data members
    bool m_up = false;
    bool m_down = false;
    bool m_oneshot = false;
    bool m_running = false;
    bool m_session = false;
    bool m_closeable = false;
    int m_clockwise = 0;
    int m_precision = 0;
    double m_diameter = 0.0;
    double m_minValue = 0.0;
    double m_maxValue = 0.0;
    double m_target = -0.0;
    double m_cumulate = -0.0;
    QString m_unit = tr("m");

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QElapsedTimer timer;

    // Qt members
    QLabel * labelTitle = nullptr;
    QLabel * labelFloat = nullptr;
    QFileSystemWatcher *fileSystemWatcher = nullptr;

    /* Qt members */
    QString m_title = tr("Odometer");

    /* UI menbers */
    SAppBar * appBar = nullptr;
    SInfoBar * infoBar = nullptr;
    SThreadEncoder * threadEncoder = nullptr;
    SVTumbler * touchTumbler = nullptr;
    SToolButton * buttonStop = nullptr;
    SToolButton * buttonPlay = nullptr;
    SToolButton * buttonDigits = nullptr;
    SFabButton * m_fabStop = nullptr;
    SFabButton * m_fabPad = nullptr;
};

#endif // STOUCHENCODER_H
