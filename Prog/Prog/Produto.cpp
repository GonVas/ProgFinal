#include "Produto.h"


Produto::Produto(ifstream & in)
{ 

}

string Produto::getNome() const {
  return nome;
}

float Produto::getCusto() const {
  return custo;
}

ostream& operator<<(ostream& out, const Produto & prod){

    out << prod.getNome() << " Costs -> " << prod.getCusto() << " €" << endl;
    return out;
}


bool operator<(const Produto &prod1, const Produto &prod2){
	if (prod1.custo < prod2.custo)
		return true;
	return false;
}
