#ifndef SBACKENDKEYBOARD_H
#define SBACKENDKEYBOARD_H

#include <QObject>
#include <QString>
#include <QLabel>
#include <QImage>


class SBackendKeyboard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString display READ getDisplay WRITE setDisplay NOTIFY displayChanged)
    Q_PROPERTY(QString url READ getImgage WRITE setImgage NOTIFY imageChanged)
//    Q_PROPERTY(QString title MEMBER m_title NOTIFY titleChanged)
//    Q_PROPERTY(QString display MEMBER m_display NOTIFY displayChanged)
//    Q_PROPERTY(QString imgage MEMBER m_url NOTIFY imageChanged)

public:
    explicit SBackendKeyboard(QObject *parent = nullptr);

    QString getTitle() const;
    void setTitle(const QString &title);

    QString getDisplay() const;
    void setDisplay(const QString &display);

    QString getImgage() const;
    void setImgage(const QString &url);

signals:
    void titleChanged(const QString &title);
    void displayChanged(const QString &display);
    void imageChanged(const QString &image);

public slots:
    void predictImage();

private:
    void setConnect();

    QString m_title;
    QString m_display;
    QString m_url;

    QLabel label;
};

#endif // SBACKENDKEYBOARD_H
