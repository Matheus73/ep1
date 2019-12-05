#include "Pessoa.hpp"
#include <iostream>
using namespace std;

Pessoa::Pessoa(){

}

Pessoa::~Pessoa(){}

void Pessoa::set_nome(string nome){
    this -> nome=nome;
}

string Pessoa::get_nome(){
    return nome;
}

void Pessoa::set_cpf(string cpf){
    this -> cpf=cpf;
}

string Pessoa::get_cpf(){
    return cpf;
}

void Pessoa::set_email(string email){
    this-> email=email;
}

string Pessoa::get_email(){
    return email;
}
