
#include "../inc/Estoque.hpp"
#include "../inc/Produto.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector <string> vetor;


void Estoque::cadastra_produto(){
    fstream arquivo("arq/Produtos.txt");
    Produto produto ;
    string nome,codigo,preco,quantidade,categoria,temp;
    bool teste=false;
    int aux=0;
    cin.clear();
    cin.ignore(10000,'\n');
    do{
        aux=0;
        cout<<"Digite aqui o Nome do produto: ";
        getline(cin,nome);
        for(size_t cont=0;cont<nome.size();cont++){
            if(isdigit(nome[cont]))
                aux++;
        }
        if(aux!=0)
            cout<<"Nome de Produto invalido!"<<endl;
        else{
            teste=true;
        }
    }while(teste==false);
    teste=false;
    produto.set_nome(nome);
    aux=0;
    do{
        aux=0;
        cout<<"Digite o Codigo do produto com 6 digitos: ";
        getline(cin,codigo);
        for(size_t cont=0;cont<codigo.size();cont++)
            if(isdigit(codigo[cont]))
                aux++;
        if((size_t)aux!=codigo.size() || aux!=6){
            cout<<"Codigo Invalido!"<<endl;
        }
        else{
            teste=true;
        }
        
    }while(teste==false);
    teste=false;
    produto.set_codigo(codigo);
    aux=0;
    do{
        int ponto=0;
        aux=0;
        cout<<"Qual o valor do produto: R$";
        getline(cin,preco);
        for(size_t cont=0;cont<preco.size();cont++){
            if(isdigit(preco[cont]))
                aux++;
            else if(preco[cont]=='.')
                ponto++;
            else{
                break;
            }
            
        }
        if(((size_t)(aux+1)==preco.size() && ponto==1)||((size_t)aux==preco.size())){
            teste=true;
        }
        else{
            cout<<"Preco invalido!"<<endl;
        }
    }while(teste==false);
    teste=false;
    produto.set_preco(preco);
    aux=0;
    do{ 
        aux=0;
        cout<<"Digite a quantidade disponivel: ";
        getline(cin,quantidade);
        for(size_t cont=0;cont<quantidade.size();cont++){
            if(isdigit(quantidade[cont]) && quantidade[cont]!='.')
                aux++;
            else
                break;
        }
        if((size_t)aux==quantidade.size())
            teste=true;
        else 
            cout<<"Quantidade invalida!"<<endl;
    }while(teste==false);
    teste=false;
    produto.set_quantidade(quantidade);
    aux=0;
    do{
        aux=0;
        cout<<"Digite as categorias do produto (utilize a '/' para separar caso seja mais de uma): ";
        getline(cin,categoria);
        for(size_t cont=0;cont<categoria.size();cont++)
            if(isdigit(categoria[cont])){
                aux++;
                break;
            }
        if(aux>0)
            cout<<"Categoria(s) invalida(s)"<<endl;
        else 
            teste=true;
    }while(teste==false);
    produto.set_categoria(categoria);
    arquivo.open("arq/Produtos.txt", ios::in);
    while(getline(arquivo,temp))
        vetor.push_back(temp);
    arquivo.close();
    //cout<<"Tamanho eh >> "<<vetor.size()<<endl;
    
    vetor.push_back(produto.get_codigo());
    vetor.push_back(produto.get_nome());
    vetor.push_back(produto.get_preco());
    vetor.push_back(produto.get_quantidade());
    vetor.push_back(produto.get_categoria());
    
    arquivo.open("arq/Produtos.txt",ios::out | ios::app);
    for(auto x=(vetor.begin());x!=(vetor.end());x++){
        arquivo<<*x<<endl;
    }
    arquivo.close();
    
    vector <string> cat;
    stringstream check1(categoria);
    while(getline(check1, temp,'/')){ 
        cat.push_back(temp); 
    } 
    for(size_t cont=0;cont<(cat.size());cont++){
        string txt = "arq/categorias/"+cat[cont]+".txt";
        arquivo.open(txt, ios::out | ios::app);
        for(auto x=(vetor.begin());x!=(vetor.end());x++){
            arquivo<<*x<<endl;
        }
        arquivo.close();
    }

    vetor.clear();
    cout<<"Produto cadastrado com sucesso!"<<endl;
}

