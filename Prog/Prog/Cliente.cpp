#include "Cliente.h"


Cliente::Cliente(ifstream & file)
{
  string info;

  getline(file, info);
  this->id = stoi(info);
  getline(file, info);
  this->date = Date newdate (info);
  getline(file, info);
  this->nome = info;
  getline(file, info);
  this->volCompras = stof(info);

}


string Cliente::getNome() const{
  return nome;
}

unsigned int Cliente::getId() const{
  return id;
}

float Cliente::getVolCompras() const{
  return volCompras;
}

Date Cliente::getDate() const
{
    return cartaoCliente;
}

void Cliente::save(ofstream & out) const{

  // A IMPLEMENTAR

}

ostream& operator<<(ostream& out, const Cliente & cli)
{
  out << cli.getId() << endl << cli.getNome() << endl << cli.getDate() << endl << cli.getVolCompras() << endl;
  return out;
}


bool operator<(const Cliente &cli1, const Cliente &cli2){
  // A IMPLEMENTAR
}
