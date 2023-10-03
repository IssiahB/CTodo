#ifndef UTILS_H
#define UTILS_H

/**
 * A utilitize function used to standardize how user input
 * is retrieved, then format it for easier use.
 * 
 * param: prompt - A message to prompt the user with
 * 
 * return: The user input as a string. (Maximum size (1024 * sizeof(char)))
*/
char* getInput(char* prompt);

/**
 * Simply calls free(userinput)
*/
void freeInput(char* userinput);

#endif