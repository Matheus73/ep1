#include "Produto.hpp"
#include <iostream>

using namespace std;

Produto::Produto(){
}
Produto::~Produto(){
}
Produto::Produto(string codigo,string nome, string quantidade,string preco, string categoria){
    set_nome(nome);
    set_preco(preco);
    set_quantidade(quantidade);
    set_codigo(codigo);
    set_categoria(categoria);
}
void Produto::set_codigo(string codigo){
    this -> codigo=codigo;
}

string Produto::get_codigo(){
    return codigo;
}

void Produto::set_nome(string nome){
    this -> nome = nome;
}

string Produto::get_nome(){
    return nome;
}

void Produto::set_preco(string preco){
    this->preco=preco;
}

string Produto::get_preco(){
    return preco;
}

void Produto::set_quantidade(string quantidade){
    this-> quantidade=quantidade;
}

string Produto::get_quantidade(){
    return quantidade;
}

void Produto::set_categoria(string categoria){
    this->categoria=categoria;
}

string Produto::get_categoria(){
    return categoria;
}

