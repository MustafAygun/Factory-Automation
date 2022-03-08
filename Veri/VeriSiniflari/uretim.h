#ifndef URETIM_H
#define URETIM_H

#include <QObject>
#include <memory>
#include <Veri_global.h>
#include "temelverisinifi.h"

using namespace std;

class VERI_EXPORT Uretim : public temelverisinifi
{
    Q_OBJECT

public:
    typedef Uretim veri;
    typedef shared_ptr<veri> Ptr;

public:
    explicit Uretim(QObject *parent = nullptr);

    Tamsayi uretimId() const;
    void setUretimId(Tamsayi uretimId);

    Tamsayi vardiyaId() const;
    void setVardiyaId(Tamsayi vardiyaId);

    Tamsayi calisanId() const;
    void setCalisanId(Tamsayi calisanId);

    Tamsayi urunId() const;
    void setUrunId(Tamsayi urunId);

    Tamsayi miktar() const;
    void setMiktar(Tamsayi miktar);

    static Ptr yeni() { return std::make_shared<veri>(); }

    void ata(Ptr kaynak)
    {
        this->_uretimId = kaynak->_uretimId;
        this->_vardiyaId = kaynak->_vardiyaId;
        this->_calisanId = kaynak->_calisanId;
        this->_urunId = kaynak->_urunId;
        this->_miktar = kaynak->_miktar;
    }

    Ptr kopyala()
    {
        auto kopya =yeni();

        kopya->_uretimId = this->_uretimId;
        kopya->_vardiyaId = this->_vardiyaId;
        kopya->_calisanId = this->_calisanId;
        kopya->_urunId = this->_urunId;
        kopya->_miktar = this->_miktar;

        return kopya;
    }

    Tamsayi toplamMiktar() const;
    void setToplamMiktar(const Tamsayi &toplamMiktar);

signals:
    void uretimIdDegisti(Tamsayi uretimId);
    void vardiyaIdDegisti(Tamsayi vardiyaId);
    void calisanIdDegisti(Tamsayi calisanId);
    void urunIdDegisti(Tamsayi urunId);
    void miktarDegisti(Tamsayi miktar);

private:
    Tamsayi _uretimId;
    Tamsayi _vardiyaId;
    Tamsayi _calisanId;
    Tamsayi _urunId;
    Tamsayi _miktar;
    Tamsayi _toplamMiktar = 0;
};

#endif // URETIM_H
