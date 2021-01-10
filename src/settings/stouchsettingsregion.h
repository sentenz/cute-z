#ifndef STOUCHSETTINGSREGION_H
#define STOUCHSETTINGSREGION_H

#include "../build/SGlobal.h"

#include <QDialog>
#include <QBasicTimer>

class QTimerEvent;

class SList;
class SLabel;
class SAnimatedStackedWidget;
class STouchLanguage;
class STouchDateTime;


class STouchSettingsRegion : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSettingsRegion(QWidget * parent = nullptr);
    ~STouchSettingsRegion();

protected:
    void timerEvent(QTimerEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

private slots:
    void slotList(const int index);
    void slotReturn();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QBasicTimer basicTimer;

    SLabel * header = nullptr;
    SList * list = nullptr;
    SAnimatedStackedWidget * stackedWidget = nullptr;
    STouchLanguage * touchLanguage = nullptr;
    STouchDateTime * touchDateTime = nullptr;
};

#endif /// STOUCHSETTINGSREGION_H
