#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class Music;
}

class Music : public QWidget
{
    Q_OBJECT

public:
    explicit Music(QWidget *parent = nullptr);
    QMediaPlayer *player=new QMediaPlayer;
    QMediaPlaylist *playlist = new QMediaPlaylist(player);

    void createPlayer()
    {
        player = new QMediaPlayer(this);
        QMediaPlaylist *playlist = new QMediaPlaylist(player);

        playlist->addMedia(QUrl("qrc:/Music/ReflectionEternal.mp3"));
        playlist->addMedia(QUrl("qrc:/Music/WishYouWereHere.mp3"));

        player->setPlaylist(playlist);
        player->play();
    }

    ~Music();

private:
    Ui::Music *ui;
};

#endif // MUSIC_H
