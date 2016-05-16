#pragma once

#ifndef VENDE++

#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include "defs.h"
#include "Date.h"
#include "Cliente.h"
#include "Transacao.h"
#include "Produto.h"
#include "utils.h"


using namespace std;

class VendeMaisMais{
 private:
  string loja; // nome da loja
  string fichClientes, fichProdutos, fichTransacoes; // nome dos ficheiros de clientes, produtos e transacoes
  bool transacoesAlterdas; // flag que fica a true se for preciso guardar no final as transacoes
  bool clientesAlterados; // flag que fica a true se for preciso guardar no final os clienets
  unsigned int maxClientesId; // variavel que guarda o identificador unico do cliente com o maior identiicador
  vector<Cliente> clientes; // vetor que guarda a informacao dos clientes existentes
  vector<Produto> produtos; // vetor que guarda a informacao dos produtos disponiveis
  vector<Transacao> transacoes; // vetor que guarda a informacao das ttransacoes efetuadas
  map<string, int> clienteIdx;  // map para "traduzir" nome do cliente no indice dele no vetor de clientes
  map<string, int> produtoIdx;  // map para "traduzir" nome do produto no indice dele no vetor de produtos
  multimap<int, int> transacaoIdx; // multima para "traduzir" o identificador do cliente nos indices das suas transacoes no vetor de transacoes
  void makeClientMap(); //Method that will create a map
  void makeProdMap();
  void MakeTransMap();
  void updateMaxIDclient();
  //int moneymade(); //Sum of all the money made from transactions

 public:
  VendeMaisMais(string loja, string fichClients, string fichProdutos, string fichTransacoes);
  void LoadClientsFromFile(ifstream & file);
  void LoadProdFromFile(ifstream & file);
  void LoadTransFromFile(ifstream & file);
  void AddDClient();
  void AddClient(unsigned int id, string nome, Date cartaoCliente, float volCompras);
  void AddTrans(unsigned int id, Date cartaoTrans, vector <string> prods );
  void listarClientesOrdemAlfa() const;
  void listarProdutos() ;
  void mostraInformacaoCliente(string nome) ;
  void listTransactions() const;
  void showtrans(string nome) const;
  void saveChanges() const;
  void editClient(unsigned int id, float newvalue);
  void editClient(string name, float newvalue);
  void removeClient(unsigned int id);
  void removeClient(string name);
  void createtrans(unsigned int id, Date data, string prods);
  void transday(Date date1) const;
  void transinterval(Date date1, Date date2) const;
  void showbottom() const;
  void recommendfor(string name) const;
  //singleclientTrans
  int getMaxIDclient() ;
  int clientAmount(); // Number of clients
  string getloja() const;
  string getFichClient() const;
  string getFichProdutos() const;
  string getFichTransacoes() const;

  friend ostream& operator<<(ostream& out, const VendeMaisMais & supermercado);
};

#endif // !VENDE++