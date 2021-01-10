#ifndef SNAVIGATIONDRAWER_H
#define SNAVIGATIONDRAWER_H

#include "../build/SGlobal.h"
#include "../components/lib/qtmaterialtheme.h"

#include <QDialog>

class QtMaterialDrawer;

class SList;


class SNavigationDrawer : public QDialog
{
    Q_OBJECT

public:
    explicit SNavigationDrawer(QWidget *parent = 0);
    ~SNavigationDrawer();

protected:
    void changeEvent(QEvent *event);
    void showEvent(QShowEvent *event);

signals:
    void signalReleased(const int index);
    void signalShow();
    void signalClose();

protected slots:
    void setupProperty();
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

private:
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    SList *const m_list;

    QtMaterialDrawer *const m_drawer;
};

#endif // SNAVIGATIONDRAWER_H
