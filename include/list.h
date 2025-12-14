#ifndef TASK_MANAGER_LIST_H_
#define TASK_MANAGER_LIST_H_

#include <stdbool.h> //For list_remove_task()
#include "task.h" //For Task instance

/**
 * @file list.h
 * @brief Header file for the linked list module.
 *
 * Defines the List data structure and the public API for creating,
 * destroying, and manipulating the list of tasks.
 */

/**
 * @brief Defines the main structure for the task list.
 */

typedef struct List{
    Task* head; //pointer to the first task on the list
    int size; //number of tasks on the list
}List;

// --- Public API Function Prototypes ---

// --- List Lifecycle Functions ---

/**
 @brief Creates a new list.
 @return Returns a pointer to the list
 */

List* list_create();

/**
 @brief Destroyes a List
 @param list_ptr pointer to the list to be destoyed
*/

void list_destroy(List** list_ptr);

// --- List Data Access Functions ---

/**
 @brief Gets list's size
 @param list the list desired to be measured
 @return Size of the list
*/
int list_get_size(const List* list);

/**
 @brief Prints a full list
 @param list list to be printed
*/
void list_print(const List* list);

/**
 @brief Finds a task in a list
 @param list List of tasks
 @param task_id Id of the task searched
 @return Returns a pointer to the task
*/
Task* list_find_task(const List* list, int task_id);

// --- List Modification Functions ---

/**
 @brief Adds a task to a list
 @param list List of tasks
 @param task Task to be added
*/
void list_add_task(List* list, Task* task);

/**
 @brief Removes a task from a list
 @param list List of tasks
 @param task_id Id of task to be removed
 @return true, if succesfully removed
*/
bool list_remove_task(List* list, int task_id);


#endif //TASK_MANAGER_LIST_H_