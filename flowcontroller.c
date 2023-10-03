#include "flowcontroller.h"
#include "utils.h"
#include <stdio.h>

void controlCreateTask() {
    printf("Creating Task...\n\n");
    char* input = getInput("Enter Task Desc: ");
    freeInput(input);
}

void controlDeleteTask() {
    printf("Deleting...");
}

void controlListTasks() {
    printf("Listing...");
}
