#include <stdio.h>
#include "game_condition.h"

/* condition function used to determine whether the loop was to continue if a win/lose condition is not met*/
int condition(int *snakeXValue, int *snakeYValue, int loop, int numRow, int numCol, int foodXValue, int foodYValue)
{
	if (*snakeXValue > numRow-2 || *snakeXValue < 1 || *snakeYValue > numCol-2 || *snakeYValue < 1)
	{
		loop = 1; /*game over due to collision with boundary*/
		printf("Game-over; out of bounds");
	}
	else if(*snakeXValue == foodXValue && *snakeYValue == foodYValue)
	{
		loop = 1; /*game won from eating food*/
		printf("Game won!");
	}
	else
	{
		loop = 0; /*game over/win condition has not been met, continue with game*/
	}
	return loop;
}