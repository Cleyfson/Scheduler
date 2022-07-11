#ifndef LISTAPROCESSOS_HPP
#define LISTAPROCESSOS_HPP

#include "Processo.hpp"

struct Node
{
    Processo *data;
    Node *next;

    Node(){
        next = nullptr;
    }
};

struct ListaProcessos
{
    Node *head = nullptr;

    void adicionar_processo(Processo* proc);
    Processo* remover_processo_maior_prioridade();
    Processo* remover_processo_menor_prioridade();
    Processo* remover_processo_por_id(int id);
    void imprimir_lista();
};




#endif
