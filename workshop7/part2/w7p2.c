/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : part 2 NBB 

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
    int treasureFound;
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
        int x, y, i; 
        int livesReamining, movesRemaining, position = MAX_PATHLENGTH + 1;

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

            if (player.lives<MINLIVES || player.lives>MAXLIVES) {
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

                printf("    Value must be between %d and %d\n", player.lives, (int)(0.75 * game.pathLength));
            }
        } while (game.moves<player.lives || game.moves>(int)(0.75 * game.pathLength));

        //bomb placement
        printf("\nBOMB Placement"
            "\n--------------");
        printf("\nEnter the bomb positions in sets of 5 where a value"
            "\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input."
            "\n(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");
       
        for (i = 0; i < game.pathLength; i += 5)
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
            "\n(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");
        
        for (i = 0; i < game.pathLength; i += 5)
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
            scanf("%d %d %d %d %d", &game.treasure[i], &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4]);
        }
        printf("TREASURE placement set");

        printf("\n\nGAME configuration set-up is complete...");

        printf("\n\n------------------------------------"
            "\nTREASURE HUNT Configuration Settings"
            "\n------------------------------------");
        printf("\nPlayer:");
        printf("\n   Symbol     : %c", player.symbol);
        printf("\n   Lives      : %d", player.lives);
        printf("\n   Treasure   : [ready for gameplay]");
        printf("\n   History    : [ready for gameplay]");

        printf("\n\nGame:");
        printf("\n   Path Length: %d", game.pathLength);
        printf("\n   Bombs      : ");
        
        for (x = 0; x < game.pathLength; x++)
        {
            printf("%d", game.bombs[x]);
        }
        
        printf("\n   Treasure   : ");
        for (y = 0; y < game.pathLength; y++)
        {
            printf("%d", game.treasure[y]);
        }

        printf("\n\n===================================="
            "\n~ Get ready to play TREASURE HUNT! ~"
            "\n====================================\n");

        //part 2
        livesReamining = player.lives;
        movesRemaining = game.moves;
        player.treasureFound = 0;
        int count = 0;
        char recentPosition[MAX_PATHLENGTH];
        char positionItem[MAX_PATHLENGTH];
       
        for (x = 0; x < game.pathLength; x++) {

            player.history[x] = 0;
        }
        for (y = 0; y < game.pathLength; y++)
        {
            positionItem[y] = '-';
        }
        for (y = 0; y < game.pathLength; y++) {
            recentPosition[y] = ' ';
        }

        do {
            //line1
            for (y = 0; y < game.pathLength; y++) {
                if (recentPosition[y] == 'V') {
                    count++;
                }
            }if (count == 0) {
                printf("\n");
            }
            else {
                printf("  ");
                for (y = 0; y < game.pathLength; y++) {
                    if (recentPosition[y] == 'V') {
                        printf("%c\n", recentPosition[y]);
                        break;
                    }
                    else {
                        printf("%c", recentPosition[y]);
                    }
                }
            }
            for (y = 0; y < game.pathLength; y++)
            {
                recentPosition[y] = ' ';
            }

            // line2
            printf("  ");
            for (y = 0; y < game.pathLength; y++)
            {
                printf("%c", positionItem[y]);
            }
            printf("\n");

            //line3
            printf("  ");
            for (i = 1; i <= game.pathLength; i++)
            {
                if (i % 10 == 0)
                {
                    printf("%d", (int)i / 10);
                }
                else
                {
                    printf("|");
                }
            }
            printf("\n");

            // Fourth Line
            printf("  ");
            for (i = 0; i < game.pathLength; i += 10)
            {
                printf("1234567890");
            }
            
            printf("\n+---------------------------------------------------+");
            printf("\n  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d", livesReamining, player.treasureFound, movesRemaining);
            printf("\n+---------------------------------------------------+\n");
            if (livesReamining == 0)
            {
                break;
            }

            // Quit 
            if (movesRemaining == 0)
            {
                break;
            }
            do {
                printf("Next Move [1-20]: ");
                scanf("%d", &position);

                if (position < 1 ||position > game.pathLength)
                {
                    printf("  Out of Range!!!\n");
                }

            } while (position < 1 || position > game.pathLength);
            printf("\n");

            if (player.history[position - 1] == 1)
            {
                printf("===============> Dope! You've been here before!\n\n");
                recentPosition[position - 1] = 'V';
                movesRemaining++;
            }
            else if (game.bombs[position - 1] == 1 && game.treasure[position - 1] == 1)
            {
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                positionItem[position - 1] = '&';
                recentPosition[position - 1] = 'V';
                livesReamining--;
                player.treasureFound++;
            }
            else if (game.bombs[position - 1] == 1)
            {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                positionItem[position - 1] = '!';
                recentPosition[position - 1] = 'V';
                livesReamining--;
            }
            else if (game.treasure[position - 1] == 1)
            {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                positionItem[position - 1] = '$';
                recentPosition[position - 1] = 'V';
                player.treasureFound++;
            }
            else
            {
                printf("===============> [.] ...Nothing found here... [.]\n\n");
                positionItem[position - 1] = '.';
                recentPosition[position - 1] = 'V';
            }

            // Storing the position in history array
            player.history[position - 1] = 1;

            // reducing the move counter
            movesRemaining--;
            if (livesReamining == 0)
            {
                printf("No more LIVES remaining!\n\n");
            }
            if (movesRemaining == 0)
            {
                printf("No more MOVES remaining!\n\n");
            }

    } while (movesRemaining >= 0 && livesReamining >= 0);

    printf("\n");

    // Ending 
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");

    printf("You should play again and try to beat your score!\n");
    printf("\n");

            return 0;
}
