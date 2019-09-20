#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

public slots:
    void addListWidgetValues(const QByteArray &qbArray);
private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);
};

#endif // WIDGET_H
