/**
 * @file mqtt.h
 * @brief MQTT pubsub function.
 *
 * @note This contains eventually any constants
 * or global variables you will need.
 *
 * @author Alexej Kloos (AKL)
 * @date 23/11/2018
 */

#ifndef MQTT_HPP
#define MQTT_HPP

#include <string>

#include "mosquitto.h"
#include "mosquittopp.h"

//using namespace mosqpp;


/// @brief Class responsibility.
class MQTT: public mosqpp::mosquittopp
{
public:
    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    MQTT(const char *id = NULL, const bool clean_session = true)
        : mosquittopp (id, clean_session)
    {
        mosqpp::lib_init();
        loop_start();
    }

    /*
    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    MQTT(const char *id, const char *host, const int port = 1883, const bool clean_session = true);

    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    MQTT(const char *id, const char *host, const int port, const char *username, const char *password, const bool clean_session = true);
    */

    /// @brief Destructor description.
    ~MQTT();

    /// @brief Method description.
    ///
    /// @note Authentication must set befor security.
    bool setAuthentication(const std::string &username, const std::string &password);

    /// @brief Method description.
    bool setSecurity(const std::string &file, const std::string &tlsVersion = "tlsv1.2");

    /// @brief Method description.
    bool setClient(const std::string &host = "localhost", const int port = 1883, const int keepalive = 1000);

    /// @brief Method description.
    bool subscribing(const std::string &topic, const int qos = 0);

    /// @brief Method description.
    bool publishing(const std::string &topic, const std::string &message, const int qos = 0, const bool retain = false);

    /// @brief Method description.
    void setHost(const std::string &text);

    /// @brief Method description.
    std::string getHost();

    /// @brief Method description.
    void setID(const std::string &id);

    /// @brief Method description.
    int getID();

    /// @brief Method description.
    void setKeepalive(const int msec);

    /// @brief Method description.
    int getKeepalive() const;

    /// @brief Method description.
    int getMID() const;

private:
    /// @brief Method description.
    ///
    /// @param url Requested url.
    void on_connect(int result);

    /// @brief Method description.
    ///
    /// @param url Requested url.
    void on_disconnect(int result);

    /// @brief Method description.
    ///
    /// @param url Requested url.
    void on_publish(int id);

    /// @brief Method description.
    ///
    /// @param url Requested url.
    void on_subscribe(int mid, int qos_count, const int *granted_qos);

    /// @brief Method description.
    ///
    /// @param url Requested url.
    void on_unsubscribe(int mid);

    /// @brief Method description.
    ///
    /// @param url Requested url.
    void on_message(const mosquitto_message *message);

    /// @brief Data member descpription.
    int m_mid = 0;
    int m_port = 0;
    int m_keepalive = 0;
    std::string m_host;
};

#endif
