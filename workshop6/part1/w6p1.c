/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : part1 NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_INCOME 500.00
#define MAX_INCOME 400000.00
#define MAXITEM 10
#define MINCOST 100.00
int main(void)
{
    double netIncome;
    int numItem;
    double totatCost = 0;
    

    printf("+--------------------------+");
    printf("\n+   Wish List Forecaster   |");
    printf("\n+--------------------------+");
    
    //loop for netincome
    do {

        printf("\n\nEnter your monthly NET income: $");
        scanf("%lf", &netIncome);

        if (netIncome < MIN_INCOME) {
            printf("ERROR: You must have a consistent monthly income of at least $%0.2lf", MIN_INCOME);

        }
        if (netIncome > MAX_INCOME) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%0.2lf", MAX_INCOME);
        }
    } while (netIncome <= MIN_INCOME || netIncome >= MAX_INCOME);

    //loop for items
    do {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &numItem);

        if (numItem <= 0 || numItem > MAXITEM) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (numItem <= 0 || numItem >= MAXITEM);

    //item details
    double cost[MAXITEM];
    int priority[MAXITEM];
    char option[MAXITEM];

    int i;
    for (i = 1; i <= numItem; i++) {
        printf("\nItem-%d Details:", i);

        //loop for cost
        do {
            printf("\n   Item cost: $");
            scanf("%lf", &cost[i - 1]);

            if (cost[i - 1] < MINCOST)
            {
                printf("      ERROR: Cost must be at least $100.00");
            }
        } while (cost[i - 1] < MINCOST);

        //loop for priority
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i - 1]);

            if ((priority[i - 1]) < 1 || (priority[i - 1]) > 3) {
            printf("      ERROR: Value must be between 1 and 3\n");

            }
        } while ((priority[i - 1]) < 1 || (priority[i - 1]) > 3);

        //loop for finance
        do {

            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &option[i-1]);

            if (option[i - 1] != 'n'&& option[i - 1] != 'y') {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (option[i - 1] != 'n' && option[i - 1] != 'y');
    }
    //table
    printf("\nItem Priority Financed        Cost");
    printf("\n---- -------- -------- -----------");

    int x;
    for (x = 1; x <= numItem; x++) {
        printf("\n%3d  %5d    %5c    %11.2lf", x, priority[x - 1], option[x - 1], cost[x - 1]);
        totatCost += cost[x - 1];
    }
    printf("\n---- -------- -------- -----------");
    printf("\n                      $%11.2lf\n\n", totatCost);

    printf("Best of luck in all your future endeavours!\n");
    return 0;
}