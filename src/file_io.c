#include <stdio.h> //For fopen()
#include <stdbool.h> // For boolean type
#include "list.h" //For list instance
#include "task.h" //For task instance
#include "file_io.h" //public API


bool save_list_to_csv(List* list, const char* filename){

    //Creating the file with write (w) mode,
    //Where all the information is updated
    FILE* file = fopen(filename, "w"); 

    //Checking if the file opened correctly
    if (file == NULL){
        fprintf(stderr, "ERROR : in save_list_to_csv() : couldn't open file.\n");
        return false;
    }

    //Header of the file
    int header = fprintf(file, "id,priority,deadline,name,description\n");

    //Checking valid header
    if (header < 0){
        fprintf(stderr, "ERROR : in save_list_to_csv() : couldn't write header.\n");
        fclose(file);
        return false;
    }

    //iterating the list and writing it
    Task* current = list->head; //getting the first task

    //checking list existance
    if (current == NULL){
        fprintf(stderr, "ERROR : in save_list_to_csv() : failed to acces list.\n");
        fclose(file);
        return false;
    }

    //saving the task
    while(current){
        fprintf(file, "%d,%d,%ld,\"%s\",\"%s\"\n", current->id, current->priority, current->deadline, current->name, current->description);
        current = current->next; //updating the task saved
    }
    
    fprintf(stderr, "INFO : save_list_to_csv() saved full list succesfully.\n");
    return true;
    
}