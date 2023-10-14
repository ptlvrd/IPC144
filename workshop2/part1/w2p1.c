/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : patrl vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : part1

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double SMALL, MEDIUM, LARGE;
    int numberofshirts;
    double subtotal;
    double taxes;
    double total;
    printf("Set Shirt Prices\n================");
    printf("\nEnter the price for a SMALL shirt: $");
    scanf("%lf", &SMALL);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &MEDIUM);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &LARGE);
    printf("\nShirt Store Price List");
    printf("\n======================");
    printf("\nSMALL  : $17.96");
    printf("\nMEDIUM : $26.96");
    printf("\nLARGE  : $35.97");
    printf("\n\nPatty's shirt size is '%c'", patSize);
    printf("\nNumber of shirts Patty is buying: ");
    scanf("%d", &numberofshirts);
    printf("\nPatty's shopping cart...");
    printf("\nContains : %d shirts",numberofshirts);
    subtotal = numberofshirts * SMALL;
    subtotal += 0.005;
    subtotal *= 100;
    subtotal = (int)subtotal;
    subtotal = (double)subtotal / 100;
    printf("\nSub-total: $%8.4lf", subtotal);
    taxes = subtotal * TAX;
    taxes += 0.005;
    taxes *= 100;
    taxes = (int)taxes;
    taxes = (double)taxes / 100;
    printf("\nTaxes    : $%8.4lf", taxes);
    total = subtotal + taxes;
    printf("\nTotal    : $%8.4lf", total);
    printf("\n\n");
   



    return 0;
}
