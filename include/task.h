#ifndef TASK_MANAGER_TASK_H_
#define TASK_MANAGER_TASK_H_

/*
task.h is the header file designed to include the signatures of
all the functions related to the CRUD (Create, Read, Update, Destroy) principle
applied to the task structure.
*/

#include <time.h> // For the time_t type used in deadline 
#include <stdbool.h> //For the is_task_valid function


/*
Define Struct for a single Task, to be later on manipulated
*/

typedef struct task{
    int id; // unique identifier for the task
    char* name; //name of the task given by user
    char* description; //brief description of the task
    time_t deadline; //task deadline
    int priority; //task priority
    struct task* next; //pointer to the next task

}Task;

//Functions prototype for the public API

/*
Creates a new Task.
Parameters:
id - the unique id every task must have
name - name of the task
description - description of the task
deadline - deadline of the task
priority - level of priority of the task
In case the function successfully creates a task,
it shall return a pointer to it. Otherwise, it returns NULL
*/

Task* create_task(int id, const char* name, const char* description, time_t deadline, int priority);

/*
Creates a deafult Task.
Parameters:
task_name - name of the task
Return : returns a pointer to the task
By default, it sets the tasks instances as:
id = 0;
priority = 3
deadline = 1 day
description = same as name
*/

Task* create_default_task(const char* task_name);

/*
Verify if a task is or not valid.
Parameters:
task - pointer to task to be evaluated
Return : true, if it is valid
false, otherwise
*/

bool is_task_valid(const Task* task);

/*
Destroy a task and free its memory.
Parameters:
task_ptr - pointer to pointer to task to be destroyed
*/

void destroy_task(Task** task_ptr);

/*
Set the name of a task.
Parameter:
task - pointer to task to be named
name - name of the task
*/

void set_task_name(Task* task, const char* name);

/*
Set task priority level.
Parameters:
task - pointer to task 
priority - integer corresponding to the priority level
*/

void set_task_priority(Task* task, int priority);

/*
Set task description.
Parameters:
task - pointer to task
description - the description to be set to the task
*/

void set_task_description(Task* task, const char* description);

/*
Set task deadline.
Parameters:
task - pointer to task
deadline - the deadline of the task
*/

void set_task_deadline(Task* task, time_t deadline);

/*
Print a task instance.
Parameters:
task - task to be printed
*/

void print_task(const Task* task);

#endif //TASK_MANAGER_TASK_H_