#include <stdio.h>
#include <stdlib.h>

#include "map.h"

/*used to move the snake head*/
int movement(char move, int row, int col, int* pX, int* pY, char** array, char *pdir, int* tx, int* ty)
{
    int temp, tempx, tempy;
    int con = 0; /*win or lose condition*/
    char t;

    if (move == 'w')
    {
        if(*pX-1 < 0) /*if arrow hitting border, do this*/
        {
            printf("cant move outside border\n");
        }
        else if (array[*pX-1][*pY] == '|') /*if arrow hitting backwards into its own tail, do this*/
        {
            printf("cant move backwards\n");
        }
        else /*move arrowhead up if no obstacles in the ways*/
        {
            tempx = *tx - 1;
            tempy = *ty;

            array[*tx][*ty] = ' ';
            *tx = tempx;

            array[*pX][*pY] = '|';

            temp = *pX - 1;
            *pX = temp;

            t = '^';
            *pdir = t;  
      
        }    
    }
    /*similar to the rest of the code*/
    else if (move == 's')
    {
        if(*pX+1 >= row)
        {
            printf("cant move outside border\n");
        }
        else if (array[*pX+1][*pY] == '|')
        {
            printf("cant move backwards\n");
        }
        else
        {
            tempx = *tx + 1;
            tempy = *ty;               

            array[*tx][*ty] = ' ';
            *tx = tempx;

            array[*pX][*pY] = '|';

            temp = *pX + 1;
            *pX = temp;

            t = 'v';
            *pdir = t;
        }
    }
    else if (move == 'd')
    {

        if(*pY+1 >= col)
        {
            printf("cant move outside border\n");
        }
        else if (array[*pX][*pY+1] == '-')
        {
            printf("cant move backwards\n");
        }
        else
        {
            tempy = *ty + 1;
            tempx = *tx;            

            array[*tx][*ty] = ' ';
            *ty = tempy;

            array[*pX][*pY] = '-';

            temp = *pY + 1;
            *pY = temp;

            t = '>';
            *pdir = t;            
        }

    }
    else if (move == 'a')
    { 
        if(*pY-1 < 0)
        {
            printf("cant move outside border\n");
        }
        else if (array[*pX][*pY-1] == '-')
        {
            printf("cant move backwards\n");
        }
        else
        {
            tempy = *ty - 1;
            tempx = *tx;            

            array[*tx][*ty] = ' ';            
            *ty = tempy;

            array[*pX][*pY] = '-';

            temp = *pY - 1;
            *pY = temp;

            t = '<';
            *pdir = t;

        }
    }

    return(con);
}