#include "task_manager.h"
#include <stdio.h>
#include <string.h>

void controlFlow(char* command);

int main() {
    TaskManager* manager = initializeManager();
    char input[1024];
    printf("\nCommands:\n  create - create a new task\n  list - list all tasks\n  delete - delete a task\n  quit - save tasks and exit\n");
    
    do {
        printf("\nEnter a command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Replace new line char with null terminator

        controlFlow(input);

    } while (strcmp(input, "quit") != 0);

    printf("Exiting Program...");

    freeTaskManager(manager);

    return 0;
}

void controlFlow(char* command) {
    if (strcmp(command, "create")) {
        
    }
}