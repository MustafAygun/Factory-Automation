#ifndef URUN_H
#define URUN_H

#include <memory>
#include<Veri_global.h>
#include "temelverisinifi.h"

using namespace std;

#include <QObject>

class VERI_EXPORT Urun : public temelverisinifi
{
    Q_OBJECT

public:
    typedef Urun veri;
    typedef shared_ptr<veri> Ptr;

public:
    explicit Urun(QObject *parent = nullptr);

    Metin urunAdi() const;
    void setUrunAdi(const Metin &urunAdi);

    static Ptr yeni() { return std::make_shared<veri>();}

    Ptr kopyala()
    {
        auto kopya = yeni();

        kopya->_id = this->_id;
        kopya->_urunAdi = this->_urunAdi;

        return kopya;
    }

    Tamsayi toplamUrun() const;
    void setToplamUrun(const Tamsayi &toplamUrun);

signals:
    void urunAdiDegisti(const Metin &urunAdi);

private:
    Metin _urunAdi;
    Tamsayi _toplamUrun = 0;
};

#endif // URUN_H
