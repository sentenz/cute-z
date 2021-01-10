#ifndef STOUCHDIALOGTUMBLER_H
#define STOUCHDIALOGTUMBLER_H

#include "../build/SGlobal.h"

#include <QDialog>

class QString;

class SLabel;
class SPushButton;
class SVTumbler;


class STouchDialogTumbler : public QDialog
{
    Q_OBJECT

public:
    explicit STouchDialogTumbler(QWidget *parent = 0);
    ~STouchDialogTumbler();

    QStringList items() const;
    void setItems(const QStringList &items);


    int currentIndex() const;
    void setCurrentIndex(const int index);

    QString currentContent() const;
    void setCurrentContent(const QString &content);

    void scrollToIndex(const int index);

    void setTitleText(const QString &text);
    void setDescription(const QString &description);
    void setAcceptText(const QString &text = tr("Done"));
    void setRejectText(const QString &text = tr("Cancel"));

    void setAcceptVisible(const bool visible = true);
    void setRejectVisible(const bool visible = true);

    void setFontSize(const int size = 18);
    void setFontSizeParamter(const int size = 18);

    void setOpacity(const double opacity);

    void enableHighlight(const bool enable = false);

    void setAlignment(const Qt::AlignmentFlag &alignment = Qt::AlignCenter);

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

    SLabel * labelTitle = nullptr;
    SLabel * labelDescription = nullptr;
    SPushButton * buttonReject = nullptr;
    SPushButton * buttonAccept = nullptr;
    SVTumbler * tumblerText = nullptr;
};

#endif /// STOUCHDIALOGTUMBLER_H
