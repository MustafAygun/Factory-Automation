#ifndef FOCALISANBASINACALISMASAATLERI_H
#define FOCALISANBASINACALISMASAATLERI_H

#include <QObject>
#include <QVector>

#include "AnalizVerileri/focalisananalizverisi.h"

#include "Analiz_global.h"

class ANALIZ_EXPORT FOCalisanBasinaCalismaSaatleri : public QObject
{
    Q_OBJECT

public:
    typedef FOCalisanAnalizVerisi AnalizSonucu;
    typedef QVector<AnalizSonucu> AnalizSonuclari;

public:
    explicit FOCalisanBasinaCalismaSaatleri(QObject *parent = nullptr);

    void hesapla();

    const AnalizSonuclari &analizSonucListesi() const;

signals:

private:
    AnalizSonuclari _analizSonucListesi;
};

#endif // FOCALISANBASINACALISMASAATLERI_H
