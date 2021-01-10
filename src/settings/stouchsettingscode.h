#ifndef STOUCHSETTINGSCODE_H
#define STOUCHSETTINGSCODE_H

#include "../build/SGlobal.h"
#include "../widget/util/SSnackbar.h"

#include <QDialog>

class QFileSystemWatcher;

class SAppBar;
class SList;


class STouchSettingsCode : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSettingsCode(QWidget *parent = nullptr);
    ~STouchSettingsCode();

protected:
    void changeEvent(QEvent * event);

signals:
    void signalReturn();

private slots:
    void slotList(const int index);
    void slotWriteSettings();
    void slotReadSettings();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void updateWidget();
    void retranslateUI();
    void restyleUI();

    bool setActivation(const int index);
    bool setCode(const int index);
    bool setScreenlockTime();
    bool setScreensaverTime();

    int m_screenLock = 0;
    int m_screenSaver = 0;
    QString m_userCode = "";
    QString m_operatorCode = "";

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QFileSystemWatcher *fileSystemWatcher = nullptr;

    /* Qt members */
    QString m_title = tr("Passcode");

    /* UI menbers */
    SAppBar * appBar = nullptr;

    SList * list = nullptr;
    SSnackbar m_snackbar;
};

#endif // STOUCHSETTINGSCODE_H
