#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "taskmanager.h"

TaskManager* gProgramTasks; 

/**
 * @returns 1 if global TaskManager is initilized else returns 0
*/
static int isManagerInitialized();

void initializeManager() {
    gProgramTasks = (TaskManager*) malloc(sizeof(TaskManager));
    if (gProgramTasks == NULL) {
        fprintf(stderr, "Uable to allocate memory for TaskManager\n");
        return;
    }

    // Creates enough space in memory for 5 task pointers
    gProgramTasks->tasks = (char**) malloc(INITIAL_CAPACITY * sizeof(char*));
    if (gProgramTasks->tasks == NULL) {
        fprintf(stderr, "Unable to allocate memory for TaskManager tasks\n");
        return;
    }

    gProgramTasks->size = 0;
    gProgramTasks->capacity = INITIAL_CAPACITY;
}

void addTask(const char* desc) {
    if (!isManagerInitialized()) {
        fprintf(stderr, "TaskManager must be init before adding tasks");
        return;
    }

    if (gProgramTasks->size >= gProgramTasks->capacity) {
        // Double capacity
        gProgramTasks->capacity *= 2;
        gProgramTasks->tasks = (char**) realloc(gProgramTasks->tasks, gProgramTasks->capacity * sizeof(char*));
    }

    if (desc[sizeof(desc) -1] != '\0') {
        fprintf(stderr, "String is not terminated properly");
    }

    // Allocate memory for the new string and copy it
    gProgramTasks->tasks[gProgramTasks->size] = (char*) malloc((strlen(desc) + 1) * sizeof(char));
    strcpy(gProgramTasks->tasks[gProgramTasks->size], desc);
    gProgramTasks->size++;
}

void deleteTask(int index) {
    if (!isManagerInitialized()) {
        fprintf(stderr, "TaskManager must be init before deleting tasks");
        return;
    }

    if (index < 0 || index >= gProgramTasks->size) {
        fprintf(stderr, "Invalid index\n");
        return;
    }

    free(gProgramTasks->tasks[index]);
    // Move the elements after deleted string one position forward
    for (int i = index; i < gProgramTasks->size - 1; i++) {
        gProgramTasks->tasks[i] = gProgramTasks->tasks[i + 1];
    }
    gProgramTasks->size--;
}

char* getTask(int index) {
    if (!isManagerInitialized()) {
        fprintf(stderr, "TaskManager must be init before adding tasks");
        return NULL;
    }

    if (index < 0 || index >= gProgramTasks->size) {
        fprintf(stderr, "Invalid index\n");
        return NULL;
    }

    return gProgramTasks->tasks[index];
}

void freeTaskManager() {
    if (!isManagerInitialized()) {
        return;
    }

    for (int i = 0; i < gProgramTasks->size; i++) {
        free(gProgramTasks->tasks[i]);
    }

    free(gProgramTasks->tasks);
    free(gProgramTasks);
}

static int isManagerInitialized() {
    if (gProgramTasks->capacity > 0) {
        return 1;
    }

    return 0;
}