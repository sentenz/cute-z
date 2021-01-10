#ifndef STOUCHINFOMAINTENANCE_H
#define STOUCHINFOMAINTENANCE_H

#include "../build/SGlobal.h"

#include <QDialog>

class SLabel;
class SList;


class STouchInfoMaintenance : public QDialog
{
    Q_OBJECT

public:
    explicit STouchInfoMaintenance(QWidget *parent = nullptr);
    ~STouchInfoMaintenance();

protected:
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

private slots:

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

    SLabel * header = nullptr;
    SList * list = nullptr;
};

#endif /// STOUCHINFOMAINTENANCE_H
