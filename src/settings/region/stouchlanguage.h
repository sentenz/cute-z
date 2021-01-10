#ifndef STOUCHLANGUAGE_H
#define STOUCHLANGUAGE_H

#include "../build/SGlobal.h"

#include <QDialog>
#include <QTranslator>

class QSettings;
class QEvent;
class QFileSystemWatcher;

class SLabel;
class SList;


class STouchLanguage : public QDialog
{
    Q_OBJECT

public:
    explicit STouchLanguage(QWidget *parent = nullptr);
    ~STouchLanguage();

protected:
    void changeEvent(QEvent *event);

signals:
    void signalReturn();

private slots:
    void slotList(const int index);
    void slotWriteSettings();
    void slotReadSettings();

private:
    void setupWidget();
    void setupLayout();
    void setConnect();
    void retranslateUI();
    void restyleUI();
    void loadLanguage(const QString &language);

    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    QString language = "en_EN";
    QSettings *settings = nullptr;
    QTranslator translator;
    QFileSystemWatcher *fileSystemWatcher = nullptr;

    SLabel * header = nullptr;
    SList * list = nullptr;
};

#endif /// STOUCHLANGUAGE_H
