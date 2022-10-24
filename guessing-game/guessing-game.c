// Katherine Co
// CS2600
// 10.23.22
// Quiz #3: Number Guessing Game
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int userMax = 10;
 
int main()
{
    
    
    char input;
    int userVal = 0;
    int userChoice = 0;
    int max = 0;
    int userWins = 0;
    int randNum;
    srand(time(0));
    // Display menu for user to choose option between 1-3
    do
    {
        printf("Welcome!\n"
                "Enter 1 to play a game\n"
                "Enter 2 to change the max number\n"
                "Enter 3 to quit\n");
        scanf(" %d", &userChoice);

        // If option 1 selected, ask user to enter number
        switch (userChoice)
        {
            case 1:
                int guesses = 0;
                int holder = 100;
                do
                {
                    printf("Enter q if you would like exit to the menu.\n"
                    "Else, enter a number from 1-%d: ", userMax);
                    scanf(" %s", &input);
                    if (holder == 100)
                    {
                        randNum = rand() % userMax + 1;
                        holder = randNum;
                    }
                    if (input == 'q')
                    {
                        break;
                    }
                    else if (isdigit(input))
                    {
                        userVal = input - '0';
                        if (userVal > holder)
                        {
                            printf("Too high!\n");      // Checks if user's value is too high
                            guesses++;
                            continue;
                        }
                        else if (userVal < holder)
                        {
                            printf("Too low!\n");       // Checks if user's value is too low
                            guesses++;
                            continue; 
                        }
                        else 
                        {
                            guesses++;
                            break;
                        }
                    }
                    else
                    {
                        printf("this program will end.");
                        break;
                    }
                } while(userVal != randNum);
                userWins = 1;
                printf("You guessed it!\n");
                break;
    
            // if option 2 selected, tell max value they can set the number
            case 2:
                printf("Enter the new maximum number: ");
                do
                {
                    scanf(" %d", &max);
                    if(max <= 0 || max > 10)    // Check number is <= 0 or > 10
                    {
                        printf("The number you have inputted is invalid.\n"
                            "Enter a valid number from 1-10: \n");
                    }
                    else
                    {
                        userMax = max;
                    }
                }
                while(max < 0 || max > 10);
            
                printf("New number range will be between 1 to %d\n", userMax);
                break;
        
            // If option 3 selected, display message "Thank you" and end program
            case 3:
                printf("Thank you for playing.\n");
                printf("Final Result:\n");
            
                if(userWins == 1)
                {
                    printf("Congratulations, you won!\n");
                    printf("You guessed %d times.\n", guesses);
                }
                else
                {
                    printf("Sorry. Better luck next time.");
                }
                break;
            }
 
    } while (userChoice != 3);
        return 0;
}
 

