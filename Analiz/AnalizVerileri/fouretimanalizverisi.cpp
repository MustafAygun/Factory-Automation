#include "fouretimanalizverisi.h"

FOUretimAnalizVerisi::FOUretimAnalizVerisi(){}

Uretim::Tamsayi FOUretimAnalizVerisi::uretimId() const
{
    return _uretimId;
}

void FOUretimAnalizVerisi::setUretimId(const Uretim::Tamsayi &uretimId)
{
    _uretimId = uretimId;
}

Uretim::Tamsayi FOUretimAnalizVerisi::vardiyaId() const
{
    return _vardiyaId;
}

void FOUretimAnalizVerisi::setVardiyaId(const Uretim::Tamsayi &vardiyaId)
{
    _vardiyaId = vardiyaId;
}

Uretim::Tamsayi FOUretimAnalizVerisi::calisanId() const
{
    return _calisanId;
}

void FOUretimAnalizVerisi::setCalisanId(const Uretim::Tamsayi &calisanId)
{
    _calisanId = calisanId;
}

Uretim::Tamsayi FOUretimAnalizVerisi::urunId() const
{
    return _urunId;
}

void FOUretimAnalizVerisi::setUrunId(const Uretim::Tamsayi &urunId)
{
    _urunId = urunId;
}

Uretim::Tamsayi FOUretimAnalizVerisi::miktar() const
{
    return _miktar;
}

void FOUretimAnalizVerisi::setMiktar(const Uretim::Tamsayi &miktar)
{
    _miktar = miktar;
}

Uretim::Tamsayi FOUretimAnalizVerisi::uretimToplami() const
{
    return _uretimToplami;
}

void FOUretimAnalizVerisi::setUretimToplami(const Uretim::Tamsayi &uretimToplami)
{
    _uretimToplami = uretimToplami;
}

Uretim::Tamsayi FOUretimAnalizVerisi::uretimOrtalamasi() const
{
    return _uretimOrtalamasi;
}

void FOUretimAnalizVerisi::setUretimOrtalamasi(const Uretim::Tamsayi &uretimOrtalamasi)
{
    _uretimOrtalamasi = uretimOrtalamasi;
}

Uretim::Tamsayi FOUretimAnalizVerisi::uretimStandartSapmasi() const
{
    return _uretimStandartSapmasi;
}

void FOUretimAnalizVerisi::setUretimStandartSapmasi(const Uretim::Tamsayi &uretimStandartSapmasi)
{
    _uretimStandartSapmasi = uretimStandartSapmasi;
}
