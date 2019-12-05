#include "Loja.hpp"
#include "Cliente.hpp"
#include "Carrinho.hpp"
#include "Pessoa.hpp"
#include "Estoque.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

void Loja::modo_venda(){
    string cpf,codigo;
    int posicao,teste,quant;
    bool socio,cond=false;
    fstream arquivo;
    char opc='s';
    cout<<"\n\n";
    cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t+++++++++++++++++ Modo Venda ++++++++++++++++++"<<endl;
    cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
    cin.clear();
    cin.ignore(10000,'\n');
    Carrinho::limpa_carrinho();
    cout<<"Digite aqui o cpf do cliente: ";
    getline(cin,cpf);
    posicao = Loja::consulta_cliente(cpf);
    if( posicao == -1){
        cout<<"\nCliente nao cadastrado!\nFechando o modo venda!\n"<<endl;
    }
    else{
        Cliente cliente =  Cliente(posicao);
        vector <string> cat;
        string temp1;
        stringstream check1(cliente.get_historico());
        while(getline(check1, temp1,'/')){ 
        cat.push_back(temp1); 
    } 
        cout<<"Cliente: "<<cliente.get_nome()<<"\n"<<endl;
        socio = cliente.get_socio();

        do{
            Estoque::lista_produtos();
            // cin.clear();
            // cin.ignore(10000,'\n');
            cout<<"\nDigite o codigo do produto que deseja adicionar ao carrinho: ";
            getline(cin,codigo);
            teste=Estoque::consulta_produto(codigo);
            if(teste==-1){
                cout<<"\nCodigo inexistente!\nCompra cancelada!\n"<<endl;
            }
            else {
                do{
                    cout<<"Digite a quantidade que deseja comprar: ";
                    cin>>quant;
                    if(cin.fail() || quant<=0){
                        cin.clear();
                        cin.ignore();
                        cout<<"Quantidade invalida!"<<endl;
                    }
                    else if(quant>Estoque::consulta_estoque(codigo)){
                        cout<<"Nao temos essa quantidade disponivel!\nDigite novamente!"<<endl;
                    }
                    else{
                        Estoque::subtrai_estoque(quant,teste);
                        Carrinho::adiciona_carrinho(codigo,quant,cliente);
                        cond=true;
                    }
                }while(cond==false);

                Carrinho::lista_carrinho();
                cout<<"\nO preco atual eh: "<<Carrinho::preco_carrinho()<<endl;
                cout<<"\n";
                do{
                    cout<<"Deseja adicionar mais produtos ao carrinho? [s/n] ";
                    cin>>opc;
                    if(cin.fail()){
                        cin.ignore();
                        cin.clear();
                        cout<<"Opcao invalida!"<<endl;
                    }
                    else if(opc!='s' && opc!='n'){
                        cout<<"Opcao invalida!"<<endl;
                    }
                }while(opc!='s' && opc!='n');
            }
            cin.clear();
            cin.ignore(10000,'\n');
        }while(opc=='s');
        // cliente.set_historico(Carrinho::consulta_categorias());
        // cout<<cliente.get_historico()<<endl;
        if(socio==true){
            cout<<"O preco final e: (-15% por ser socio) "<<0.85*(Carrinho::preco_carrinho())<<"\n"<<endl;
            Loja::cupom_fiscal(cliente.get_nome(),cliente.get_cpf(),(0.85*(Carrinho::preco_carrinho())));
            cout<<"SEU CUPOM FISCAL JA FOI EMITIDO ELE SE ENCONTRA NA PASTA ARQ/ CASO DESEJE IMPRIMIR\n\n"<<endl;
            arquivo.open("arq/Balanco.txt", ios::out | ios::app);
            arquivo<<(0.85*(Carrinho::preco_carrinho()))<<endl;
            arquivo.close();
        }
        else{
            cout<<"O preco final e: R$"<<Carrinho::preco_carrinho()<<endl;
            Loja::cupom_fiscal(cliente.get_nome(),cliente.get_cpf(),(Carrinho::preco_carrinho()));
            cout<<"SEU CUPOM FISCAL JA FOI EMITIDO ELE SE ENCONTRA NA PASTA ARQ/ CASO DESEJE IMPRIMIR\n\n"<<endl;
            arquivo.open("arq/Balanco.txt", ios::out | ios::app);
            arquivo<<((Carrinho::preco_carrinho()))<<endl;
            arquivo.close();
        }

        


    }
}

