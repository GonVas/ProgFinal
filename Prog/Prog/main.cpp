#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Vende++.h"
#include "Menus.h"
#include "utils.h"
#include <windows.h>


int main(){
  string loja, fichClients, fichProdutos, fichTransacoes;

  // pede a informacoo sobre o nome da loja e os 3 ficheiros com
  // informacoo de clientes, produtos e transacoes

  if(! infoInicial(loja, fichClients, fichProdutos, fichTransacoes))
    return(-1);  //This is probabily never going to happen.

  // cria uma loja
  VendeMaisMais supermercado(loja, fichClients, fichProdutos, fichTransacoes);

  cout << "Informacao da loja '" << loja << " do supermercado Vende++:" << endl;
 // cout << supermercado << endl;  // mostra estatisticas da loja

  opcoesIniciais(supermercado); // menu inicial com as grandes opcoes
				// que implementam as funcioanlidades
				// disonibilizadas

  return 0;
}


//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <stdexcept>
//
//#include "Matrix.h"
//
//using namespace std;
//
//int main()
//{
//    vector <string> client1;
//    vector <string> client2;
//    vector <string> client3;
//    vector <string> produtos;
//    vector <vector <string>> clients;
//    vector <vector <bool>> matrix;
//
//
//    client1.push_back("laranja");
//    client1.push_back("banana");
//    client1.push_back("pipocas");
//    client1.push_back("morangos");
//    client1.push_back("macas");
//
//    client2.push_back("laranja");
//    client2.push_back("banana");
//    client2.push_back("pipocas");
//    client2.push_back("ananas");
//
//    client3.push_back("cereais");
//    client3.push_back("agua");
//    client3.push_back("sumo");
//    client3.push_back("ananas");
//    client3.push_back("queijo");
//
//    produtos.push_back("laranja");
//    produtos.push_back("banana");
//    produtos.push_back("pipocas");
//    produtos.push_back("morangos");
//    produtos.push_back("macas");
//    produtos.push_back("ananas");
//    produtos.push_back("cereais");
//    produtos.push_back("agua");
//    produtos.push_back("sumo");
//    produtos.push_back("queijo");
//
//    clients.push_back(client1);
//    clients.push_back(client2);
//    clients.push_back(client3);
//
//    matrix.resize(clients.size());
//    for (int i = 0; i < matrix.size(); i++)
//        matrix[i].resize(produtos.size());
//
//
//    for (int k = 0; k < matrix.size(); k++ )
//    {
//        for (int j = 0; j < produtos.size(); j++)
//        {
//            if(find(clients[k].begin(), clients[k].end(), produtos[j]) != clients[k].end())
//                {
//                    matrix[k][j] = 1;
//                }
//                else
//                {
//                    matrix[k][j] = 0;
//                }
//        }
//    }
//
//    cout << "Matrix: " << endl << endl;
//
//    	for (int i = 0; i < (matrix.size()); i++)
//        {
//            for (int l = 0; l < produtos.size(); l++)
//            {
//               cout << "->" << (matrix[i])[l] << " ";
//            }
//            cout << endl;
//        }
//
//        cout << endl << "Matrix displayed. " << endl;
//
//        cout << " matrix size: " << matrix.size() << "\n";
//
//    int same = 0;
//    int maxsame = 0;
//
//    int targetclient = 0;
//
//    for(int v = 0; v < matrix.size(); v++)
//    {
//        if(v != targetclient)
//            {
//                for(int h = 0; h < produtos.size(); h++)
//                {
//                    if(matrix[targetclient][h] == matrix[v][h] && matrix[v][h] == 1)
//                    {
//                        same = same +1;
//                    }
//                }
//                if (same > maxsame)
//                    maxsame = same;
//
//                same = 0;
//            }
//
//    }
//
//    cout << "Max same is :" << maxsame << endl;
//
//
//
//    cout << "Hello world!" << endl;
//    return 0;
//}
