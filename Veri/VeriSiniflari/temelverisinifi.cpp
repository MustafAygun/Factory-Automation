#include "temelverisinifi.h"

temelverisinifi::temelverisinifi(QObject *parent) : QObject(parent) {
     _id = 0;
}

temelverisinifi::IdTuru temelverisinifi::id() const
{ return _id; }

void temelverisinifi::setId(const temelverisinifi::IdTuru &id) {
  if(_id != id){
      _id=id;
      idDegisti(_id);
  }
}
