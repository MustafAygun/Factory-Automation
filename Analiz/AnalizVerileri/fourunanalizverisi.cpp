#include "fourunanalizverisi.h"

FOUrunAnalizVerisi::FOUrunAnalizVerisi(){}

Urun::IdTuru FOUrunAnalizVerisi::urunId() const
{
    return _urunId;
}

void FOUrunAnalizVerisi::setUrunId(const Urun::IdTuru &urunId)
{
    _urunId = urunId;
}

Urun::Metin FOUrunAnalizVerisi::urunAdi() const
{
    return _urunAdi;
}

void FOUrunAnalizVerisi::setUrunAdi(const Urun::Metin &urunAdi)
{
    _urunAdi = urunAdi;
}

Urun::Tamsayi FOUrunAnalizVerisi::urunSayisi() const
{
    return _urunSayisi;
}

void FOUrunAnalizVerisi::setUrunSayisi(const Urun::Tamsayi &urunSayisi)
{
    _urunSayisi = urunSayisi;
}

Urun::Tamsayi FOUrunAnalizVerisi::urunToplami() const
{
    return _urunToplami;
}

void FOUrunAnalizVerisi::setUrunToplami(const Urun::Tamsayi &urunToplami)
{
    _urunToplami = urunToplami;
}

Urun::Tamsayi FOUrunAnalizVerisi::urunOrtalamasi() const
{
    return _urunOrtalamasi;
}

void FOUrunAnalizVerisi::setUrunOrtalamasi(const Urun::Tamsayi &urunOrtalamasi)
{
    _urunOrtalamasi = urunOrtalamasi;
}

Urun::Tamsayi FOUrunAnalizVerisi::urunStandartSapmasi() const
{
    return _urunStandartSapmasi;
}

void FOUrunAnalizVerisi::setUrunStandartSapmasi(const Urun::Tamsayi &urunStandartSapmasi)
{
    _urunStandartSapmasi = urunStandartSapmasi;
}
