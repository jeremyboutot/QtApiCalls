#include "savedalertmessages.h"
#include "ui_savedalertmessages.h"

SavedAlertMessages::SavedAlertMessages(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SavedAlertMessages)
{
    ui->setupUi(this);
}

SavedAlertMessages::~SavedAlertMessages()
{
    delete ui;
}
