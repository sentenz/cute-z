#ifndef SINFOBAR_H
#define SINFOBAR_H

#include "../build/SGlobal.h"
#include "../components/lib/qtmaterialtheme.h"

#include <QWidget>

class SLabel;

class QtMaterialAppBar;


class SInfoBar : public QWidget
{
    Q_OBJECT

public:
    explicit SInfoBar(QWidget *parent = 0);
    ~SInfoBar();

    void addText(const QString &text);
    void setText(const int index, const QString &text);

protected:
    void changeEvent(QEvent *event);

signals:

protected slots:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void restyleUI();

private:
    void clear();

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QList<SLabel *> m_list;
    QtMaterialAppBar    *const m_appBar;
};

#endif // SINFOBAR_H
