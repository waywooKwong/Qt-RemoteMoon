<<<<<<< HEAD
#ifndef MOON_H
#define MOON_H

#include <QWidget>

namespace Ui
{
class moon;
}

class moon : public QWidget
{
    Q_OBJECT

public:
    explicit moon(QWidget *parent = nullptr);
    ~moon();

protected:
    void paintEvent(QPaintEvent *) override;
    void timerEvent(QTimerEvent *) override;


private:
    double m_phase=0;
    Ui::moon *ui;
};

#endif // MOON_H
=======
#ifndef MOON_H
#define MOON_H

#include <QWidget>

#include <QVBoxLayout>
#include <QPushButton>

namespace Ui
{
class moon;
}

class moon : public QWidget
{
    Q_OBJECT

public:
    explicit moon(QWidget *parent = nullptr);
    ~moon();

protected:
    void paintEvent(QPaintEvent *) override;
    void timerEvent(QTimerEvent *) override;

    void onOkButtonClicked();


private:    
    void setupUi();
    double m_phase=0;

    QVBoxLayout *layout;
    QPushButton *button;
    Ui::moon *ui;
};

#endif // MOON_H
>>>>>>> 3671142 (git 初始化尝试)
