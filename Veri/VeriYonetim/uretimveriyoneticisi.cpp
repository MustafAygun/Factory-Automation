#include "uretimveriyoneticisi.h"

UretimVeriYoneticisi::UretimVeriYoneticisi(QObject *parent) : QObject(parent)
{

}


QDataStream &operator<<(QDataStream &dosya, const Uretim::Ptr uretim)
{
 dosya <<uretim->uretimId()<<uretim->urunId()
      <<uretim->calisanId()<<uretim->vardiyaId()
     <<uretim->miktar()<<uretim->toplamMiktar();
 return dosya;
}

QDataStream &operator>>(QDataStream &dosya, Uretim::Ptr &uretim)
{

   Uretim::Tamsayi uretimid,uruniD,calisanid,vardiyaid,miktar,toplammiktar;
   dosya>> uretimid>>uruniD>>calisanid>>vardiyaid>>miktar>>toplammiktar;
   auto yeniuretim=Uretim::yeni();
    yeniuretim->setUrunId(uruniD);
    yeniuretim->setUretimId(uretimid);
    yeniuretim->setCalisanId(calisanid);
    yeniuretim->setVardiyaId(vardiyaid);
    yeniuretim->setMiktar(miktar);
    yeniuretim->setToplamMiktar(toplammiktar);

    uretim=yeniuretim;
    return dosya;
}
