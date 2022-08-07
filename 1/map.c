/*function used to create the array for everything*/
#include <stdio.h>
#include <stdlib.h>

#include "random.h"

/* printing out the border of the array*/
void print_2d_array(int rows, int cols, char **a) 
{
    int i,j;
    for(j=0; j<cols+2; ++j)
    {
        printf("*");
    }

    for(i=0; i<rows; ++i)
    {
        printf("\n*");
        for(j=0; j<cols; j++)
        {
            printf("%c",a[i][j]);
        }
        printf("*");
    }

    printf("\n");
     for(j=0; j<cols+2; ++j)
    {
        printf("*");
    }
    printf("\n");
}

/*creates the grid and all the elements in the grid(snake and fruit included)*/
char** grid(int sizerows, int sizecols, int foodX, int foodY, int length, int px, int py, char pd, int tx, int ty)
{
    /*stating all the variables*/
    int rows = sizerows, cols = sizecols;
    int i,j;
    int count;
    char fruit = '@';

    /*dynamically allocate*/
    char **arr = malloc(rows * sizeof(char*));
    for(i = 0; i<rows; ++i)
    {
        arr[i] = malloc(cols * sizeof(char*));
    } 

    /*placing empty array*/
    for(i=0;i<rows;i++)
    {
        for(j=0; j<cols; j++)
        {
            arr[i][j] = ' ';
        }
    }

    arr[px][py] = pd; /*made the snake head*/
    arr[foodX][foodY] = fruit; /*made */
    arr[tx][ty] = '-'; 

    for(count=0; count<=length-2;count++) /*made the snake body of symbol "-*/
    {
        arr[0][count] = '-';
    }
    
    
    system("clear");
    print_2d_array(rows, cols, arr);
    
    return (arr);
}