
#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <ocean.h>
#include <qlabel.h>
#include <qpalette.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

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
    Ocean *ocean=new Ocean();
};

#endif // INTERFACE_H
