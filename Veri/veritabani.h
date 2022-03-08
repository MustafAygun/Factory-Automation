#ifndef VERITABANI_H
#define VERITABANI_H

#include <QObject>

#include <VeriYonetim/calisanveriyoneticisi.h>
#include <VeriYonetim/uretimveriyoneticisi.h>
#include <VeriYonetim/urunveriyoneticisi.h>
#include <VeriYonetim/vardiyaveriyoneticisi.h>
#include <Veri_global.h>

class VERI_EXPORT Veritabani : public QObject
{
    Q_OBJECT
private:
    explicit Veritabani(QObject *parent = nullptr);

public:
    static Veritabani &veritabani();

    CalisanVeriYoneticisi &calisan();

    UretimVeriYoneticisi &uretim();

    UrunVeriYoneticisi &urun();

    VardiyaVeriYoneticisi &vardiya();
    void kaydet(QString dosyaAdi);
    void yukle (QString dosyaAdi);

private:
    CalisanVeriYoneticisi _calisan;
    UretimVeriYoneticisi _uretim;
    UrunVeriYoneticisi _urun;
    VardiyaVeriYoneticisi _vardiya;
signals:
};

#endif // VERITABANI_H
