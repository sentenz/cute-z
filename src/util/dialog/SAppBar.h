#ifndef SAPPBAR_H
#define SAPPBAR_H

#include "../build/SGlobal.h"
#include "../components/lib/qtmaterialtheme.h"

#include <QWidget>

class QButtonGroup;

class SLabel;

class QtMaterialAppBar;


class SAppBar : public QWidget
{
    Q_OBJECT

public:
    explicit SAppBar(const QString &text, QWidget *parent = 0);
    explicit SAppBar(const QIcon &icon, const QString &text, QWidget *parent = 0);
    ~SAppBar();

    void addIcon(const QIcon &icon);

    void setText(const QString &text);

protected:
    void changeEvent(QEvent *event);

signals:
    void signalClicked(const int index);

protected slots:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void restyleUI();

private:
    int m_counter = 0;
    QIcon m_icon = QIcon();

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    SLabel              *const m_label;
    QButtonGroup        *const m_buttonGroup;
    QtMaterialAppBar    *const m_appBar;
};

#endif // SAPPBAR_H
