<<<<<<< HEAD
#include "help.h"
#include "ui_help.h"
#include "interface.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
}

Help::~Help()
{
    delete ui;
}

void Help::on_pushButton_clicked()
{
    Interface *interface=new Interface();
    interface->show();
    this->close();
}


void Help::on_pushButton_2_clicked()
{
    this->close();
}

=======
#include "help.h"
#include "ui_help.h"
#include "interface.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->setWindowTitle("RemoteMoon");
}

void Help::on_pushButton_clicked()
{
    Interface *interface=new Interface();
    interface->show();
    this->close();
}

void Help::on_pushButton_2_clicked()
{
    this->close();
}

Help::~Help()
{
    delete ui;
}

>>>>>>> 3671142 (git 初始化尝试)
