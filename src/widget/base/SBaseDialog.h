#ifndef SBASEDIALOG_H
#define SBASEDIALOG_H

#include "../build/SGlobal.h"

#include <QDialog>
#include <QEasingCurve>

class QEvent;

class SLabel;


class SBaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SBaseDialog(QWidget * parent = nullptr);
    ~SBaseDialog();

    void closeable(const bool boolean);
    bool closeable() const;

protected:
    /* Events members */
    void changeEvent(QEvent * event);
    void showEvent(QShowEvent * event);
    void closeEvent(QCloseEvent * event);

    /* Members */
    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

private:
    /* Funtion members */
    void setupProperty();
    void restyleUI();

    /* Data members */
    bool m_closeable = false;
};

#endif /* SBASEDIALOG_H */
