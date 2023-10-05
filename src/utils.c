#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* getInput(char* prompt) {
    char* input = (char*) malloc(sizeof(char) * 1024);

    printf(prompt);
    fgets(input, 1024, stdin);
    input[strlen(input) - 1] = '\0'; // Replace new line char with null terminator

    return input;
}

void freeInput(char* userinput) {
    free(userinput);
}

int parseInt(char* pInteger) {
    // Determine length of pointed to array
    int length = 0;
    while (pInteger[length] != '\0') {
        if (!isdigit(pInteger[length])) {
            fprintf(stderr, "Value given to parseInt must be a digit character\n");
            return -1;
        }
        length++;

        // Can only parse up to 999,999,999
        if (length > 9) {
            fprintf(stderr, "Value given to parseInt is too large of a number\n");
            return -1;
        }
    }

    // The number that will store the fully parsed integer
    int fullNum = 0;
    for (int i = 0; i < length; i++) {
        int tempInt = (int) pInteger[i] - '0'; // Gets int value

        // Shifts existing numbers to the left and adds on the new parsed num
        fullNum = (fullNum * 10) + tempInt;
    }

    return fullNum;
}