#include "calisanekle.h"
#include "ui_calisanekle.h"
#include <veritabani.h>
#include <QMessageBox>
calisanekle::calisanekle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calisanekle)
{
    ui->setupUi(this);

   _calisan=Veritabani::veritabani().calisan().yeni();
    _degisiklikvar=false;
}


calisanekle::~calisanekle()
{
    delete ui;
}

void calisanekle::gorselGuncelle()
{
    ui->leadi->setText(_calisan->adi());
    ui->leSoyadi->setText(_calisan->soyadi());
    ui->leSicilno->setText(_calisan->sicilno());
    ui->leKimlikno->setText(_calisan->tckimlik());
    ui->teAdress->setText(_calisan->adres());

}

void calisanekle::veriGuncelle()
{
    _calisan->setAdi(ui->leadi->text());
    _calisan->setSoyadi(ui->leSoyadi->text());
    _calisan->setSicilno(ui->leSicilno->text());
    _calisan->setTckimlik(ui->leKimlikno->text());
    _calisan->setAdres(ui->teAdress->document()->toPlainText());
}
bool calisanekle::degisiklikvar() const
{
    return _degisiklikvar;
}

void calisanekle::setDegisiklikvar(bool degisiklikvar)
{
    _degisiklikvar = degisiklikvar;
}

void calisanekle::gorseldegisti()
{
    setDegisiklikvar(true);
}

void calisanekle::reject()
{
    if (_degisiklikvar)
    {
        auto cevap =QMessageBox::question(this,"bilgi değişti","kaydetmeden cıkmak istediginize emin misiniz",
                                          QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if(cevap==QMessageBox::No){return;
        }
    }
    QDialog::reject();
}

void calisanekle::on_kaydet_clicked()
{
    veriGuncelle();
    Veritabani::veritabani().calisan().ekle(_calisan);
    auto cevap=  QMessageBox::question(
                    this,"calisan eklendi","yeni calisan eklemek istermisiniz?",
                           QMessageBox::Yes |QMessageBox::No,QMessageBox::Yes);
        if (cevap==QMessageBox::Yes){
            _calisan=Veritabani::veritabani().calisan().yeni();
            gorselGuncelle();
            ui->leadi->setFocus();
     setDegisiklikvar(false);
}else
{
       accept();
        }}
