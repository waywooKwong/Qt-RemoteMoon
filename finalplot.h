#ifndef FINALPLOT_H
#define FINALPLOT_H

#include <QObject>
#include <QWidget>

namespace Ui
{
class FinalPlot;
}

class FinalPlot : public QWidget
{
    Q_OBJECT

public:
    explicit FinalPlot(QWidget *parent = nullptr);
    ~FinalPlot();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int x=100;
    int y=660;
    Ui::FinalPlot *ui;

private slots:
    void animate();
    void on_pushButton_clicked();
};
#endif // FINALPLOT_H
