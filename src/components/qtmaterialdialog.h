#ifndef QTMATERIALDIALOG_H
#define QTMATERIALDIALOG_H

#include <QScopedPointer>
#include "lib/qtmaterialoverlaywidget.h"

class QLayout;
class QtMaterialDialogPrivate;

class QtMaterialDialog : public QtMaterialOverlayWidget
{
    Q_OBJECT

public:
    explicit QtMaterialDialog(QWidget *parent = 0);
    ~QtMaterialDialog();

    QLayout *windowLayout() const;
    void setWindowLayout(QLayout *layout);

    void setBackgroundColor(const QColor &color);
    void setForegroundColor(const QColor &color);

public slots:
    void showDialog();
    void hideDialog();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    const QScopedPointer<QtMaterialDialogPrivate> d_ptr;

private:
    QColor m_colorBase = Qt::black;
    Q_DISABLE_COPY(QtMaterialDialog)
    Q_DECLARE_PRIVATE(QtMaterialDialog)
};

#endif // QTMATERIALDIALOG_H
