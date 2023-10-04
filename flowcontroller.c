#include "flowcontroller.h"
#include "utils.h"
#include <stdio.h>

void controlCreateTask() {
    printf("Creating Task...\n\n");
    char* desc = getInput("Enter Task Desc: ");
    

    freeInput(desc);
}

void controlDeleteTask() {
    printf("Deleting...");
}

void controlListTasks() {
    printf("Listing...");
}
