#include "Vende++.h"

void VendeMaisMais::MakeClient(ifstream & file)
{
    string garbage, fullclient;
    string s_id, s_name, s_values, s_name;

    getline(file,garbage);

    while(getline(file, fullclient))
    {
        Cliente
    }

}

VendeMaisMais::VendeMaisMais(string loja, string fichClients, string fichProdutos, string fichTransacoes){
{
    this->loja = loja;
    this->fichClientes = fichClients;
    this->fichProdutos = fichProdutos;
    this->fichTransacoes = fichTransacoes;
    this->clientesAlterados = false;
    this->transacoesAlterdas = false;

    ifstream cl_file(fichClients);
    MakeClient(cl_file);


}

/*********************************
 * Gestao de Clientes
 ********************************/

// lista os cleinets por ordem alfabetica crescente
void VendeMaisMais::listarClientesOrdemAlfa() const{

  // A IMPLEMENTAR

}

// mostra a informacao individual de um cliente
void VendeMaisMais::mostraInformacaoCliente(string nome){



}

/*********************************
 * Gestao de Produtos
 ********************************/

// lisat os produto por ordem alfabetica crescente
void VendeMaisMais::listarProdutos() const{

  // A IMPLEMENTAR

}


/*********************************
 * Preservar Informacao
 ********************************/

// guarda apenas a informacao de clientes e/ou de transacoes que foi alterada
void VendeMaisMais::saveChanges() const{

  // A IMPLEMENTAR

}

/*********************************
 * Mostrar Loja
 ********************************/

// mostra o conteudo de uma loja
ostream& operator<<(ostream& out, const VendeMaisMais & supermercado){

  // A IMPLEMENTAR

}
