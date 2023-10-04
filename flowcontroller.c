#include "flowcontroller.h"
#include "utils.h"
#include "taskmanager.h"
#include <stdio.h>

void controlCreateTask() {
    printf("\nCreating Task...\n");
    char* desc = getInput("Enter Task Desc: ");
    
    addTask(desc);
    freeInput(desc);
}

void controlDeleteTask() {
    printf("Deleting...");
}

void controlListTasks() {
    if (gProgramTasks->size < 1) {
        printf("\nNo Tasks!\n");
        return;
    }

    // TODO when listing tasks only 7 characters are displayed figure out error

    printf("\nListing...\n");
    for (int i = 0; i < gProgramTasks->size; i++) {
        char* task = getTask(i);
        printf("\t%d - %s\n", i, task);
    }

}
