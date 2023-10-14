/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char type1, type2, type3;
    int weight1, weight2, weight3;
    char cream1, cream2, cream3;

    //variable for customer preference
    char strength;
    char cream;
    int numserving;


    // output
    printf("Take a Break - Coffee Shop"
        "\n==========================");
    printf("\n\nEnter the coffee product information being sold today...");
    printf("\n\nCOFFEE-1...");

    //products data1
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf(" %d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);

    // product data2
    printf("\nCOFFEE-2...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf(" %d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);

    //product data3
    printf("\nCOFFEE-3...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf(" %d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);

    //table
    printf("\n---+------------------------+---------------+-------+");
    printf("\n   |    Coffee              |   Packaged    | Best  |");
    printf("\n   |     Type               |  Bag Weight   | Served|");
    printf("\n   +------------------------+---------------+ With  |");
    printf("\nID | Light | Medium | Rich  |  (G) | Lbs    | Cream |");
    printf("\n---+------------------------+---------------+-------|");
    printf("\n 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |", type1 == 'l'|| type1 == 'L', type1 == 'm'|| type1 == 'M', type1 == 'R'||type1 == 'r', weight1, weight1 / GRAMS_IN_LBS, cream1 == 'y' || cream1=='Y');
    printf("\n 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |", type2 == 'l' || type2 == 'L', type2 == 'm' || type2 == 'M', type2 == 'R' || type2 == 'r', weight2, weight2 / GRAMS_IN_LBS, cream2 == 'y' || cream2 == 'Y');
    printf("\n 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |", type3 == 'l' || type3 == 'L', type3 == 'm' || type3 == 'M', type3 == 'R' || type3 == 'r', weight3, weight3 / GRAMS_IN_LBS, cream3 == 'y' || cream3 == 'Y');

    //customer preference table1
    printf("\n\nEnter how you like your coffee...");
    printf("\n\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &numserving);

    printf("\nThe below table shows how your preferences align to the available products:");
    printf("\n\n--------------------+-------------+-------+");
    printf("\n  |     Coffee      |  Packaged   | With  |");
    printf("\nID|      Type       | Bag Weight  | Cream |");
    printf("\n--+-----------------+-------------+-------+");
    printf("\n 1|       %d         |      %d      |   %d   |", strength == type1 || strength == type1 + 32 || strength == type1 - 32, (1 <= numserving && numserving <= 4 && weight1 == 250) || (5 <= numserving && numserving <= 9 && weight1 == 500) || (10 <= numserving && weight1 == 1000), cream == cream1 || cream == cream1 + 32 || cream == cream1-32);
    printf("\n 2|       %d         |      %d      |   %d   |", strength == type2 || strength == type2 + 32 || strength == type2 - 32, (1 <= numserving && numserving <= 4 && weight2 == 250) || (5 <= numserving && numserving <= 9 && weight2 == 500) || (10 <= numserving && weight2 == 1000), cream == cream2 || cream == cream2 + 32 || cream == cream2 - 32);
    printf("\n 3|       %d         |      %d      |   %d   |", strength == type3 || strength == type3 + 32 || strength == type3 - 32, (1 <= numserving && numserving <= 4 && weight3 == 250) || (5 <= numserving && numserving <= 9 && weight3 == 500) || (10 <= numserving && weight3 == 1000), cream == cream3 || cream == cream3 + 32 || cream == cream3 - 32);

    //customer preference table2
    printf("\n\nEnter how you like your coffee...");
    printf("\n\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &numserving);

    printf("\nThe below table shows how your preferences align to the available products:");
    printf("\n\n--------------------+-------------+-------+");
    printf("\n  |     Coffee      |  Packaged   | With  |");
    printf("\nID|      Type       | Bag Weight  | Cream |");
    printf("\n--+-----------------+-------------+-------+");
    printf("\n 1|       %d         |      %d      |   %d   |", strength == type1 || strength == type1 + 32 || strength == type1 - 32, (1 <= numserving && numserving <= 4 && weight1 == 250) || (5 <= numserving && numserving <= 9 && weight1 == 500) || (10 <= numserving && weight1 == 1000), cream == cream1 || cream == cream1 + 32 || cream == cream1 - 32);
    printf("\n 2|       %d         |      %d      |   %d   |", strength == type2 || strength == type2 + 32 || strength == type2 - 32, (1 <= numserving && numserving <= 4 && weight2 == 250) || (5 <= numserving && numserving <= 9 && weight2 == 500) || (10 <= numserving && weight2 == 1000), cream == cream2 || cream == cream2 + 32 || cream == cream2 - 32);
    printf("\n 3|       %d         |      %d      |   %d   |", strength == type3 || strength == type3 + 32 || strength == type3 - 32, (1 <= numserving && numserving <= 4 && weight3 == 250) || (5 <= numserving && numserving <= 9 && weight3 == 500) || (10 <= numserving && weight3 == 1000), cream == cream3 || cream == cream3 + 32 || cream == cream3 - 32);

    printf("\n\nHope you found a product that suits your likes!");
    printf("\n");


    return 0;
} 
