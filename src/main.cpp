#include "ListaProcessos.hpp"
#include "Processo.hpp"
#include "avaliacao_basica_escalonador.hpp"
#include <iostream>
using namespace std;

int main()
{
    ListaProcessos lista;

    int id, prioridade;
    string nome;
    char opcao;

    while (1) {
        cin >> opcao;

        switch (opcao) {
        case 'a':
            cin >> id >> nome >> prioridade;
            lista.adicionar_processo(new Processo(id, nome, prioridade));
            break;
        case 'm':
            lista.remover_processo_maior_prioridade();
            break;
        case 'n':
            lista.remover_processo_menor_prioridade();
            break;
        case 'r':
            cin >> id;
            lista.remover_processo_por_id(id);
            break;
        case 'p':
            lista.imprimir_lista();
            break;
        case 'b':
            avaliacao_basica();
            break;
        }
    }

    return 0;
}
