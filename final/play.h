#ifndef PLAY_H
#define PLAY_H

#include <QLabel>
#include <QTimer>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

namespace Ui
{
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
    void paintEvent(QPaintEvent *);
    void onOkButtonClicked();

    void hideLabel();

private:
    Ui::Play *ui;

    void setupUi();
    void createMoons();
    void startAnimations();

    QVBoxLayout *layout;
    QLabel *label;
    QPushButton *button;
    QTimer* timerLabel;
    QTimer* timerButton;

    const int moonCount = 9;
    const int moonSize = 100;
    int count = moonCount;
    QLabel *moons[9];
    QSequentialAnimationGroup *animationGroup;
};

#endif // PLAY_H
