#include "Menus.h"

inline void fileopening(ifstream & file, string & filename)  //Simple inline function that is gonna open a file
{
  getline(cin, filename);

  file.open(filename);

  while(!(file.good()))      //while it cant open file, send a error message and try again
  {
      cout << "Could not find file, try again. \n";
      getline(cin, filename);
      file.open(file);
  }

}

bool infoInicial(string & loja, string & fichClientes, string & fichProdutos, string & fichTransacoes){

  cout << "What is the name of the store. \n";
  getline(cin, loja);

  cout << "Where is the Client file? \n";
  ifstream cl_file;
  fileopening(cl_file, fichClientes);
  cl_file.close();

  cout << "Where is the Products file? \n";
  ifstream pro_file;
  fileopening(cl_file, fichProdutos);
  pro_file.close();

  cout << "Where is the Transactions file? \n";
  ifstream tran_file;
  fileopening(cl_file, fichTransacoes);
  tran_file.close();

  return true;
}

/******************************************
 * Gestao de Clientes
 ******************************************/
unsigned short int menuGestaoClientes(){
  unsigned short int opcao;

  clearScreen();
  cout << TAB_BIG << "Menu Gestao Clientes" << endl;
  cout << endl;
  cout << TAB << "1 - Listar clientes" << endl;
  cout << TAB << "2 - Ver informacao cliente" << endl;
  cout << TAB << "3 - Editar cliente" << endl;
  cout << TAB << "4 - Remover cliente" << endl;
  cout << TAB << "5 - Voltar ao menu inicial" << endl << endl;
  cout << TAB << "Qual a sua opcao: ";
  opcao = leUnsignedShortInt(1, 5);

  if(opcao == 5)
    return 0;

  return opcao;
}


void opcoesGestaoClientes(VendeMaisMais & supermercado){
  unsigned int opcao;
  string nome;

  while((opcao = menuGestaoClientes()))
    switch (opcao){
    case 1: supermercado.listarClientesOrdemAlfa();
      break;
    case 2: cout << "Qual o nome do cliente: ";
      getline(cin, nome);
      supermercado.mostraInformacaoCliente(nome);
      break;
    case 3:
      break;
    case 4:
      break;
    }
}

/******************************************
 * Gestao de Transacoes
 ******************************************/
unsigned short int menuGestaoTransacoes(){

}

void opcoesGestaoTransacoes(VendeMaisMais & supermercado){
  unsigned int opcao;

  while((opcao = menuGestaoTransacoes()))
    switch (opcao){
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    }
}

/******************************************
 * Gestao de Transacoes
 ******************************************/
unsigned short int menuRecomendacao(){

}

void opcoesRecomendacao(VendeMaisMais & supermercado){
  unsigned int opcao;

  while((opcao = menuRecomendacao()))
    switch (opcao){
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    }

}

/******************************************
 * Menu Inicial
 ******************************************/
unsigned short int menuInicial(){
  unsigned short int opcao;

  clearScreen();
  cout << TAB_BIG << "Menu Inicial" << endl;
  cout << endl;
  cout << TAB << "1 - Gestao de clientes" << endl;
  cout << TAB << "2 - Lista produto disponiveis" << endl;
  cout << TAB << "3 - Gestao de transacoes" << endl;
  cout << TAB << "4 - Recomendacoes" << endl;
  cout << TAB << "5 - Sair do programa" << endl << endl;
  cout << TAB << "Qual a sua opcao: ";
  opcao = leUnsignedShortInt(1, 5);

  if(opcao == 5)
    return 0;

  return opcao;
}

void opcoesIniciais(VendeMaisMais & supermercado){
  unsigned int opcao;


  while((opcao = menuInicial()))
    switch (opcao){
    case 1: opcoesGestaoClientes(supermercado);
      break;
    case 2: supermercado.listarProdutos();
      break;
    case 3: opcoesGestaoTransacoes(supermercado);
      break;
    case 4: opcoesRecomendacao(supermercado);
      break;
    }

  supermercado.saveChanges();
}
