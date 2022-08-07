#include <stdio.h>
#include "area.h"
#include "neighbours.h"

/*This function counts neighbours of a given cell X and Y value*/
int neighbours(int** playArea, int xValue, int yValue)
{
    int i, j;
    int sum = 0;
    for(i = xValue-1; i < xValue+1; i++)
    {
        for(j = yValue-1; j < yValue+1; j++)
        {
            sum += playArea[i][j];
        }
    }
    sum -= playArea[xValue][yValue];/*This is necessary to remove the cell from the count*/
    return sum;
}
