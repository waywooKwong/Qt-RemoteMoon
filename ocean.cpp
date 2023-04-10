#include "ocean.h"
#include "ui_ocean.h"

Ocean::Ocean(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ocean)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
}

Ocean::~Ocean()
{
    delete ui;
}
