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


#endif