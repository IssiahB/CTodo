#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "taskmanager.h"

void saveTasks() {
    FILE* file = fopen("taskdata.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to save tasks");
        return;
    }

    for (int i = 0; i < gProgramTasks->size; i++) {
        char* task = getTask(i);
        // Make sure task has enough space for new line and end of line
        int len = strlen(task);
        char* taskWithNewline = malloc(len + 2);

        if (taskWithNewline == NULL) {
            fprintf(stderr, "Unable to allocate memeory to save task");
            return;
        }

        // Copy task and add new line and end of line
        strcpy(taskWithNewline, task);
        taskWithNewline[len] = '\n'; // Append new line character
        taskWithNewline[len + 1] = '\0'; // Append end of line terminator
        fputs(taskWithNewline, file);

        free(taskWithNewline);
    }
    fclose(file);
}

void loadTasks() {
    FILE* file = fopen("taskdata.txt", "r");
    if (file == NULL) {
        return; // No need to inform user will create file at end of program
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        int len = strlen(buffer);
        // Replace new line character with null terminator
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        addTask(buffer);
    }

    fclose(file);
}