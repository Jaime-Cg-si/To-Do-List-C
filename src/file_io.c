#include <stdio.h> //For fopen(), fgets()
#include <stdbool.h> // For boolean type
#include "list.h" //For list instance
#include "task.h" //For task instance
#include "file_io.h" //public API

/**
 @brief implementation of save_list_to_csv()
*/
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

/** 
 @brief Implementation of load_list_from_csv()
*/

bool load_list_from_csv(const char* filename, List* list){

    FILE* file = fopen(filename, "r"); //opening the file

    //Checking if the file exists
    if (file == NULL){
        fprintf(stderr, "INFO : in load_list_from_csv() : There is no file to update from.\n");
        return true;
    }

    char line_buffer[256]; // necessary for parsing the file

    char* header = fgets(line_buffer, 256, file); //reading the header of the file

    if (header == NULL){
        fprintf(stderr, "ERROR : in load_list_from_csv() : failed to read the file's header.\n");
        fclose(file);
        return false;
    }

    
    //uploading the list
    while(fgets(line_buffer, sizeof(line_buffer), file) != NULL){ //while there are tasks to upload
       
       //uploading the tasks instances
        int id, priority;
        time_t deadline;
        char name[256];
        char description[256];
        sscanf(line_buffer, "%d,%d,%ld,\"%255[^\"]\",\"%255[^\"]\"", &id, &priority, &deadline, name, description);

        //creating a new task
        Task* current_task = create_task(id, name, description, deadline, priority);

        //adding it to the list
        list_add_task_from_task(list, current_task);

    }
    return true;

}
