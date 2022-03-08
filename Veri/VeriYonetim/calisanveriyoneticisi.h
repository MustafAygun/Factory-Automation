#ifndef CALISANVERIYONETICISI_H
#define CALISANVERIYONETICISI_H

#include <QObject>
#include<QDataStream>
#include "temelveriyonetimsinifi.h"
#include <VeriSiniflari/calisan.h>

#include<Veri_global.h>

class VERI_EXPORT CalisanVeriYoneticisi : public QObject,
        public TemelVeriYonetimSinifi<Calisan>
{
    Q_OBJECT
public:
    explicit CalisanVeriYoneticisi(QObject *parent = nullptr);

signals:
    void elemanEklendi(Pointer ptr);
    void elemanSilindi(Pointer ptr);
    void elemanDegisti(Pointer eski, Pointer yeni);
};
QDataStream & operator <<(QDataStream &dosya,const Calisan::Ptr &calisan);
QDataStream & operator >>(QDataStream &dosya, Calisan::Ptr &calisan);


#endif // CALISANVERIYONETICISI_H
