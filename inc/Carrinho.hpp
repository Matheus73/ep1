#ifndef CARRINHO_HPP
#define CARRINHO_HPP
#include <iostream>
#include <string>
#include "Cliente.hpp"
using namespace std;
class Carrinho{
public:
    static void adiciona_carrinho(string codigo, int quantidade,Cliente cliente); //ok
    static void lista_carrinho(); //ok
    static float preco_carrinho();//ok
    static void limpa_carrinho(); //ok
    static int consulta_categorias(string txt);
    virtual void abs()=0;

};


#endif