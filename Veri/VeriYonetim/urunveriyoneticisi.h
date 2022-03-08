#ifndef URUNVERIYONETICISI_H
#define URUNVERIYONETICISI_H
#include<QDataStream>
#include <QObject>

#include "temelveriyonetimsinifi.h"
#include <VeriSiniflari/urun.h>


#include<Veri_global.h>

class VERI_EXPORT UrunVeriYoneticisi : public QObject,
        public TemelVeriYonetimSinifi<Urun>
{
    Q_OBJECT
public:
    explicit UrunVeriYoneticisi(QObject *parent = nullptr);

signals:
    void elemanEklendi(Pointer ptr);
    void elemanSilindi(Pointer ptr);
    void elemanDegisti(Pointer eski, Pointer yeni);
};
    QDataStream &operator<<(QDataStream &dosya,Urun::Ptr &urun);
    QDataStream &operator>>(QDataStream &dosya,const Urun::Ptr &urun);
#endif // URUNVERIYONETICISI_H
