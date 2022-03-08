#include "uretimbilgileri.h"
#include "ui_uretimbilgileri.h"

uretimBilgileri::uretimBilgileri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uretimBilgileri)
{
    ui->setupUi(this);
}

uretimBilgileri::~uretimBilgileri()
{
    delete ui;
}
