#ifndef CALISAN_H
#define CALISAN_H

#include <QObject>
#include <Veri_global.h>
#include <memory>
#include <QFile>

#include "temelverisinifi.h"
#include<Veri_global.h>

using namespace std;

class VERI_EXPORT Calisan : public temelverisinifi
{
    Q_OBJECT
public:
    typedef Calisan veri;
    typedef shared_ptr<veri> Ptr;

public:
    explicit Calisan(QObject *parent = nullptr);

    Tamsayi calisanId() const;
    void setCalisanId(Tamsayi calisanId);

    Metin tckimlik() const;
    void setTckimlik(const Metin &tckimlik);

    Metin adi() const;
    void setAdi(const Metin &adi);

    Metin soyadi() const;
    void setSoyadi(const Metin &soyadi);

    Metin adres() const;
    void setAdres(const Metin &adres);

    Metin sicilno() const;
    void setSicilno(const Metin &sicilno);

    static Ptr yeni() {return std::make_shared<veri>(); };

    void ata(Ptr kaynak)
    {
        this->_calisanId = kaynak->_calisanId;
        this->_tckimlik = kaynak->_tckimlik;
        this->_adi = kaynak->_adi;
        this->_soyadi = kaynak->_soyadi;
        this->_adres = kaynak->_adres;
        this->_sicilno = kaynak->_sicilno;
    }

    Ptr kopyala()
    {
        auto kopya = yeni();

        kopya->_calisanId = this->_calisanId;
        kopya->_tckimlik = this->_tckimlik;
        kopya->_adi = this->_adi;
        kopya->_soyadi = this->_soyadi;
        kopya->_adres = this->_adres;
        kopya->_sicilno = this->_sicilno;

        return  kopya;
    }

signals:
    void calisanIdDegisti(Tamsayi calisanId);
    void tckimlikDegisti(Metin tckimlik);
    void adiDegisti(Metin adi);
    void soyadiDegisti(Metin soyadi);
    void adresDegisti(Metin adres);
    void sicilnoDegisti(Metin sicilno);

private:
    Tamsayi _calisanId;
    Metin _tckimlik;
    Metin _adi;
    Metin _soyadi;
    Metin _adres;
    Metin _sicilno;
};

#endif // CALISAN_H
