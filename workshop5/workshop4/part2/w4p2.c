/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : part2 NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{   // declaring variables
    int needA, needO, needP, needT, needC;
    int loop=1;
 
    int pickedA=0, pickedO=0, pickedP=0, pickedT=0, pickedC=0;

    // input needed
    while (loop == 1) {
        printf("Grocery Shopping");
        printf("\n================");

        printf("\nHow many APPLES do you need? : ");
        scanf(" %d", &needA);
        while (needA < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many APPLES do you need? : ");
            scanf(" %d", &needA);
        }

        printf("\nHow many ORANGES do you need? : ");
        scanf(" %d", &needO);
        while (needO < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many ORANGES do you need? : ");
            scanf(" %d", &needO);
        }
        
        printf("\nHow many PEARS do you need? : ");
        scanf(" %d", &needP);
        while (needP < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many PEARS do you need? : ");
            scanf(" %d", &needP);
        }
       
        printf("\nHow many TOMATOES do you need? : ");
        scanf(" %d", &needT);
        while (needT < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many TOMATOES do you need? : ");
            scanf(" %d", &needT);
        }

        printf("\nHow many CABBAGES do you need? : ");
        scanf(" %d", &needC);
        while (needC < 0) {
            printf("ERROR: Value must be 0 or more.");
            printf("\nHow many CABBAGES do you need? : ");
            scanf(" %d", &needC);
        }

        printf("\n--------------------------");
        printf("\nTime to pick the products!");
        printf("\n--------------------------"
        "\n\n");

        int remainderA = needA, remainderO = needO, remainderP = needP, remainderT = needT, remainderC = needC;
        while(needA > 0) {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf(" %d", &pickedA);

            if (pickedA > remainderA) {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", remainderA);
            }
            else if (pickedA <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((pickedA < remainderA) && (pickedA > 0)) {
                printf("Looks like we still need some APPLES...\n");
                remainderA = remainderA - pickedA;
            } 
            else if (pickedA == remainderA) {
                printf("Great, that's the apples done!"
                       "\n\n");
                break;
            }
        }
        while (needO > 0) {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf(" %d", &pickedO);

            if (pickedO > remainderO) {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", remainderO);
            }
            else if (pickedO <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((pickedO < remainderO) && (pickedO > 0)) {
                printf("Looks like we still need some ORANGES...\n");
                remainderO = remainderO - pickedO;
            }
            else if (pickedO == remainderO) {
                printf("Great, that's the oranges done!"
                    "\n\n");
                break;
            }
        }
        while (needP > 0) {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf(" %d", &pickedP);

            if (pickedP > remainderP) {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", remainderP);
            }
            else if (pickedP <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((pickedP < remainderP) && (pickedP > 0)) {
                printf("Looks like we still need some PEARS...\n");
                remainderP = remainderP - pickedP;
            }
            else if (pickedP == remainderP) {
                printf("Great, that's the pears done!"
                    "\n\n");
                break;
            }
        }
        while (needT > 0) {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf(" %d", &pickedT);

            if (pickedT > remainderT) {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", remainderT);
            }
            else if (pickedT <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((pickedT < remainderT) && (pickedT > 0)) {
                printf("Looks like we still need some TOMATOES...\n");
                remainderT = remainderT - pickedT;
            }
            else if (pickedT == remainderT) {
                printf("Great, that's the tomatoes done!"
                    "\n\n");
                break;
            }
        }
        while (needC > 0) {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf(" %d", &pickedC);

            if (pickedC > remainderC) {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", remainderC);
            }
            else if (pickedC <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((pickedC < remainderC) && (pickedC > 0)) {
                printf("Looks like we still need some CABBAGES...\n");
                remainderC = remainderC - pickedC;
            }
            else if (pickedC == remainderC) {
                printf("Great, that's the cabbages done!"
                    "\n\n");
                break;
            }
        }
        printf("All the items are picked!");
        
        printf("\n\nDo another shopping? (0=NO): ");
        scanf(" %d", &loop);
        printf("\n");

    }printf("Your tasks are done for today - enjoy your free time!"
    "\n");

    return 0;
}