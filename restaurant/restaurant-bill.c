// Katherine Co
// CS2600
// 10.19.22
// Quiz #3: Restaurant Bill
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* argv[])
{
    // Ask user for input tax and tip in percentage in form of "restaurant-bill.o <tax> <tip>" 
    printf("\nPlease enter the restaurant tax and your tip as percentages in the form of 'restaurant-bill.o <tax> <tip>.'\n"
           "NOTE: tax must be greater than 0 and tip must be greater than or equal to 0.\n");

    // Make sure user inputs valid format and valid numbers
    if (argc != 3)
    {
        printf("\nERROR:\nPlease enter the restaurant tax and your tip in the form of 'restaurant-bill.o <tax> <tip>.'\n");
    }
    else
    {
        printf("\nMENU:\n"
               "Salad: $9.95\n"
               "Soup: $4.55\n"
               "Sandwich: $13.25\n"
               "Pizza: $22.35\n");
        
        // Placed the menu items into a list
        char *meal[4]={"Salad","Soup","Sandwich","Pizza"};
        double price[4]={9.95,4.55,13.25,22.35};

        // Create a random number generator to use for the menu items
        int randMeal = 0;
        time_t t;

        // Use random number generator to choose menu itme and calculate tax and tip
        srand(time(&t));    
        randMeal = rand() % 4;  // Used to find the random number with the % operator

        printf("\nYour meal after using the random meal generator:\n%s", meal[randMeal]);
        printf(" - $%.2f\n", price[randMeal]);

        double mealPrice = price[randMeal];
        double tax = mealPrice * (atof(argv[1]) / 100);
        double tip = mealPrice * (atof(argv[2]) / 100);

        // Output tax and tip
        printf("Tax Amount: $%.2f ",tax);
        printf("(%s%%)\n", argv[1]);
        printf("Tip Amount: $%.2f ", tip);
        printf("(%s%%)\n", argv[2]);

        printf("YOUR TOTAL: $%.2f\n", mealPrice + tax + tip);
    }

    return 0;
}