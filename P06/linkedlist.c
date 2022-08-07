#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


LinkedList* createLinkedList()
{
	LinkedList* list;
	list = (LinkedList*)malloc(sizeof(LinkedList));
	list -> head = NULL;
	list -> count = 0;

	return list;
}

void insertStart(LinkedList* list, void* entry)
{
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode*));
	newNode-> value = entry;

	newNode-> next = list -> head;

	list -> head = newNode;
	list -> count++;	
}

/*
void* removeStart(LinkedList* list)
{
	void* value = NULL;

	LinkedListNode* temp;
	temp = list -> head;

	if(list -> head != NULL)
	{
		value = list -> head -> value;
		list -> head = list -> head -> next;

		free(temp);
		temp = NULL;
	}
	else
	{
		perror("List is empty");
	}
	list -> count--;
	return value;
}

void insertLast(LinkedList* list, void* entry)
{
	LinkedListNode* currentNode;

	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode*));
	newNode -> value = entry;
	newNode -> next = NULL;
	
	currentNode = list ->  head;

	if(list -> head == NULL)
	{
		list -> head = newNode;
	}
	else
	{
		while(currentNode -> next != NULL)
	{
		currentNode = currentNode -> next;
	}
	currentNode -> next = newNode;
	}
	list -> count++;
}

void* removeLast(LinkedList* list)
{
	LinkedListNode* currentNode;
	void* value;
	if(list -> head == NULL)
	{
		perror("Cannot remove a node from an empty list");
	}

	currentNode = list -> head;

	while(currentNode -> next != NULL)
	{
		currentNode = currentNode -> next;
	}
	value = currentNode -> value;
	free(currentNode);
	currentNode = NULL;
	list -> count--;
	return value;
}

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
			(*funcPtr)(currentNode -> value);
		}	
	}
	else
	{
		perror("List is empty");
	}
}

void freeLinkedList(LinkedList* list, listFunc funcPtr)
{
}
*/

