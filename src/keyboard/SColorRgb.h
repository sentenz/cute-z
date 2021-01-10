#ifndef SCOLORRGB_H
#define SCOLORRGB_H

#include "../build/SGlobal.h"
#include <QDialog>

class QString;

class SSlider;
class SLabel;


class SColorRgb : public QDialog
{
    Q_OBJECT

public:
    explicit SColorRgb(QWidget *parent = nullptr);
    ~SColorRgb();

    QColor getColor() const;
    void setColor(const QColor color);

protected:
    void changeEvent(QEvent *event);

signals:
    void signalColorChanged(const QColor &color);

public slots:
    void slotColorChanged(const QColor &color);

private slots:
    void slotIndexR(const int index);
    void slotIndexG(const int index);
    void slotIndexB(const int index);

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    QColor m_color = ::GlobalColorContrast;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    SLabel * labelR = nullptr;
    SLabel * labelG = nullptr;
    SLabel * labelB = nullptr;
    SSlider * sliderR = nullptr;
    SSlider * sliderG = nullptr;
    SSlider * sliderB = nullptr;
};

#endif /* SCOLORRGB_H */
