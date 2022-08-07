#include <stdio.h>
#include "game_condition.h"
#include "linkedlist.h"
#include "random_generator.h"

/* condition function used to determine whether the loop was to continue if a win/lose condition is not met*/
int condition(LinkedListNode* currentNode, int winCond, int foodXValue, int foodYValue, int numRow, int numCol, int lowerX, int lowerY, int foodToWin, int foodTally)
{
	if (currentNode -> snakeYValue > numRow-2 || currentNode -> snakeYValue < 1 || currentNode -> snakeXValue > numCol-2 || currentNode -> snakeXValue < 1)
	{
		printf("Game-over; out of bounds");
		winCond = 1; /*game over due to collision with boundary*/
	}
	else if((currentNode -> snakeXValue == foodYValue) && (currentNode -> snakeYValue == foodXValue))
	{
		/*if food has been consumed, then the food consumed tally increments and is printed out as a fraction to display how much food must be consumed til game is won*/		
		
		/*foodXValue = Random(lowerX, numRow-2);
		foodYValue = Random(lowerY, numCol-2);*/
		foodTally++;
		winCond = 0;
	}
	else if(foodTally == foodToWin)
	{
		/*if number of food consumed to win is met then the game is won*/
		winCond = 1;
		printf("Game won!");
	}
	else
	{
		winCond = 0; /*game over/win condition has not been met, continue with game*/
	}
	return winCond;
}