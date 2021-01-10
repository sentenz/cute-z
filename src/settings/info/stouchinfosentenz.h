#ifndef STOUCHINFOSENTENZ_H
#define STOUCHINFOSENTENZ_H

#include "../build/SGlobal.h"

#include <QDialog>

class SLabel;
class SList;


class STouchInfoSentenz : public QDialog
{
    Q_OBJECT

public:
    explicit STouchInfoSentenz(QWidget *parent = nullptr);
    ~STouchInfoSentenz();

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

#endif // STOUCHINFOSENTENZ_H
