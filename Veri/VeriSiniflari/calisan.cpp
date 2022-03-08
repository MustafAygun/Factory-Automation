#include "calisan.h"
#include <QtMath>

#include <QFile>
#include<QDataStream>

Calisan::Calisan(QObject *parent) : temelverisinifi(parent)
{
    _calisanId = 0;
    _tckimlik = "";
    _adi = "";
    _soyadi = "";
    _adres= "";
    _sicilno = "";
}

Calisan::Tamsayi Calisan::calisanId() const
{
    return _calisanId;
}

void Calisan::setCalisanId(int calisanId)
{
    if(_calisanId != calisanId){
       _calisanId = calisanId;
       calisanIdDegisti(_calisanId);
    }
}

Calisan::Metin Calisan::tckimlik() const
{
    return _tckimlik;
}

void Calisan::setTckimlik(const Metin &tckimlik)
{
    if(_tckimlik != tckimlik){
         _tckimlik = tckimlik;
         tckimlikDegisti(_tckimlik);
    }
}

Calisan::Metin Calisan::adi() const
{
    return _adi;
}

void Calisan::setAdi(const Metin &adi)
{
    if(_adi != adi){
        _adi = adi;
        adiDegisti(_adi);
    }
}

Calisan::Metin Calisan::soyadi() const
{
    return _soyadi;
}

void Calisan::setSoyadi(const Metin &soyadi)
{
    if(_soyadi != soyadi){
        _soyadi = soyadi;
        soyadiDegisti(_soyadi);
    }
}

Calisan::Metin Calisan::adres() const
{
    return _adres;
}

void Calisan::setAdres(const Metin &adres)
{
    if(_adres != adres){
       _adres = adres;
       adresDegisti(_adres);
    }
}

Calisan::Metin Calisan::sicilno() const
{
    return _sicilno;
}

void Calisan::setSicilno(const Metin &sicilno)
{
    if(_sicilno != sicilno){
         _sicilno = sicilno;
         sicilnoDegisti(_sicilno);
    }
}


