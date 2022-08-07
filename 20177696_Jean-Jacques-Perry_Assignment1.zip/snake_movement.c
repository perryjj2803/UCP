#include <stdio.h>
#include "snake_movement.h"
#include "terminal.h"
/*movement function used to handle both user input and snake head movement as well as determining the state of the snake head depending on which way the snake is facing based on the last user input*/
void movement(int *snakeXValue, int *snakeYValue, char *headDirection, char *direction)
{
	char move;
	disableBuffer();
	scanf("%c", &move);
	enableBuffer();

	switch (move)
	{
	case 'a':
		*snakeYValue = *snakeYValue-1;
        *headDirection = '<';
		*direction = 'l'; /*left*/
		break;

	case 'd':
		*snakeYValue = *snakeYValue+1;
        *headDirection = '>';
		*direction = 'r'; /*right*/
		break;

	case 'w':
		*snakeXValue = *snakeXValue-1;
        *headDirection = '^';
		*direction = 'u'; /*up*/
	    break;

	case 's':
		*snakeXValue = *snakeXValue+1;
        *headDirection = 'v';
		*direction = 'd'; /*down*/
		break;

	default:
		perror("Invalid input for snake direction");
	}
}