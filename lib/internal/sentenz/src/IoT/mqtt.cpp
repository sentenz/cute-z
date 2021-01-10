#include "mqtt.hpp"

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

/*
MQTT::MQTT(const char *id, const bool clean_session)
    : mosquittopp (id, clean_session)
{
    mosqpp::lib_init();
    loop_start();
}

MQTT::MQTT(const char *id, const char *host, const int port, const bool clean_session)
    : mosquittopp (id, clean_session)
{
    mosqpp::lib_init();
    this->setClient(host, port);
    loop_start();
}

MQTT::MQTT(const char *id, const char *host, const int port, const char *username, const char *password, const bool clean_session)
    : mosquittopp(id, clean_session)
{
    mosqpp::lib_init();
    this->setAuthentication(username, password);
    this->setClient(host, port);
    loop_start();           // Start thread managing connection / publish / subscribe
}
*/

MQTT::~MQTT()
{
    mosquittopp::disconnect();
    loop_stop();            // Kill the thread
    mosqpp::lib_cleanup();  // Mosquitto library cleanup
}

bool MQTT::setAuthentication(const std::string &username, const std::string &password)
{
    int result = username_pw_set(username.toStdString().c_str(), password.toStdString().c_str());

    return (result == MOSQ_ERR_SUCCESS);
}

bool MQTT::setSecurity(const std::string &file, const std::string &tlsVersion)
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

bool MQTT::setClient(const std::string &host, const int port, const int keepalive)
{
    this->m_host = host;
    this->m_port = port;
    this->m_keepalive = keepalive;

    int result = connect_async(host.toStdString().c_str(), port, keepalive);

    return (result == MOSQ_ERR_SUCCESS);
}

bool MQTT::subscribing(const std::string &topic, const int qos)
{
    int result = subscribe(NULL, topic.toStdString().c_str(), qos);;

    return (result == MOSQ_ERR_SUCCESS);
}

bool MQTT::publishing(const std::string &topic, const std::string &message, const int qos, const bool retain)
{
    int result = publish(NULL, topic.toStdString().c_str(), message.length(), message.toStdString().c_str(), qos, retain);

    return (result = MOSQ_ERR_SUCCESS);
}

void MQTT::setHost(const std::string &text)
{
    this->m_host = const_cast<char*>(text.toStdString().c_str());
}

std::string MQTT::getHost()
{
    return this->m_host;
}

void MQTT::setID(const std::string &id)
{
    mosquittopp(id.toStdString().c_str());
}

int MQTT::getID()
{
    return this->m_mid;
}

void MQTT::setKeepalive(const int msec)
{
    this->m_keepalive = msec;
}

int MQTT::getKeepalive() const
{
    return m_keepalive;
}

int MQTT::getMID() const
{
    return this->m_mid;
}

void MQTT::on_connect(int result)
{
    if (!result)
    {
        std::cout << "connected";
    }
    else
    {
        std::cout << "not connected";
    }
}

void MQTT::on_disconnect(int result)
{
    Q_UNUSED(result);
}

void MQTT::on_publish(int id)
{
    Q_UNUSED(id);

    this->m_mid++;
    std::cout << "published " << this->m_mid;
}

void MQTT::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    Q_UNUSED(mid);
    Q_UNUSED(qos_count);
    Q_UNUSED(granted_qos);

    if (this->m_mid != 0)
    {
        std::cout << "published " << this->m_mid;
    }
    this->m_mid++;
}

void MQTT::on_unsubscribe(int mid)
{
    Q_UNUSED(mid);

    this->m_mid--;
}

void MQTT::on_message(const mosquitto_message *message)
{
    if (message->payloadlen)
    {
        //std::string string(message->topic);
        //string += '>';
        std::string text = (char*) message->payload;

        std::cout << "message " << text;
    }
}
