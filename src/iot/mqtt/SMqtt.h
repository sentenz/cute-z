/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

/**
 * @file SMqtt.h
 * @brief MQTT pubsub function.
 *
 * @note This contains eventually any constants
 * or global variables you will need.
 *
 * @author Alexej Kloos (AKL)
 * @date 23/11/2018
 */

#ifndef SMQTT_H
#define SMQTT_H

#include "mosquitto.h"
#include "mosquittopp.h"

#include <QWidget>
#include <QString>
#include <QJsonObject>

//using namespace mosqpp;

// Example:
//
// SMqtt * mqtt = new SMqtt("Client1");
// mqtt->setAuthentication("client", "client@mqtt");
// mqtt->setSecurity("/etc/mosquitto/certs/ca.pem");
// mqtt->setClient("sentenz", 8883);
//
// connect(this->mqtt, &SMqtt::signalConnected, this, &STouchAnalyticsPlotMqtt::slotConnected);
// connect(this->mqtt, &SMqtt::signalDisconnected, this, &STouchAnalyticsPlotMqtt::slotDisconnected);
// connect(this->mqtt, &SMqtt::signalMessageReceived, this, &STouchAnalyticsPlotMqtt::slotMessageReceived);
//
// QJsonObject json = this->mqtt->getJson(message);
// json["ID"].toString();
// json["Value"].toString();
// json["Temperature"].toString();


/// @brief Class responsibility.
class SMqtt : public QWidget, public mosqpp::mosquittopp
{
    Q_OBJECT

public:
    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    SMqtt(const char *id = NULL, const bool clean_session = true)
        : mosquittopp (id, clean_session)
    {
        mosqpp::lib_init();
        loop_start();
    }

    /*
    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    SMqtt(const char *id, const char *host, const int port = 1883, const bool clean_session = true);

    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    SMqtt(const char *id, const char *host, const int port, const char *username, const char *password, const bool clean_session = true);
    */

    /// @brief Destructor description.
    ~SMqtt();

    /// @brief Method description.
    ///
    /// @note Authentication must set befor security.
    bool setAuthentication(const QString &username, const QString &password);

    /// @brief Method description.
    bool setSecurity(const QString &file, const QString &tlsVersion = "tlsv1.2");

    /// @brief Method description.
    bool setClient(const QString &host = "localhost", const int port = 1883, const int keepalive = 60);

    /// @brief Method description.
    bool subscribing(const QString &topic, const int qos = 0);

    /// @brief Method description.
    bool unsubscribing(const QString &topic);

    /// @brief Method description.
    bool publishing(const QString &topic, const QString &message, const int qos = 0, const bool retain = false);

    /// @brief Method description.
    void setHost(const QString &host);

    /// @brief Method description.
    QString getHost();

    /// @brief Method description.
    void setID(const QString &id);

    /// @brief Method description.
    int getID();

    /// @brief Method description.
    void setKeepalive(const int msec);

    /// @brief Method description.
    int getKeepalive() const;

    /// @brief Method description.
    int getMID() const;

    /// @brief Method description.
    QString setJson(const QJsonObject &json);

    /// @brief Method description.
    QJsonObject getJson(const QString &message);

signals:
    /// @brief Method description.
    void signalConnected(const bool);

    /// @brief Method description.
    void signalDisconnected(const bool);

    /// @brief Method description.
    void signalMessageTransmit(const bool);

    /// @brief Method description.
    void signalMessageReceived(const QString);

    /// @brief Method description.
    void signalSubscribed();

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
    QString m_host;
};

#endif
