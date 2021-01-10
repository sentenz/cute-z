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
 * @file shttp.h
 * @brief HTTP request function.
 *
 * @note This contains eventually any constants
 * or global variables you will need.
 *
 * @author Alexej Kloos (AKL)
 * @date 10/11/2018
 */

#ifndef SHTTP_H
#define SHTTP_H

#include <QProgressDialog>
#include <QNetworkAccessManager>
#include <QUrl>

QT_BEGIN_NAMESPACE
class QFile;
class QSslError;
class QAuthenticator;
class QNetworkReply;
QT_END_NAMESPACE


/// @brief Class responsibility.
class SProgressDialog : public QProgressDialog
{
    Q_OBJECT

public:
    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    explicit SProgressDialog(const QUrl &url, QWidget *parent = nullptr);

public slots:
    /// @brief Method description.
    ///
    /// @param bytesRead Requested url.
    /// @param totalBytes Requested url.
   void slotNetworkReplyProgress(qint64 bytesRead, qint64 totalBytes);
};

/// @brief Class responsibility.
class SHttp : public QDialog
{
    Q_OBJECT

public:
    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    explicit SHttp(QWidget *parent = nullptr);

    /// @brief Method description.
    ///
    /// @param url Requested url.
    void startRequest(const QUrl &url);

private slots:
    /// @brief Method description.
    void slotDownloadFile();

    /// @brief Method description.
    void slotCancelDownload();

    /// @brief Method description.
    void slotHttpFinished();

    /// @brief Method description.
    void slotHttpReadyRead();

    /// @brief Method description.
    void slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator);

#ifndef QT_NO_SSL
    /// @brief Method description.
    void slotSslErrors(QNetworkReply *, const QList<QSslError> &errors);
#endif

private:
    /// @brief Establishes connection between signals and slots.
    void setConnect();

    /// @brief Method description.
    ///
    /// @param fileName Requested url.
    /// @return Return value description.
    QFile *openFileForWrite(const QString &fileName);

    /// @brief Data member descpription.
    bool m_aborted = false;
    /// @brief Data member descpription.
    QString m_urlPath = "";
    /// @brief Default file name, if no file name is given in the url path.
    QString m_defaultFileName = "";
    /// @brief Data member descpription.
    QString m_downloadDirectory = "";
    /// @brief Data member descpription.
    QUrl m_url;
    /// @brief Data member descpription.
    QNetworkAccessManager m_manager;
    /// @brief Data member descpription.
    QNetworkReply *m_reply = nullptr;
    /// @brief Data member descpription.
    QFile *m_file = nullptr;
};

#endif
