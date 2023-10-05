#include "flowcontroller.h"
#include "utils.h"
#include "taskmanager.h"
#include <stdio.h>

void controlCreateTask() {
    char* desc = getInput("Enter Task Desc: ");
    
    addTask(desc);
    freeInput(desc);
}

void controlDeleteTask() {
    if (gProgramTasks->size < 1) {
        printf("\nNo Tasks To Delete!\n");
        return;
    }

    // List available tasks
    controlListTasks();
    // Get user seleted index
    char* pIndex = getInput("Enter Task Index: ");
    int index = parseInt(pIndex);
    freeInput(pIndex);

    // Delete index from taskmanager
    deleteTask(index);
}

void controlListTasks() {
    if (gProgramTasks->size < 1) {
        printf("\nNo Tasks To List!\n");
        return;
    }

    for (int i = 0; i < gProgramTasks->size; i++) {
        char* task = getTask(i);
        printf("\t%d - %s\n", i, task);
    }
}
