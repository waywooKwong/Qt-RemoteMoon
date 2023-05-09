#include "play.h"
#include "ui_play.h"
#include "finalplot.h"

#include <QRandomGenerator>
#include <QMouseEvent>

Play::Play(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->setWindowTitle("RemoteMoon");

    createMoons();
    startAnimations();
    setupUi();
}
void Play::setupUi()
{
    layout = new QVBoxLayout(this);
    label = new QLabel("Clarify the moons", this);
    layout->addWidget(label);
    label->setStyleSheet("font-family: JetBrains Mono NL; color: white; font-size: 48px; font-weight: bold;");
    label->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    timerLabel=new QTimer(this);
    connect(timerLabel, &QTimer::timeout, this, &Play::hideLabel);
    timerLabel->start(3000);//label显示消失

    button = new QPushButton("To the remote place", this);
    button->setStyleSheet("font-family: JetBrains Mono NL; font-size: 48px; font-weight: bold;");
    button->setEnabled(false);
    layout->addWidget(button);
    button->hide();
    connect(button, &QPushButton::clicked, this, &Play::onOkButtonClicked);//button在图案全部消失后再显示
}

void Play::createMoons()
{
    animationGroup = new QSequentialAnimationGroup();

    for (int i = 0; i < moonCount; ++i)
    {
        QColor color = QColor::fromRgb(QRandomGenerator::global()->bounded(256),
                                       QRandomGenerator::global()->bounded(256),
                                       QRandomGenerator::global()->bounded(256));
        QPoint pos = QPoint(QRandomGenerator::global()->bounded(width() - moonSize),
                            QRandomGenerator::global()->bounded(height() - moonSize));
        moons[i] = new QLabel(this);
        moons[i]->setFixedSize(moonSize, moonSize);
        moons[i]->move(pos);
        moons[i]->setBackgroundRole(QPalette::Base);
        moons[i]->setAutoFillBackground(true);
        moons[i]->setStyleSheet(QString("background-color: %1; border-radius: %2px;").arg(color.name()).arg(moonSize / 2));
        QPropertyAnimation *animation = new QPropertyAnimation(moons[i], "geometry");
        animation->setDuration(1000);
        animation->setStartValue(QRect(pos, QSize(moonSize, moonSize)));
        animation->setEndValue(QRect(pos, QSize(0, 0)));
        animationGroup->addAnimation(animation);
    }
}

void Play::mousePressEvent(QMouseEvent *event)
{
    for (int i = 0; i < moonCount; ++i)
    {
        if (moons[i] != nullptr && moons[i]->geometry().contains(event->pos()))
        {
            delete moons[i];
            moons[i] = nullptr;
            count--;
            break;
        }
    }
    // 如果所有图案都已删除，启用button
    if (count == 0)
    {
        button->show();
        button->setEnabled(true);
    }
}
void Play::startAnimations()
{
    animationGroup->start();
}

void Play::onOkButtonClicked()
{
    FinalPlot* finalplot=new FinalPlot();
    finalplot->show();
    this->close();
}

void Play::hideLabel()
{
    label->hide();
}


#include <qmath.h>
#include <QPainter>
void Play::paintEvent(QPaintEvent *)
{
    int phase = 0;
    int cloudX=100,cloudY=100;
    int moonX,moonY;


    ////蓝浪
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    // 渐变色
    QColor color1(80, 140, 220);
    QColor color2(60, 120, 200);
    QColor color3(40, 100, 180);

    int width = this->width();
    int height = this->height();
    QVector<QPointF> points;

    for (int i = 0; i <= width; i += 5)
    {
        double x = i;
        double y = qSin((i + phase) * 0.03) * 20;
        y += qSin((i + phase) * 0.05) * 20;
        y += qSin((i + phase) * 0.1) * 5;
        y += qSin((i + phase) * 0.2) * 1;
        y += height / 1.8 - 40;
        points.append(QPointF(x, y));
    }
    points.append(QPointF(width, height));
    points.append(QPointF(0, height));

    // 画出海浪
    QLinearGradient gradient(0, 0, 0, height);
    gradient.setColorAt(0, color1);
    gradient.setColorAt(0.5, color2);
    gradient.setColorAt(1, color3);
    painter.setBrush(gradient);
    painter.drawPolygon(points);

    //海中月
    QPainter painterMoon(this);
    painterMoon.setRenderHint(QPainter::Antialiasing,true);

    QRadialGradient gradientMoon(cloudX/2+563, -cloudY/2+663, 62.5);
    gradientMoon.setColorAt(0, Qt::yellow);
    gradientMoon.setColorAt(1, QColor(255,255,224));
    QBrush brush(gradientMoon);
    painterMoon.setBrush(brush);

    moonX=cloudX/2+500;
    moonY=-cloudY/2+600;
    painterMoon.drawEllipse(moonX,moonY,125,125);
    painterMoon.setPen(Qt::NoPen);
}

Play::~Play()
{
    delete ui;
}

////此为错误样例，介绍时可以讲解
/// 在 mousePressEvent() 函数中，使用计数器 count 来记录剩余的图案数量，而不是遍历整个数组 moons。
/// 修改了删除图案的代码，将其从数组 moons 中移除，而不是将其指针置为空。
/*
void Play::mousePressEvent(QMouseEvent *event)
{
    for (int i = 0; i < moonCount; ++i) {
        if (moons[i]->geometry().contains(event->pos())) {
            moons[i]->deleteLater();
            // 将已删除的图案指针置为空
            moons[i] = nullptr;
            break;
        }
    }

    // 判断是否所有图案都已删除
    bool allMoonsDeleted = true;
    for (int i = 0; i < moonCount; ++i) {
        if (moons[i] != nullptr) {
            allMoonsDeleted = false;
            break;
        }
    }

    // 若所有图案都已删除，启用OK按钮
    if (allMoonsDeleted) {
        button->setEnabled(true);
    }
}
*/
