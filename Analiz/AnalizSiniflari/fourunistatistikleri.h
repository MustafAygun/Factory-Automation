#ifndef URUNISTATISTIKLERI_H
#define URUNISTATISTIKLERI_H

#include <QObject>
#include <QVector>

#include "AnalizVerileri/fourunanalizverisi.h"

#include "Analiz_global.h"

class ANALIZ_EXPORT UrunIstatistikleri : public QObject
{
    Q_OBJECT

public:
    typedef FOUrunAnalizVerisi AnalizSonucu;
    typedef QVector<AnalizSonucu> AnalizSonuclari;

public:
    explicit UrunIstatistikleri(QObject *parent = nullptr);

    void hesapla3();

    const AnalizSonuclari &analizSonucListesi() const;

signals:

private:
    AnalizSonuclari _analizSonucListesi;
};

#endif // URUNISTATISTIKLERI_H
