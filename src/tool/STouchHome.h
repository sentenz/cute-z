#ifndef STOUCHHOME_H
#define STOUCHHOME_H

#include "../build/SGlobal.h"

#include <QDialog>

class SAppBar;
class SList;


class STouchHome : public QDialog
{
    Q_OBJECT

public:
    explicit STouchHome(QWidget * parent = nullptr);
    ~STouchHome();

protected:
    void changeEvent(QEvent *event);

signals:
    void signalDrawer();
    void signalOption();
    void signalReleased(const int index);

private:
    void setupWidget();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    /* Data members */
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    /* String members */
    QString m_title = tr("Home");

    /* UI menbers */
    SAppBar * appBar = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHHOME_H
