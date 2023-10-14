/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : part 1 NBB 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//macros
#define MAX_PATHLENGTH 70
#define MIN_PATHLENGTH 10
#define MAXLIVES 10
#define MINLIVES 1
#define MULTIPLE 5
#define MAXMOVES 26
#define MINMOVES 3

//stRuct for playerinfo
struct playerInfo
{
    int lives;
    char symbol;
    int treasure;
    int history[MAX_PATHLENGTH];
};

//struct for gameinfo
struct gameInfo {

    int moves;
    int pathLength;
    int bombs[MAX_PATHLENGTH];
    int treasure[MAX_PATHLENGTH];
};

int main(void)
{ 
    struct playerInfo player;
    struct gameInfo game;

    printf("================================"
         "\n         Treasure Hunt!"
         "\n================================");

    //player configuration
    printf("\n\nPLAYER Configuration");
    printf("\n--------------------");
    printf("\nEnter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    //lives
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        if (player.lives<MINLIVES || player.lives>MAXLIVES){
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.lives<MINLIVES || player.lives>MAXLIVES);

    printf("Player configuration set-up is complete");

    printf("\n\nGAME Configuration");
    printf("\n------------------\n");

    //path length
    do {
    
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
        if (game.pathLength<MIN_PATHLENGTH || game.pathLength>MAX_PATHLENGTH || (game.pathLength % MULTIPLE != 0)) {

            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }

    } while (game.pathLength<MIN_PATHLENGTH || game.pathLength>MAX_PATHLENGTH || (game.pathLength % MULTIPLE != 0));

    //number of moves
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        if (game.moves<player.lives || game.moves>(int)(0.75 * game.pathLength)) {

            printf("    Value must be between %d and %d\n",player.lives, (int)(0.75 * game.pathLength));
        }
    } while (game.moves<player.lives || game.moves>(int)(0.75 * game.pathLength));

    //bomb placement
    printf("\nBOMB Placement"
             "\n--------------");
    printf("\nEnter the bomb positions in sets of 5 where a value"
           "\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input."
           "\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    int i;
    for (i = 0; i < game.pathLength; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
    }
    printf("BOMB placement set");
   
    //treasure placement
    printf("\n\nTREASURE Placement"
             "\n------------------");
    printf("\nEnter the treasure placements in sets of 5 where a value"
           "\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input."
           "\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    int x;
    for (x = 0; x < game.pathLength; x += 5)
    {
        printf("   Positions [%2d-%2d]: ", x + 1, x + 5);
        scanf("%d %d %d %d %d", &game.treasure[x], &game.treasure[x + 1], &game.treasure[x + 2], &game.treasure[x + 3], &game.treasure[x + 4]);
    }
    printf("TREASURE placement set");

    printf("\n\nGAME configuration set-up is complete...");

    printf("\n\n------------------------------------"
        "\nTREASURE HUNT Configuration Settings"
        "\n------------------------------------");
    printf("\nPlayer:");
    printf("\n   Symbol     : %c",player.symbol);
    printf("\n   Lives      : %d", player.lives);
    printf("\n   Treasure   : [ready for gameplay]");
    printf("\n   History    : [ready for gameplay]");

    printf("\n\nGame:");
    printf("\n   Path Length: %d",game.pathLength);
    printf("\n   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasure[i]);
    }

    printf("\n\n===================================="
           "\n~ Get ready to play TREASURE HUNT! ~"
    "\n====================================\n");
    return 0;
}