void Loja::modo_estoque(){
    int opc,posicao,quant,aux;
    fstream prod;
    string temp;
    //string codigo;
    do{
    cout<<"\n\n";
    cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t++++++++++++++++ Modo Estoque +++++++++++++++++"<<endl;
    cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
    cout<<"\t============ (1) Cadastrar Produto ============"<<endl;
    cout<<"\t====== (2) Aumentar quantidade de produto ====="<<endl;
    cout<<"\t==== (3) Diminuir a quantidade de produto ====="<<endl;
    cout<<"\t==== (4) Verificar se o produto ja existe ====="<<endl;
    cout<<"\t================= (5) voltar =================="<<endl;
    cout<<"\nDigite aqui sua escolha: ";
    cin>>opc;
    if(cin.fail()){
        cin.clear();
        cin.ignore(10000,'\n');
        opc=10;
        

    }
    switch (opc)
    {
    case 1:
        Estoque::cadastra_produto();
        break;
    case 2:
        posicao =Estoque::consulta_produto();
        if(posicao==-1)
            cout<<"\nProduto nao cadastrado!"<<endl;
        else{
            vector <string> tut;
            prod.open("arq/Produtos.txt", ios::in);
            while(getline(prod,temp))
                tut.push_back(temp);
            prod.close();

            cout<<"\tO produto e: \n"<<endl;
            cout<<"Codigo: "<<tut[posicao]<<endl;
            cout<<"Nome: "<<tut[posicao+1]<<endl;
            cout<<"Preco: "<<tut[posicao+2]<<endl;
            cout<<"Quantidade: "<<tut[posicao+3]<<endl;
            cout<<"Categorias: "<<tut[posicao+4]<<"\n"<<endl;

            do{
                aux=0;
                cout<<"Aumentar em quanto? ";
                cin>>quant;
                if(cin.fail())
                    aux++;
            }while(aux!=0);
        Estoque::adiciona_estoque(quant,posicao);
        }

        break;
    case 3:
        posicao =Estoque::consulta_produto();
        if(posicao==-1)
            cout<<"\nProduto nao cadastrado!"<<endl;
        else{
            do{
            vector <string> tut;
            prod.open("arq/Produtos.txt", ios::in);
            while(getline(prod,temp))
                tut.push_back(temp);
            prod.close();

            cout<<"\tO produto e: \n"<<endl;
            cout<<"Codigo: "<<tut[posicao]<<endl;
            cout<<"Nome: "<<tut[posicao+1]<<endl;
            cout<<"Preco: "<<tut[posicao+2]<<endl;
            cout<<"Quantidade: "<<tut[posicao+3]<<endl;
            cout<<"Categorias: "<<tut[posicao+4]<<"\n"<<endl;
                aux=0;
                cout<<"Diminuir em quanto? ";
                cin>>quant;
                if(cin.fail())
                    aux++;
            }while(aux!=0);
        Estoque::subtrai_estoque(quant,posicao);
        }
        break;
    case 4:
        // cout<<"Digite aqui o codigo do produto: ";
        // cin>>codigo;
        posicao=Estoque::consulta_produto();
        if(posicao==-1)
            cout<<"\nProduto nao cadastrado!"<<endl;
        else 
            cout<<"\nProduto ja cadastrado!"<<endl;
        break;
    default:
        cout<<"Escolha invalida!"<<endl;
        break;
    }
    }while(opc!=5);
}

void Loja::modo_recomendacao(){
    cout<<"\n\n";
    cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"\t++++++++++++++ Modo Recomendacao ++++++++++++++"<<endl;
    cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
    string cpf;
    int posicao;
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"Digite aqui o cpf do cliente: ";
    getline(cin,cpf);
    posicao = Loja::consulta_cliente(cpf);
    if( posicao == -1){
        cout<<"\nCliente nao cadastrado!\nFechando o modo Recomendacao!\n"<<endl;
    }
    else{
        Cliente cliente =  Cliente(posicao);
        //cout<<cliente.get_historico()<<endl;
        vector <string> cat;
        string temp;
        fstream arquivo;
        stringstream check1(cliente.get_historico());
        while(getline(check1, temp,'/')){ 
            cat.push_back(temp); 
        } 
        //cout<<"teste2"<<endl;
        //cat.erase(cat.begin());
        vector <string> print;
        while(print.size()<10*5){
            for(int cont=1;(size_t)cont<cat.size();cont++){
                string txt = "arq/categorias/"+cat[cont]+".txt";
                arquivo.open(txt, ios::in);
                while(getline(arquivo,temp)){
                    print.push_back(temp);

                }
                arquivo.close();
            }
        }
        cout<<"RECOMENDADOS: "<<endl;
        for(auto i=print.begin();i<print.end();i+=5){
            //cout<<"CODIGO "<<*i<<endl;
            cout<<"\nProduto "<<*(i+1)<<endl;
            //cout<<"PRECO "<<*(i+2)<<endl;
            //cout<<"QUANT "<<*(i+3)<<endl;
            //cout<<"CATEGORIAS "<<*(i+4)<<endl;
            //cout<<"\n";
        }
    }
}



