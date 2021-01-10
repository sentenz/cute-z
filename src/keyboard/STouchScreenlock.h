#ifndef STOUCHSCREENLOCK_H
#define STOUCHSCREENLOCK_H

#include "../build/SGlobal.h"
#include <QDialog>

class QString;
class QFile;
class QSettings;
class QShowEvent;
class QCloseEvent;

class SLabel;
class SPushButton;


class STouchScreenlock : public QDialog
{
    Q_OBJECT

public:
    enum class Role {
        User,
        Operator,
        Admin,
        Appropriate
    };

    explicit STouchScreenlock(QWidget *parent = nullptr);
    ~STouchScreenlock();

    void setRole(const Role &role = Role::User);
    void setDigits(const int &digits);
    bool isAccepted() const;
    void enableSymbols(const bool visible = false, const bool enable = true);

protected:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);

signals:

private slots:
    void slotButtonEvent();
    void slotCheckCode();
    void slotClose(const bool animate = true);

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void init();
    void labelAnimation();
    void retranslateUI();
    void restyleUI();

    Role m_role = Role::User;
    QString m_password = "";
    QString m_userCode = "";
    QString m_operatorCode = "";
    QString m_adminCode = "";
    QString m_appropriateCode = "";
    bool m_access = false;
    int m_digits = 4;
    int m_attempt = 0;

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QSettings *settings = nullptr;

    SLabel * labelTitle = nullptr;
    SLabel *labelPassword = nullptr;
    SPushButton *buttonZero = nullptr;
    SPushButton *buttonOne = nullptr;
    SPushButton *buttonTwo = nullptr;
    SPushButton *buttonThree = nullptr;
    SPushButton *buttonFour = nullptr;
    SPushButton *buttonFive = nullptr;
    SPushButton *buttonSix = nullptr;
    SPushButton *buttonSeven = nullptr;
    SPushButton *buttonEight = nullptr;
    SPushButton *buttonNine = nullptr;
    SPushButton *buttonDelete = nullptr;
    SPushButton *buttonCancel = nullptr;
};

#endif // STOUCHSCREENLOCK_H
