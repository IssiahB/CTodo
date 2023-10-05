#include "taskmanager.h"
#include "flowcontroller.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

#include "utils.h"

/**
 * Simply checks the user input against the available
 * commands in the program, and then delegates the responsibility
 * to a function in flowcontroller.c
*/
void controlFlow(char* command);

int main() {
    initializeManager();
    char* input;
    printf("\nCommands:\n  create - create a new task\n  list - list all tasks\n  delete - delete a task\n  quit - save tasks and exit\n");
    
    do {
        input = getInput("\nEnter Command: ");
        controlFlow(input);

    } while (strcmp(input, "quit") != 0);

    printf("Exiting Program...");

    freeTaskManager();
    freeInput(input);

    return 0;
}

void controlFlow(char* command) {
    if (command == NULL) {
        printf("Error with given command\n");
        return;
    }

    if (strcmp(command, "create") == 0) {
        controlCreateTask();
    }

    if (strcmp(command, "delete") == 0) {
        controlDeleteTask();
    }

    if (strcmp(command, "list") == 0) {
        controlListTasks();
    }
}