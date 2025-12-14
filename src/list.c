#include <stdio.h> //For fprintf()
#include <errno.h> //For perror
#include "list.h" //Public API
#include <stdlib.h> //For malloc() and free()



/**
 @brief Implementation of list_create()
*/

List* list_create(){

    List* new_list = (List*) malloc(sizeof(List));

    if (new_list == NULL){
        perror("ERROR : in list_create()");
        return NULL;
    }

    //Initial attributions
    new_list->head = NULL;
    new_list->size = 0;

    return new_list;
}

/**
 @brief Implementation of list_destroy()
*/

void list_destroy(List** list_ptr){

    if (list_ptr == NULL || (*list_ptr) == NULL){
        fprintf(stderr, "ERROR : in list_destroy() : invalid parameter\n");
        return;
    }

    List* list = *list_ptr; //Accessing the list itself

    Task* current = list->head; //list iterator to iterate around the list

    while (current != NULL){

        Task* next = current->next; //Saves the next task address
        destroy_task(&current);
        current = next;
    }

    free(list);
    *list_ptr = NULL;

}

/**
 @brief Implementation of list_add_task()
*/

void list_add_task(List* list, Task* task){

    if (list == NULL || task == NULL){
        fprintf(stderr, "ERROR : in list_add_task() : invalid parameter.\n");
        return;
    }

    /*To efficiency purposes, list_add_task()
    shall add a new task always on the beggining*/

    task->next = list->head; //Connecting the new task with the previous list
    list->head = task; //Connecting the list with the new task
    list->size++; //Adjusting the list's size

}

/**
 @brief Implementation of list_get_size()
*/

int list_get_size(const List* list){

    if (list == NULL){
        fprintf(stderr, "ERROR : in list_get_size() : invalid parameter.\n");
        return -1;
    }

    return list->size;
}

/**
 @brief Implementation of list_print()
*/

void list_print(const List* list){

    if (list == NULL){
        fprintf(stderr, "ERROR : In list_print() : Invalid parameter.\n");
        return;
    }

    Task* current = list->head;

    while (current){

        print_task(current);
        current = current->next;
    }

}

/**
 @brief Implementation of list_find_task()
*/

Task* list_find_task(const List* list, int task_id){

    if (list == NULL || task_id < 0){
        fprintf(stderr, "ERROR : in list_find_task() : invalid parameter.\n");
        return NULL;
    }

    Task* current = list->head;

    while (current){

        if (current->id == task_id){ 
            return current;
        }

        current = current->next;
    }

    return NULL;
}

/**
 @brief Implementation of list_remove_task()
*/

bool list_remove_task(List* list, int task_id){

    if (list == NULL || task_id < 0){
        fprintf(stderr, "ERROR : in list_remove_task() : Invalid parameter.\n");
        return false;
    }

    if (list->head == NULL){
        fprintf(stderr, "INFO : in list_remove_task() : Empty list cannot have an element removed.\n");
        return false;
    }

    Task* previous = NULL;
    Task* current = list->head;

    while (current != NULL && current->id != task_id){
        previous = current;
        current = current->next;
    }

    //Case 1 - The task did not exist
    if (current == NULL){
        fprintf(stderr, "INFO : in list_remove_task() : Could not find task with id : %d.\n", task_id);
        return false;
    }
    

    //Case 2 - The task to be removed is the first one

    if (previous == NULL){

        list->head = current->next;

    }

    //Case 3 - The task to be removed is an internal task

    else{
        previous->next = current->next;
    }

    destroy_task(&current);
    list->size--;
    return true;

}