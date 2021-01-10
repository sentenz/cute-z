#ifndef STOUCHSETTINGSDESIGN_H
#define STOUCHSETTINGSDESIGN_H

#include "../build/SGlobal.h"

#include <QDialog>

class QFileSystemWatcher;

class SAppBar;
class SList;


class STouchSettingsDesign : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSettingsDesign(QWidget * parent = nullptr);
    ~STouchSettingsDesign();

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

    int m_itemShape = 0;
    int m_colorMode = 0;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorHighlight = ::GlobalColorHighlight;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorBar = ::GlobalColorBase;

    QFileSystemWatcher * fileSystemWatcher = nullptr;

    /* Qt members */
    QString m_title = tr("History");

    /* UI menbers */
    SAppBar * appBar = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHSETTINGSDESIGN_H
