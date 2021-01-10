#ifndef SANIMATION_H
#define SANIMATION_H

#include <QWidget>

class QLabel;
class QMovie;
class QString;
class QShowEvent;
class QCloseEvent;


class SAnimation : public QWidget
{
    Q_OBJECT

public:
    explicit SAnimation(QWidget *parent = 0);
    ~SAnimation();

    void setDefaultFileName(const QString fileName);
    void setPressedFileName(const QString fileName);
    void setReleasedFileName(const QString fileName);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);

signals:
    void pressed();
    void released();

private slots:
    void slotDefaultEvent();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();

    bool m_event = false;
    bool m_accepted = false;

    QString m_defaultFileName = "";
    QString m_pressedFileName = "";
    QString m_releasedFileName = "";

    QLabel *processLabel = nullptr;
    QMovie *movie = nullptr;
};

#endif /// SANIMATION_H
