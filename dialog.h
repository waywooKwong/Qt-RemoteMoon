<<<<<<< HEAD
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class dialog;
}

class dialog : public QDialog
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

private:
    Ui::dialog *ui;
};

#endif // DIALOG_H
=======
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui
{
class dialog;
}

class dialog : public QDialog //此处调整使用了QDialog
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::dialog *ui;

};

#endif // DIALOG_H
>>>>>>> 3671142 (git 初始化尝试)
