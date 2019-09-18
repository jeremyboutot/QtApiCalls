#include "widget.h"
#include "ui_widget.h"
#include "apicalls.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ApiCalls *apicalls = new ApiCalls;
    QByteArray myByteArray;
    myByteArray = apicalls->getJsonTestData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addListWidgetValues(QByteArray &dataBuffer)
{
    qDebug() << "QByteArray received from ApiCalls class" << endl;
}
