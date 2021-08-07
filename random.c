#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>

void clearscr(void);
int play(int level, int gamemode);
int random_number(int min_num, int max_num);
int gamemode1(int level, int restart, int gamemode);
int gamemode2(int level, int restart, int gamemode);
int gamemode3(int maxattempt, int time, int restart, int gamemode);
int playagain(int restart, int gamemode);
int setup(void);

/* ---------------------UPTADE---------------------
Block input of level if not numerical
When playagain, ask user what gamemode / level
Put best score in a diferent file and class by user/hightscore
Print average of all players
Different game mode (5 tries max / Best score / Time)
Different file for diferent game mode
Define the limit of random
Add (a lot) hither or (magaaaaaa) highter
X for giving up
H for Help
C for Credits
B for Best score 
Add top 100 on website
*/

///////////////////////////////////////////////////////////////////////////MAIN//////////////////////////////////////////////////////////////////////////////////////
int main (void)
{
    setup();    
}


int setup(void)
{
    clearscr();
    printf("\n------------------------------WELCOME------------------------------\n");
    printf("Press 'X' to give up\n\n");
    printf("Press 'H' for help\n\n");
    printf("Press 'C' for credits\n\n");
    int level = 0;
    do
    {
        printf("Choose level (1 to 3) : ");
        scanf("%i", &level);
        if (level < 1 || level > 3)
        {
            printf("ERROR M17 : Wrong Value\n\n");
        }
    }
    while(level < 1 || level > 3);
    int gamemode;
    do
    {
        printf("Choose gamemode (1 to 3) : ");
        scanf("%i", &gamemode);
        if (gamemode < 1 || gamemode > 3)
        {
            printf("ERROR M54 : Wrong Value\n\n");
        }
    }
    while(gamemode < 1 || gamemode > 3);
    clearscr();
    play(level, gamemode);
}


///////////////////////////////////////////////////////////////////////////Play//////////////////////////////////////////////////////////////////////////////////////

int play(int level, int gamemode)
{
    printf("\n----------------------------------------\n           WELCOME TO LEVEL :\n                   %i\n----------------------------------------\n", level);
///////////////////////////////////////////////////////////////////////////GAMEMODE 1//////////////////////////////////////////////////////////////////////////////////////
    if (gamemode == 1)
    {
        if (level == 1)
        {
            gamemode1(10, 1, 1);
        }
        else if (level == 2)
        {
            gamemode1(50, 2, 1);
        }
        else if (level == 3)
        {
            gamemode1(100, 3, 1);
        }        
    }
///////////////////////////////////////////////////////////////////////////GAMEMODE 2//////////////////////////////////////////////////////////////////////////////////////
    else if (gamemode == 2)
    {
        if (level == 1)
        {
            gamemode2(40, 1, 1);
        }
        else if (level == 2)
        {
            gamemode2(20, 2, 1);
        }
        else if (level == 3)
        {
            gamemode2(10, 3, 1);
        }        
    }
///////////////////////////////////////////////////////////////////////////GAMEMODE 3//////////////////////////////////////////////////////////////////////////////////////
    else if (gamemode == 3)
    {
        if (level == 1)
        {
            gamemode3(20, 40, 1, 3);
        }
        else if (level == 2)
        {
            gamemode3(15, 20, 2, 3);
        }
        else if (level == 3)
        {
            gamemode3(10, 10, 3, 3);
        } 
    }
    
}

///////////////////////////////////////////////////////////////1///////////////////////////////////////////////////////////////
int gamemode1 (int level, int restart, int gamemode)
{
    int x = random_number(0, level);
    int guess;
    printf("\nNumber is in between 0 and %i\n", level);
    for (int counter = 0; guess != x; counter++)
    {
        do
        {
            printf("\nThis is your guess number %i : ", counter + 1);
            scanf("%i", &guess);
            if (guess < 0 || guess > level)
            {
                printf("ERROR G1.90 : Value not in range with current level\n\n");
            }
        }
        while (guess < 0 || guess > level);

        if (guess == x)
        {
            clearscr();
            printf("\nWell done !\nYou won ! the number was : %i and you found it in %i attempts !\n", x, counter + 1);
            sleep(3);
            // ADD "DO YOU WANT TO SAVE YOUR PROGRESS ?  USERNAME : (or username at start)"
            //Play again
            playagain(restart, gamemode);
        }

        else if (guess < x)
        {
            printf("\nThe number is highter !\n");
        }
        else if (guess > x)
        {
            printf("\nThe number is lower !\n");
        }
    }    
}

///////////////////////////////////////////////////////////////2///////////////////////////////////////////////////////////////
int gamemode2(int time, int restart, int gamemode)
{
    int x = random_number(0, 100);
}



///////////////////////////////////////////////////////////////3///////////////////////////////////////////////////////////////
int gamemode3(int maxattempt, int time, int restart, int gamemode)
{
    int x = random_number(0, 100);
}




int playagain(int restart, int gamemode)
{
    char playagain[5];
    do
    {
        printf("\nDo you want to play again ? (y / n) ");
        scanf("%s", playagain);

        for(int i = 0, n = strlen(playagain) ; i < n ; i++)
        {
            playagain[i] = tolower(playagain[i]);
        }
        if (!(strcmp(playagain, "y") == 0 || strcmp(playagain, "n") == 0 || strcmp(playagain, "yes") == 0 || strcmp(playagain, "no") == 0))
        {
            printf("ERROR G1.109 : Please input 'y' or 'n'\n\n");
            continue;
        }
        if (strcmp(playagain, "y") == 0 || strcmp(playagain, "yes") == 0)
        {
            clearscr();
            printf("Good luck !\n");
            sleep(2);
            play(restart, gamemode);
            break;

        }
        else if (strcmp(playagain, "n") == 0 || strcmp(playagain, "no") == 0)
        {
            clearscr();
            printf("Goodbye !\n");
            sleep(2);
            return 0;
            break;
        }
    }
    while (!(strcmp(playagain, "y") == 0 || strcmp(playagain, "n") == 0 || strcmp(playagain, "yes") == 0 || strcmp(playagain, "no") == 0));
}
































void clearscr(void)
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
//add some other OSes here if needed
#else
    #error "OS not supported."
    //you can also throw an exception indicating the function can't be used
#endif
}


int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;
    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    }
    else
    {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}
