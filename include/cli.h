#ifndef CLI_H
#define CLI_H

#include "list.h" 
#include <stdbool.h> 
#include <string.h> 
#include <stdio.h>

/**
 @brief Starts and runs the cli
 @param list the list of tasks
*/

void cli_start(List* list);

#endif