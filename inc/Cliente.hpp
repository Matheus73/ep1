#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>
#include "Pessoa.hpp"
using namespace std;

class Cliente : public Pessoa{
private: 
    bool socio;
    string historico;
public:
    Cliente();
    ~Cliente();
    Cliente(string nome,string cpf,string email,bool socio,string historico);
    Cliente(int posicao);
    void set_socio(bool socio);
    bool get_socio();
    void set_historico(string historico);
    string get_historico();
};
#endif
