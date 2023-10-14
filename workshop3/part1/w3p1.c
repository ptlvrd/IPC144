/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  :patel vrundaben vijaykumar 
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

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    // declaring variables
    const int id1 = 111;
    const int id2 = 222;
    const int id3 = 111;
    const char tax1 = 'Y';
    const char tax2 = 'N';
    const char tax3 = 'N';
    const double price1 = 111.4900;
    const double price2 = 222.9900;
    const double price3 = 334.4900;
    double average;

    printf("Product Information"
           "\n===================");
    //printing product data
    printf("\nProduct-1 (ID:%d)", id1);
    printf("\n  Taxed: %c", tax1);
    printf("\n  Price: $%.4lf", price1);

    printf("\n\nProduct-2 (ID:%d)", id2);
    printf("\n  Taxed: %c", tax2);
    printf("\n  Price: $%.4lf", price2);

    printf("\n\nProduct-3 (ID:%d)", id3);
    printf("\n  Taxed: %c", tax3);
    printf("\n  Price: $%.4lf", price3);

    //average
    average = (price1 + price2 + price3) / 3;
    printf("\n\nThe average of all prices is: $%.4lf", average);

    printf("\n\nAbout Relational and Logical Expressions!");
    printf("\n========================================");
    printf("\n1. These expressions evaluate to TRUE or FALSE"
        "\n2. FALSE: is always represented by integer value 0"
        "\n3. TRUE : is represented by any integer value other than 0");
    printf("\n\nSome Data Analysis..."
        "\n=====================");

    //analysis
    printf("\n1. Is product 1 taxable? -> %d\n", tax1 || price1 == 'Y');
    printf("\n2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", tax2 || tax3 != 'N');
    printf("\n3. Is product 3 less than testValue ($%.2lf)? -> %d\n", testValue, price3<testValue );
    printf("\n4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", price3 > (price1 && price2));
    printf("\n5. Is the price of product 1 equal to or more than the price difference"
           "\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)", price1 >= (price3 - price2), (price3-price2));
    printf("\n\n6. Is the price of product 2 equal to or more than the average price? -> %d\n", price2 >= average);
    printf("\n7. Based on product ID, product 1 is unique -> %d\n", (id1 == id2)&&(id1 == id3));
    printf("\n8. Based on product ID, product 2 is unique -> %d\n", (id2 != id1)&&(id2 != id3));
    printf("\n9. Based on product ID, product 3 is unique -> %d\n", (id3 == id1)&&(id3 == id2)); 
  
   
    return 0;
}
