/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3
int main(void)
{
    //decalring variables
    const int JAN = 1, DEC = 12;
    int year, month;
    int loop = 1;
    int i;
    double mornRate, eveRate;
    double mornRateSum = 0, eveRateSum = 0;
    //Displaying the title for the well-being log application
    printf("General Well-being Log"
        "\n======================\n");

    while (loop == 1)
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }

        if (month<JAN || month>DEC) {

            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

        if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC)) {
            printf("\n*** Log date set! ***"
                   "\n\n");


            // using the for loop
            for (i = 1; i <= LOG_DAYS; i++) {

                switch (month) {

                case 1:
                    printf("%d-JAN-0%d\n", year, i);
                    break;
                case 2:
                    printf("%d-FEB-0%d\n", year, i);
                    break;
                case 3:
                    printf("%d-MAR-0%d\n", year, i);
                    break;
                case 4:
                    printf("%d-APR-0%d\n", year, i);
                    break;
                case 5:
                    printf("%d-MAY-0%d\n", year, i);
                    break;
                case 6:
                    printf("%d-JUN-0%d\n", year, i);
                    break;
                case 7:
                    printf("%d-JUL-0%d\n", year, i);
                    break;
                case 8:
                    printf("%d-AUG-0%d\n", year, i);
                    break;
                case 9:
                    printf("%d-SEP-0%d\n", year, i);
                    break;
                case 10:
                    printf("%d-OCT-0%d\n", year, i);
                    break;
                case 11:
                    printf("%d-NOV-0%d\n", year, i);
                    break;
                case 12:
                    printf("%d-DEC-0%d\n", year, i);
                    break;
                }

                //ratings
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mornRate);
                while (mornRate < 0.0 || mornRate>5.0) {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &mornRate);
                }

                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveRate);
                while (eveRate < 0.0 || eveRate>5.0) {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    
                }
                printf("\n");
                mornRateSum += mornRate;
                eveRateSum += eveRate; 
            } loop = 0;
        }

    }
    printf("Summary"
        "\n=======");

    //total
    printf("\nMorning total rating: %.3lf", mornRateSum);
    printf("\nEvening total rating:  %.3lf", eveRateSum);
    printf("\n----------------------------");
    printf("\nOverall total rating: %.3lf", mornRateSum + eveRateSum);

    //average
    printf("\n\nAverage morning rating:  %.1lf", mornRateSum / LOG_DAYS);
    printf("\nAverage evening rating:  %.1lf", eveRateSum / LOG_DAYS);
    printf("\n----------------------------");
    printf("\nAverage overall rating:  %.1lf", ((mornRateSum / LOG_DAYS) + (eveRateSum / LOG_DAYS))/2);
    printf("\n");
    return 0;
}