#include "uretim.h"
#include <QtMath>

#include <QFile>
#include<QDataStream>

Uretim::Uretim(QObject *parent) : temelverisinifi(parent)
{
    _uretimId = 0;
    _vardiyaId = 0;
    _calisanId = 0;
    _urunId = 0;
    _miktar = 0;
}

Uretim::Tamsayi Uretim::uretimId() const
{
    return _uretimId;
}

void Uretim::setUretimId(Tamsayi uretimId)
{
    if(_uretimId != uretimId){
        _uretimId = uretimId;
        uretimIdDegisti(this->_uretimId);
    }
}

Uretim::Tamsayi Uretim::vardiyaId() const
{
    return _vardiyaId;
}

void Uretim::setVardiyaId(Tamsayi vardiyaId)
{
    if(_vardiyaId != vardiyaId){
        _vardiyaId = vardiyaId;
        vardiyaIdDegisti(this->_vardiyaId);
    }

}

Uretim::Tamsayi Uretim::calisanId() const
{
    return _calisanId;
}

void Uretim::setCalisanId(Tamsayi calisanId)
{
    if(_calisanId != calisanId){
        _calisanId = calisanId;
        calisanIdDegisti(this->_calisanId);
    }
}

Uretim::Tamsayi Uretim::urunId() const
{
    return _urunId;
}

void Uretim::setUrunId(Tamsayi urunId)
{
    if(_urunId != urunId){
        _urunId = urunId;
        urunIdDegisti(this->_urunId);
    }
}

Uretim::Tamsayi Uretim::miktar() const
{
    return _miktar;
}

void Uretim::setMiktar(Tamsayi miktar)
{
    if(_miktar != miktar){
        _miktar = miktar;
        miktarDegisti(this->_miktar);
    }
}
int Uretim::toplamMiktar() const
{
    return _toplamMiktar;
}

void Uretim::setToplamMiktar(const Tamsayi &toplamMiktar)
{
    _toplamMiktar = toplamMiktar;
}



