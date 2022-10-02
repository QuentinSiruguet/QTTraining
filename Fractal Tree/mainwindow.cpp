#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);

    this->sliderAngle = this->ui->horizontalSlider;
    this->sliderCoeff = this->ui->horizontalSlider_2;
    this->sliderBlen = this->ui->horizontalSlider_3;

    connect(this->sliderAngle, &QSlider::valueChanged, this , &MainWindow::changeAngle);
    connect(this->sliderCoeff, &QSlider::valueChanged, this , &MainWindow::changeCblen);
    connect(this->sliderBlen, &QSlider::valueChanged, this , &MainWindow::changeBlen);
}

MainWindow::~MainWindow()
{
    delete this->ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    this->p = new QPainter(this);
    this->p->fillRect(this->rect(), QColor(QColorConstants::Black));
    this->p->setPen(QColor(150,150,255));
    this->p->translate(this->size().width()/2, this->size().height());
    branch(this->blen);
    this->p->end();
}

void MainWindow::redraw()
{
    this->update();
    if(this->p->isActive())
    {
        this->p->translate(this->size().width()/2, this->size().height());
        this->branch(blen);
        this->p->end();
    }
}

void MainWindow::branch(float len)
{
    this->p->drawLine(0, 0, 0, -len);
    this->p->translate(0, -len);

    if(len>3 && this->p->isActive())
    {
        for(int i = 1; i <= bnumb; i++)
        {
            this->p->save();
            this->p->rotate(this->angle/i);
            this->branch(len*this->cblen);
            this->p->restore();

            this->p->save();
            this->p->rotate(-this->angle/i);
            this->branch(len*this->cblen);
            this->p->restore();
        }
    }
}
