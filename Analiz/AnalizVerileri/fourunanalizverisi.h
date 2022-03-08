#ifndef FOURUNANALIZVERISI_H
#define FOURUNANALIZVERISI_H

#include <QObject>
#include<QVector>

#include<Analiz_global.h>

#include <VeriSiniflari/urun.h>

class ANALIZ_EXPORT  FOUrunAnalizVerisi {
public:
    explicit FOUrunAnalizVerisi();

    Urun::IdTuru urunId() const;
    void setUrunId(const Urun::IdTuru &urunId);

    Urun::Metin urunAdi() const;
    void setUrunAdi(const Urun::Metin &urunAdi);

    Urun::Tamsayi urunSayisi() const;
    void setUrunSayisi(const Urun::Tamsayi &urunSayisi);

    Urun::Tamsayi urunToplami() const;
    void setUrunToplami(const Urun::Tamsayi &urunToplami);

    Urun::Tamsayi urunOrtalamasi() const;
    void setUrunOrtalamasi(const Urun::Tamsayi &urunOrtalamasi);

    Urun::Tamsayi urunStandartSapmasi() const;
    void setUrunStandartSapmasi(const Urun::Tamsayi &urunStandartSapmasi);

signals:

private:
    Urun::IdTuru _urunId;
    Urun::Metin _urunAdi;
    Urun::Tamsayi _urunSayisi;
    Urun::Tamsayi _urunToplami;
    Urun::Tamsayi _urunOrtalamasi;
    Urun::Tamsayi _urunStandartSapmasi;
};

#endif // FOURUNANALIZVERISI_H
