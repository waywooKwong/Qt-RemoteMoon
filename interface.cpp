
#include "interface.h"
#include "ui_interface.h"
#include "ocean.h"

Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);//设置页面大小
    setStyleSheet("QLabel{color:#7E0C6E}");//设置标题颜色

}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_pushButton_clicked()
{
    this->close();
    ocean=new Ocean();
    ocean->show();
}


void Interface::on_pushButton_2_clicked()
{

}


void Interface::on_pushButton_3_clicked()
{
    this->close();
}

