#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#define INITIAL_CAPACITY 5

typedef struct task_manager
{
    char** tasks;
    int size;
    int capacity;
} TaskManager;

/**
 * Creates a new TaskManager with dynamic memory. TaskManager
 * is a struct that contains 3 fields 'tasks', 'size', and 'capacity':
 * 
 * tasks - "An array of strings that will hold the descriptions of tasks."
 * size - "How many descriptions there currently are in the 'tasks' array.""
 * capacity - "How many descriptions there can be in the 'tasks' array."
*/
TaskManager* initializeManager();

/**
 * Adds a task description to the 'tasks' array in a TaskManager.
 * If there is not enough space in the array, will reallocate memory.
*/
void addTask(TaskManager* manager, const char* str);

/**
 * Deletes a task for the 'tasks' array inside a TaskManager.
 * Will shift the elements in the array to fill in gaps
*/
void deleteTask(TaskManager* manager, int index);

/**
 * Returns a task from a given index inside a TaskManager
*/
char* getTask(TaskManager* manager, int index);

/**
 * Frees up all allocated memory given to a TaskManager
*/
void freeTaskManager(TaskManager* manager);

#endif