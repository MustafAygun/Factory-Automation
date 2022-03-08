#ifndef URETIMVERIYONETICISI_H
#define URETIMVERIYONETICISI_H
#include <QObject>
#include<QDataStream>
#include "temelveriyonetimsinifi.h"
#include <VeriSiniflari/uretim.h>
#include<Veri_global.h>

class VERI_EXPORT UretimVeriYoneticisi : public QObject,
        public TemelVeriYonetimSinifi<Uretim>
{
    Q_OBJECT
public:
    explicit UretimVeriYoneticisi(QObject *parent = nullptr);

signals:
    void elemanEklendi(Pointer ptr);
    void elemanSilindi(Pointer ptr);
    void elemanDegisti(Pointer eski, Pointer yeni);

};
QDataStream &operator<<(QDataStream &dosya,const Uretim::Ptr uretim);
QDataStream &operator>>(QDataStream &dosya, Uretim::Ptr uretim);

#endif // URETIMVERIYONETICISI_H
