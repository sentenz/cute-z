#ifndef STOUCHINFOMODULE_H
#define STOUCHINFOMODULE_H

#include "../build/SGlobal.h"

#include <QDialog>

class SLabel;
class SList;


class STouchInfoModule : public QDialog
{
    Q_OBJECT

public:
    explicit STouchInfoModule(QWidget *parent = nullptr);
    ~STouchInfoModule();

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

#endif // STOUCHINFOMODULE_H
