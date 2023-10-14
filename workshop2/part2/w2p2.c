/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : part 2 

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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double SMALL, MEDIUM, LARGE;
    int quantity[3];
    
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
    scanf("%d", &quantity[0]);
    printf("\nTommy's shirt size is '%c'", tomSize);
    printf("\nNumber of shirts Tommy is buying: ");
    scanf("%d", &quantity[2]);
    printf("\nSally's shirt size is '%c'", salSize);
    printf("\nNumber of shirts Sally is buying: ");
    scanf("%d", &quantity[1]);
    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total");
    printf("\n-------- ---- ----- --- --------- --------- ---------");
    
    char size[3] = { patSize,salSize,tomSize };
   
    double price[3] = {SMALL,MEDIUM,LARGE};
    
    //Defining array for Subtotal, Taxes, Total
    double subtotal[3];
    double taxes[3];
    double total[3];

    int i;
    for (i =0; i < 3; i++) {
        //Calculate subtotal for all
        subtotal[i] = quantity[i] * price[i];
        subtotal[i] += 0.005;
        subtotal[i] *= 100;
        subtotal[i] = (int)subtotal[i];
        subtotal[i] = (double)subtotal[i] / 100;
        
        taxes[i] = subtotal[i]*TAX;
        taxes[i] += 0.005;
        taxes[i] *= 100;
        taxes[i] = (int)taxes[i];
        taxes[i] = (double)taxes[i] / 100;
       
        total[i] = subtotal[i] + taxes[i];

        
    }
    printf("\nPatty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf", size[0], price[0], quantity[0], subtotal[0], taxes[0], total[0]);
    printf("\nSally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf", size[1], price[1], quantity[1], subtotal[1], taxes[1], total[1]);
    printf("\nTommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf", size[2], price[2], quantity[2], subtotal[2], taxes[2], total[2]);

    //Calculating Grand total
    double GSubtotal;
    double GTaxes;
    double GTotal;
    GSubtotal = subtotal[0] + subtotal[1] + subtotal[2];
    GTaxes = taxes[0] + taxes[1] + taxes[2];
    GTotal = total[0] + total[1] + total[2];
    printf("\n-------- ---- ----- --- --------- --------- ---------");
    printf("\n%33.4lf % 9.4lf % 9.4lf",GSubtotal,GTaxes,GTotal\n"); 
    printf("\nDaily retail sales represented by coins");
    printf("\n=======================================");
    printf("\nSales EXCLUDING tax");

    //Calculating and Printing Coins
    printf("\nCoin     Qty   Balance"
        "\n-------- --- ---------");
    printf("\n%22.4lf\n",GSubtotal);
    int valfull = GSubtotal * 100;
    int toonies = valfull / 200;
    int remainder = valfull % 200;
    printf("Toonies  %3d %9.4lf\n", toonies, (double)remainder/100);
    
    double x = (double)remainder / 100;
    int loonies = (int)x;
    double  remainder2 = x-1;
    printf("Loonies  %3d %9.4lf\n", loonies, remainder2);
    
   
    int Q = remainder2 * 100;
    int Quarter = Q - (Q % 25);
    Quarter = Quarter / 25;
    int remainder3 = Q % 25;
    printf("Quarters %3d %9.4lf\n", Quarter,(double)remainder3/100);

    int dimes = 0;
    printf("Dimes    %3d %9.4lf\n",dimes , (double)remainder3 / 100);

    int Nickels = 0;
    printf("Nickels  %3d %9.4lf\n", Nickels, (double)remainder3 / 100);

    int Pennies = remainder3;
    double remainder4 = 0;
    printf("Pennies  %3d %9.4lf\n", Pennies,remainder4);

    int GQuantity = quantity[0] + quantity[1] + quantity[2];
    float shirt = GSubtotal / GQuantity;
    printf("\nAverage cost/shirt: $%.4lf",shirt);

    printf("\n\nSales INCLUDING tax");

    //Calculating and Printing Coins
    printf("\nCoin     Qty   Balance"
        "\n-------- --- ---------");
    double total1 = GTaxes + GSubtotal;
    printf("\n%22.4lf\n", total1);
    valfull = total1 * 100;
    toonies = valfull / 200;
    remainder = valfull % 200;
    printf("Toonies  %3d %9.4lf\n", toonies, (double)remainder / 100);

    x = (double)remainder / 100;
    loonies = (int)x;
    remainder2 = x - 1;
    printf("Loonies  %3d %9.4lf\n", loonies, remainder2);


    Q = remainder2 * 100;
    Quarter = Q - (Q % 25);
    Quarter = Quarter / 25;
    remainder3 = Q % 25;
    printf("Quarters %3d %9.4lf\n", Quarter, (double)remainder3 / 100);

    dimes = 0;
    printf("Dimes    %3d %9.4lf\n", dimes, (double)remainder3 / 100);


    int N = remainder3;
    int Nickels1 = N - (N % 5);
    Nickels1 = Nickels1 / 5;
    remainder4 = N % 5;
    printf("Nickels  %3d %9.4lf\n", Nickels1, (double)remainder4 / 100);
    
    Pennies = remainder4;
    double remainder5 = 0;
    printf("Pennies  %3d %9.4lf\n", Pennies, remainder5);

    shirt = (double)total1 / GQuantity;
    printf("\nAverage cost/shirt: $%.4lf", shirt);
    

    return 0;
}
