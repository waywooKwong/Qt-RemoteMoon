#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>

namespace Ui
{
class Interface;
}

class Interface : public QMainWindow

{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Interface *ui;
};

#endif // INTERFACE_H