int Estoque::consulta_produto(){
    string temp,codigo;
    int aux=0;
    cin.clear();
    cin.ignore(10000,'\n');
    fstream arquivo;
    cout<<"Digite aqui teu codigo: ";
    cin>>codigo;
    arquivo.open("arq/Produtos.txt", ios::in);
    while(getline(arquivo,temp)){
        //cout<<"entrou"<<endl;
        vetor.push_back(temp);
        if(vetor[aux]==codigo){
            arquivo.close();
            return aux;
        }
        aux++;
    }


    arquivo.close();
    return -1;
}

int Estoque::consulta_produto(string codigo){
    string temp;
    int aux=0;
    fstream arquivo;
    arquivo.open("arq/Produtos.txt", ios::in);
    while(getline(arquivo,temp)){
        //cout<<"entrou"<<endl;
        vetor.push_back(temp);
        if(vetor[aux]==codigo){
            arquivo.close();
            return aux;
        }
        aux++;
    }


    arquivo.close();
    return -1;
}

void Estoque::adiciona_estoque(int quant,int posicao){
    string temp;
    int val;
    vetor.clear();
    // cin.clear();
    // cin.ignore(10000,'\n');
    fstream arquivo;
    arquivo.open("arq/Produtos.txt", ios::in);
    while(getline(arquivo,temp)){
        vetor.push_back(temp);
    }
    arquivo.close();
    posicao+=3;
    val=atoi(vetor[posicao].c_str());
    //cout<<val;
    val+=quant;
    vetor[posicao]=to_string(val);
    arquivo.open("arq/Produtos.txt", ios::out | ios::trunc);
    for(auto x=(vetor.begin());x!=(vetor.end());x++){
        arquivo<<*x<<endl;
    }
    cout<<"Quantidade aumentada!"<<endl;
    arquivo.close();
    vetor.clear();

}

void Estoque::subtrai_estoque(int quant,int posicao){
    string temp;
    int val;
    vetor.clear();
    // cin.clear();
    // cin.ignore(10000,'\n');
    fstream arquivo;
    arquivo.open("arq/Produtos.txt", ios::in);
    while(getline(arquivo,temp)){
        vetor.push_back(temp);
    }
    arquivo.close();
    posicao+=3;
    val=atoi(vetor[posicao].c_str());
    //cout<<val;
    if(val-quant<0){
        cout<<"Impossivel realizar a acao!"<<endl;
    }
    else {
        val-=quant;
        vetor[posicao]=to_string(val);
        arquivo.open("arq/Produtos.txt", ios::out | ios::trunc);
        for(auto x=(vetor.begin());x!=(vetor.end());x++){
            arquivo<<*x<<endl;
        }
        cout<<"Quantidade Subtraida!"<<endl;
        arquivo.close();
        vetor.clear();
    }

}

void Estoque::lista_produtos(){
    fstream arquivo;
    string temp;
    vetor.clear();
    arquivo.open("arq/Produtos.txt", ios::in);
    while(getline(arquivo,temp)){
        vetor.push_back(temp);
    }
    arquivo.close();
    cout<<"\n\t@@@@@@@@@@@@@@ Lista de Produtos @@@@@@@@@@@@@@"<<endl;
    for(auto cont=(vetor.begin());cont<(vetor.end());cont+=5){
        cout<<"\nCodigo: "<<*cont<<endl;
        cout<<"Nome: "<<*(cont+1)<<endl;
        cout<<"Preco: "<<*(cont+2)<<endl;
        cout<<"Quantidade: "<<*(cont+3)<<endl;
        cout<<"Categoria(s): "<<*(cont+4)<<endl;
    }
}

int Estoque::consulta_estoque(string codigo){
    int posicao = Estoque::consulta_produto(codigo);
    int val;
    string temp;
    fstream arquivo;
    arquivo.open("arq/Produtos.txt", ios::in);
    while(getline(arquivo,temp)){
        vetor.push_back(temp);
    }
    arquivo.close();
    posicao+=3;
    val=atoi(vetor[posicao].c_str());
    return val;
}







