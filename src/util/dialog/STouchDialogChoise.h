#ifndef STOUCHDIALOGCHOISE_H
#define STOUCHDIALOGCHOISE_H

#include "../build/SGlobal.h"

#include <QDialog>

class QString;

class SList;
class SLabel;
class SPushButton;


class STouchDialogChoise : public QDialog
{
    Q_OBJECT

public:
    explicit STouchDialogChoise(QWidget *parent = 0);
    ~STouchDialogChoise();


    void items(const QStringList &items);
    QStringList items() const;

    void index(const int index);
    int index() const;

    QString content() const;
    void content(const QString &content);

    void title(const QString &text);
    void setFontSize(const int size = 18);
    void setFontSizeParamter(const int size = 18);
    void setAcceptText(const QString &text = tr("Done"));
    void setRejectText(const QString &text = tr("Cancel"));
    void setAcceptVisible(const bool visible = true);
    void setRejectVisible(const bool visible = true);
    void setOpacity(const double opacity);
    void setBaseColor(const QColor &color);
    void setContrastColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setHighlightColor(const QColor &color);
    bool isAccepted();
    bool isRejected();

protected:
    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent *event);
    void changeEvent(QEvent *event);

signals:

private slots:
    void slotIndex(int index);
    void slotAccept();
    void slotReject();
    void slotClose();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    bool m_accepted = false;
    double m_opacity = 0.7;
    int m_index;
    QColor frame_color = Qt::white;
    QStringList m_items;
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    SLabel *labelTitle = nullptr;
    SPushButton *buttonReject = nullptr;
    SPushButton *buttonAccept = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHDIALOGCHOISE_H
