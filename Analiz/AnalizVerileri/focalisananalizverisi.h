#ifndef FOCALISANANALIZVERISI_H
#define FOCALISANANALIZVERISI_H

#include <QObject>
#include<Analiz_global.h>

#include <VeriSiniflari/calisan.h>
#include <VeriSiniflari/vardiya.h>

class ANALIZ_EXPORT FOCalisanAnalizVerisi {
public:
    explicit FOCalisanAnalizVerisi();

    Calisan::IdTuru calisanId() const;
    void setCalisanId(const Calisan::IdTuru &calisanId);

    Calisan::Metin calisanAdi() const;
    void setCalisanAdi(const Calisan::Metin &calisanAdi);

    Calisan::Metin calisanSoyadi() const;
    void setCalisanSoyadi(const Calisan::Metin &calisanSoyadi);

    Calisan::IsaretsizTamsayi vardiyaSayisi() const;
    void setVardiyaSayisi(const Calisan::IsaretsizTamsayi &vardiyaSayisi);

    Calisan::TarihSaat vardiyaToplami() const;
    void setVardiyaToplami(const Calisan::TarihSaat &vardiyaToplami);

    Calisan::TarihSaat vardiyaOrtalamasi() const;
    void setVardiyaOrtalamasi(const Calisan::TarihSaat &vardiyaOrtalamasi);

    Calisan::TarihSaat vardiyaStandartSapmasi() const;
    void setVardiyaStandartSapmasi(const Calisan::TarihSaat &vardiyaStandartSapmasi);

signals:

private:
    Calisan::IdTuru _calisanId;
    Calisan::Metin _calisanAdi;
    Calisan::Metin _calisanSoyadi;
    Calisan::IsaretsizTamsayi _vardiyaSayisi;
    Calisan::TarihSaat _vardiyaToplami;
    Calisan::TarihSaat _vardiyaOrtalamasi;
    Calisan::TarihSaat _vardiyaStandartSapmasi;
};

#endif // FOCALISANANALIZVERISI_H
