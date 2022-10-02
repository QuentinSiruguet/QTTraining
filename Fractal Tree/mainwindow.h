#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    QPainter *p;
    QSlider *sliderAngle;
    QSlider *sliderCoeff;
    QSlider *sliderBlen;

    int blen = 200;
    int angle = 45;
    float cblen = 0.1;
    int bnumb = 1;

    void changeBlen(){this->blen = sliderBlen->value(), redraw();}
    void changeAngle(){this->angle = sliderAngle->value(), redraw();}
    void changeCblen(){this->cblen = (float)sliderCoeff->value()/100, redraw();}

    void redraw();
    void branch(float);
};
#endif // MAINWINDOW_H
