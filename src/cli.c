#include "cli.h" //Public API
#include "list.h" //For create_list(), list_add_task()
#include <stdbool.h> //For cli_start()
#include <string.h> // For strcmp(), strncmp()



/**
 @brief Implementation of the cli_start()
*/


void cli_start(){

    bool program_on = true;
    char input_buffer[256];

    while (program_on != false){

        fgets(input_buffer, 256, stdin) //Receive user's input


        //Adapting the input to compare it in the future
        char* current = input_buffer;

        while ((*current) != '\n' && (*current) != '\0'){
            current++;
        }

        *current = '\0';

        //Checking if the user wants to leave
        if (strcmp(input_buffer, "exit") == 0){
            program_on = false;
            break;
        }

        //Checking for "help"
        else if (strcmp(input_buffer, "help") == 0){

            printf("--- TASK MANAGER MENU ---\n\n");

            printf("Description of the system's command: \n");
            printf("list : lists all of the tasks on the list\n");
            printf("add : adds a new default task to the list\n");
            printf("remove : removes a task from the list\n");
            printf("help : opens the task manager menu\n");
            printf("exit : exits the program\n");
            printf("--- (END OF) TASK MANAGER MENU ---\n\n");

        }

        //Checking for add

        else if (strncmp(input_buffer, "add ", 4) == 0){

            //Adding a task to the list
            list_add_task(list, input_buffer+4);

        }

    }
}