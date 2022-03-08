#include "urun.h"

#include <QtMath>

#include <QFile>
#include<QDataStream>

Urun::Urun(QObject *parent) : temelverisinifi(parent){
       _urunAdi="";
}
Urun::Metin Urun::urunAdi() const
{
    return _urunAdi;
}

void Urun::setUrunAdi(const Metin &urunAdi)
{
    if(_urunAdi != urunAdi){
        _urunAdi = urunAdi;
        urunAdiDegisti(_urunAdi);
    }

}

Urun::Tamsayi Urun::toplamUrun() const
{
    return _toplamUrun;
}

void Urun::setToplamUrun(const Tamsayi &toplamUrun)
{
    _toplamUrun = toplamUrun;
}


