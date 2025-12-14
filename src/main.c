// src/main.c - Programa de Teste COMPLETO para o Módulo List

#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "list.h"

int main() {
    printf("--- Iniciando Testes do Módulo List ---\n\n");

    // --- Teste 1: Criação e verificação de lista vazia ---
    printf("--- Teste 1: Criação de uma lista vazia...\n");
    List* minha_lista = list_create();
    if (minha_lista == NULL) {
        fprintf(stderr, "FALHA CRÍTICA: list_create() retornou NULL.\n");
        return EXIT_FAILURE;
    }
    printf("SUCESSO: list_create() retornou um ponteiro válido.\n\n");

    // --- Teste 2: Adicionando tarefas ---
    printf("--- Teste 2: Adicionando 3 tarefas à lista...\n");
    // Lembre-se: nossa função adiciona no INÍCIO, então a ordem será 3 -> 2 -> 1
    list_add_task(minha_lista, create_task(1, "Estudar Ponteiros", "Capítulo 5", time(NULL), 1));
    list_add_task(minha_lista, create_task(2, "Implementar a Lista", "Exercício de C", time(NULL), 2));
    list_add_task(minha_lista, create_task(3, "Testar a Lista", "Escrever o main.c", time(NULL), 3));
    printf("SUCESSO: 3 tarefas adicionadas.\n\n");

    // --- Teste 3: Verificando o tamanho e imprimindo ---
    printf("--- Teste 3: Verificando tamanho e imprimindo a lista completa...\n");
    if (list_get_size(minha_lista) == 3) {
        printf("SUCESSO: O tamanho da lista é 3.\n");
    } else {
        fprintf(stderr, "FALHA: O tamanho da lista é %d, mas deveria ser 3.\n", list_get_size(minha_lista));
    }
    printf("  Estado atual da lista (deve ser 3, 2, 1):\n");
    list_print(minha_lista);
    printf("\n");

    // --- Teste 4: Buscando tarefas ---
    printf("--- Teste 4: Buscando tarefas...\n");
    Task* found_task = list_find_task(minha_lista, 2);
    if (found_task != NULL) {
        printf("SUCESSO: Tarefa com ID 2 encontrada. Nome: '%s'\n", found_task->name);
    } else {
        fprintf(stderr, "FALHA: Não foi possível encontrar a tarefa com ID 2.\n");
    }
    Task* not_found_task = list_find_task(minha_lista, 99);
    if (not_found_task == NULL) {
        printf("SUCESSO: A busca por uma tarefa inexistente (ID 99) corretamente retornou NULL.\n");
    } else {
        fprintf(stderr, "FALHA: A busca por uma tarefa inexistente retornou um ponteiro válido!\n");
    }
    printf("\n");

    // --- Teste 5: Removendo uma tarefa do MEIO (ID 2) ---
    printf("--- Teste 5: Removendo uma tarefa do MEIO (ID 2)...\n");
    bool success = list_remove_task(minha_lista, 2);
    if (success) {
        printf("SUCESSO: list_remove_task retornou true.\n");
        printf("  Novo tamanho da lista: %d\n", list_get_size(minha_lista));
        printf("  Estado atual da lista (deve ser 3, 1):\n");
        list_print(minha_lista);
    } else {
        fprintf(stderr, "FALHA: list_remove_task retornou false ao tentar remover o ID 2.\n");
    }
    printf("\n");

    // --- Teste 6: Removendo a tarefa da CABEÇA (ID 3, que agora é a cabeça) ---
    printf("--- Teste 6: Removendo a tarefa da CABEÇA (ID 3)...\n");
    success = list_remove_task(minha_lista, 3);
    if (success) {
        printf("SUCESSO: list_remove_task retornou true.\n");
        printf("  Novo tamanho da lista: %d\n", list_get_size(minha_lista));
        printf("  Estado atual da lista (deve ser 1):\n");
        list_print(minha_lista);
    } else {
        fprintf(stderr, "FALHA: list_remove_task retornou false ao tentar remover o ID 3.\n");
    }
    printf("\n");

    // --- Teste 7: Removendo a tarefa da CAUDA (ID 1, que agora é a única) ---
    printf("--- Teste 7: Removendo a tarefa da CAUDA (ID 1)...\n");
    success = list_remove_task(minha_lista, 1);
    if (success) {
        printf("SUCESSO: list_remove_task retornou true.\n");
        printf("  Novo tamanho da lista: %d\n", list_get_size(minha_lista));
        printf("  Estado atual da lista (deve estar vazia):\n");
        list_print(minha_lista);
    } else {
        fprintf(stderr, "FALHA: list_remove_task retornou false ao tentar remover o ID 1.\n");
    }
    printf("\n");

    // --- Teste 8: Tentando remover tarefa que não existe ---
    printf("--- Teste 8: Tentando remover tarefa que não existe (ID 99)...\n");
    success = list_remove_task(minha_lista, 99);
    if (!success) {
        printf("SUCESSO: list_remove_task corretamente retornou false para uma tarefa inexistente.\n");
    } else {
        fprintf(stderr, "FALHA: list_remove_task retornou true para uma tarefa inexistente!\n");
    }
    printf("\n");
    
    // --- Teste Final: Destruição da lista ---
    printf("--- Teste Final: Destruindo a lista (agora vazia)...\n");
    list_destroy(&minha_lista);
    if (minha_lista == NULL) {
        printf("SUCESSO: O ponteiro da lista é NULL após a destruição final.\n");
    } else {
        fprintf(stderr, "FALHA: O ponteiro da lista NÃO é NULL após a destruição final.\n");
    }
    printf("\n");

    printf("--- TODOS OS TESTES DO MÓDULO LIST FORAM CONCLUÍDOS COM SUCESSO ---\n");
    return EXIT_SUCCESS;
}