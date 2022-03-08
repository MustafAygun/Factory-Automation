#include "vardiya.h"
#include <QtMath>
#include <QFile>
#include<QDataStream>
#include <memory>

Vardiya::Vardiya(QObject *parent) : temelverisinifi(parent)
{
    //bos  tarih degerleri atanacak
     _vardiyaId =0;
     _vardiyaBaslangic = QDateTime::currentDateTime();
     _vardiyaBitis = QDateTime::currentDateTime();
}
Vardiya::Tamsayi Vardiya::vardiyaId() const
{
    return _vardiyaId;
}

void Vardiya::setVardiyaId(Tamsayi vardiyaid){
    if(_vardiyaId != vardiyaId()){
        _vardiyaId= vardiyaId();
        vardiyaIdDegisti(_vardiyaId);
    }
}

Vardiya::TarihSaat Vardiya::vardiyaBaslangic() const
{
    return _vardiyaBaslangic;
}

void Vardiya::setVardiyaBaslangic(const TarihSaat &vardiyaBaslangic)
{
    if(_vardiyaBaslangic !=vardiyaBaslangic){
        _vardiyaBaslangic=vardiyaBaslangic;
        vardiyaBaslangicDegisti(_vardiyaBaslangic);
    }
}
Vardiya::TarihSaat Vardiya::vardiyaBitis() const
{
    return _vardiyaBitis;
}

Vardiya::TarihSaat Vardiya::toplamSure() const
{
    return _toplamSure;
}

void Vardiya::setToplamSure(const TarihSaat &toplamSure)
{
    _toplamSure = toplamSure;
}

