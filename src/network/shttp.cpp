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

#include <QtWidgets>
#include <QtNetwork>
#include <QUrl>

#include "shttp.h"

const char defaultUrl[] = "http://192.168.0.135/WirelessLog/AllInfo.csv";
const char defaultFileName[] = "AllInfo.csv";

SProgressDialog::SProgressDialog(const QUrl &url, QWidget *parent)
  : QProgressDialog(parent)
{
    setWindowTitle(tr("Download Progress"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setLabelText(tr("Downloading %1.").arg(url.toDisplayString()));
    setMinimum(0);
    setValue(0);
    setMinimumDuration(0);
    setMinimumSize(QSize(400, 75));
}

void SProgressDialog::slotNetworkReplyProgress(qint64 bytesRead, qint64 totalBytes)
{
    setMaximum(totalBytes);
    setValue(bytesRead);
}

SHttp::SHttp(QWidget *parent)
    : QDialog(parent)
    , m_urlPath(defaultUrl)
    , m_defaultFileName(defaultFileName)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QString downloadDirectory = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    if (downloadDirectory.isEmpty() || !QFileInfo(downloadDirectory).isDir())
    {
        downloadDirectory = QDir::currentPath();
    }
    this->m_downloadDirectory = QDir::toNativeSeparators(downloadDirectory);
}

void SHttp::setConnect()
{
    //connect(downloadButton, &QAbstractButton::clicked, this, &SHttp::slotDownloadFile);
    connect(&this->m_manager, &QNetworkAccessManager::authenticationRequired, this, &SHttp::slotAuthenticationRequired);
#ifndef QT_NO_SSL
    connect(&this->m_manager, &QNetworkAccessManager::sslErrors, this, &SHttp::slotSslErrors);
#endif
}

void SHttp::startRequest(const QUrl &url)
{
    this->m_url = url;
    this->m_aborted = false;

    this->m_reply = this->m_manager.get(QNetworkRequest(this->m_url));
    connect(this->m_reply, &QNetworkReply::finished, this, &SHttp::slotHttpFinished);
    connect(this->m_reply, &QIODevice::readyRead, this, &SHttp::slotHttpReadyRead);

    SProgressDialog *progressDialog = new SProgressDialog(this->m_url, this);
    progressDialog->setAttribute(Qt::WA_DeleteOnClose);
    connect(progressDialog, &QProgressDialog::canceled, this, &SHttp::slotCancelDownload);
    connect(this->m_reply, &QNetworkReply::downloadProgress, progressDialog, &SProgressDialog::slotNetworkReplyProgress);
    connect(this->m_reply, &QNetworkReply::finished, progressDialog, &SProgressDialog::hide);
    progressDialog->show();
}

void SHttp::slotDownloadFile()
{
    const QString urlPath = this->m_urlPath;
    if (urlPath.isEmpty())
    {
        return;
    }

    const QUrl newUrl = QUrl::fromUserInput(urlPath);
    if (!newUrl.isValid())
    {
        QMessageBox::information(this, tr("Error"), tr("Invalid URL: %1: %2").arg(urlPath, newUrl.errorString()));
        return;
    }

    QString fileName = newUrl.fileName();
    if (fileName.isEmpty())
    {
        fileName = this->m_defaultFileName;
    }
    if (fileName.isEmpty())
    {
        fileName = defaultFileName;
    }
    QString downloadDirectory = QDir::cleanPath(this->m_downloadDirectory);
    bool useDirectory = !downloadDirectory.isEmpty() && QFileInfo(downloadDirectory).isDir();
    if (useDirectory)
    {
        fileName.prepend(downloadDirectory + '/');
    }
    if (QFile::exists(fileName))
    {
        if (QMessageBox::question(this, tr("Overwrite Existing File"), tr("There already exists a file called %1%2. Overwrite?")
                                     .arg(fileName, useDirectory ? QString() : QStringLiteral(" in the current directory")),
                                     QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::No)
        {
            return;
        }
        QFile::remove(fileName);
    }

    this->m_file = openFileForWrite(fileName);
    if (!this->m_file)
    {
        return;
    }

    // schedule the request
    startRequest(newUrl);
}

QFile *SHttp::openFileForWrite(const QString &fileName)
{
    QScopedPointer<QFile> file(new QFile(fileName));
    if (!file->open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Error"), tr("Unable to save the file %1: %2.").arg(QDir::toNativeSeparators(fileName), file->errorString()));
        return nullptr;
    }
    return file.take();
}

void SHttp::slotCancelDownload()
{
    this->m_aborted = true;
    this->m_reply->abort();
}

void SHttp::slotHttpFinished()
{
    QFileInfo fi;
    if (this->m_file)
    {
        fi.setFile(this->m_file->fileName());
        this->m_file->close();
        delete this->m_file;
        this->m_file = nullptr;
    }

    if (this->m_aborted)
    {
        this->m_reply->deleteLater();
        this->m_reply = nullptr;
        return;
    }

    if (this->m_reply->error())
    {
        QFile::remove(fi.absoluteFilePath());
        this->m_reply->deleteLater();
        this->m_reply = nullptr;
        return;
    }

    const QVariant redirectionTarget = this->m_reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

    this->m_reply->deleteLater();
    this->m_reply = nullptr;

    if (!redirectionTarget.isNull())
    {
        const QUrl redirectedUrl = this->m_url.resolved(redirectionTarget.toUrl());
        if (QMessageBox::question(this, tr("Redirect"), tr("Redirect to %1 ?").arg(redirectedUrl.toString()),
                                  QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
        {
            QFile::remove(fi.absoluteFilePath());
            return;
        }
        this->m_file = openFileForWrite(fi.absoluteFilePath());
        if (!this->m_file)
        {
            return;
        }
        startRequest(redirectedUrl);
        return;
    }

    // Open file
    if (true)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(fi.absoluteFilePath()));
    }
}

void SHttp::slotHttpReadyRead()
{
    // This slot gets called every time the QNetworkReply has new data.
    // We read all of its new data and write it into the file.
    // That way we use less RAM than when reading it at the finished()
    // signal of the QNetworkReply
    if (this->m_file)
    {
        //this->m_file->write(this->m_reply->readAll());

        QTextDocument document(this->m_reply->readAll());
        QStringList list = document.toPlainText().split(QRegExp("[,\n\t ]+"), QString::SkipEmptyParts);

        int i = 0;
        foreach (QString line, list)
        {
            if (!line.isEmpty())
            {
                if (++i > document.lineCount()-1)
                {
                    this->m_file->write(line.append("\n").toUtf8());
                }
            }
        }

    }
}

void SHttp::slotAuthenticationRequired(QNetworkReply *, QAuthenticator *authenticator)
{
    /*
    QDialog authenticationDialog;
    Ui::Dialog ui;
    ui.setupUi(&authenticationDialog);
    authenticationDialog.adjustSize();
    ui.siteDescription->setText(tr("%1 at %2").arg(authenticator->realm(), this->m_url.host()));

    // Did the URL have information? Fill the UI
    // This is only relevant if the URL-supplied credentials were wrong
    ui.userEdit->setText(this->m_url.userName());
    ui.passwordEdit->setText(this->m_url.password());

    if (authenticationDialog.exec() == QDialog::Accepted)
    {
        authenticator->setUser(ui.userEdit->text());
        authenticator->setPassword(ui.passwordEdit->text());
    }
    */
}

#ifndef QT_NO_SSL
void SHttp::slotSslErrors(QNetworkReply *, const QList<QSslError> &errors)
{
    QString errorString;
    foreach (const QSslError &error, errors)
    {
        if (!errorString.isEmpty())
        {
            errorString += '\n';
        }
        errorString += error.errorString();
    }

    if (QMessageBox::warning(this, tr("SSL Errors"), tr("One or more SSL errors has occurred:\n%1").arg(errorString),
                             QMessageBox::Ignore | QMessageBox::Abort) == QMessageBox::Ignore)
    {
        this->m_reply->ignoreSslErrors();
    }
}
#endif
