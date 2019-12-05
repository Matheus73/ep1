#ifndef LOJA_HPP
#define LOJA_HPP
#include <string>
#include "Cliente.hpp"
using namespace std;
class Loja{
public:
    static void modo_venda();
    static void modo_estoque(); //ok
    static void modo_recomendacao();
    static void cadastra_cliente(); //ok
    static bool consulta_socio(string cpf);
    static int consulta_cliente(string cpf); //pk
    static void cupom_fiscal(string nome,string cpf,float preco);
    static void modo_balanco();
    virtual int abs()=0;

};


#endif
