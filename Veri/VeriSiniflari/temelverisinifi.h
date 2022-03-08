#ifndef TEMELVERISINIFI_H
#define TEMELVERISINIFI_H

#include <QDate>
#include <QDateTime>
#include <QObject>
#include <QString>
#include <Veri_global.h>

class VERI_EXPORT temelverisinifi : public QObject {
  Q_OBJECT
public:
  typedef QString Metin;
  typedef int IdTuru;
  typedef QDateTime TarihSaat;
  typedef unsigned int IsaretsizTamsayi;
  typedef int Tamsayi;


public:
  explicit temelverisinifi(QObject *parent = nullptr);


IdTuru id() const;
void setId(const IdTuru &id);
signals:
  void idDegisti(const IdTuru &id);

protected:
IdTuru _id;
};

#endif // TEMELVERISINIFI_H
