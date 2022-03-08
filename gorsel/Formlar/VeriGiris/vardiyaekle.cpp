#include "vardiyaekle.h"
#include "ui_vardiyaekle.h"

vardiyaekle::vardiyaekle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vardiyaekle)
{
    ui->setupUi(this);
}

vardiyaekle::~vardiyaekle()
{
    delete ui;
}
