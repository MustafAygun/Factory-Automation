#include "calisanveriyoneticisi.h"

CalisanVeriYoneticisi::CalisanVeriYoneticisi(QObject *parent) : QObject(parent)
{

}

QDataStream &operator <<(QDataStream &dosya, const Calisan::Ptr &calisan)
{
    dosya<< calisan->adi()<<calisan->soyadi()
         <<calisan->id()<<calisan->tckimlik()
        <<calisan->sicilno()<<calisan->adres();
return dosya;
}

QDataStream &operator >>(QDataStream &dosya, Calisan::Ptr &calisan)
{
    Calisan::Metin adi,soyadi,tcKimlik,sicil,adres;
    Calisan::Tamsayi id;
    dosya>> adi >> soyadi>>id>>tcKimlik>>sicil>>adres;
            auto yenicalisan=Calisan::yeni();
            yenicalisan->setAdi(adi);
            yenicalisan->setSoyadi(soyadi);
            yenicalisan->setId(id);
            yenicalisan->setTckimlik(tcKimlik);
            yenicalisan->setSicilno(sicil);
            yenicalisan->setAdres(adres);
            calisan=yenicalisan;

    return dosya;
}
