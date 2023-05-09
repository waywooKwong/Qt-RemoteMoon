<<<<<<< HEAD

#include "interface.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Interface w;
    w.show();
    return a.exec();
}
=======
#include "interface.h"
#include "help.h"
#include "ocean.h"
#include "moon.h"
#include "dialog.h"
#include "lightray.h"
#include "dialog2.h"
#include "play.h"
#include "finalplot.h"

#include "music.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Background Music
    Music music;
    music.createPlayer();

    //Name,Window
    QIcon icon(":/Pictures/moon.png");
    a.setWindowIcon(icon);
    QMainWindow mainWindow;
    mainWindow.setWindowIcon(icon);
    mainWindow.setWindowTitle("Remote Moon");
    a.setApplicationName("Remote Moon");

    Interface w;
    Help help;
    Ocean ocean;
    dialog dialog;
    lightRay lightRay;
    moon moon; 
    dialog2 dialog2;
    Play play;   
    FinalPlot finalplot;

    //help.show();
    //ocean.show();
    //dialog.show();
    //lightRay.show();
    //moon.show();
    //dialog2.show();
    //play.show();
    //finalplot.show();

    w.show();
    return a.exec();
}
>>>>>>> 3671142 (git 初始化尝试)
