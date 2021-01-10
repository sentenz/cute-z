#ifndef SPUSHBUTTON_H
#define SPUSHBUTTON_H

#include "../build/SGlobal.h"
#include "../components/qtmaterialflatbutton.h"

#include <QWidget>
#include <QColor>


class SPushButton : public QtMaterialFlatButton
{
    Q_OBJECT

public:
    explicit SPushButton(QWidget * parent = nullptr);
    explicit SPushButton(const QString & text, QWidget * parent = nullptr);
    explicit SPushButton(const QIcon & icon, QWidget * parent = nullptr);
    explicit SPushButton(const QIcon & icon, const QString & text, QWidget * parent = nullptr);
    ~SPushButton();

    void setDisabledMode(const bool disabled = false);

protected:
    void changeEvent(QEvent *event);

private slots:

private:
    void setupProperty();
    void setupWidget();
    void restyleUI();

    bool m_disabled = false;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;
};

#endif // SPUSHBUTTON_H
