#ifndef STOUCHSETTINGSINFO_H
#define STOUCHSETTINGSINFO_H

#include "../build/SGlobal.h"

#include <QDialog>
#include <QBasicTimer>

class QTimerEvent;

class SList;
class SLabel;
class SAnimatedStackedWidget;
class STouchInfoSentenz;
class STouchInfoModule;
class STouchInfoMaintenance;


class STouchSettingsInfo : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSettingsInfo(QWidget *parent = nullptr);
    ~STouchSettingsInfo();

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
    STouchInfoSentenz * touchInfoSentenz = nullptr;
    STouchInfoModule * touchInfoModule = nullptr;
    STouchInfoMaintenance * touchInfoMaintenance = nullptr;
};

#endif // STOUCHSETTINGSINFO_H
