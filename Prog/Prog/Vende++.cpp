#include "Vende++.h"
#include "utils.h"

//Load all the clients from the file
void VendeMaisMais::LoadClientsFromFile(ifstream & file)
{
    string s_clientnum, fullclient, garbage;
    int clientnum;
    //string s_id, s_name, s_values, s_name;

    getline(file,garbage);

    while(getline(file, fullclient))
    {
        //See utils.cpp for information about extract_from_string
        Cliente newclient(stoi(extract_from_string(0, fullclient, ';', 1)), extract_from_string(1, fullclient, ';', 1) , Date(extract_from_string(2, fullclient, ';', 1)), stof(extract_from_string(3, fullclient, ';', 1)) );
        //With this line it will extract the different components of client and convert them to the correct types and then create a client
        clientes.push_back(newclient);
    }

    /*getline(file, s_clientnum);

    clientnum = stoi(s_clientnum);

    for (int i = 0; i < clientnum; i++)
    {
        Cliente newclient(file);
        clientes.push_back(newclient);
    }*/

}

void VendeMaisMais::LoadProdFromFile(ifstream & file)
{
    string garbage, fullProduct;
    //string s_prod, s_value;

    getline(file,garbage);

    while(getline(file, fullProduct))
    {
        Produto newproduct(extract_from_string(0, fullProduct, ';', 1), stof(extract_from_string(1, fullProduct, ';', 1));
    }
}

void VendeMaisMais::LoadTransFromFile(ifstream & file)
{
     string garbage, fullTrans, onlyprods;
     string s_prod, singleprod;
     vector <string> prods;
     int prodpos;
     int i = 0;

    getline(file,garbage);

    while(getline(file, fullTrans))
    {
        prodpos = fullTrans.find(';');
        prodpos = fullTrans.find(';');   //prodpos is the position where the products start
        onlyprods =  fullTrans.substr(prodpos); // onlyprods now equals to the portion of the products in the a line of the transaction file

        while( extract_from_string(i, onlyprods, ',', true) != "OVER" ) //see the documentation of extract_from_string in utils.cpp for more info
        {
            singleprod = extract_from_string(i, onlyprods, ',', true); //this will extract a single product
            prods.push_back(singleprod);
            i++;
        }

        Transacao newTrans(extract_from_string(0, fullProduct, ';', 1), Date(extract_from_string(1, fullProduct, ';', 1)), prods);
        prods.erase(); //need to reset the prods for another iteration
    }
}

void VendeMaisMais::updateMaxIDclient() //Function to find what is the biggest ID
{
    int maxID = -1;

    for (int i = 0; i < (this->clientes).size(); i++) //Loop to go trough all the clients
    {
        if( (this->clientes).at(i).getId() > maxID ) //(this->clientes).at(i) is a single cliente (this->clientes).at(i).getID() is his ID
        {
            maxID = (this->clientes).at(i).getId() ;
        }
    }

	this->maxClientesId = maxID;
}

int VendeMaisMais::getMaxIDclient() const
{
    updateMaxIDclient();
    return maxClientesId;
}

void VendeMaisMais::MakeClientMap()
{
    pair <string, int> newpair;
    for (int i = 0; i < ((this->clientes).size()); i++)
    {
        this->clienteIdx[(this->clientes)[i].getNome()] = i;
    }
}

void VendeMaisMais::makeProdMap()
{
    pair <string, int> newpair;
    for (int i = 0; i < ((this->produtos).size()); i++)
    {
        this->produtoIdx[(this->produtos)[i].getNome()] = i;
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
    LoadClientsFromFile(cl_file);
    ifstream prod_file(fichProdutos);
    LoadProdFromFile(prod_file);
    ifstream trans_file(fichTransacoes);
    LoadTransFromFile(tans_file);

    updateMaxIDclient();
    MakeClientMap();

}

/*********************************
 * Gestao de Clientes
 ********************************/

//Adds a client with all the parameters
 void VendeMaisMais::AddClient(unsigned int id, string nome, Date cartaoCliente, float volCompras )
 {
     Cliente anotherclient(id, nome, cartaoCliente, volCompras);
     clientes.push_back(anotherclient);
     clientesAlterados = true;
 }

 void AddTrans(unsigned int id, Date cartaoTrans, vector <string> prods );
 {
     Transacao anotherTrans(id, cartaoTrans, prods);
     transacoes.push_back(anotherTrans);
     transacoesAlterdas = true;
 }

// lista os cleinets por ordem alfabetica crescente
void VendeMaisMais::listarClientesOrdemAlfa() const
{
    map<string, int>::iterator iter;

    for (iter = (this->clienteIdx).begin(); iter != (this->clienteIdx).end(); ++iter) {
           cout << clientes[(iter->second)];
}

// mostra a informacao individual de um cliente
void VendeMaisMais::mostraInformacaoCliente(string nome)
{
    int cpos;
    try
    {
       cpos = clientes[clientIdx.at(nome)];
       cout << this->clientes[cpos];

    }catch (const std::out_of_range& oor){
    std::cerr << "You typed a name of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }

}

void VendeMaisMais::editClient(string name, float newvalue)
{
    int cpos;
    try
    {
        cpos = clientes[clientIdx.at(nome)];
        (this->clientes)[cpos].setVolCompras(newvalue);

    }catch (const std::out_of_range& oor) {
    std::cerr << "You typed a name of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }
}

 void VendeMaisMais::removeClient(string name)
 {
    int cpos;
    try
    {
        cpos = clientes[clientIdx.at(nome)];
        (this->clientes).erase(cpos);

    }catch (const std::out_of_range& oor) {
    std::cerr << "You typed a name of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }
}


void VendeMaisMais::editClient(unsigned int id, float newvalue)
{
    try
    {
        cpos = clientes[clientIdx.at(nome)];
        (this->clientes)[(id-1)].setVolCompras(newvalue);

    }catch (const std::out_of_range& oor) {
    std::cerr << "You typed a Id of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }
}

 void VendeMaisMais::removeClient(unsigned int id)
 {
    int cpos;
    try
    {
        cpos = clientes[clientIdx.at(nome)];
        (this->clientes).erase((id-1));

    }catch (const std::out_of_range& oor) {
    std::cerr << "You typed a name of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }
}

int VendeMaisMais::clientAmount()
{
    return this->clientes.size();
}

/*********************************
 * Gestao de Produtos
 ********************************/

// lisat os produto por ordem alfabetica crescente
void VendeMaisMais::listarProdutos() const{

    string alphabetic [(this->produtos).size()];
    string *pointer = alphabetic;
    for (int k = 0; k < (this->produtos).size(); k++)
    {
        alphabetic[k] = (this->produtos)[k];
    }
    sort(pointer, pointer+((this->produtos).size()));

    cout << "Available products: " << endl;
    for (int k = 0; k < (this->produtos).size(); k++)
    {
        cout << *(pointer+k) << endl;
    }


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

 string VendeMaisMais::getloja()
 {
     return this->loja;
 }
 string VendeMaisMais::getFichClient()
 {
     return this->fichClientes;
 }
 string VendeMaisMais::getFichProdutos()
 {
     return this->fichProdutos;
 }
 string VendeMaisMais::getFichTransacoes()
 {
     return this->fichTransacoes;
 }

// mostra o conteudo de uma loja
ostream& operator<<(ostream& out, const VendeMaisMais & supermercado){

  out << "Supermarket name: " << supermercado.getloja() << endl;
  out << "Client path: " << supermercado.getFichClient() << endl;
  out << "Products path: " << supermercado.getFichProdutos() << endl;
  out << "Transactions path: " << supermercado.getFichTransacoes() << endl;
  out << "Amount of clients; " << supermercado.clientAmount() << endl;
  return out;

}
