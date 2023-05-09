<<<<<<< HEAD
#ifndef DIALOG2_H
#define DIALOG2_H

#include <QWidget>

namespace Ui {
class dialog2;
}

class dialog2 : public QWidget
{
    Q_OBJECT

public:
    explicit dialog2(QWidget *parent = nullptr);
    ~dialog2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialog2 *ui;
};

#endif // DIALOG2_H
=======
#ifndef DIALOG2_H
#define DIALOG2_H

#include <QWidget>

namespace Ui
{
class dialog2;
}

class dialog2 : public QWidget
{
    Q_OBJECT

public:
    explicit dialog2(QWidget *parent = nullptr);
    ~dialog2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialog2 *ui;
};

#endif // DIALOG2_H
>>>>>>> 3671142 (git 初始化尝试)
