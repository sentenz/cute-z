#ifndef STOUCHSETTINGSSYSTEM_H
#define STOUCHSETTINGSSYSTEM_H

#include "../build/SGlobal.h"

#include <QDialog>
#include <QBasicTimer>

class QTimerEvent;

class SAppBar;
class SList;
class SAnimatedStackedWidget;
class STouchSettingsSystemNFC;
class STouchSettingsSystemEncoder;


class STouchSettingsSystem : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSettingsSystem(QWidget * parent = nullptr);
    ~STouchSettingsSystem();

protected:
    void timerEvent(QTimerEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

private slots:
    void slotList(const QString &content);
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

    /* Qt members */
    QString m_title = tr("Systems");
    QBasicTimer basicTimer;

    /* UI menbers */
    SAppBar * appBar = nullptr;
    SList * list = nullptr;
    SAnimatedStackedWidget * stackedWidget = nullptr;
    STouchSettingsSystemNFC * touchSettingsSystemNFC = nullptr;
    STouchSettingsSystemEncoder * touchSettingsSystemEncoder = nullptr;
};

#endif /// STOUCHSETTINGSSYSTEM_H
