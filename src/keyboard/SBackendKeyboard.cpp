#include "SBackendKeyboard.h"
#include "../neuron/mnist/sneuronmnist.h"

#include <QPixmap>
#include <QDebug>


SBackendKeyboard::SBackendKeyboard(QObject *parent) : QObject(parent)
{
    this->setConnect();
}

void SBackendKeyboard::setConnect()
{
    connect(this, &SBackendKeyboard::imageChanged, this, &SBackendKeyboard::predictImage);
}

QString SBackendKeyboard::getTitle() const
{
    qDebug() << "getTitle";

    return this->m_title;
}

void SBackendKeyboard::setTitle(const QString &title)
{
    qDebug() << "setTitle";

    if (this->m_title == title)
    {
        return;
    }
    this->m_title = title;

    emit titleChanged(this->m_title);
}

QString SBackendKeyboard::getDisplay() const
{
    qDebug() << "getDisplay";

    return this->m_display;
}

void SBackendKeyboard::setDisplay(const QString &display)
{
    qDebug() << "setDisplay";

    this->m_display = display;

    emit displayChanged(this->m_display);
}

QString SBackendKeyboard::getImgage() const
{
    qDebug() << "getImgage";

    return this->m_url;
}

void SBackendKeyboard::setImgage(const QString &url)
{
    this->m_url = url;

    QImage image(url.toLocal8Bit());
    label.setPixmap(QPixmap::fromImage(image));
    label.show();

    emit imageChanged(this->m_url);

    qDebug() << "setImgage";
}

void SBackendKeyboard::predictImage()
{
    int num = neuron_mnist::recognize("/etc/sentenz/neuron/mnist/LeNet-model", "/etc/sentenz/neuron/mnist/number.bmp");

    this->setDisplay(QString::number(num));
}
