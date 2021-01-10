#ifndef STOUCHDATABASEENCODER_H
#define STOUCHDATABASEENCODER_H

#include "../build/SGlobal.h"

#include <QDialog>
#include <QBasicTimer>

class QTimerEvent;

class SLabel;
class SList;
class SAnimatedStackedWidget;
//class STouchDatabaseEncoderID;


class STouchDatabaseEncoder : public QDialog
{
    Q_OBJECT

public:
    explicit STouchDatabaseEncoder(QWidget *parent = 0);
    ~STouchDatabaseEncoder();

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
    void setupGUI();
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
//    STouchDatabaseEncoderID *touchDatabaseEncoderID = nullptr;
};

#endif // STOUCHDATABASEENCODER_H
