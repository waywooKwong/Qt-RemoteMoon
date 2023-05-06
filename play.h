#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
//
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
//

namespace Ui {
class Play;
}

class Play : public QWidget
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);
    ~Play();

protected:
    void mousePressEvent(QMouseEvent *event);
    void onOkButtonClicked();

    void hideLabel();

    void paintEvent(QPaintEvent *);

private:
    Ui::Play *ui;

    void setupUi();
    void createMoons();
    void startAnimations();

    QVBoxLayout *layout;
    QLabel *label;
    QPushButton *button;
    const int moonCount = 9;
    const int moonSize = 100;
    int count = moonCount;
    QLabel *moons[9];
    QSequentialAnimationGroup *animationGroup;

    QTimer* timerLabel;
    QTimer* timerButton;


};



#endif // PLAY_H
