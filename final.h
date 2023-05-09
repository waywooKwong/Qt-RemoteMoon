#ifndef FINAL_H
#define FINAL_H

#include <QWidget>
#include <QMediaPlayer>

namespace Ui {
class Final;
}

class Final : public QWidget
{
    Q_OBJECT

public:
    explicit Final(QWidget *parent = nullptr);
    Final(QMediaPlayer* player, QWidget *parent = nullptr);
    ~Final();

protected:
    void updatePosition();
    void paintEvent(QPaintEvent *) override;

private:
    QMediaPlayer* player;
    QRect currentRect;
    Ui::Final *ui;
};

#endif // FINAL_H
