<<<<<<< HEAD
#ifndef OCEAN_H
#define OCEAN_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QObject>
#include <QtWidgets>

namespace Ui
{
class Ocean;
}

class Ocean : public QWidget
{
    Q_OBJECT

public:
    explicit Ocean(QWidget *parent = nullptr);
    ~Ocean();

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::Ocean *ui;
    QTimer* timer;
    int phase = 0;    
    int cloudX=100,cloudX2=120,cloudY=100,cloudY2=120;
    int moonX=100, moonY=550;
};

#endif // OCEAN_H
=======
#ifndef OCEAN_H
#define OCEAN_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QObject>
#include <QtWidgets>

namespace Ui
{
class Ocean;
}

class Ocean : public QWidget
{
    Q_OBJECT

public:
    explicit Ocean(QWidget *parent = nullptr);
    ~Ocean();

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::Ocean *ui;
    QTimer* timer;
    int phase = 0;    
    int cloudX=100,cloudX2=120,cloudY=100,cloudY2=120;
    int moonX=100, moonY=550;
};

#endif // OCEAN_H
>>>>>>> 3671142 (git 初始化尝试)
