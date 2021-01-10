#ifndef SRADIODIALOG_H
#define SRADIODIALOG_H

#include "../build/SGlobal.h"

#include <QDialog>

class QVBoxLayout;
class QButtonGroup;

class QtMaterialDialog;

class SPushButton;
class SLabel;


class SRadioDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SRadioDialog(QWidget *parent = 0);
    ~SRadioDialog();

    void setTitle(const QString &text);
    QString title() const;

    void addText(const QString &text);

    void setIndex(const int index);
    int index();

    void setAcceptButton(const QString &text);
    void setRejectButton(const QString &text);

    bool isAccepted();
    bool isRejected();

    void setBackgroundColor(const QColor &color);
    void setForegroundColor(const QColor &color);

protected:
    void changeEvent(QEvent *event);
    void showEvent(QShowEvent *event);

protected slots:
    void setupProperty();
    void setupWidget();
    void setupLayout();
    void setConnect();
    void restyleUI();

private:
    bool m_accepted = false;
    int m_index = -1;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QString m_title = "";
    QString m_text = "";

    QVBoxLayout * m_radioLayout = nullptr;
    QButtonGroup * m_buttonGroup = nullptr;

    SLabel *const m_titleLabel = nullptr;
    SPushButton *const m_rejectButton = nullptr;
    SPushButton *const m_acceptButton = nullptr;

    QtMaterialDialog *const m_dialog = nullptr;
};

#endif // SRADIODIALOG_H
