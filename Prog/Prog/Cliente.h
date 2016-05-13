#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Date.h"

using namespace std;


class Cliente {
 private:
  unsigned int id;
  string nome;
  Date cartaoCliente;
  float volCompras;

 public:
  Cliente(ifstream & file);
  string getNome() const;
  unsigned int getId() const;
  float getVolCompras() const;
  Date getDate() const;
  void save(ofstream & out) const;
  friend ostream& operator<<(ostream& out, const Cliente & cli);  // mostra informacao do cliente no ecra
  friend bool operator<(const Cliente &cli1, const Cliente &cli2); // compara 2 clientes (1 cleinte e menor que outro se o seu nome for "alfabeticamente" inferior)
};

