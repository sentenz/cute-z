#ifndef STOUCHDIALOGSCREENSAVER_H
#define STOUCHDIALOGSCREENSAVER_H

#include <QDialog>
#include "../build/SGlobal.h"

class QString;
class QPropertyAnimation;

class SIconButton;


class STouchDialogScreensaver : public QDialog
{
    Q_OBJECT

public:
    explicit STouchDialogScreensaver(QWidget *parent = 0);

protected:
    void showEvent(QShowEvent *event);
    void changeEvent(QEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);

signals:

private slots:
    void slotClose();

private:
    void setupWidget();
    void setupGUI();
    void setConnect();
    void retranslateUI();
    void restyleUI();


    QColor background_color = ::GlobalColorBase;
    QTimer *timer = nullptr;
    QPropertyAnimation *animation = nullptr;

    SIconButton * m_icon = nullptr;
};

#endif // STOUCHDIALOGSCREENSAVER_H
