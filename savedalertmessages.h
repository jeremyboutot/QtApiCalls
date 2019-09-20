#ifndef SAVEDALERTMESSAGES_H
#define SAVEDALERTMESSAGES_H

#include <QWidget>

namespace Ui {
class SavedAlertMessages;
}

class SavedAlertMessages : public QWidget
{
    Q_OBJECT

public:
    explicit SavedAlertMessages(QWidget *parent = nullptr);
    ~SavedAlertMessages();

private:
    Ui::SavedAlertMessages *ui;
};

#endif // SAVEDALERTMESSAGES_H
