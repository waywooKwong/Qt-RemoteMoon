#include "dialog.h"
#include "ui_dialog.h"
#include "lightray.h"

dialog::dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->setWindowTitle("RemoteMoon");
}

dialog::~dialog()
{
    delete ui;
}

void dialog::on_pushButton_2_clicked()
{
    lightRay *lightray=new lightRay;
    lightray->show();
    this->close();
}

