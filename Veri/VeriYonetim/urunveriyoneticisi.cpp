#include "urunveriyoneticisi.h"

UrunVeriYoneticisi::UrunVeriYoneticisi(QObject *parent) : QObject(parent)
{

}

QDataStream &operator<<(QDataStream &dosya, Urun::Ptr &urun)
{
    dosya<<urun->urunAdi()<<urun->id()<<urun->toplamUrun();
    return dosya;
}

QDataStream &operator>>(QDataStream &dosya, const Urun::Ptr &urun)
{
    Urun::Tamsayi urunid,toplamurun;
    Urun::Metin adi;
    dosya >>adi>>urunid>>toplamurun;
    auto yeniurun=urun->yeni();
    yeniurun->setUrunAdi(adi);
    yeniurun->setId(urunid);
    yeniurun->setToplamUrun(toplamurun);
    yeniurun=urun;
    return dosya;
}
