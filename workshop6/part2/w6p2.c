/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : part2 NBB

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
    double totalCost=0;
    int loop = 1;
    int selection, note = 0;
  


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
            scanf(" %c", &option[i - 1]);

            if (option[i - 1] != 'n' && option[i - 1] != 'y') {
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
        totalCost += cost[x - 1];
    }
    printf("\n---- -------- -------- -----------");
    printf("\n                      $%11.2lf\n", totalCost);

    //making selection 
    do {
        printf("\nHow do you want to forecast your wish list?");
        printf("\n 1. All items (no filter)");
        printf("\n 2. By priority");
        printf("\n 0. Quit/Exit");
        printf("\nSelection: ");
        scanf("%d", &selection);
        int priorityF,item;
        double costpriority = 0, years, months, monthsremain;
       if (selection == 0)
        {
            loop = 0;
        }
      else if (selection < 0 || selection>2) 
       {
            printf("\nERROR: Invalid menu selection.\n");
       }
       
      else if (selection == 1) {
            printf("\n====================================================");
            printf("\nFilter:   All items");
            printf("\nAmount:   $%0.2lf", totalCost);
            
            months = (totalCost / netIncome) + 0.5;
            years = ((int)months)/ 12;
            monthsremain = (months - (years * 12)) + 0.5;


            printf("\nForecast: %d years, %d months", (int)years, (int)monthsremain);

            note = 0;
            for (item = 0; item < numItem; item++)
            {
                if (option[item] == 'y') {
                    note += 1;
                }
            }
            if (note != 0)
            {
                printf("\nNOTE: Financing options are available on some items."
                    "\n      You can likely reduce the estimated months.");
            }
            printf("\n====================================================\n");
        }
      else if(selection == 2)
        {
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf(" %d", &priorityF);
            printf("\n====================================================");
            printf("\nFilter:   by priority (%d)", priorityF);

            int y;
            for (y = 0; y < numItem; y++)
            {
                if (priority[y] == priorityF) {
                    costpriority += cost[y];
                }
            }
            months = (costpriority / netIncome) + 0.5;
            years = ((int)months) / 12;
            monthsremain = (months - (years * 12)) + 0.5;
                
                printf("\nAmount:   $%0.2lf", costpriority);
                printf("\nForecast: %d years, %d months", (int)years, (int)monthsremain);

                note = 0;
                for (item = 0; item < numItem; item++)
                {
                    if (option[item] == 'y'&& priority[item]==priorityF) {
                        note += 1;
                    }
                }
                if (note != 0)
                {
                    printf("\nNOTE: Financing options are available on some items."
                           "\n      You can likely reduce the estimated months.");
                }
                printf("\n====================================================\n");
            
      }
       
    } while (loop == 1);
        
    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}