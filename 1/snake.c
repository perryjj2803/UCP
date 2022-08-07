/*main function to run from*/
#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "random.h"
#include "terminal.h"
#include "move.h"

/*used to free the array*/
void Freearray(char** arr, int rows)
{
    int i;
    for(i = 0; i < rows; ++i)
    {
        free(arr[i]);
    }
    free(arr);
}

/*main function*/
int main(int argc, char *argv[])
{
    int row_map, col_map, snk_len;
    char move;
    int con = 0;

    /*check how many arguments there are*/
    if(argc == 4)
    {
        sscanf(argv[1],"%d", &row_map);
        sscanf(argv[2],"%d", &col_map);
        sscanf(argv[3],"%d", &snk_len);
        /*check if any breaking conditions are present*/
        if(snk_len<col_map)
        {
            if(row_map >= 5 || col_map >= 5)
            {
                if(snk_len >= 3)
                {
                    /*core of the program*/
                    int foodX, foodY;
                    int px, py; /*snake head coordinates*/
                    int tx, ty;
                    char pdir;
                    char **arr;
                    py = snk_len-1, px = 0;
                    ty = 0, tx = 0;
                    pdir = '>';
                    initRandom();

                    /*food randomisation*/    
                    foodX = randomN(1,row_map-1);
                    foodY = randomN(0,col_map-1);

                    /* start game*/
                    /* initializes the grid*/
                    arr = grid(row_map, col_map, foodX, foodY, snk_len, px, py, pdir, tx, ty);
                    system("clear");

                    /*con is the win/lose condition, where con = 0 means no win or loss*/
                    while(con == 0)
                    { 
                        /*prints grid and starts the game*/
                        print_2d_array(row_map, col_map, arr);
                        printf("%d %d", tx, ty);

                        disableBuffer();
                        scanf("%c",&move);
                        enableBuffer();

                        arr[px][py] = ' ';

                            /*checks move and does accordingly*/
                            if(move == 'd'||move == 's'||move == 'a'||move == 'w')
                            {
                                con = movement(move, row_map, col_map, &px, &py, arr, &pdir, &tx, &ty);
                                if(px == foodX && py == foodY)
                                {
                                    con = 1;
                                }
                            }
                        arr[px][py] = pdir;
                        system("clear");
                    }
                    /*con 1 = win*/
                    if(con == 1)
                    {
                        printf("you win!\n");
                    }
                    /*con 2 = lose*/
                    if(con == 2)
                    {
                        printf("you lose\n");
                    }
                    /*frees the array*/
                    Freearray(arr, row_map);
                }
                else
                {
                    printf("snake length has to be longer!\n");
                }
            }
            else
            {
                printf("please make better dimensions for the grid!\n");
            }
        }
        else
        {
            printf("snake length cannot be longer than column dimensions!\n");
        }
    }
    else
    {
        printf("please input 3 integers in the format of (row)(column)(length)\n");
    }
    return(0);
}