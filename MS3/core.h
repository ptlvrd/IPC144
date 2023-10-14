/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :patel vrundaben vijaykumar
Student ID#:158605220
Email      :vvpatel20@myseneca.ca
Section    :milestone3 NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

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
void inputCStringNumbers(char* string, int minNumChar, int maxNumChar);
//6. Function: displayFormattedPhone
void displayFormattedPhone(const char* string);



// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
