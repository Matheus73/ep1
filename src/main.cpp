#include <iostream>
#include <fstream>
#include <string>
#include "../inc/Cliente.hpp"
#include "Loja.hpp"
#include <vector>
//vector <string> vetor;

using namespace std;

int main(){
    int opc;
    Cliente cliente;
    do{
    cout<<"\t+++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t+++++++++++ Mercado da Victoria +++++++++"<<endl;
    cout<<"\t+++++++++++++++++++++++++++++++++++++++++\n"<<endl;
    cout<<"\t=========== (1) Modo Venda =============="<<endl;
    cout<<"\t======== (2) Modo Recomendacao =========="<<endl;
    cout<<"\t=========== (3) Modo estoque ============"<<endl;
    cout<<"\t=== (4) Consultar Historico de vendas ==="<<endl;
    cout<<"\t======== (5) Registrar Cliente =========="<<endl;
    cout<<"\t=============== (6) Sair ================"<<endl;
    cout<<"\nDigite a sua opcao: ";
    cin>>opc;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        opc=5;
        cout<<"Opcao invalida!"<<endl;
        }
    switch (opc){
        case 1:
            Loja::modo_venda();
            break;
        case 2:
            Loja::modo_recomendacao();
            break;
        case 3:
            Loja::modo_estoque();
            break;
        case 4:
            Loja::modo_balanco();
            break;
        case 5:
            Loja::cadastra_cliente();
            break;
            
        case 6:
            cout<<"Programa encerrado"<<endl;
            break;
        default:
            cout<<"\nOpcao invalida!"<<endl;
            break;
    }
    }while(opc!=6);
    return 0;
}
