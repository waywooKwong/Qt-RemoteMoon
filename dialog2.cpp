#include "dialog2.h"
#include "ui_dialog2.h"
#include "play.h"

dialog2::dialog2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog2)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->setWindowTitle("RemoteMoon");
}

dialog2::~dialog2()
{
    delete ui;
}

void dialog2::on_pushButton_clicked()
{
    Play* play=new Play();
    play->show();
    this->close();
}
