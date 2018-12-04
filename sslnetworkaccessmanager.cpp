#include "sslnetworkaccessmanager.h"

#include <qnetworkreply.h>



SslNetworkAccessManager::SslNetworkAccessManager()
{
}

QNetworkReply *SslNetworkAccessManager::createRequest(Operation op, const QNetworkRequest &req, QIODevice *outgoingData)
{
    QNetworkReply * reply = QNetworkAccessManager::createRequest(op, req, outgoingData);
    reply->ignoreSslErrors();
    return reply;
}



