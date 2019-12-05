#include <iostream>

using namespace std;

class Estoque{
public:
    static void cadastra_produto(); //ok 
    static void subtrai_estoque(int quant,int posicao); //ok
    static void adiciona_estoque(int quant,int posicao);//ok
    static int consulta_produto(); //ok 
    static int consulta_produto(string codigo); //ok
    static int consulta_estoque(string codigo); //ok
    static void lista_produtos(); //ok
    virtual void abs()=0;
};
