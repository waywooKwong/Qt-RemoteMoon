#include "music.h"
#include "ui_music.h"

Music::Music(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Music)
{
    ui->setupUi(this);
}

Music::~Music()
{
    delete ui;
}
