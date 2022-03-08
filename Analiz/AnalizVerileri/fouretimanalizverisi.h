#ifndef FOURETIMANALIZVERISI_H
#define FOURETIMANALIZVERISI_H

#include <QObject>
#include <Analiz_global.h>
#include <VeriSiniflari/uretim.h>

class ANALIZ_EXPORT FOUretimAnalizVerisi {
   public:
    explicit FOUretimAnalizVerisi();

    Uretim::Tamsayi uretimId() const;
    void setUretimId(const Uretim::Tamsayi &uretimId);

    Uretim::Tamsayi vardiyaId() const;
    void setVardiyaId(const Uretim::Tamsayi &vardiyaId);

    Uretim::Tamsayi calisanId() const;
    void setCalisanId(const Uretim::Tamsayi &calisanId);

    Uretim::Tamsayi urunId() const;
    void setUrunId(const Uretim::Tamsayi &urunId);

    Uretim::Tamsayi miktar() const;
    void setMiktar(const Uretim::Tamsayi &miktar);

    Uretim::Tamsayi uretimToplami() const;
    void setUretimToplami(const Uretim::Tamsayi &uretimToplami);

    Uretim::Tamsayi uretimOrtalamasi() const;
    void setUretimOrtalamasi(const Uretim::Tamsayi &uretimOrtalamasi);

    Uretim::Tamsayi uretimStandartSapmasi() const;
    void setUretimStandartSapmasi(const Uretim::Tamsayi &uretimStandartSapmasi);

signals:

private:
    Uretim::Tamsayi _uretimId;
    Uretim::Tamsayi _vardiyaId;
    Uretim::Tamsayi _calisanId;
    Uretim::Tamsayi _urunId;
    Uretim::Tamsayi _miktar;
    Uretim::Tamsayi _uretimToplami;
    Uretim::Tamsayi _uretimOrtalamasi;
    Uretim::Tamsayi _uretimStandartSapmasi;
};

#endif // FOURETIMANALIZVERISI_H
