<<<<<<< HEAD
#ifndef LIGHTRAY_H
#define LIGHTRAY_H

#include <QWidget>

namespace Ui
{
class lightRay;
}

class lightRay : public QWidget
{
    Q_OBJECT

public:
    explicit lightRay(QWidget *parent = nullptr);
    void onTimeout();
    ~lightRay();

private slots:
    void onPushButtonClicked();

private:
    Ui::lightRay *ui;
    class dialog2 *m_dialog = nullptr;
};

#endif // LIGHTRAY_H
=======
#ifndef LIGHTRAY_H
#define LIGHTRAY_H

#include <QWidget>

namespace Ui
{
class lightRay;
}

class lightRay : public QWidget
{
    Q_OBJECT

public:
    explicit lightRay(QWidget *parent = nullptr);
    void onTimeout();
    ~lightRay();

private slots:
    void onPushButtonClicked();

private:
    Ui::lightRay *ui;
};

#endif // LIGHTRAY_H
>>>>>>> 3671142 (git 初始化尝试)
