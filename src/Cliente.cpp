#include <iostream>
#include <fstream>
#include "Cliente.hpp"
#include "Pessoa.hpp"

fstream arquivo;

using namespace std;
Cliente::Cliente(){
}

Cliente::Cliente(string nome,string cpf,string email,bool socio,string historico){
    set_nome(nome);
    set_cpf(cpf);
    set_email(email);
    set_socio(socio);
    set_historico(historico);
}


Cliente::~Cliente(){
}

void Cliente::set_socio(bool socio){
    this->socio=socio;
}

Cliente::Cliente(int posicao){
    string temp;
    vector <string> vetor;
    fstream arquivo;
    arquivo.open("arq/Clientes.txt", ios::in);
    while(getline(arquivo,temp)){
        vetor.push_back(temp);
    }

    set_cpf(vetor[posicao]);
    set_nome(vetor[posicao+1]);
    set_email(vetor[posicao+2]);
    if(vetor[posicao+3]=="socio"){
        set_socio(true);
    }
    else{
        set_socio(false);
    }   
    set_historico(vetor[posicao+4]);

    arquivo.close();
}

bool Cliente::get_socio(){
    return socio;
}

void Cliente::set_historico(string his){
    this->historico=historico+his;
}

string Cliente::get_historico(){
    return historico;
}
