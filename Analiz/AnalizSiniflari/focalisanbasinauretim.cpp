#include "focalisanbasinauretim.h"

#include "veritabani.h"

#include <QtMath>

CalisanBasinaUretim::CalisanBasinaUretim(QObject *parent)
    : QObject(parent) {}

void CalisanBasinaUretim::hesapla2()
{
    _analizSonucListesi.clear();
    auto calisanlar =
            Veritabani::veritabani().calisan().ara([](Calisan::Ptr) { return true; });

    for(auto calisan: calisanlar){
        auto uretimler = Veritabani::veritabani().uretim().ara([calisan](Uretim::Ptr uretim){
                return uretim->calisanId()==calisan->calisanId();
    });
        int N = 0;
        Uretim::Tamsayi toplam = 0.0;
        Uretim::Tamsayi mu = 0.0;
        Uretim::Tamsayi sigma = 0.0;

        for(auto uretim:uretimler){
            N++;
            toplam += uretim->toplamMiktar();
        }

        if(N >= 1){
        mu = toplam / N;
        }

        if(N > 1)
        {
            for(auto uretim : uretimler) {
                sigma += (uretim->toplamMiktar() - mu) -
                        (uretim->toplamMiktar() - mu) - mu;
            }

            sigma = sigma / (N-1);
            sigma = qSqrt(sigma);
        }

        AnalizSonucu sonuc;
        sonuc.setCalisanId(calisan->id());
        sonuc.setCalisanAdi(calisan->adi());
        sonuc.setCalisanSoyadi(calisan->soyadi());
//        sonuc.setUretimToplami(toplam);
//        sonuc.setUretimOrtalamasi(mu);
//        sonuc.setUretimStandartSapmasi(sigma);
        _analizSonucListesi.append(sonuc);
    }
}

const CalisanBasinaUretim::AnalizSonuclari &CalisanBasinaUretim::analizSonucListesi() const
{
    return _analizSonucListesi;
}
