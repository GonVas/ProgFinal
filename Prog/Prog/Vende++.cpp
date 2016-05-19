#include "Vende++.h"
#include <string>
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
        s_clientnum = extract_from_string(0, fullclient, ';',0);
        clientnum = stoi(s_clientnum);
        //See utils.cpp for information about extract_from_string
        Cliente newclient(clientnum, extract_from_string(1, fullclient, ';', 1) , Date(extract_from_string(2, fullclient, ';', 1)), stof(extract_from_string(3, fullclient, ';', 1)) );
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
        Produto newproduct(extract_from_string(0, fullProduct, ';', 1), stof(extract_from_string(1, fullProduct, ';', 1)));
        this->produtos.push_back(newproduct);
    }
}

void VendeMaisMais::LoadTransFromFile(ifstream & file)
{
     string garbage, fullTrans, onlyprods;
     string s_prod, singleprod;
     vector <string> prods;
     int prodpos;
     int i = 0;
     int clientid;

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
        clientid = stoi(extract_from_string(0, fullTrans, ';', 1));
        Transacao newTrans(clientid, Date(extract_from_string(1, fullTrans, ';', 1)), prods);
        prods.clear(); //need to reset the prods for another iteration
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

int VendeMaisMais::getMaxIDclient()
{
	updateMaxIDclient();
    return maxClientesId;
}

void VendeMaisMais::makeClientMap()
{
    pair <string, int> newpair;
    for (int i = 0; i < ((this->clientes).size()); i++)
    {
        this->clienteIdx[(this->clientes)[i].getNome()] = i;
    }
}

void VendeMaisMais::MakeTransMap()
{

    for (int i = 0; i < ((this->transacoes).size()); i++)
    {
		this->transacaoIdx.insert(pair<int, int>((this->transacoes)[i].getid(), i));
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

VendeMaisMais::VendeMaisMais(string loja, string fichClients, string fichProdutos, string fichTransacoes)
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
	LoadTransFromFile(trans_file);

    updateMaxIDclient();
	makeClientMap();
    MakeTransMap();

}

/*********************************
 * Gestao de Clientes
 ********************************/

//Adds a client with all the parameters
void VendeMaisMais::AddClient(unsigned int id, string nome, Date cartaoCliente, float volCompras)
 {
     Cliente anotherclient(id, nome, cartaoCliente, volCompras);
     clientes.push_back(anotherclient);
     clientesAlterados = true;
 }

void VendeMaisMais::AddTrans(unsigned int id, Date cartaoTrans, vector <string> prods)
 {
     Transacao anotherTrans(id, cartaoTrans, prods);
     transacoes.push_back(anotherTrans);
     transacoesAlterdas = true;
 }

// lista os cleinets por ordem alfabetica crescente
void VendeMaisMais::listarClientesOrdemAlfa() const
{
	map<string, int>::const_iterator iter;

	for (iter = (this->clienteIdx).begin(); iter != (this->clienteIdx).end(); ++iter)
		cout << clientes[(iter->second)];

}

// mostra a informacao individual de um cliente
void VendeMaisMais::mostraInformacaoCliente(string nome)
{
    int id;
    try
    {
        id = (this->clientes)[this->clienteIdx.at(nome)].getId();
       cout << this->clientes[id];

    }catch (const std::out_of_range& oor){
    std::cerr << "You typed a name of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }

}

void VendeMaisMais::editClient(string name, float newvalue)
{
    int id;
    try
    {
        id = (this->clientes)[this->clienteIdx.at(name)].getId();
        (this->clientes)[id].setVolCompras(newvalue);

    }catch (const std::out_of_range& oor) {
    std::cerr << "You typed a name of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }
}

 void VendeMaisMais::removeClient(string name)
 {
   int id;
    try
    {
		id = (this->clientes)[this->clienteIdx.at(name)].getId();

		(this->clientes).erase( ((this->clientes).begin()) + (id-1));

    }catch (const std::out_of_range& oor) {
    std::cerr << "You typed a name of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }
}


void VendeMaisMais::editClient(unsigned int id, float newvalue)
{
    try
    {
        (this->clientes)[(id-1)].setVolCompras(newvalue);

    }catch (const std::out_of_range& oor) {
    std::cerr << "You typed a Id of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }
}

 void VendeMaisMais::removeClient(unsigned int id)
 {
    try
    {
        (this->clientes).erase( (this->clientes).begin()+(id-1));

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
void VendeMaisMais::listarProdutos()
{
/*
    string alphabetic [(this->produtos).size()];
    string *pointer = alphabetic;
    for (int k = 0; k < (this->produtos).size(); k++)
    {
        alphabetic[k] = (this->produtos)[k].getNome();
    }
    sort(pointer, pointer+((this->produtos).size()));

    cout << "Available products: " << endl;
    for (int k = 0; k < (this->produtos).size(); k++)
    {
        cout << *(pointer+k) << endl;
    }

*/
}

void VendeMaisMais::createtrans(unsigned int id, Date data, string prods)
{
    vector <string> vectorprods;
    string singleprod;
    int i;
    float cost = 0.0;

    while( extract_from_string(i, prods, ',', true) != "OVER" ) //see the documentation of extract_from_string in utils.cpp for more info
        {
            singleprod = extract_from_string(i, prods, ',', true); //this will extract a single product
            cost += produtos[((this->produtoIdx).at(singleprod))].getCusto();
            vectorprods.push_back(singleprod);
            i++;
        }
    Transacao newtrans (id, data, vectorprods);
    transacoes.push_back(newtrans);

    for(int j = 0; j < (this->clientes).size(); j++)
    {
        if (id == (this->clientes)[j].getId())
        {
            (this->clientes)[j].addMoney(cost);
        }
    }

    transacoesAlterdas = true;
    clientesAlterados = true;
}

void VendeMaisMais::singleclientTrans(string name)
{
    int id;
    try
    {
        id = (this->clientes)[(this->clienteIdx).at(name)].getId();
        pair <multimap<int,int>::iterator, multimap<int,int>::iterator> ret;
        ret = (this->transacaoIdx).equal_range(id);
        for (multimap<int,int>::iterator it=ret.first; it!=ret.second; ++it)
             {
                cout << transacoes.at(it->second);
             }

    }catch (const std::out_of_range& oor){
    std::cerr << "You typed a name of a client that doesn´t exist. Details: " << oor.what() << '\n';
  }
}


void VendeMaisMais::transday(Date date1) const
{
    for (int i = 0; i < (this->transacoes).size(); i++)
    {
        if ( ((this->transacoes).at(i)).getdata() == date1)
        {
            cout << ((this->transacoes).at(i));
        }
    }
}

void VendeMaisMais::transinterval(Date date1, Date date2) const
{
    for (int i = 0; i < (this->transacoes).size(); i++)
    {
        if ( (((this->transacoes).at(i)).getdata() >= date1) && !(((this->transacoes).at(i)).getdata() > date2))
        {
            cout << ((this->transacoes).at(i));
        }
    }
}

void VendeMaisMais::showbottom() const
{
    /*
    multimap<float, int> mymap;
    int breaker = 0;

    int id [(this->clientes).size()] = 0;

    for(int i = 0; i < (this->clientes).size(); i++)
    {

        mymap.insert(pair<float,int>( ((this->clientes)[i].getVolCompras()), ((this->clientes)[i].getId()) ) );
    }

    multimap<float, int>::iterator p;
    for(p = mymap.begin(); p != mymap.end(); p++)
    {
        cout << (this->clientes).at(p->second - 1);
        if(breaker > 9)
            break;
        breaker++;
    }
*/
}

void VendeMaisMais::recommendfor(string name) const
{
    int pos;
    try
    {
        pos = (this->clienteIdx).at(name);

    }catch (const std::out_of_range& oor) {
    std::cerr << "You typed a name of a client that doesn´t exist. Details: " << oor.what() << '\n';
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

 string VendeMaisMais::getloja() const
 {
     return this->loja;
 }
 string VendeMaisMais::getFichClient() const
 {
     return this->fichClientes;
 }
 string VendeMaisMais::getFichProdutos() const
 {
     return this->fichProdutos;
 }
 string VendeMaisMais::getFichTransacoes() const
 {
     return this->fichTransacoes;
 }

// mostra o conteudo de uma loja
ostream& operator<<(ostream& out, VendeMaisMais & supermercado){

  out << "Supermarket name: " << supermercado.getloja() << endl;
  out << "Client path: " << supermercado.getFichClient() << endl;
  out << "Products path: " << supermercado.getFichProdutos() << endl;
  out << "Transactions path: " << supermercado.getFichTransacoes() << endl;
  out << "Amount of clients; " << supermercado.clientAmount() << endl;
  return out;

}
