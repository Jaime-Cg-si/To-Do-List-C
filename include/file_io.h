#ifndef FILE_IO_H
#define FILE_IO_H

#include "list.h" //for list instance
#include <stdbool.h> // for boolean type

/**
 @brief Saves a taask list to a CSV file
 @param list task list
 @param filename name of the file where the list will be saved
 @return true if the file was succesfully saved, false otherwise
*/

bool save_list_to_csv(List* list, const char* filename);

/**
 @brief Uploads a task list from a csv file into the RAM
 @param filename name of the file where the list is saved
 @param list list which will receive all the tasks saved
 @return true if succesfully uploaded, false otherwise*
*/

bool load_list_from_csv(const char* filename, List* list);

#endif