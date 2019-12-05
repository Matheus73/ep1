#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Pessoa {
private:
    string nome;
    string cpf;
    vector <int> historico;
    string email;

public:
    Pessoa();
    ~Pessoa();
    void set_nome(string nome);
    string get_nome();
    void set_cpf(string cpf);
    string get_cpf();
    void set_email(string email);
    string get_email();
    //virtual int abs()=0;

    
};

#endif
