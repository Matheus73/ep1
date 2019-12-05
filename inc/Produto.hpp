#ifndef PRODUTO_HPP
#define PRODUTO_HPP
#include <string>
using namespace std;
class Produto{
private:
    string codigo;
    string nome;
    string categoria;
    string quantidade;
    string preco;


public:
    Produto();
    Produto(string codigo,string nome,string categoria,string preco,string quantidade);
    ~Produto();
    //Métodos do código
    void set_codigo(string codigo);
    string get_codigo();

    //Método do nome
    void set_nome(string nome);
    string get_nome();
    
    //Método da categoria
    void set_categoria(string categoria);
    string get_categoria();

    //Métodos da quantidade
    void set_quantidade(string quantidade);
    string get_quantidade();

    //Métodos do preço
    void set_preco(string preco);
    string get_preco();





};

#endif
