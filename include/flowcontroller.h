#ifndef FLOWCONTROLLER_H
#define FLOWCONTROLLER_H

/**
 * Simply lets the user input a task description
 * and stores it in the taskmanager
*/
void controlCreateTask();

/**
 * Allows the user to select the index of a task 
 * they would like to delete, then deletes it from
 * the taskmanager.
*/
void controlDeleteTask();

/**
 * Gets every task stored in the taskmanager, and 
 * prints to the user alongside the tasks index.
*/
void controlListTasks();

#endif