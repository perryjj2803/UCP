#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/*function to create linkedlist*/
LinkedList* createLinkedList()
{
	LinkedList* list;
	list = (LinkedList*)malloc(sizeof(LinkedList));
	list -> head = NULL;
	list -> count = 0;

	return list;
}

/*function to create a node within the linkedlist*/
LinkedListNode* createNode(int snakeXValue, int snakeYValue, char nodeChar)
{
	LinkedListNode* newNode;
	newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	newNode -> next = NULL;
	newNode -> snakeXValue = snakeXValue;
	newNode -> snakeYValue = snakeYValue;
	newNode -> nodeChar = nodeChar;

	return newNode;
}

/*function used to insert a snake body part at the start of the snake*/
void insertStart(LinkedList* list, LinkedListNode* newNode)
{
	newNode -> next = list -> head;
	list -> head = newNode;	
	/*count++;*/
}

/* didnt end up using this function to print the linked list. Idea was to create a generic linkedlist print function
void printLinkedList(LinkedList* list, listFunc funcPtr)
{
	LinkedListNode* currentNode;
	int count = 0;
	if(list -> head != NULL)
	{
		currentNode = list -> head;

		while(currentNode -> next != NULL)
		{
			currentNode = currentNode -> next;
			printf("Node number: %d\n" ,count++);
			(*funcPtr)(currentNode -> snakeX);
			(*funcPtr)(currentNode -> snakeY);
			(*funcPtr)(currentNode -> nodeChar);
		}	
	}
	else
	{
		perror("List is empty");
	}
}
*/

/*function used to free memory of snake linkedlist*/
void freeLinkedList(LinkedList* list)
{
	LinkedListNode* currentNode = list -> head;
	LinkedListNode* temp;

	while(currentNode != NULL)
	{
		temp = currentNode -> next;
		free(currentNode);
		currentNode = temp;
	}
	free(list);
}


