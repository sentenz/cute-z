#ifndef SCENTRAL_H
#define SCENTRAL_H

#include <QMainWindow>
#include <QBasicTimer>

#include "SGlobal.h"

class QString;
class QPoint;
class QFileSystemWatcher;
class QEvent;
class QObject;
class QTimerEvent;

class SControlEncoder;
class SControlNFC;
class STouchPanel;
class STouchSettings;
class STouchScreenlock;
class STouchHome;
class SAnimatedStackedWidget;
class SNavigationDrawer;
class SSnackbar;


class SCentral : public QMainWindow
{
    Q_OBJECT

public:
    explicit SCentral(QWidget *parent = nullptr);
    ~SCentral();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void showEvent(QShowEvent *event);
    void timerEvent(QTimerEvent *event);
    void changeEvent(QEvent *event);

private slots:
    void slotWriteSettings();
    void slotReadSettings();

private:
    /* Function members */
    void setupWidget();
    void setupLayout();
    void updateWidget();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    void setLock();
    void setScreensaver();
    void setLockTimer();
    void showGesture(QMouseEvent *event);

    /* Data members */
    bool m_init = false;
    bool m_appActive = false;
    bool m_screenLockEnabled = false;
    int m_screenLockTime = 0;
    int m_screenSaverTime = 0;
    int m_colorMode = 0;

    /* Qt members */
    QPoint *m_delta = nullptr;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QBasicTimer basicTimerLock;
    QBasicTimer basicTimerScreensaver;
    QFileSystemWatcher * fileSystemWatcher = nullptr;

    /* Sentenz members */
    SAnimatedStackedWidget * stackedWidget = nullptr;
    SControlEncoder * controlEncoder = nullptr;
    SControlNFC * controlNFC = nullptr;
    STouchPanel * touchPanel = nullptr;
    STouchSettings * touchSettings = nullptr;
    STouchScreenlock * touchScreenlock = nullptr;
    STouchHome * touchHome = nullptr;
    SNavigationDrawer * m_drawer = nullptr;
    SSnackbar * m_snackbar = nullptr;
};

#endif /// SCENTRAL_H
