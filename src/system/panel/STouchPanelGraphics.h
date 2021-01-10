#ifndef STOUCHPANELGRAPHICS_H
#define STOUCHPANELGRAPHICS_H

#include <QDialog>
#include <QList>
#include <QEvent>

class QGridLayout;

class SToolButton;
class SEngine;


class STouchPanelGraphics : public QDialog
{
    Q_OBJECT

public:
    explicit STouchPanelGraphics(QWidget *parent = 0);
    ~STouchPanelGraphics();

protected:
    //bool event(QEvent *event);
    void changeEvent(QEvent *event);

public slots:
    void slotAddButton();
    void slotRemoveButton();

public slots:
    void slotButtonPressed();
    void slotButtonReleased();
    void slotButtonToggled();
    void slotArrangeButton();
    void slotRemoveAllButtons();

private:
    void setupWidget();
    void setupGUI();
    void setConnect(SToolButton *button);
    void disConnect(SToolButton *button);
    int getButton();
    void retranslateUI();

    QList<SToolButton *> list;
    QGridLayout *layout = nullptr;

    SEngine *engine = nullptr;
};

#endif /// STOUCHPANELGRAPHICS_H

