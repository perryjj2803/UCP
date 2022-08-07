#include <stdio.h>
#include "snake_movement.h"
#include "terminal.h"
#include "linkedlist.h"
/*movement function used to handle both user input and snake movement as well as determining the state of the snake head depending on which way the snake is facing based on the last user input*/
void movement(LinkedListNode* currentNode)
{
	char move;
	disableBuffer();
	scanf("%c", &move);
	enableBuffer();

	switch (move)
	{
	case 'a':
		currentNode -> snakeXValue = currentNode -> snakeXValue-1;
        currentNode -> nodeChar = '<';
		break;

	case 'd':
		currentNode -> snakeXValue = currentNode -> snakeXValue+1;
		currentNode -> nodeChar = '>';
		break;

	case 'w':
		currentNode -> snakeYValue = currentNode -> snakeYValue-1;
		currentNode -> nodeChar = '^';
	    break;

	case 's':
		currentNode -> snakeYValue = currentNode -> snakeYValue+1;
		currentNode -> nodeChar = 'v';
		break;

	default:
		perror("Invalid input for snake direction");
	}
}