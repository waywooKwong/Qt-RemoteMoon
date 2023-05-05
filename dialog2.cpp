#include "dialog2.h"
#include "ui_dialog2.h"
#include "moon.h"

dialog2::dialog2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog2)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
}

dialog2::~dialog2()
{
    delete ui;
}

void dialog2::on_pushButton_clicked()
{
    this->close();
    class moon*moon=new class moon();
    moon->show();
}

