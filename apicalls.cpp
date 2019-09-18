#include "apicalls.h"
#include "widget.h"



ApiCalls::ApiCalls(QObject *parent) :
    QObject(parent),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{

}

QByteArray ApiCalls::getJsonTestData()
{
    const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/posts");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);
    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&ApiCalls::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&ApiCalls::dataReadFinished);
    return *mDataBuffer;

}

void ApiCalls::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void ApiCalls::dataReadFinished()
{
    if (mNetReply->error())
        qDebug() << "Error: " << mNetReply->errorString();
    else
    {
        qDebug() << "Data fetch finished: " << QString(*mDataBuffer);
    }
}
