// main.c

#include <stdio.h>
#include "list.h" // Precisa saber o que é uma 'List' para criá-la
#include "cli.h"  // Precisa saber da existência de 'cli_start'

int main() {
    // 1. O "Gerente Geral" cria o recurso principal.
    List* task_list = list_create();

    if (task_list == NULL) {
        fprintf(stderr, "Falha crítica: não foi possível alocar memória para a lista.\n");
        return 1; // Retorna um código de erro
    }

    // 2. O "Gerente Geral" delega o trabalho para o "Especialista em CLI",
    //    passando o recurso (a lista) para ele trabalhar.
    cli_start(task_list);

    // 3. Após o cli_start terminar (por causa do 'exit' ou Ctrl+D),
    //    o programa termina. A limpeza da memória (list_destroy) é feita
    //    DENTRO do cli_start, no comando 'exit'.
    
    return 0; // Sucesso
}