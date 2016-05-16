#include "Transacao.h"

unsigned int Transacao::getIdCliente() const{
  return idCliente;
}

Transacao::Transacao(unsigned int idCliente, Date data, vector<string> & produtos)
{
    this->idCliente = idCliente;
    this->data = data;
    this->produtos = produtos;
}

unsigned int Transacao::getid()
{
	return (this->idCliente);
}
Date Transacao::getdata()
{
    return this->data;
}
vector<string> Transacao::getprodutos()
{
    return this->produtos;
}

Transacao::Transacao(ifstream & in){ // le uma transacao na forma de  idcliente ; data ; lista produtos
  // A IMPLEMENTAR
}

void Transacao::save(ofstream & out) const{ // transacao guardada como na forma de  idcliente ; data ; lista produtos
  // A IMPLEMENTAR
}

string Transacao::vectortostring()
{
    string temp;
    for (int i = 0; i < (this->produtos).size(); i++)
    {
        temp += (this->produtos)[i];
        temp += ", ";

    }
    temp.pop_back();
    temp.pop_back();
    return temp;
}

ostream& operator<<(ostream& out, const Transacao & trans){

  out << trans.getid() << ";" << trans.getdata() << ";" << trans.vectortostring() << endl;
  return out;
}
