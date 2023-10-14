/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  :patel vrundaben vijaykumar
Student ID#:158605220
Email      :vvpatel20@myseneca.ca
Section    :milestone1 NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer 
void clearInputBuffer(void) { 
    // Discard all remaining char's from the standard input buffer
     while (getchar() != '\n') {
         ; // do nothing!
     } 
}
// Wait for user to input the "enter" key to continue
void suspend(void) {
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//1. function inputint
int inputInt(void) {
    char character = ' ';
    int value;
    do {
        scanf("%d%c", &value, &character);
        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (character != '\n');
    return value;
}

//2. function inputintpossitive
int inputIntPositive(void) {
    char character = ' ';
    int value;
    do {
        scanf("%d%c", &value, &character);
        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        if (value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value <= 0);
    return value;
}

//3.funtction inputintrange
int inputIntRange(int lowerbound, int upperbound) {
    char character = ' ';
    int value;
    do {
        scanf("%d%c", &value, &character);
        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (!(value <= upperbound && value >= lowerbound)) {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
    } while (!(value <= upperbound && value >= lowerbound));
    return value;
}

//4. Function: inputCharOption
char inputCharOption(char string[]) {
    int i, count = 0;
    char value;
    do {
        scanf(" %c", &value);
        for (i = 0; string[i] != '\0'; i++) {
            if (value == string[i]) {
                count++;
            }
        }if (count == 0) {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
    } while (count == 0);
    clearInputBuffer();
    return value;
}

//5. Function: inputCString
void inputCString(char* string, int minNumChar, int maxNumChar) {
    int flag = 1;
    char character = 'a';
    while (flag) {
        int length = 0;
        while (character != '\n' && length <= maxNumChar) {
            character = getchar();
            string[length] = character;
            length++;
        }
        if(character=='\n'&&length<=(maxNumChar+1)) {
            length--;
            string[length] = '\0';
        }
        else {
            string[maxNumChar] = '\0';
            clearInputBuffer();
        }
        if (minNumChar == maxNumChar && length != minNumChar) {
            printf("ERROR: String length must be exactly %d chars: ", minNumChar);
            character = 'a';
        }
        else if (length<minNumChar || length>maxNumChar) {
            if (length > maxNumChar) {
                printf("ERROR: String length must be no more than %d chars: ", maxNumChar);
                character = 'a';
            }
            else if (length < minNumChar) {
                printf("ERROR: String length must be between %d and %d chars: ", minNumChar, maxNumChar);
                character = 'a';
            }
        }
        else {
            flag = 0;
        }
    }
}
//6. Function: displayFormattedPhone
void displayFormattedPhone(const char* string) {
    int length = 0, i;
    while (string != NULL && string[length] && isdigit(string[length])) {
        length++;
    }
    if (length == 10) {
        i = 0;
        printf("(");
        while (i < 3) {
            printf("%c", string[i]);
            i++;
        }
        printf(")");
        while (i < 6) {
            printf("%c", string[i]);
            i++;
        }
        printf("-");
        while (i < 10) {
            printf("%c", string[i]);
            i++;
        }
    }
    else {
        printf("(___)___-____");
    }
    if (string != 0) {
        for (i = 0; string[i] != '\0'; i++)
            length++;
    }
}
