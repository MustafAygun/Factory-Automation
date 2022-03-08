#include "focalisananalizverisi.h"

FOCalisanAnalizVerisi::FOCalisanAnalizVerisi(){}

Calisan::IdTuru FOCalisanAnalizVerisi::calisanId() const
{
    return _calisanId;
}

void FOCalisanAnalizVerisi::setCalisanId(const Calisan::IdTuru &calisanId)
{
    _calisanId = calisanId;
}

Calisan::Metin FOCalisanAnalizVerisi::calisanAdi() const
{
    return _calisanAdi;
}

void FOCalisanAnalizVerisi::setCalisanAdi(const Calisan::Metin &calisanAdi)
{
    _calisanAdi = calisanAdi;
}

Calisan::Metin FOCalisanAnalizVerisi::calisanSoyadi() const
{
    return _calisanSoyadi;
}

void FOCalisanAnalizVerisi::setCalisanSoyadi(const Calisan::Metin &calisanSoyadi)
{
    _calisanSoyadi = calisanSoyadi;
}

Calisan::IsaretsizTamsayi FOCalisanAnalizVerisi::vardiyaSayisi() const
{
    return _vardiyaSayisi;
}

void FOCalisanAnalizVerisi::setVardiyaSayisi(const Calisan::IsaretsizTamsayi &vardiyaSayisi)
{
    _vardiyaSayisi = vardiyaSayisi;
}

Calisan::TarihSaat FOCalisanAnalizVerisi::vardiyaToplami() const
{
    return _vardiyaToplami;
}

void FOCalisanAnalizVerisi::setVardiyaToplami(const Calisan::TarihSaat &vardiyaToplami)
{
    _vardiyaToplami = vardiyaToplami;
}

Calisan::TarihSaat FOCalisanAnalizVerisi::vardiyaOrtalamasi() const
{
    return _vardiyaOrtalamasi;
}

void FOCalisanAnalizVerisi::setVardiyaOrtalamasi(const Calisan::TarihSaat &vardiyaOrtalamasi)
{
    _vardiyaOrtalamasi = vardiyaOrtalamasi;
}

Calisan::TarihSaat FOCalisanAnalizVerisi::vardiyaStandartSapmasi() const
{
    return _vardiyaStandartSapmasi;
}

void FOCalisanAnalizVerisi::setVardiyaStandartSapmasi(const Calisan::TarihSaat &vardiyaStandartSapmasi)
{
    _vardiyaStandartSapmasi = vardiyaStandartSapmasi;
}
