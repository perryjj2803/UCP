#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
	int snakeXValue;
	int snakeYValue;
	char nodeChar;
	struct LinkedListNode* next;
}LinkedListNode;

typedef struct 
{
	LinkedListNode* head;
	int count;
}LinkedList;

typedef void (*listFunc)(void* data);

LinkedList* createLinkedList();
LinkedListNode* createNode(int snakeXValue, int snakeYValue, char nodeChar);
void insertStart(LinkedList* list, LinkedListNode* newNode);
void printLinkedList(LinkedList* list, listFunc funcPtr);
void freeLinkedList(LinkedList* list);

#endif