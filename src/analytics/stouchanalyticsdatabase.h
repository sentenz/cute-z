#ifndef STOUCHANALYTICSDATABASE_H
#define STOUCHANALYTICSDATABASE_H

#include "../build/SGlobal.h"

#include <QDialog>

class QEvent;

class SList;


class STouchAnalyticsDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit STouchAnalyticsDatabase(QWidget *parent = 0);
    ~STouchAnalyticsDatabase();

protected:
    void changeEvent(QEvent *event);
    void focusInEvent(QFocusEvent *event);

signals:

private slots:

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void setDatabase();
    void retranslateUI();
    void restyleUI();

    int m_order = 0;
    double m_measurement = 0.0;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    SList * list = nullptr;
};

#endif // STOUCHANALYTICSDATABASE_H
