#ifndef VARDIYA_H
#define VARDIYA_H

#include <memory>
#include<Veri_global.h>
#include "temelverisinifi.h"

using namespace std;

#include <QObject>


class VERI_EXPORT Vardiya : public temelverisinifi
{
    Q_OBJECT

public:
    typedef Vardiya veri;
    typedef shared_ptr<veri> Ptr;

public:
    explicit Vardiya(QObject *parent = nullptr);

    Tamsayi vardiyaId() const;
    void setVardiyaId(Tamsayi vardiyaid);

    TarihSaat vardiyaBaslangic() const;
    void setVardiyaBaslangic(const TarihSaat &vardiyaBaslangic);

    TarihSaat vardiyaBitis() const;
    void setVardiyaBitis(const TarihSaat &vardiyaBitis);

    static Ptr yeni() { return std::make_shared<veri>();}

    void ata(Ptr kaynak)
    {
        this->_vardiyaId = kaynak->_vardiyaId;
        this->_vardiyaBaslangic = kaynak->_vardiyaBaslangic;
        this->_vardiyaBitis = kaynak->_vardiyaBitis;
    }



    Ptr kopyala()
    {
        auto kopya = yeni();

        kopya->_vardiyaId = this->_vardiyaId;
        kopya->_vardiyaBaslangic = this->_vardiyaBaslangic;
        kopya->_vardiyaBitis = this->_vardiyaBitis;

        return  kopya;
    }

    TarihSaat toplamSure() const;
    void setToplamSure(const TarihSaat &toplamSure);

signals:
    void vardiyaIdDegisti(int vardiyaId);
    void vardiyaBaslangicDegisti(const TarihSaat &vardiyaBaslangic);
    void vardiyaBitisDegisti(const TarihSaat &vardiyaBitis);

private:
    Tamsayi _vardiyaId;
    TarihSaat _vardiyaBaslangic;
    TarihSaat _vardiyaBitis;
    TarihSaat _toplamSure = QDateTime::currentDateTime();
};

#endif // VARDIYA_H
