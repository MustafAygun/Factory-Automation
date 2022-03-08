#ifndef VARDIYAVERIYONETICISI_H
#define VARDIYAVERIYONETICISI_H

#include <QObject>

#include "temelveriyonetimsinifi.h"
#include <VeriSiniflari/vardiya.h>


#include<Veri_global.h>

class VERI_EXPORT VardiyaVeriYoneticisi : public QObject,
        public TemelVeriYonetimSinifi<Vardiya>
{
    Q_OBJECT
public:
    explicit VardiyaVeriYoneticisi(QObject *parent = nullptr);

signals:
    void elemanEklendi(Pointer ptr);
    void elemanSilindi(Pointer ptr);
    void elemanDegisti(Pointer eski, Pointer yeni);
};

#endif // VARDIYAVERIYONETICISI_H
