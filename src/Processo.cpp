#include <iostream>
#include "Processo.hpp"
using namespace std;

Processo::Processo()
{
    this->_id = 0;
    this->_nome = "";
    this->_prioridade = 0;
}


Processo::Processo(int id, string nome, int prioridade)
{
    this->_id = id;
    this->_nome = nome;
    this->_prioridade = prioridade;
}

void Processo::imprimir_dados()
{
    cout << this->_id << " ";
    cout << this->_nome << " ";
    cout << this->_prioridade << "\n";
}