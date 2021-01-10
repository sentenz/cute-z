#ifndef STOUCHSETTINGSRESET_H
#define STOUCHSETTINGSRESET_H

#include "../build/SGlobal.h"

#include <QDialog>

class SAppBar;
class SList;


class STouchSettingsReset : public QDialog
{
    Q_OBJECT

public:
    explicit STouchSettingsReset(QWidget *parent = nullptr);
    ~STouchSettingsReset();

protected:
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

private slots:
    void slotList(const int index);

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();

    void removeSettings(const QString &file, const QString &group);
    void removeFile(const QString &path, const QString &name);

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    /* Qt members */
    QString m_title = tr("Reset");

    /* UI menbers */
    SAppBar * appBar = nullptr;
    SList * list = nullptr;
};

#endif // STOUCHSETTINGSRESET_H
