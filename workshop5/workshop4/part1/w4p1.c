/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    char input;
    int a;
    int i = 0;
    int loop = 1;
    printf("+----------------------+\n"
        "Loop application STARTED\n"
        "+----------------------+\n\n");


    while (loop == 1)
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf("%c%d%*c", &input, &a);

        if (input == 'D' || input == 'W' || input == 'F')
        {
            if (a >= 3 && a <= 20)
            {
                if (input == 'D')
                {
                    printf("DO-WHILE: ");
                    do {
                        printf("%c", input);
                        i++;
                    } while (a > i);
                    i = 0;
                    printf("\n\n");

                }
                else if (input == 'W')
                {
                    printf("WHILE   : ");
                    while (a > i)
                    {
                        printf("%c", input);
                        i++;
                    }
                    i = 0;
                    printf("\n\n");
                }
                else if (input == 'F')
                {
                    printf("FOR     : ");
                    for (i = 0; a > i; i++)
                    {
                        printf("%c", input);
                    }
                    i = 0;
                    printf("\n\n");
                }
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else
        {
            if (input == 'Q')
            {
                if (a == 0)
                {
                    loop = 0;
                }
                else
                {
                    printf("ERROR: To quit, the number of iterations should be 0!\n\n");
                }
            }
            else
            {
                printf("ERROR: Invalid entered value(s)!\n\n");
            }
        }
    }
    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    printf("\n");
    return 0;


}

