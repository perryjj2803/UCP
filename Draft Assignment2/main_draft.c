#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "play_area.h"
#include "random_generator.h"
#include "terminal.h"
#include "snake_movement.h"
#include "game_condition.h"
#include "linkedlist.h"

int main(int argc, char** argv)
{

 /*If user does not provide the right number of arguments, the program will print perror*/
	if( argc == 2)
	{        
        LinkedList* list = createLinkedList();
        int ch, numRow, numCol, snakeXValue, snakeYValue, foodXValue, foodYValue, lowerX, lowerY;
        char nodeChar;
        int i = 0;
        char** playArea;

    	initRandom();

	    foodXValue = Random(lowerX, numRow-2);
	    foodYValue = Random(lowerY, numCol-2);

	    playArea = initialarray(numRow, numCol);
    
        FILE *f = fopen(argv[1], "r");
        if(f == NULL)
        {
            printf("Error: could not open the file 'snake.txt'\n");
        }
        else
        {
            fscanf(f, "%d %d", &numRow, &numCol);

            for(i=0; i < 8; i++)
            {
                fscanf(f, "%d %d %c", &snakeXValue, &snakeYValue, &nodeChar);
                insertStart(list, snakeXValue, snakeYValue, nodeChar);
                printf("snake co ordinates are %d %d and the character is %c \n", &snakeXValue, &snakeYValue, &nodeChar);
            }
            fclose(f);
        }
        
   		int lowerX = 2; /*set lower bound for random number generator Xvalue to prevent food from spawning on top row*/
		int lowerY = 1;
		int foodXValue, foodYValue;
		int snakeXValue = 1; /*initialize snake in top row*/
		int snakeYValue = snakeSize; /*initialize snake in top row with y value being equivalent to head of snake*/
        char headDirection = '>';
		char direction;
		int loop = 0;

		/*int* tailXValue = (int*)malloc(sizeof(int)*numCol); inted use for initializing an array of tail X co-ordinates*/
		/*int* tailYValue = (int*)malloc(sizeof(int)*numCol); inted use for initializing an array of tail Y co-ordinatres*/

    	char** playArea;

   		initRandom();

		foodXValue = Random(lowerX, numRow-2);
		foodYValue = Random(lowerY, numCol-2);

		playArea = initialarray(numRow, numCol);
		
		while(loop == 0)
		{
			printarray(playArea, numRow, numCol, foodXValue, foodYValue, snakeXValue, snakeYValue, headDirection);
		
			/*printf("%d%d\n" ,foodXValue ,foodYValue); used for debugging food co-ordinates in print due to segmentation faults and ensuring food does not print on top line where snake is initialized*/
			/*printf("%d%d\n" ,snakeXValue, snakeYValue); used for debugging snake head co-ordinates to ensure it is printing within the play area when segmentation faults were present*/
			/*printf("%d%d\n" ,numRow-2, numCol-2); used for debugging play area size*/
				
			movement(&snakeXValue, &snakeYValue, &headDirection, &direction);
			/*tail_movement(snakeXValue, snakeYValue, tailLength, &tailYValue, &tailXValue); function to handle tail X and Y value translation for each head movement*/
			loop = condition(&snakeXValue, &snakeYValue, loop, numRow, numCol, foodXValue, foodYValue);
			system("clear");	

		}
		freeplayArea(playArea, numRow, numCol);
		/*free(tailXValue); planned on using this to clear tailXValue pointer memory but snake tail wasnt working*/
		/*free(tailYValue); planned on using this to clear tailYValue pointer memory but snake tail wasnt working*/	
	}
	else
	{
		perror("Incorrect amount of arguments. Program Usage: ./snake <row_map> <col_map> <snake_length>");	
	}
	return 0;
}
