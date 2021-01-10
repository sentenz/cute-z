#ifndef STOUCHSETTINGSSYSTEMENCODER_H
#define STOUCHSETTINGSSYSTEMENCODER_H

#include "../build/SGlobal.h"

#include <QDialog>

class QFileSystemWatcher;

class SLabel;
class SList;


class STouchSettingsSystemEncoder : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSettingsSystemEncoder(QWidget *parent = nullptr);
    ~STouchSettingsSystemEncoder();

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
    void updateWidget();
    void retranslateUI();
    void restyleUI();

    // Data members
    bool m_closeable = false;
    int m_clockwise = 0;
    int m_precision = 0;
    double m_diameter = 0.0;

    // Qt members
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QFileSystemWatcher *fileSystemWatcher = nullptr;

    // Sentenz members
    SLabel * header = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHSETTINGSSYSTEMENCODER_H
