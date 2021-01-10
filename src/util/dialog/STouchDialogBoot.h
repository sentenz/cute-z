#ifndef STOUCHDIALOGBOOT_H
#define STOUCHDIALOGBOOT_H

#include <QDialog>
#include "../build/SGlobal.h"

class QLabel;
class QButtonGroup;


class STouchDialogBoot : public QDialog
{
    Q_OBJECT

public:
    explicit STouchDialogBoot(QWidget *parent = 0);

    void setOpacity(const double opacity);
    void setBaseColor(const QColor &color = Qt::black);

protected:
    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent *event);
    void changeEvent(QEvent *event);

signals:

private slots:
    void slotButtonPressed(int index);
    void slotButtonReleased(int index);
    void slotClose();

private:
    void setupWidget();
    void setConnect();
    void retranslateUI();
    void restyleUI();
    QString formStyleSheetString(const QString &style = "");

    double m_opacitiy = 0.85;
    QColor m_colorBase = ::GlobalColorContrast;

    QLabel *labelShutdown = nullptr;
    QLabel *labelRestart = nullptr;
    QLabel *labelCancel = nullptr;
    QButtonGroup *buttonGroup = nullptr;
};

#endif /// STOUCHDIALOGBOOT_H
