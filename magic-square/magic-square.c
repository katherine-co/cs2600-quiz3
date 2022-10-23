// Katherine Co
// CS2600
// 10.22.22
// Quiz #3: Lo Shu Magic Square
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Generate Lo Shu Square
int main()
{
    bool rows = false;
    bool colums = false;
    bool diagonals = false;
    int countSqaure = 0;
    int magicSqur[3][3];
    int index = 0;
    int populatArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Lo Shu Magic Square\n");
    
    if (rows == false || columns == false || diagonals == false)
    {
        do
        {
            rows = false;
            columns = false;
            diagonals = false;
            index = 0;
            int sum = 15;
        
            // Loop through magic square to put random nubmers
            int s = sizeof(populatArray) / sizeof(populatArray[0]);
            randArrayGen(populatArray, s);
            
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    magicSqur[i][j] = populatArray[index];
                    index++;
                }
            }

            // After Lo Shu square is filled, check if square is a Lo Shu
            int row1 = magicSqur[0][0] + magicSqur[0][1] + magicSqur[0][2];
            int row2 = magicSqur[1][0] + magicSqur[1][1] + magicSqur[1][2];
            int row3 = magicSqur[2][0] + magicSqur[2][1] + magicSqur[2][2];
            if (row1 == 15 && row2 == 15 && row3 == 15) rows = true;

            int column1 = magicSqur[0][0] + magicSqur[1][0] + magicSqur[2][0];
            int column2 = magicSqur[0][1] + magicSqur[1][1] + magicSqur[2][1];
            int column3 = magicSqur[0][2] + magicSqur[1][2] + magicSqur[2][2];
            if (column1 == 15 && column2 == 15 && column3 == 15) columns = true;

            int diagonal1 = magicSqur[0][0] + magicSqur[1][1] + magicSqur[2][2];
            int diagonal2 = magicSqur[0][2] + magicSqur[1][1] + magicSqur[2][0];
            if (diagonal1 == 15 && diagonal2 == 15) diagonals = true;

        }
        while (rows == false || columns == false || diagonals == false);
    }

        // Swap numbers until you get a Lo Shu square


    // Add counter to count how many attempts before success
}

// Use random number generator to generate array
void randArrayGen(int array[], int a)
{
    time_t t;
    srand((unsigned) time(&t));

    for (int x=a-1; x>0; x--)
    {
        int y = rand() % (x+1);
        swapInt(&array[x], &array[y]);
    }
}