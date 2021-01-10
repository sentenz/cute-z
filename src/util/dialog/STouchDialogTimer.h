#ifndef STOUCHDIALOGTIMER_H
#define STOUCHDIALOGTIMER_H

#include "../build/SGlobal.h"

#include <QDialog>

class QTimeLine;


class STouchDialogTimer : public QDialog
{
    Q_OBJECT

public:
    explicit STouchDialogTimer(QWidget *parent = 0);

    void setTime(const int sec);
    void setOpacity(const double opacity);

protected:
    void paintEvent(QPaintEvent *event);
    void changeEvent(QEvent *event);
    void showEvent(QShowEvent *event);

signals:

private slots:
    void slotFinished();

private:
    void setupWidget();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    int m_counter = 0;
    double m_frameFactor = 0.0;
    double m_opacitiy = 0.9;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QTimeLine *m_timeLine = nullptr;
};

#endif // STOUCHDIALOGTIMER_H
