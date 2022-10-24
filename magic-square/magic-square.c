// Katherine Co
// CS2600
// 10.22.22
// Quiz #3: Lo Shu Magic Square

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
 
int magicSqur[3][3] =   //Empty Lo Shu Square
{
    {0,0,0},
    {0,0,0},
    {0,0,0}
};

int populateArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// Swap numbers until you get a Lo Shu square
void swapVal()
{
    for(int i = 8; i > 0; i--)
    {
      int j = (rand() % (i + 1));
      int temp = populateArray[i];

      populateArray[i] = populateArray[j];
      populateArray[j] = temp;
    }
}

int foundMagic(int magicSqur[3][3])
{
    int magic = 1;

    // After Lo Shu square is filled, check if square is a Lo Shu
    int diagonal1 = magicSqur[0][0] + magicSqur[1][1] + magicSqur[2][2];    // Checks diagonals
    if(diagonal1 != 15) magic = 0;
    int diagonal2 = magicSqur[0][2] + magicSqur[1][1] + magicSqur[2][0];
    if(diagonal2 != 15) magic = 0;

    int row1 = magicSqur[0][0] + magicSqur[0][1] + magicSqur[0][2];     // Checks rows
    if(row1 != 15) magic = 0;
    int row2 = magicSqur[1][0] + magicSqur[1][1] + magicSqur[1][2];
    if(row2 != 15) magic = 0;
    int row3 = magicSqur[2][0] + magicSqur[2][1] + magicSqur[2][2];
    if(row3 != 15) magic = 0;

    int column1 = magicSqur[0][0] + magicSqur[1][0] + magicSqur[2][0];  // Checks columns
    if(column1 != 15) magic = 0;
    int column2 = magicSqur[0][1] + magicSqur[1][1] + magicSqur[2][1];
    if(column2 != 15) magic = 0;
    int column3 = magicSqur[0][2] + magicSqur[1][2] + magicSqur[2][2];
    if(column3 != 15) magic = 0;

    return magic;
}

void printSqur(int arr[3][3])   // Printing the Lo Shu square
{
    int i;
    int j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if(j == 0) printf("[ ");
            printf("%d ", arr[i][j]);
        }
        printf("]\n");
    }
}

// Generate Lo Shu Square
void createGrid()
{
    swapVal();
    int n = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            magicSqur[i][j] = populateArray[n];
            n++;
        }
    }

}
 
int main()
{  
    printf("Welcome to Lo Shu Magic Square!\n");
    srand(time(0));
 
    int found = 0;
    int count = 0;
    while(!found) {     // Continues generating grid until Lo Shu is found
        createGrid();
        count++;
 
        if(foundMagic(magicSqur) == 1) found = 1;
    }
    printf("Printing a Lo Shu Magic Square:\n");
    printSqur(magicSqur);
    printf("It took %d attempts to get a Lo Shu Magic Square.", count);

    return EXIT_SUCCESS;
}