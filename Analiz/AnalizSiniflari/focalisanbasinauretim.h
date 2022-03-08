#ifndef CALISANBASINAURETIM_H
#define CALISANBASINAURETIM_H

#include <QObject>
#include <QVector>

#include "AnalizVerileri/focalisananalizverisi.h"

#include "Analiz_global.h"

class ANALIZ_EXPORT CalisanBasinaUretim : public QObject
{
    Q_OBJECT

public:
    typedef FOCalisanAnalizVerisi AnalizSonucu;
    typedef QVector<AnalizSonucu>AnalizSonuclari;

public:
    explicit CalisanBasinaUretim(QObject *parent = nullptr);

    void hesapla2();

    const AnalizSonuclari &analizSonucListesi() const;

signals:

private:
    AnalizSonuclari _analizSonucListesi;
};

#endif // CALISANBASINAURETIM_H
