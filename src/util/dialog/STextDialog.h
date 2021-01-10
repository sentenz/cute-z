#ifndef SDIALOG_H
#define SDIALOG_H

#include "../build/SGlobal.h"

#include <QDialog>

class QtMaterialDialog;
class SPushButton;
class SLabel;


class STextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit STextDialog(QWidget *parent = 0);
    ~STextDialog();

    void setTitle(const QString &text);
    QString title() const;

    void setDescription(const QString &text);
    QString description() const;

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

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QString m_title = "";
    QString m_text = "";

    SLabel *const m_titleLabel = nullptr;
    SLabel *const m_textLabel = nullptr;
    QtMaterialDialog *const m_dialog = nullptr;
    SPushButton *const m_rejectButton = nullptr;
    SPushButton *const m_acceptButton = nullptr;
};

#endif // SDIALOG_H
