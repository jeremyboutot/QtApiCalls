#include "widget.h"
#include "ui_widget.h"
#include "apicalls.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ApiCalls *apicalls(new(ApiCalls));
    QByteArray myByteArray;
    connect(apicalls,SIGNAL(sendQByteArray(QByteArray)), this,SLOT(addListWidgetValues(QByteArray)));
    apicalls->getJsonTestData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addListWidgetValues(const QByteArray &qbArray)
{
    qDebug() << "This was emitted from the apicalls.cpp class" << endl;
    //Create json document fropm the byte array
    QJsonDocument doc = QJsonDocument::fromJson(qbArray);
    //Turn the QJsonDocument into a QJsonArray
    QJsonArray array = doc.array();
    //Loop through the array getting the string value from a QVariantMap and add it to the listWidget
    for ( int i = 0; i < array.size(); i++)
    {
        if (i == 0) {
            ui->comboBox->addItem("");
        }
        QJsonObject object = array.at(i).toObject();
        QVariantMap map = object.toVariantMap();
        QString title = map["title"].toString();
        ui->listWidget->addItem("[" + QString::number(i+1) + "] " + title);
        ui->comboBox->addItem("[" + QString::number(i+1) + "] " + title);
    }
}

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->messageTextEdit->setText(arg1);
}
