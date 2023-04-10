#ifndef OCEAN_H
#define OCEAN_H

#include <QWidget>

namespace Ui {
class Ocean;
}

class Ocean : public QWidget
{
    Q_OBJECT

public:
    explicit Ocean(QWidget *parent = nullptr);
    ~Ocean();

private:
    Ui::Ocean *ui;
};

#endif // OCEAN_H
