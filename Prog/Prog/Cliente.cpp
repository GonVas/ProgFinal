

#include "Cliente.h"
#include <sstream>


Cliente::Cliente(string s_file)
{
  string info;
  ifstream stream;
  stream.open(s_file);

  getline(stream, info, ';');
  this->id = stoi(info);
  getline(stream, info, ';');
  Date newdate(info);
  this->cartaoCliente = newdate;
  getline(stream, info, ';');
  this->nome = info;
  getline(stream, info, ';');
  this->volCompras = stof(info);

}

Cliente::Cliente(unsigned int id, string nome, Date cartaoCliente, float volCompras)
{
	this->id = id;
	this->nome = nome;
	this->cartaoCliente = cartaoCliente;
	this->volCompras = volCompras;
}

string Cliente::getNome() const{
  return nome;
}

unsigned int Cliente::getId() const{
  return id;
}

void Cliente::setVolCompras(float new_value)
{
    this->volCompras = new_value;
}

float Cliente::getVolCompras() const{
  return volCompras;
}

Date Cliente::getDate() const
{
    return cartaoCliente;
}

void Cliente::addMoney(float new_value)
{
    this->volCompras += new_value;
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
	if (cli1.getNome() < cli2.getNome())
		return true;
	return false;
	
}
