#ifndef STOUCHSETTINGSSYSTEMNFC_H
#define STOUCHSETTINGSSYSTEMNFC_H

#include "../build/SGlobal.h"

#include <QDialog>

class QFileSystemWatcher;

class SLabel;
class SList;


class STouchSettingsSystemNFC : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSettingsSystemNFC(QWidget *parent = nullptr);
    ~STouchSettingsSystemNFC();

    void setCloseable(const bool closeable = false);

protected:
    void changeEvent(QEvent *event);
    void showEvent(QShowEvent *event);

signals:
    void signalReturn();

private slots:
    void slotList(const int index);
    void slotWriteSettings();
    void slotReadSettings();

private:
    // Function members
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    // Data members
    bool m_closeable = false;
    int m_minValue = -1;
    int m_maxValue = -1;
    int m_direction = 0;

    // Qt members
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QFileSystemWatcher * fileSystemWatcher = nullptr;

    // Sentenz members
    SLabel * header = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHSETTINGSSYSTEMNFC_H
