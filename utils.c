#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getInput(char* prompt) {
    char* input = (char*) malloc(sizeof(char) * 1024);

    printf(prompt);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Replace new line char with null terminator

    return input;
}

void freeInput(char* userinput) {
    free(userinput);
}