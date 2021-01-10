#include "SMqtt.h"

#include <QJsonDocument>
#include <QDebug>

/*
SMqtt::SMqtt(const char *id, const bool clean_session)
    : mosquittopp (id, clean_session)
{
    mosqpp::lib_init();
    loop_start();
}

SMqtt::SMqtt(const char *id, const char *host, const int port, const bool clean_session)
    : mosquittopp (id, clean_session)
{
    mosqpp::lib_init();
    this->setClient(host, port);
    loop_start();
}

SMqtt::SMqtt(const char *id, const char *host, const int port, const char *username, const char *password, const bool clean_session)
    : mosquittopp(id, clean_session)
{
    mosqpp::lib_init();
    this->setAuthentication(username, password);
    this->setClient(host, port);
    loop_start();           // Start thread managing connection / publish / subscribe
}
*/

SMqtt::~SMqtt()
{
    mosquittopp::disconnect();
    //loop_stop();            // Kill the thread
    mosqpp::lib_cleanup();  // Mosquitto library cleanup
}

bool SMqtt::setAuthentication(const QString &username, const QString &password)
{
    int result = username_pw_set(username.toStdString().c_str(), password.toStdString().c_str());

    return (result == MOSQ_ERR_SUCCESS);
}

bool SMqtt::setSecurity(const QString &file, const QString &tlsVersion)
{
    int result = 0;

    result = tls_set(file.toStdString().c_str());
    if (result != MOSQ_ERR_SUCCESS)
    {
        return false;
    }

    result = tls_opts_set(1, tlsVersion.toStdString().c_str(), NULL);
    if (result != MOSQ_ERR_SUCCESS)
    {
        return false;
    }

    return (result == MOSQ_ERR_SUCCESS);
}

bool SMqtt::setClient(const QString &host, const int port, const int keepalive)
{
    this->m_host = host;
    this->m_port = port;
    this->m_keepalive = keepalive;

    int result = connect_async(host.toStdString().c_str(), port, keepalive);

    return (result == MOSQ_ERR_SUCCESS);
}

bool SMqtt::subscribing(const QString &topic, const int qos)
{
    int result = subscribe(NULL, topic.toStdString().c_str(), qos);;

    return (result == MOSQ_ERR_SUCCESS);
}

bool SMqtt::unsubscribing(const QString &topic)
{
    int result = unsubscribe(NULL, topic.toStdString().c_str());;

    return (result == MOSQ_ERR_SUCCESS);
}

bool SMqtt::publishing(const QString &topic, const QString &message, const int qos, const bool retain)
{
    int result = publish(NULL, topic.toStdString().c_str(), message.length(), message.toStdString().c_str(), qos, retain);

    return (result = MOSQ_ERR_SUCCESS);
}

void SMqtt::setHost(const QString &host)
{
    this->m_host = host;
}

QString SMqtt::getHost()
{
    return this->m_host;
}

void SMqtt::setID(const QString &id)
{
    mosquittopp(id.toStdString().c_str());
}

int SMqtt::getID()
{
    return this->m_mid;
}

void SMqtt::setKeepalive(const int msec)
{
    this->m_keepalive = msec;
}

int SMqtt::getKeepalive() const
{
    return m_keepalive;
}

int SMqtt::getMID() const
{
    return this->m_mid;
}

QString SMqtt::setJson(const QJsonObject &json)
{
    QJsonDocument doc(json);
    QByteArray byteArray = doc.toJson();

    return QString(byteArray);
}

QJsonObject SMqtt::getJson(const QString &message)
{
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());

    // check validity of the document
    if (!doc.isNull())
    {
        if (doc.isObject())
        {
            obj = doc.object();
        }
        else
        {
            qDebug() << "Document is not an object";
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << message;
    }

    return obj;
}

void SMqtt::on_connect(int result)
{
    if (!result)
    {
        emit this->signalConnected(true);
    }
    else
    {
        emit this->signalConnected(false);
    }
}

void SMqtt::on_disconnect(int result)
{
    if (!result)
    {
        emit this->signalDisconnected(true);
    }
    else
    {
        emit this->signalDisconnected(false);
    }
}

void SMqtt::on_publish(int id)
{
    Q_UNUSED(id);

    this->m_mid++;
    emit this->signalMessageTransmit(true);
}

void SMqtt::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    Q_UNUSED(mid);
    Q_UNUSED(qos_count);
    Q_UNUSED(granted_qos);

    if (this->m_mid != 0)
    {
        emit this->signalSubscribed();
    }
    this->m_mid++;
}

void SMqtt::on_unsubscribe(int mid)
{
    Q_UNUSED(mid);

    this->m_mid--;
}

void SMqtt::on_message(const mosquitto_message *message)
{
    if (message->payloadlen)
    {
        //QString string(message->topic);
        //string += '>';
        QString string = (char*) message->payload;

        emit this->signalMessageReceived(string);
    }
}
