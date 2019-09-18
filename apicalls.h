#ifndef APICALLS_H
#define APICALLS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class ApiCalls : public QObject
{
    Q_OBJECT
public:
    explicit ApiCalls(QObject *parent = nullptr);
    void getJsonTestData();

signals:
    void sendQByteArray(QByteArray *qbArray);

public slots:

private:
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;

private slots:
    void dataReadyRead();
    void dataReadFinished();
};

#endif // APICALLS_H
