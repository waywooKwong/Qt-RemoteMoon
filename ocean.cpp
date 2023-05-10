#include "ocean.h"
#include "ui_ocean.h"
#include <dialog.h>

#include <qmath.h>
#include <QPainter>
#include <QPainterPath>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QPen>

Ocean::Ocean(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ocean)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->setWindowTitle("RemoteMoon");

    //定时更新
    phase = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]()
    {
        phase += 5;
        update();
    });
    timer->start(60);
}

void Ocean::paintEvent(QPaintEvent *)
{
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

    ////白山
    // 渐变色
    QColor color11(255, 255, 0);
    QColor color21(255, 255, 255);
    QColor color31(102, 178, 255);

    for (int i = 0; i <= width; i += 5)
    {
        double x = i * 5;//调整x距离实现了动态效果
        double y = qSin((i + phase + 5) * 0.03) * 20 ;
        y += qSin((i + phase + 5) * 0.05) * 20 + 10;
        y += qSin((i + phase + 5) * 0.1) * 5 + 25;
        y += qSin((i + phase + 5) * 0.2) * 1 + 30;
        y += height / 1.5 - 30;
        points.append(QPointF(x, y));
    }
    points.append(QPointF(width, height));
    points.append(QPointF(0, height));

    //海浪
    QLinearGradient gradient1(0, 0, 0, height);
    gradient.setColorAt(0, color11);
    gradient.setColorAt(0.5, color21);
    gradient.setColorAt(1, color31);
    painter.setBrush(gradient);
    painter.drawPolygon(points);

    //云一
    int x = cloudX;
    int y = cloudY;
    int radius = 75;

    painter.setBrush(QBrush(QColor(255, 255, 255)));
    painter.drawEllipse(x, y, radius, radius);
    painter.drawEllipse(x + radius / 1, y, radius*2+10, radius);
    painter.drawEllipse(x - radius / 1+20, y, radius*2-10, radius);
    painter.drawEllipse(x + radius / 2-20, y - radius / 2, radius*2+10, radius+10);
    painter.drawEllipse(x - radius / 2-15, y - radius / 2, radius*2, radius-10);

    painter.setBrush(QBrush(QColor(255, 255, 255)));
    painter.drawEllipse(x + radius / 1+500, y+100, radius*2, radius);
    painter.drawEllipse(x - radius / 1+20+500, y+100, radius*2, radius);
    painter.drawEllipse(x + radius / 2-20+500, y - radius / 2+100, radius*2+10, radius+10);
    painter.drawEllipse(x - radius / 2-15+500, y - radius / 2+100, radius*2, radius-10);

    //云二
    int x2 = 1180-cloudX2;
    int y2 = cloudY2+100;

    painter.setBrush(QBrush(QColor(255, 255, 255)));
    painter.drawEllipse(x2 - radius / 1.5, y2 - radius, radius, radius);
    painter.drawEllipse(x2 + radius / 1, y2 - radius, radius, radius);
    painter.drawEllipse(x2 + radius / 2, y2 - radius * 1.5, radius, radius);
    painter.drawEllipse(x2 - radius / 2, y2 - radius * 1.5, radius, radius);
    painter.drawEllipse(x2 + radius / 2-20, y2 - radius, radius+10, radius+10);

    //海中月
    QPainter painterMoon(this);
    painterMoon.setRenderHint(QPainter::Antialiasing,true);

    QRadialGradient gradientMoon(cloudX/2 + 563, -cloudY/2 + 663, 62.5);
    gradientMoon.setColorAt(0, Qt::yellow);
    gradientMoon.setColorAt(1, QColor(255,255,224));
    QBrush brush(gradientMoon);
    painterMoon.setBrush(brush);

    moonX=100;
    moonY=550;
    painterMoon.drawEllipse(moonX,moonY,125,125);
    painterMoon.setPen(Qt::NoPen);
}

//位置更新
void Ocean::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        cloudX += 10 + QRandomGenerator::global()->bounded(-25, 25);
        cloudY += 10 + QRandomGenerator::global()->bounded(-50, 50);
        cloudX2 -= -20 + QRandomGenerator::global()->bounded(-30, 30);
        cloudY2 += 10 + QRandomGenerator::global()->bounded(-45, 45);
    }
    //越出边界更新回初始位置
    if(cloudY>=720)
    {
        cloudY=100;
    }
    if(cloudY2>=720)
    {
        cloudY2=100;
    }
    if(cloudX>=1280)
    {
        cloudX=100;
    }
    if(cloudX2>=1200)
    {
        cloudX2=100;
    }

    //碰撞检测
    int dx = moonX - cloudX,dx2 = moonX - cloudX2;
    int dy = moonY - cloudY,dy2 = moonY - cloudY2;
    int dist = qSqrt(dx*dx + dy*dy),dist2 = qSqrt(dx2*dx2 + dy2*dy2);
    if (dist < 100 ||dist2 < 100)
    {
        close();
        class dialog* dialog=new class dialog();
        dialog->show();
    }
}

Ocean::~Ocean()
{
    delete ui;
}
