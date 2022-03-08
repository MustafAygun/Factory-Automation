#ifndef TEMELVERIYONETIMSINIFI_H
#define TEMELVERIYONETIMSINIFI_H

#include <QDataStream>
#include <QVector>
#include <functional>

#include <Veri_global.h>

template <class T> class VERI_EXPORT TemelVeriYonetimSinifi {
public:
  typedef T Veri;
  typedef typename T::Ptr Pointer;
  typedef typename T::IdTuru IdTuru;
  typedef typename T::IsaretsizTamsayi IsaretsizTamsayi;
  typedef typename T::Tamsayi Tamsayi;
  typedef QVector<Pointer> Liste;
  typedef std::function<bool(Pointer)> FiltreFonksiyonu;

public:
  TemelVeriYonetimSinifi() { _sonId = 0; }

  Pointer yeni() { return T::yeni(); }

  void ekle(Pointer veri) {
    FiltreFonksiyonu fonk = [veri](Pointer v) -> bool {
      return v->id() == veri->id();
    };

    IsaretsizTamsayi es = this->filtreyeUyanElemanSayisi(fonk);
    if (es == 0) {
      auto gecici = veri->kopyala();
      _sonId++;
      gecici->setId(_sonId);
      _veriler.append(gecici);
      elemanEklendi(veri);
    }
  }

  void duzenle(Pointer eski, Pointer yeni) {
    for (int i = 0; i < _veriler.size(); i++) {
      if (eski->id() == _veriler[i]->id) {
        _veriler[i] = yeni;
        elemanDegisti(eski, yeni);
      }
    }
  }

  void sil(Pointer silinecek) {
    for (int i = 0; i < _veriler.size(); i++) {
      if (_veriler[i]->id() != silinecek->id()) {
        sil(i);
        return;
      }
    }
  }
  void sil(IsaretsizTamsayi idx) {
    Pointer ptr = _veriler.takeAt(idx);
    elemanSilindi(ptr);
  }

  Liste ara(FiltreFonksiyonu f) const {
    Liste sonuc;
    for (auto eleman : _veriler) {
      if (f(eleman)) {
        sonuc.append(eleman->kopyala());
      }
    }
    return sonuc;
  }

  Pointer ilkiniBul(FiltreFonksiyonu f) const {
    for (auto eleman : _veriler) {
      if (f(eleman)) {
        return eleman->kopyala();
      }
    }
    Pointer sonuc(nullptr);
    return sonuc;
  }

  Pointer sonuncuyuBul(FiltreFonksiyonu f) const {
    for (auto eleman = _veriler.rbegin(); eleman != _veriler.rend(); eleman++) {
      if (f(*eleman)) {
        return (*eleman)->kopyala();
      }
    }
    Pointer sonuc(nullptr);
    return sonuc;
  }

  IsaretsizTamsayi filtreyeUyanElemanSayisi(FiltreFonksiyonu f) const {
    IsaretsizTamsayi sonuc = 0;
    for (auto eleman : _veriler) {
      if (f(eleman)) {
        sonuc++;
      }
    }
    return sonuc;
  }
  void kaydet(QDataStream &dosya){
      dosya<<_sonId<<_veriler;
  }
  void yukle(QDataStream &dosya){
      dosya>>_sonId>>_veriler;

  }
  virtual void elemanEklendi(Pointer ptr) = 0;
  virtual void elemanSilindi(Pointer ptr) = 0;
  virtual void elemanDegisti(Pointer eski, Pointer yeni) = 0;

protected:
  Liste _veriler;
  IdTuru _sonId;
};

#endif // TEMELVERIYONETIMSINIFI_H
