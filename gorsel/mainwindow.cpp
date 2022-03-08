#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include <QMessageBox>
#include<Formlar/VeriGiris/calisanekle.h>
#include<Formlar/VeriGiris/urunekle.h>
#include<Formlar/VeriGiris/vardiyaekle.h>
#include<Formlar/VeriGiris/uretimekle.h>
#include <veritabani.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){ui->setupUi(this);}


MainWindow::~MainWindow(){delete ui;}


void MainWindow::close()
{auto cevap=  QMessageBox::question(
                this,"cıkıs onayı","cıkmak istediginize emin misiniz",
                       QMessageBox::Yes |QMessageBox::No,QMessageBox::No);
    if (cevap==QMessageBox::Yes){
    QMainWindow::close();
    }
}


void MainWindow::on_actionyeni_calisan_ekle_triggered()
{
    calisanekle form;
    form.exec();
}

void MainWindow::on_actionurun_ekle_triggered()
{
    urunekle form;
    form.exec();

}

void MainWindow::on_actionvardiya_ekle_triggered()
{
    vardiyaekle form;
    form.exec();

}

void MainWindow::on_actionuretim_ekle_triggered()
{

uretimekle().uruncomboboxdoldur();

    auto calisansayisi=Veritabani::veritabani().calisan().filtreyeUyanElemanSayisi(
                [](Calisan::Ptr ){return true;});


    while (calisansayisi==0) {
        auto cevap= QMessageBox::question(
                    this,tr("calisan bulunamadı?"),
                    tr("yeni calisan eklemek istermiydiniz?"),
                    QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);


        if(cevap==QMessageBox::No){
            QMessageBox::critical(
                        this,tr("kapatılıyor"),
                        tr("calisan eklemeden uretim ekleyemezsiniz!"),
                        QMessageBox::Ok,QMessageBox::Ok);
            return;
        }
    on_actionyeni_calisan_ekle_triggered();
    calisansayisi=Veritabani::veritabani().calisan().filtreyeUyanElemanSayisi(
                [](Calisan::Ptr ){return true;});
    uretimekle().calisancomboboxdoldur();
    }

    auto urunsayisi=Veritabani::veritabani().urun().filtreyeUyanElemanSayisi(
                [](Urun::Ptr){return true;});


    while (urunsayisi==0) {
        auto cevap= QMessageBox::question(
                    this,tr("ürün bulunamadı?"),
                    tr("yeni ürün eklemek istermiydiniz?"),
                    QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
        if(cevap==QMessageBox::No){
            QMessageBox::critical(
                        this,tr("kapatılıyor"),
                        tr("ürün eklemeden uretim ekleyemezsiniz!"),
                        QMessageBox::Ok,QMessageBox::Ok);
            return;
        }
    on_actionurun_ekle_triggered();
     urunsayisi=Veritabani::veritabani().urun().filtreyeUyanElemanSayisi(
                [](Urun::Ptr ){return true;});
     uretimekle().uruncomboboxdoldur();
    }


    uretimekle form;
    form.exec();



}

void MainWindow::on_actionkaydet_triggered()
{
    QString dosyaAdi = QFileDialog::getSaveFileName(this,tr("dosya secin"),
                                                    qApp->applicationDirPath(),tr("fabrika otomasyonu Veri Dosyası(*,movd)"));

    if(dosyaAdi!=""){
        Veritabani::veritabani().kaydet(dosyaAdi);
    }
}
