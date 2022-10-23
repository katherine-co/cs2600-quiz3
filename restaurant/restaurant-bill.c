// Katherine Co
// CS2600
// 10.19.22
// Quiz #3: Restaurant Bill
#include <stdio.h>

int main (int argc, char* argv[])
{
    // Ask user for input ta and tip in percentage
    printf("\nPlease enter the restaurant tax and your tip as percentages in the form of 'restaurant-bill.o <tax> <tip>'\n"
           "NOTE: tax must be greater than 0 and tips must be greater than or equal to 0.\n");

    // Make sure user inputs valid format and valid numbers
    if (argc != 3)
    {
        printf("\nERROR:\n Please enter the restaurant tax and your tip:\n"
               "./restaurant_bill.out (tax) (tip)\n");
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
    }
    // Create a random number generator to use for the menu items


    // Use random number generator to choose menu itme and calculate tax and tip


    // Output tax and tip
}