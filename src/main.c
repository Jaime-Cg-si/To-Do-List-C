// src/main.c - Nosso Programa de Teste

#include <stdio.h>
#include "task.h" // Inclui a API do nosso módulo Task

int main() {
    printf("--- Iniciando Testes do Módulo Task ---\n\n");

    // --- Teste 1: Criação de Tarefa Válida ---
    printf("--- Teste 1: Tentando criar uma tarefa válida...\n");
    Task* task1 = create_task(1, "Estudar Ponteiros em C", "Revisar o capítulo 5 do livro K&R.", time(NULL) + 86400, 3); // Deadline para amanhã

    if (task1 != NULL) {
        printf("SUCESSO: Tarefa 1 criada.\n");
        printf("  ID: %d\n", task1->id);
        printf("  Nome: %s\n", task1->name);
        printf("  Prioridade: %d\n", task1->priority);
    } else {
        fprintf(stderr, "FALHA: create_task retornou NULL para uma tarefa válida.\n");
    }
    printf("\n");

    // --- Teste 2: Tentando criar uma tarefa inválida (prioridade errada) ---
    printf("--- Teste 2: Tentando criar uma tarefa com prioridade inválida...\n");
    Task* task2 = create_task(2, "Tarefa Inválida", "Teste com prioridade 99.", time(NULL), 99);

    if (task2 == NULL) {
        printf("SUCESSO: create_task corretamente retornou NULL para prioridade inválida.\n");
    } else {
        fprintf(stderr, "FALHA: Tarefa com prioridade inválida foi criada!\n");
        destroy_task(&task2); // Limpa a sujeira se o teste falhar
    }
    printf("\n");

    // --- Teste 3: Modificando uma tarefa existente (Update) ---
    printf("--- Teste 3: Modificando o nome da Tarefa 1...\n");
    if (task1 != NULL) {
        printf("  Nome antigo: %s\n", task1->name);
        set_task_name(task1, "Estudar Gerenciamento de Memória em C AVANÇADO");
        printf("  Novo nome: %s\n", task1->name);
    }
    printf("\n");

    // --- Teste 4: Destruindo uma tarefa (Delete) ---
    printf("--- Teste 4: Destruindo a Tarefa 1...\n");
    destroy_task(&task1);

    if (task1 == NULL) {
        printf("SUCESSO: O ponteiro da Tarefa 1 agora é NULL após a destruição.\n");
    } else {
        fprintf(stderr, "FALHA: O ponteiro da Tarefa 1 NÃO é NULL após destroy_task.\n");
    }
    printf("\n");

    printf("--- Testes do Módulo Task Concluídos ---\n");

    return 0; // Indica que o programa terminou com sucesso
}