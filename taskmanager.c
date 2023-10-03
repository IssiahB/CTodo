#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "taskmanager.h"

TaskManager* initializeManager() {
    TaskManager* manager = (TaskManager*) malloc(sizeof(TaskManager));
    manager->tasks = (char**) malloc(INITIAL_CAPACITY * sizeof(char*));
    manager->size = 0;
    manager->capacity = INITIAL_CAPACITY;
    return manager;
}

void addTask(TaskManager* manager, const char* str) {
    if (manager->size >= manager->capacity) {
        // Double capacity
        manager->capacity *= 2;
        manager->tasks = (char**) realloc(manager->tasks, manager->capacity * sizeof(char*));
    }

    // Allocate memory for the new string and copy it
    manager->tasks[manager->size] = (char*) malloc((strlen(str) + 1) * sizeof(char));
    strcpy(manager->tasks[manager->size], str);
    manager->size++;
}

void deleteTask(TaskManager* manager, int index) {
    if (index < 0 || index >= manager->size) {
        printf("Invalid index\n");
        return;
    }

    free(manager->tasks[index]);
    // Move the elements after deleted string one position forward
    for (int i = index; i < manager->size - 1; i++) {
        manager->tasks[i] = manager->tasks[i + 1];
    }
    manager->size--;
}

char* getTask(TaskManager* manager, int index) {
    if (index < 0 || index >= manager->size) {
        printf("Invalid index\n");
        return NULL;
    }

    return manager->tasks[index];
}

void freeTaskManager(TaskManager* manager) {
    for (int i = 0; i < manager->size; i++) {
        free(manager->tasks[i]);
    }

    free(manager->tasks);
    free(manager);
}