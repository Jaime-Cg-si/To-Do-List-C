#include "cli.h" // public api
#include "file_io.h" // for save_list_to_csv()
/**
 @brief Implementation of remove_newline()
 @param str - pointer to the first letter of the string
 */

 void remove_newline(char* str){
    //finds the '\n' and changes for '\0'
    str[strcspn(str, "\n")] = '\0';
 }

/**
 @brief Implementation of the cli_start()
*/


void cli_start(List* list){

    bool program_on = true;

    //uploading the previous tasks
    bool check_upload = load_list_from_csv("tasks.csv", list);

    //checking if the program succesfully uploaded
    if (!check_upload){
        fprintf(stderr, "ERROR : in cli_start() : failed to upload file.\n");
    }

    char input_buffer[256];

    while (program_on != false){
        printf(">>>");
        fgets(input_buffer, 256, stdin); //Receive user's input
        remove_newline(input_buffer);



        //Checking if the user wants to leave
        if (strcmp(input_buffer, "exit") == 0){
            program_on = false;
            bool list_save = save_list_to_csv(list, "tasks.csv");

            if (list_save == false){
                fprintf(stderr, "ERROR : in cli_start() : failed to save tasks.\n");
            }

            list_destroy(&list);
            break;
        }

        //Checking for "help"
        else if (strcmp(input_buffer, "help") == 0){

            printf("--- TASK MANAGER MENU ---\n\n");

            printf("Description of the system's command: \n");
            printf("list : lists all of the tasks on the list\n");
            printf("add : adds a new default task to the list\n");
            printf("edit <task_id> <task_instance> : edits a task instance\n");
            printf("remove : removes a task from the list\n");
            printf("help : opens the task manager menu\n");
            printf("exit : exits the program\n");
            printf("--- (END OF) TASK MANAGER MENU ---\n\n");

        }

        //Input : add

        else if (strncmp(input_buffer, "add ", 4) == 0){

            const char* task_name = strstr(input_buffer, "add");

            task_name += 4;

            if (*task_name != '\0' && *task_name != ' '){
                list_add_task(list, task_name);
            }
            else{
                fprintf(stderr, "ERROR : in cli_start() : invalid task name.\n");
            }

        }// end add

        //Input : edit

        else if(strncmp(input_buffer, "edit ", 5) == 0){
            int task_id = -1; //Initializing with invalid value

            int read_values = sscanf(input_buffer, "%*s %d", &task_id); //sscanf() will return 1 if successfully read the string integer

            if (read_values == 1){

                //task_id now contains the users task_id input
                fprintf(stderr, "INFO : in cli_star() : edit command read task_id as : %d\n", task_id);

                //finding the task
                Task* task = list_find_task(list, task_id);

                if (task != NULL){
                    fprintf(stderr, "Task %s (ID : %d) succesfully found and ready to be edited\n", task->name, task->id);

                    //Searching for what parameter does the user wants to edit

                    //name
                    if (strstr(input_buffer, "name") != NULL){

                        const char* name_ptr = strstr(input_buffer, "name");

                        name_ptr +=4; //skiping "name "

                        while (*name_ptr == ' '){
                            //blank space
                            name_ptr++;
                        }

                        //now its guaranteed that we are in the new name section
                        if (*name_ptr == '"'){
                            //The new name starts with an "
                            name_ptr++;
                        }

                        char* end_ptr = (char*) name_ptr; //we use this to search for the "

                        while (*end_ptr != '\0' && *end_ptr != '"'){ 
                            end_ptr++;
                        }

                        if (*end_ptr == '"'){
                            //cutting the string in order to exclude "
                            *end_ptr = '\0';
                        }

                        set_task_name(task, name_ptr);
                    }//end name

                    //priority
                    else if (strstr(input_buffer, "priority") != NULL){

                        const char* priority_substring = strstr(input_buffer, "priority"); //priority_substring points to p

                        if (priority_substring != NULL){

                            int new_priority;

                            int read_itens = sscanf(priority_substring, "%*s %d", &new_priority);

                            if (read_itens == 1){
                                set_task_priority(task, new_priority);
                            }

                            else{
                                fprintf(stderr, "ERROR : in cli_start() : Failed to read new priority.\n");
                            }

                        }

                        else{
                            fprintf(stderr, "ERROR : in cli_start() : Use edit <id> priority <priority level>.\n");
                        }

                    } //end priority

                    else{
                        fprintf(stderr, "ERROR : in cli_start() : Use a valid instance to edit.\n");
                    }
                    
                }

                else{
                    fprintf(stderr, "ID : %d does not corresponds to any listed task.\n", task_id);
                }


            }

            else{
                fprintf(stderr, "ERROR : in cli_start(): edit command failed.\n");
            }


        } //end edit

        //list
        else if (strcmp(input_buffer, "list")==0){
            list_print(list);
        }//end list


    }
}