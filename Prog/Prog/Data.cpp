#include "Data.h"


Data::Data(string dataStr){ // data na forma DD/MM/AAA
  // A IMPLEMENTAR
}

int Data::getDia() const{
  return dia;
}

int Data::getMes() const{
  return mes;
}

int Data::getAno() const{
  return ano;
}

void Data::setDia(int dia){
  // A IMPLEMENTAR
}

void Data::setMes(int mes){
  // A IMPLEMENTAR
}

void Data::setAno(int ano){
  // A IMPLEMENTAR
}

void Data::save(ofstream & out) const{
  // A IMPLEMENTAR
}

ostream& operator<<(ostream& out, const Data & data){
  // A IMPLEMENTAR
}
