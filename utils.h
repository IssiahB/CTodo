#ifndef UTILS_H
#define UTILS_H

/**
 * A utilitize function used to standardize how user input
 * is retrieved, then format it for easier use.
 * 
 * @param prompt A message to prompt the user with
 * 
 * @return The user input as a string. (Maximum size (1024 * sizeof(char)))
*/
char* getInput(char* prompt);

/**
 * Simply calls free(userinput)
*/
void freeInput(char* userinput);

/**
 * Parses a string to a positive integer and returns that
 * integer. The Maximum number that can be parsed is:
 * 999,999,999.
 * 
 * @param charInt the string to be parsed
 * @returns The parsed integer if parsing was successful
 *          otherwise returns -1.
*/
int parseInt(char* pInteger);

#endif