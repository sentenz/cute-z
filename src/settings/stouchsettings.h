#ifndef STOUCHSETTINGS_H
#define STOUCHSETTINGS_H

#include "../build/SGlobal.h"

#include <QWidget>
#include <QBasicTimer>

class QTimerEvent;
class QStackedWidget;

class SAppBar;
class SList;
class SPushButton;
class SAnimatedStackedWidget;
class STouchAnalytics;
class STouchHistory;
class STouchTools;
class STouchSettingsSystem;
class STouchSettingsCode;
class STouchSettingsRegion;
class STouchSettingsDesign;
class STouchSettingsReset;
class STouchSettingsInfo;


class STouchSettings : public QWidget
{
    Q_OBJECT

public:
    explicit STouchSettings(QWidget *parent = nullptr);
    ~STouchSettings();

    void setBaseColor(const QColor &color);
    void setContrastColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setHighlightColor(const QColor &color);

protected:
    void timerEvent(QTimerEvent *event);
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

public slots:
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

    /* Qt members */
    QString m_title = tr("Options");
    QBasicTimer basicTimer;

    /* UI menbers */
    SAppBar * appBar = nullptr;
    SList * list = nullptr;
    SAnimatedStackedWidget * stackedWidget = nullptr;
    STouchAnalytics * touchAnalytics = nullptr;
    STouchHistory * touchHistory = nullptr;
    STouchTools * touchTools = nullptr;
    STouchSettingsSystem * touchSettingsSystem = nullptr;
    STouchSettingsCode * touchSettingsCode = nullptr;
    STouchSettingsRegion * touchSettingsRegion = nullptr;
    STouchSettingsDesign * touchSettingsDesign = nullptr;
    STouchSettingsReset * touchSettingsReset = nullptr;
    STouchSettingsInfo * touchSettingsInfo = nullptr;
};

#endif // STOUCHSETTINGS_H
