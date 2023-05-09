#include "lightray.h"
#include "ui_lightray.h"
#include "moon.h"

#include <cmath>
#include <QApplication>
#include <QTimer>

#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QtWidgets>

lightRay::lightRay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lightRay)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->setWindowTitle("RemoteMoon");

    QGraphicsScene* scene = new QGraphicsScene(this); // 创建图形场景
    QGraphicsView* view = new QGraphicsView(scene, this);
    view->setAttribute(Qt::WA_DeleteOnClose);

    view->resize(size());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ////按钮
    QPushButton* button = new QPushButton("Find more", this);
    button->setFont(QFont("JetBrains Mono NL", 16));
    button->setStyleSheet("background-color: black; color: white; border-radius: 5px;");
    button->move(560,500); // 设置按钮位置
    connect(button, &QPushButton::clicked, this, &lightRay::onPushButtonClicked);

    QTimer* timerButton = new QTimer(this);
    timerButton->setSingleShot(true);
    connect(timerButton, &QTimer::timeout, this, [=]()
    {
        button->setVisible(true);
    });
    timerButton->start(23000);
    button->setVisible(false);

    ////light1
    QGraphicsLineItem* lightRay1 = new QGraphicsLineItem(0, 0, width(), height());
    lightRay1->setPen(QPen(Qt::yellow, 24));
    scene->addItem(lightRay1);

    qreal angle = qDegreesToRadians((double)-45);
    qreal dx = 4 * qCos(angle);
    qreal dy = -3 * qSin(angle);

    ////light2
    QGraphicsLineItem* lightRay2 = new QGraphicsLineItem(800, 150, width(), height());
    lightRay2->setPen(QPen(QColor(0, 47, 167), 24));
    scene->addItem(lightRay2);

    qreal angle2 = qDegreesToRadians((double)45);
    qreal dx2 = 4.8 * qCos(angle2);
    qreal dy2 = 3.6 * qSin(angle2);

    ////light3
    QGraphicsLineItem* lightRay3 = new QGraphicsLineItem(450, 200, width(), height());
    lightRay3->setPen(QPen(QColor(126,12,110), 24));
    scene->addItem(lightRay3);

    qreal angle3 = qDegreesToRadians((double)30);
    qreal dx3 = 4 * qCos(angle3);
    qreal dy3 = 3 * qSin(angle3);

    ////light4
    QGraphicsLineItem* lightRay4 = new QGraphicsLineItem(800, 250, width(), height());
    lightRay4->setPen(QPen(QColor(139,0,0), 24));
    scene->addItem(lightRay4);

    qreal angle4 = qDegreesToRadians((double)-30);
    qreal dx4 = -4 * qCos(angle4);
    qreal dy4 = 3 * qSin(angle4);

    ////light5
    QGraphicsLineItem* lightRay5 = new QGraphicsLineItem(800, 250, width(), height());
    lightRay5->setPen(QPen(QColor(255,140,0), 24));
    scene->addItem(lightRay5);

    qreal angle5 = qDegreesToRadians((double)-30);
    qreal dx5 = -4 * qCos(angle5);
    qreal dy5 = 3 * qSin(angle5);

    ////light6
    QGraphicsLineItem* lightRay6 = new QGraphicsLineItem(600, 350, width(), height());
    lightRay6->setPen(QPen(QColor(230,230,250), 24));
    scene->addItem(lightRay6);

    qreal angle6 = qDegreesToRadians((double)40);
    qreal dx6 = -4 * qCos(angle6);
    qreal dy6 = 3 * qSin(angle6);

    ////light7
    QGraphicsLineItem* lightRay7 = new QGraphicsLineItem(0, 500, width(), height());
    lightRay7->setPen(QPen(Qt::white, 24));
    scene->addItem(lightRay7);

    qreal angle7 = qDegreesToRadians((double)-30);
    qreal dx7 = -4 * qCos(angle7);
    qreal dy7 = 3 * qSin(angle7);

    QTimer* timerLight = new QTimer(this);
    connect(timerLight, &QTimer::timeout, [=]
    {
        QPointF pos = lightRay1->pos();
        lightRay1->setPos(pos - QPointF(dx, dy));
        QPointF pos2 = lightRay2->pos();
        lightRay2->setPos(pos2 + QPointF(-dx2, dy2));
        QPointF pos3 = lightRay3->pos();
        lightRay3->setPos(pos3 + QPointF(dx3, -dy3));
        QPointF pos4 = lightRay4->pos();
        lightRay4->setPos(pos4 + QPointF(dx4, -dy4));
        QPointF pos5 = lightRay5->pos();
        lightRay5->setPos(pos5 + QPointF(-dx5, dy5));
        QPointF pos6 = lightRay6->pos();
        lightRay6->setPos(pos6 + QPointF(-dx6, -dy6));
        QPointF pos7 = lightRay7->pos();
        lightRay7->setPos(pos7 + QPointF(dx7, -dy7));
    });
    timerLight->start(50); // 每50毫秒更新一次光线位置

}
void lightRay::onPushButtonClicked()
{
    class moon* moon= new class moon();
    moon->show();
    this->close();
}

lightRay::~lightRay()
{
    delete ui;
}





