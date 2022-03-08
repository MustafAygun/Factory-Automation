#include "veritabani.h"
#include <QFile>
#include<QDataStream>
Veritabani::Veritabani(QObject *parent) : QObject(parent)
{

}

Veritabani &Veritabani::veritabani()
{
    static Veritabani nesne;
    return nesne;
}

CalisanVeriYoneticisi &Veritabani::calisan() { return _calisan; }

UretimVeriYoneticisi &Veritabani::uretim() { return _uretim; }

UrunVeriYoneticisi &Veritabani::urun() { return _urun; }

VardiyaVeriYoneticisi &Veritabani::vardiya() { return _vardiya; }

void Veritabani::kaydet(QString dosyaAdi)
{
    QFile dosya(dosyaAdi);
    if(dosya.open(QIODevice::WriteOnly)){
        QDataStream ds(&dosya);
        _calisan.kaydet(ds);
        dosya.close();
    }
}

void Veritabani::yukle(QString dosyaAdi)
{
    QFile dosya(dosyaAdi);
    if(dosya.open(QIODevice::ReadOnly)){
        QDataStream ds(&dosya);
        _calisan.yukle(ds);
        dosya.close();
    }
}
