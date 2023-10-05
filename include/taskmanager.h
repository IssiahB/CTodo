#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#define INITIAL_CAPACITY 5

typedef struct task_manager
{
    char** tasks;
    int size;
    int capacity;
} TaskManager;

extern TaskManager* gProgramTasks;

/**
 * Initializes a global TaskManager "gProgramTasks" with dynamic memory. TaskManager
 * is a struct that contains 3 fields 'tasks', 'size', and 'capacity':
 * 
 * tasks - "An array of strings that will hold the descriptions of tasks."
 * size - "How many descriptions there currently are in the 'tasks' array.""
 * capacity - "How many descriptions there can be in the 'tasks' array."
*/
void initializeManager();

/**
 * Adds a task description to the global TaskManager.
 * If there is not enough space in Taskmanager, will reallocate memory.
 * 
 * @param desc The description of the task to add to TaskManager
*/
void addTask(const char* desc);

/**
 * Deletes a task from the global task manager.
 * Will shift the elements in the task manager to fill in gaps
 * 
 * @param index The index of the element to delete (0 - size)
*/
void deleteTask(int index);

/**
 * Returns a task from a given index inside the global TaskManager
 * 
 * @param index the index of the element to return (0 - size)
*/
char* getTask(int index);

/**
 * Frees up all allocated memory given to the global TaskManager
*/
void freeTaskManager();

#endif