#include "finalplot.h"
#include "ui_finalplot.h"
#include <qmath.h>
#include <music.h>

#include <QTimer>
#include <QPainter>
#include <QPainterPath>
#include <QMainWindow>
#include <QApplication>


FinalPlot::FinalPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinalPlot)
{
    ui->setupUi(this);
    this->setFixedSize(1280, 760);
    this->setWindowTitle("RemoteMoon");

    // 设置定时器以便进行动画更新
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &FinalPlot::animate);
    timer->start(15);
}

void FinalPlot::paintEvent(QPaintEvent *)
{
    int radius=100;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRect(rect());
    painter.setClipPath(path);
    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 400));
    gradient.setColorAt(1, QColor(0, 0, 0, 255));
    gradient.setColorAt(0, QColor(192, 192, 192, 100));
    painter.setBrush(gradient);
    painter.drawRect(rect());

    painter.setBrush(Qt::yellow);
    painter.drawEllipse(x, y, radius, radius);
}
void FinalPlot::animate()
{
    if (x < 1090 && y > 30)
    {
        x += 2.4;
        y -= 0.5;
    }
    update();//更新参数进行绘图
}
FinalPlot::~FinalPlot()
{
    delete ui;
}

void FinalPlot::on_pushButton_clicked()
{
    this->close();
}
