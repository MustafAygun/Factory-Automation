#include "uretimekle.h"
#include "ui_uretimekle.h"
#include <veritabani.h>
#include <VeriSiniflari/urun.h>
#include<VeriSiniflari/calisan.h>
#include<VeriSiniflari/uretim.h>
#include<VeriSiniflari/vardiya.h>
#include<Formlar/VeriGiris/vardiyaekle.h>
#include<QMessageBox>
#include <Formlar/VeriGiris/calisanekle.h>
#include <Formlar/VeriGiris/urunekle.h>

uretimekle::uretimekle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uretimekle)
{
    ui->setupUi(this);

     _degisiklikvarmi =false;
    _uretim =Veritabani::veritabani().uretim().yeni();
    this->uruncomboboxdoldur();
    this->calisancomboboxdoldur();
}

uretimekle::~uretimekle()
{
    delete ui;

}
void uretimekle::reject()
{
    if(_degisiklikvarmi==true){
        auto cevap =QMessageBox::question(this,
                                          "bilgi değişti",
                                          "kaydetmeden cıkmak istediginize emin misiniz",
                                          QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if(cevap==QMessageBox::No){return;
        }
    }    QDialog::reject();

}

void uretimekle::degisti()
{
    setDegisiklikvarmi(true);
}

void uretimekle::on_pbKaydet_clicked()
{
    veriguncelle();
    if(_urun->id() == 0 || _calisan->calisanId()==0){
        QMessageBox::critical(this,tr("Hata var!!"),
                              tr("urun yada calisan secilmedi Kayıt yapılamaz"),
                              QMessageBox::Ok);
        return;
    }
    Veritabani::veritabani().uretim().ekle(_uretim);
    auto cevap=  QMessageBox::question(
                    this,"calisan eklendi","yeni calisan eklemek istermisiniz?",
                           QMessageBox::Yes |QMessageBox::No,QMessageBox::Yes);
        if (cevap==QMessageBox::Yes){
            _uretim=Veritabani::veritabani().uretim().yeni();
            gorselguncelle();
     setDegisiklikvarmi(false);
}else
{
       accept();
    }

}

bool uretimekle::degisiklikvarmi() const
{
    return _degisiklikvarmi;
}

void uretimekle::setDegisiklikvarmi(bool degisiklikvarmi)
{
    _degisiklikvarmi = degisiklikvarmi;
}

void uretimekle::gorselguncelle()
{ if(_urun->id()==0){ui->cmbUrunid->setCurrentIndex(0);}
    else{
        for(int i =1;1<ui->cmbUrunid->count();i++){
            int gizliid=ui->cmbUrunid->itemData(i).toInt();
            if(gizliid==_urun->id()){
                ui->cmbUrunid->setCurrentIndex(i);
                break;
            }
        }
    }

    if(_calisan->calisanId()==0){ui->cmbCalisanid->setCurrentIndex(0);}
        else{
            for(int i =1;1<ui->cmbCalisanid->count();i++){
                int gizliid=ui->cmbCalisanid->itemData(i).toInt();
                if(gizliid ==_calisan->calisanId()){
                    ui->cmbCalisanid->setCurrentIndex(i);
                    break;
                }
            }
        }


    ui->sbMiktar->setValue(_uretim->miktar());

}

void uretimekle::veriguncelle()
{
    _uretim->setCalisanId(ui->cmbCalisanid->currentData().toInt());
    _urun->setId(ui->cmbUrunid->currentData().toInt());
_uretim->setMiktar(ui->sbMiktar->value());

}

void uretimekle::on_Calisanekle_linkActivated(const QString &link)
{
    calisanekle form;
    form.exec();
    this->calisancomboboxdoldur();
}

void uretimekle::on_Urunekle_linkActivated(const QString &link)
{
    urunekle form;
    form.exec();
    this->uruncomboboxdoldur();
}

void uretimekle::uruncomboboxdoldur()
{
    auto tumurunler=
            Veritabani::veritabani().urun().ara([](Urun::Ptr){return true;});

    //sıralama yapıyor!!
    std::sort(tumurunler.begin(),tumurunler.end(),[](Urun::Ptr a,Urun::Ptr b){
        if(a->urunAdi()==b->urunAdi()) {
            return a->urunAdi()<b->urunAdi();
        }
        return a->urunAdi()<b->urunAdi();});


    ui->cmbUrunid->clear();
    ui->cmbUrunid->addItem(tr("urun seçin"),0);
    for(auto urun:tumurunler){
    ui->cmbUrunid->addItem(urun->urunAdi(),urun->id());}
}

void uretimekle::calisancomboboxdoldur()
{ auto tumcalisan=
            Veritabani::veritabani().calisan().ara([](Calisan::Ptr){return true;});

    //sıralama yapıyor!!
    std::sort(tumcalisan.begin(),tumcalisan.end(),[](Calisan::Ptr a,Calisan::Ptr b){
        if(a->adi()==b->adi()){
            return  a->soyadi()<b->soyadi();
            }
        return a->adi()<b->adi();});

    ui->cmbCalisanid->clear();
    ui->cmbCalisanid->addItem(tr("calisan secin"),0);
    for(auto Calisan:tumcalisan){
    ui->cmbCalisanid->addItem(Calisan->adi(),Calisan->calisanId());}
}
