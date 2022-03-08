#include "urunekle.h"
#include "ui_urunekle.h"
#include <QMessageBox>
#include <veritabani.h>

urunekle::urunekle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::urunekle)
{
    ui->setupUi(this);
    _Urun=Veritabani::veritabani().urun().yeni();

    _degisiklikvarmi= false;
}

urunekle::~urunekle()
{
    delete ui;
}

void urunekle::on_Kaydet_clicked()
{
    veriGuncelle();
    Veritabani::veritabani().urun().ekle(_Urun);
    auto cevap=  QMessageBox::question(
                    this,"urun kaydı eklendi","yeni ürun eklemek istermisiniz?",
                           QMessageBox::Yes |QMessageBox::No,QMessageBox::Yes);
        if (cevap==QMessageBox::Yes){
            _Urun=Veritabani::veritabani().urun().yeni();
            gorselGuncelle();
            ui->leurunAdi->setFocus();
     setDegisiklikvarmi(false);
}else
{
       accept();
        }
}

bool urunekle::degisiklikvarmi() const
{
    return _degisiklikvarmi;
}

void urunekle::gorselGuncelle()
{
    ui->leurunAdi->setText(_Urun->urunAdi());
}

void urunekle::veriGuncelle()
{
    _Urun->setUrunAdi(ui->leurunAdi->text());
}

void urunekle::setDegisiklikvarmi(bool degisiklikvarmi)
{
    _degisiklikvarmi = degisiklikvarmi;
}

void urunekle::degisti()
{
    setDegisiklikvarmi(true);
}

void urunekle::reject()
{
    if(degisiklikvarmi()==true){
        auto cevap =QMessageBox::question(this,"bilgi değişti","kaydetmeden cıkmak istediginize emin misiniz",
                                          QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if(cevap==QMessageBox::No){return;
        }
    }    QDialog::reject();

}