void Loja::cadastra_cliente(){
    string nome,cpf,email,esc,temp,sociost;
    bool condicao=false;
    size_t cont,tamanho,aux;
    Cliente cliente;
    bool socio;
    vector <string> vetor;
    fstream arquivo("arq/Clientes.txt");
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"\n\n\t============= Cadastro de Clientes =============="<<endl;
    do{
        cout<<"Digite o nome do cliente: ";
        getline(cin,nome);
        //cin>>nome;
        tamanho=nome.size();
        //cout<<"O tamanho eh: "<<tamanho<<endl;
        for(cont=0;cont<tamanho;cont++){
            aux=0;
            if(isdigit(nome[cont])){
                cout<<"Nome invalido!"<<endl;
                aux++;
                break; 
            }
        }
        if(aux==0)
            condicao=true;
    
    }while(condicao==false);
    cliente.set_nome(nome);
    aux=0;
    condicao=false;
    //cin.clear();
    //cin.ignore(10000,'\n');
    do{
        aux=0;
        cout<<"Digite o CPF do cliente: ";
        getline(cin,cpf);
        if(cpf.size()==11){
            for(cont=0;cont<cpf.size();cont++){
                if(isdigit(cpf[cont])){
                    aux++;
                }
            }
            if(aux==cpf.size())
                condicao=true;
            if(aux<cpf.size())
                cout<<"CPF invalido!"<<endl;
        }
        else{
            cout<<"CPF invalido!"<<endl;
        }

    }while(condicao==false);
    
    cliente.set_cpf(cpf);
    aux=0;
    condicao=false;
    //cin.clear();
    //cin.ignore(10000,'\n');
    do{
        aux=0;
        cout<<"Digite o email do Cliente: ";
        getline(cin,email);
        for(cont=0;cont<email.size();cont++){
            if(email[cont]=='@' || email[cont]==' ')
                aux++;
        }
        if(aux!=1){
            cout<<"Email invalido!"<<endl; 
        }
        else{
            condicao=true;
        }
    }while(condicao==false);
    cliente.set_email(email);
    condicao=false;
    //cin.clear();
    //cin.ignore(10000,'\n');
    do{
        cout<<"Quer ser sócio? [s/n]";
        getline(cin,esc);
        if(esc=="s"||esc=="S"){
            socio=true;
            sociost="socio";
            condicao=true;
        }
        else if(esc=="n" || esc=="N"){
            socio=false;
            sociost="visitante";
            condicao=true;
        }
        else
        {
            cout<<"Escolha invalida!"<<endl;
        }
        
        

    }while(condicao==false);
    cliente.set_socio(socio);
    cliente.set_historico("/");
    arquivo.open("arq/Clientes.txt", ios::in);
    while(getline(arquivo,temp))
        vetor.push_back(temp);
    arquivo.close();
    vetor.push_back(cliente.get_cpf());
    vetor.push_back(cliente.get_nome());
    vetor.push_back(cliente.get_email());
    vetor.push_back(sociost);
    vetor.push_back(cliente.get_historico());

    arquivo.open("arq/Clientes.txt",ios::out | ios::app);
    for(auto x=(vetor.begin());x!=(vetor.end());x++){
        arquivo<<*x<<endl;
    }
    arquivo.close();
    vetor.clear();
    
    cout<<"Cliente cadastrado com sucesso!\n\n"<<endl;

}

int Loja::consulta_cliente(string cpf){
    string temp;
    vector <string> vetor;
    int aux=0;
    // cin.clear();
    // cin.ignore(10000,'\n');
    fstream arquivo;
    arquivo.open("arq/Clientes.txt", ios::in);
    while(getline(arquivo,temp)){
        //cout<<"entrou"<<endl;
        vetor.push_back(temp);
        if(vetor[aux]==cpf){
            arquivo.close();
            return aux;
        }
        aux++;
    }
    arquivo.close();
    return -1;
}

bool Loja::consulta_socio(string cpf){
    int posicao=Loja::consulta_cliente(cpf);
    string temp;
    fstream arquivo;
    vector <string> vetor;
    arquivo.open("arq/Clientes.txt", ios::in);
    while(getline(arquivo,temp)){
        vetor.push_back(temp);
    }
    arquivo.close();

    if(vetor[posicao+3]=="socio"){
        //cout<<"vdd";
        return true;
    }
    else{
        return false;
    }
}

void Loja::cupom_fiscal(string nome, string cpf,float preco){
    string temp;
    vector <string> produtos;
    vector <string> aux;
    fstream arquivo;
    arquivo.open("arq/Carrinho.txt",ios::in);
    while(getline(arquivo,temp))
        aux.push_back(temp);
    arquivo.close();
    arquivo.open("arq/CupomFiscal.txt", ios::out | ios::trunc);
    arquivo<<"\t=============== Cupom Fiscal =================="<<endl;
    arquivo<<"\t============== MERCADO DA VICTORIA ============\n\n"<<endl;
    arquivo<<"Cliente: "<<nome<<"           "<<"CPF: "<<cpf<<"\n\n"<<endl;
    for(auto cont=(aux.begin());cont<(aux.end());cont+=5)
        arquivo<<"Produto: "<<*(cont+1)<<"  Preco: "<<*(cont+2)<<"   Quant: "<<*(cont+3)<<endl;
    arquivo<<"\n\n\n";
    arquivo<<"\tPreco Final: "<<preco<<endl;
    arquivo.close();
}

void Loja::modo_balanco(){
    fstream arquivo;
    float temp;
    vector <float> precos;
    float precofinal=0;
    arquivo.open("arq/Balanco.txt", ios::in);
    while(!arquivo.eof()){
        arquivo>>temp;
        precofinal+=temp;
    }

    cout<<"\n\nA quantidade ja vendida ate hoje e: "<<precofinal-temp<<endl;
}