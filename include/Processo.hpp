#ifndef PROCESSO_HPP
#define PROCESSO_HPP


#include <iostream>
using namespace std;

struct Processo
{
    int _id;
    int _prioridade;
    string _nome;

    Processo();
    Processo(int id, string nome, int prioridade);
    void imprimir_dados();
};

#endif










