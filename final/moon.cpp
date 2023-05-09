#include "moon.h"
#include "ui_moon.h"
#include "dialog2.h"

#include <QApplication>
#include <QWidget>
#include <QtWidgets>
#include <QLabel>
#include <QPainter>
#include <QTimer>
#include <cmath>
#include <QPainterPath>


moon::moon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::moon)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    this->setWindowTitle("RemoteMoon");

    startTimer(300);
    setupUi();
}
void moon::setupUi()
{
    layout = new QVBoxLayout(this);
    button = new QPushButton("Moon is coming", this);
    button->setStyleSheet("font-family: JetBrains Mono NL; font-size: 48px; font-weight: bold;");
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &moon::onOkButtonClicked);
}

void moon::onOkButtonClicked()
{
    class dialog2 * dialog2=new class dialog2;
    dialog2->show();
    this->close();
}

void moon::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);

    int width0 = this->width() ;
    int width = 200 ;
    int radius = width / 2;

    // 绘制圆形月亮
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(width0-width,radius,radius,radius);
    painter.setPen(Qt::NoPen);

    // 根据月相调整绘制方式
    if (m_phase > 0 && m_phase < 0.5)
    {
        int arc = m_phase * 720;
        painter.setBrush(QColor(192,192,192));
        painter.drawPie(width0-width, radius, radius, radius, 90 * 16 - arc / 2, arc * 16);//

        button->hide();
    }
    else
    {
        int arc = (1.0 - m_phase) * 720;
        painter.setBrush(Qt::black);
        painter.drawPie(width0-width, radius, radius, radius, 90 * 16 - arc / 2, arc * 16);//

        // 绘制月亮的阴影效果
        QPainterPath path;
        path.addEllipse(width0-width, radius, radius, radius);//
        path.addRect(rect());
        painter.setClipPath(path);

        QLinearGradient gradient(QPointF(0, 0), QPointF(0, 400));
        gradient.setColorAt(0, QColor(0, 0, 0, 255));
        //gradient.setColorAt(1, QColor(192, 192, 192, 100));//可实现渐变效果

        painter.setBrush(gradient);
        painter.drawRect(rect());

        button->show();
    }
}

void moon::timerEvent(QTimerEvent *)
{
    m_phase += 0.01;
    if (m_phase >= 1.0)
    {
        m_phase = 0.0;
    }
    update();
}

moon::~moon()
{
    delete ui;
}
