#ifndef STOUCHPANELENGINE_H
#define STOUCHPANELENGINE_H

#include "../build/SGlobal.h"

#include <QWidget>

class SAppBar;
class SRaisedButton;
class SEngine;


class STouchPanelEngine : public QWidget
{
    Q_OBJECT

public:
    explicit STouchPanelEngine(QWidget *parent = nullptr);
    ~STouchPanelEngine();

protected:
    void changeEvent(QEvent *event);

signals:
    void signalReturn();
    void signalOptions();

public slots:
    void slotEngineUp();
    void slotEngineStop();
    void slotEngineDown();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    /* Data members */
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    /* String members */
    QString m_title = tr("Control Panel");

    /* UI menbers */
    SAppBar * appBar = nullptr;

    /* Sentenz members */
    SRaisedButton * m_buttonUp = nullptr;
    SRaisedButton * m_buttonDown = nullptr;
    SEngine * engine = nullptr;
};

#endif /// STOUCHPANELENGINE_H

