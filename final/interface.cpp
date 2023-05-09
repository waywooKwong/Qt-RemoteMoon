#include "interface.h"
#include "ui_interface.h"
#include "ocean.h"
#include "help.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>

Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);//设置页面大小
    setStyleSheet("QLabel{color:#7E0C6E}");//设置标题颜色，NKU青莲紫rgb(126,12,110)

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Remote Moon");
    QWidget *window = new QWidget;
    window->setWindowTitle("Remote Moon");
    this->setWindowTitle("RemoteMoon");
}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_pushButton_clicked()
{
    this->close();
    Ocean* ocean=new Ocean();
    ocean->show();
}


void Interface::on_pushButton_2_clicked()
{
    this->close();
    Help* help=new Help();
    help->show();
}


void Interface::on_pushButton_3_clicked()
{
    this->close();
}

