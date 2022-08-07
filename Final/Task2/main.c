#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "area.h"
#include "neighbours.h"

int main(int argc, char *argv[])
{
    int cycles, cycleCount;
    int i, j;
    int numCol, numRow;

    cycles = atoi(argv[2]);

    if(((argc == 3) && (cycles >= 0)))
    {

        FILE *f = fopen(argv[1], "r");
        if(f == NULL)
        {
            printf("Error: could not open the cell file\n");
        }
        else
        {
            fscanf(f, "%d %d", &numCol, &numRow);

            int** playArea;
            /*int** nextPlayArea; Store values for the next cell generation*/
            playArea = initialarray(numCol, numRow);
            /*nextPlayArea = initialarray(numCol, numRow);*/

            for(i=0; i < numCol; i++)
            {
                for(j=0; j < numRow; j++)
                {
                    fscanf(f, "%d ", &playArea[i][j]);
                }
                fscanf(f,"\n");
            }
            /* The following segment of code was used to ensure the FileIO worked appropriately and was frequently used while debugging until the colour function was implemented.*/
            /*for(i=0; i < numCol; i++)
            {
                for(j=0; j < numRow; j++)
                {
                    printf("%d ", playArea[i][j]);
                }
                printf("\n");
            }*/

            fclose(f);
            /* Purpose of the for loop is to simulate the game of life, but due to my neighbour count function being incomplete this loop cannot be used effectively*/
            for(cycleCount=0; cycleCount < cycles; cycleCount++)
            {
                system("clear");
                printArea(numRow, numCol, playArea);
                sleep(1);
            }
            freeArea(playArea, numRow, numCol);
        }
    }
    else
    {
        perror("Invalid number of arguments. Total of 3 arguments required 1. Life executable 2. Cell text file 3. Number of cycles to perform (is greater than 0)");
    }
    return 0;
}
