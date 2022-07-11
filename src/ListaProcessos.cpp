#include <iostream>
#include "ListaProcessos.hpp"
#include "Processo.hpp"
using namespace std;


void ListaProcessos::adicionar_processo(Processo* proc)
{
    
    if (head == nullptr)
    {
        Node *newNode = new Node;
        newNode->data = proc;
        newNode->next = nullptr;
        head = newNode;
    }
    else
    {
        Node *current = head;
        Node *previous = nullptr;
        while (proc->_prioridade < current->data->_prioridade && current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }        

        if (proc->_prioridade > current->data->_prioridade && previous == nullptr)
        {
            Node *aux = new Node;
            aux->data = proc;
            aux->next = current;
            head = aux;
        }
        else if (proc->_prioridade > current->data->_prioridade)
        {
            Node *aux = new Node;
            aux->data = proc;
            aux->next = current;
            previous->next = aux;
        }
        else if (proc->_prioridade == current->data->_prioridade)
        {
            Node *aux = new Node;
            aux->data = proc;
            aux->next = current->next;
            current->next = aux;
        }
        else
        {
            Node *aux = new Node;
            aux->data = proc;
            aux->next = nullptr;
            current->next = aux;
        }
    }
}

Processo* ListaProcessos::remover_processo_maior_prioridade()
{
    Node *temp = head;
    head = temp->next;
    return temp->data;
}

Processo* ListaProcessos::remover_processo_menor_prioridade()
{
    Node *temp = head;
    Node *previous = nullptr;
    while (temp->next != nullptr)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = nullptr;
    return temp->data;
}

Processo* ListaProcessos::remover_processo_por_id(int id)
{
    Node *current = head;
    Node *previous = nullptr;   
    while (current->data->_id != id && current->next != nullptr)
    {
        previous = current;
        current = current->next;
    }
    if (current->next == nullptr)
    {
        return nullptr;
    }
    if (previous == nullptr)
    {
        head = head->next;
        return current->data;
    }
    else
    {
        previous->next = current->next;
        return current->data;
    }
}

void ListaProcessos::imprimir_lista()
{
    Node *temp = head;
    while (temp != nullptr)
    {   
        temp->data->imprimir_dados();
        temp = temp->next;
    }
}