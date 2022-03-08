#include "focalisanbasinacalismasaatleri.h"

#include "veritabani.h"

#include <QtMath>

FOCalisanBasinaCalismaSaatleri::FOCalisanBasinaCalismaSaatleri(QObject *parent)
    : QObject(parent) {}

void FOCalisanBasinaCalismaSaatleri::hesapla() {
    _analizSonucListesi.clear();
    auto calisanlar =
            Veritabani::veritabani().calisan().ara([](Calisan::Ptr) { return true; });

    for(auto calisan: calisanlar){
        auto vardiyalar = Veritabani::veritabani().vardiya().ara([calisan](Vardiya::Ptr vardiya){
                return vardiya->vardiyaId()==calisan->id();
    });
     int N = 0;
     Vardiya::TarihSaat toplam = QDateTime::currentDateTime();
     Vardiya::TarihSaat mu = QDateTime::currentDateTime();
     Vardiya::TarihSaat sigma = QDateTime::currentDateTime();

     for(auto vardiya:vardiyalar){
         N++;
      //   toplam += vardiya->toplamSure();
     }

     if(N >= 1){
  //   mu = toplam / N;
      }

   //  if(N > 1){
      //   for(auto vardiya : vardiyalar) {
      //   sigma += (vardiya->toplamSure() - mu) * (vardiya->toplamSure() -mu) - mu;
       //  }

      //   sigma = sigma / (N-1);
    //     sigma = qSqrt(sigma);
    // }

     AnalizSonucu sonuc;
     sonuc.setCalisanId(calisan->id());
     sonuc.setCalisanAdi(calisan->adi());
     sonuc.setCalisanSoyadi(calisan->soyadi());
     sonuc.setVardiyaToplami(toplam);
     sonuc.setVardiyaOrtalamasi(mu);
     sonuc.setVardiyaStandartSapmasi(sigma);
     _analizSonucListesi.append(sonuc);
    }
}

const FOCalisanBasinaCalismaSaatleri::AnalizSonuclari &
FOCalisanBasinaCalismaSaatleri::analizSonucListesi() const
{
    return _analizSonucListesi;
}
