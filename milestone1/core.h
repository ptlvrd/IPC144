#pragma once
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

#include <stdio.h>

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//1. function inputint
int inputInt(void);

//2. function inputintpossitive
int inputIntPositive(void);

//3. funtction inputintrange
int inputIntRange(int lowerbound, int upperbound);

//4. Function: inputCharOption
char inputCharOption(char string[]);

//5. Function: inputCString
void inputCString(char* string, int minNumChar, int maxNumChar);

//6. Function: displayFormattedPhone
void displayFormattedPhone(const char* string);