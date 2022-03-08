#include "fourunistatistikleri.h"

#include "veritabani.h"

#include <QtMath>

UrunIstatistikleri::UrunIstatistikleri(QObject *parent) : QObject(parent)
{

}

void UrunIstatistikleri::hesapla3()
{
    _analizSonucListesi.clear();
    auto urunler =
            Veritabani::veritabani().urun().ara([](Urun::Ptr) { return true; });

    for(auto urun: urunler){
        auto uretim = Veritabani::veritabani().uretim().ara([urun](Uretim::Ptr uretim){
                return uretim->urunId()==urun->id();
    });
        int N = 0;
        Uretim::Tamsayi toplam = 0;
        Uretim::Tamsayi mu = 0;
        Uretim::Tamsayi sigma = 0;

        for(auto uretim:uretim){
            N++;
            toplam += uretim->miktar();
        }

        if(N >= 1){
            mu = toplam / N;
        }

        if(N > 1){
            for(auto uretim : uretim) {
                sigma += (uretim->miktar() - mu) *
                        (uretim->miktar() - mu) - mu;
            }

            sigma = sigma / (N-1);
            sigma = qSqrt(sigma);
        }

        AnalizSonucu sonuc;
        sonuc.setUrunId(urun->id());
        sonuc.setUrunAdi(urun->urunAdi());
        sonuc.setUrunToplami(toplam);
        sonuc.setUrunOrtalamasi(mu);
        sonuc.setUrunStandartSapmasi(sigma);
    };
}

const UrunIstatistikleri::AnalizSonuclari &
UrunIstatistikleri::analizSonucListesi() const
{
    return _analizSonucListesi;
}
