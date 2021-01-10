#ifndef SLABEL_H
#define SLABEL_H

#include "../build/SGlobal.h"

#include <QWidget>
#include <QIcon>
#include <QString>
#include <QColor>
#include <QLabel>

class QButtonGroup;
class QFileSystemWatcher;


class SLabel : public QLabel
{
    Q_OBJECT

public:
    enum class Theme {
        None,
        Transparent,
        Base,
        Contrast,
        Subtext,
        Text,
        Topic,
        Header,
        FilledRoundRect
    };

    explicit SLabel(QWidget * parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    explicit SLabel(const QString & text, QWidget * parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
//    explicit SLabel(const QIcon & icon, const QString & text, QWidget * parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~SLabel();

    void header(const QString & text = "", const QChar & left = 0x200A, const QChar & right = 0x200A);
    void header(const int index, const QString & text = "", const QChar & left = 0x200A, const QChar & right = 0x200A);

    void fontSize(const int size);

    void setTheme(const Theme &theme = Theme::Transparent);

protected:
    void changeEvent(QEvent *event);

signals:
    void signalPressed(const int index);
    void signalReleased(const int index);
    void signalClicked(const int index);

private:
    void setupWidget();
    void setConnect();
    void restyleUI();

    QString formStyleSheet(const Theme &style);


    QColor m_colorBase = ::GlobalColorBase;
    QColor m_colorContrast = ::GlobalColorContrast;
    QColor m_colorText = ::GlobalColorText;
    QColor m_colorHighlight = ::GlobalColorHighlight;

    int m_fontSize = 0;
    Theme m_style = Theme::Transparent;
    QString m_text = "";
    QButtonGroup * slotGroup = nullptr;
};

#endif // SLABEL_H
