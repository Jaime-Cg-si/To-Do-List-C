#include <stdio.h> // For fprintf()
#include <stdlib.h> //For malloc() and free()
#include <string.h> //For strcpy()
#include "task.h" //Our public API
#include <time.h> //For time()

#define MIN_PRIORITY 1
#define MAX_PRIORITY 5


/**
@brief Implementation of the create_task() function
*/

Task* create_task(int id, const char* name, const char* description, time_t deadline, int priority){

    Task* new_task = (Task*) malloc(sizeof(Task)); //Allocates memory for the new task

    if (new_task == NULL){
        //malloc() failed
        return NULL;
    }

    /*
    To insert the task's name, first we need to allocate space for the string
    and the '\0' character. Then, we use strcpy
    */
    new_task->name = (char*) malloc(sizeof(char) * (strlen(name)+1));

    if (new_task->name == NULL){
        free(new_task);
        return NULL;
    }

    strcpy(new_task->name, name);

    /*
    We use the same procedure in the task description
    */

    new_task->description = (char*) malloc(sizeof(char) * (strlen(description)+1));

    if (new_task->description == NULL){
        free(new_task->name);
        free(new_task);
        return NULL;
    }
    
    strcpy(new_task->description, description);

    //Dealing with the direct parameters
    new_task->id = id;
    new_task->deadline = deadline;
    new_task->priority = priority;
    new_task->next = NULL;

    if (is_task_valid(new_task) == false){
        fprintf(stderr, "ERROR : in create_task(): New task invalid.\n");
        destroy_task(&new_task);
        return NULL;
    }

    return new_task;
}

/**
 @brief Implementation of the create_default_task()
*/

Task* create_default_task(const char* task_name){

    if (task_name == NULL){
        fprintf(stderr, "ERROR : in create_default_task() : Invalid task name.\n");
        return NULL;
    }

    Task* new_task = (Task*) malloc(sizeof(Task)); //Allocating memory for the new task
    
    new_task->name = (char*) malloc(sizeof(char) * (strlen(task_name)+1)); //Adding the task name
    strcpy(new_task->name, task_name);

    new_task-> description = (char*) malloc(sizeof(char)* (strlen(task_name)+1)); //Adding task description
    strcpy(new_task->description, task_name);

    new_task->priority = 3; //Adding task priority
    new_task->id = 0; //Adding task id

    time_t now = time(NULL);
    new_task->deadline = now + (24 * 60 * 60); //Adding task deadline

    new_task->next = NULL;

    return new_task;
}

/**
@brief Implementation of the is_task_valid() function
*/

bool is_task_valid(const Task* task){

    if (task == NULL){
        return false;
    }

    if (task->id < 0 || task->name == NULL || task->description == NULL) {
        return false;
    }

    if (task->priority < MIN_PRIORITY || task->priority > MAX_PRIORITY) {
        return false;
    }

    time_t now = time(NULL);
    if (task->deadline < now) {
        return false;
    }

    return true;
}

/**
@brief Implementation of the destroy_task() function
*/
void destroy_task(Task** task_ptr){

    if (task_ptr == NULL || *task_ptr == NULL){
        //invalid parameter
        return;
    }

    Task* task = *task_ptr;
    free(task->description);
    free(task->name);
    free(task);
    *task_ptr = NULL;
}

/**
@brief Implementation of the set_task_name() function
*/
void set_task_name(Task* task, const char* name){

    if (task == NULL || name == NULL){
        //invalid parameter
        return;
    }

    if ( task->name != NULL && strcmp(task->name, name) == 0){
        //the new name and the old names are the same 
        return;
    }

    char* new_name = (char*) malloc(sizeof(char) * (strlen(name)+1)); //creating the new name string

    if (new_name == NULL){
        return;
    }

    strcpy(new_name, name);

    free (task->name); //cleaning the old name
    task->name = new_name;
}

/**
@brief Implementation of the set_task_priority() function
*/

void set_task_priority(Task* task, int priority){

    if (task == NULL){
        //Invalid parameter
        fprintf(stderr, "ERROR: in set_task_priority(): Received a null task pointer\n");
        return;
    }

    if (priority < MIN_PRIORITY || priority > MAX_PRIORITY){
        fprintf(stderr, "ERROR: in set_task_priority(): priority level %d out of range [%d - %d]\n", priority, MIN_PRIORITY, MAX_PRIORITY);
        return;
    }

    task->priority = priority;
}

/**
@brief Implementation of the set_task_description() funciton 
*/

void set_task_description(Task* task, const char* description){

    if (task == NULL || description == NULL){
        fprintf(stderr, "ERROR: in set_task_description() : one of the parameters is NULL \n");
    }

    if (task->description && (strcmp(task->description, description) == 0)){
        return;
    }

    char* new_description = (char*) malloc(sizeof(char) * (strlen(description) + 1));

    if (new_description == NULL){
        fprintf(stderr, "ERROR: in set_task_description() : failed to allocate memory for the new description\n");
        return;
    }
    strcpy(new_description, description);

    free(task->description);
    task->description = new_description;

}

/**
@brief Implementation of the set_task_deadline() function
*/
void set_task_deadline(Task* task, time_t deadline){

    if (task == NULL){
        fprintf(stderr, "ERROR: in set_task_deadline(): task parameter NULL\n");
        return;
    }

    time_t now = time(NULL);

    if (deadline < now){
        fprintf(stderr, "ERROR: in set_task_deadline(): deadline in the past.\n");
        return;
    }

    task->deadline = deadline;
}

/**
@brief Implementation of the print_task() funciton
*/

void print_task(const Task* task){

    if (task == NULL){
        return;
    }

    printf("----------------------------------------\n");
    printf("Task id : %d\n", task->id);
    printf("Name: %s\n", task->name);
    printf("Description: %s\n", task->description);
    printf("Task Priority: %d\n", task->priority);
    printf("----------------------------------------\n");

}