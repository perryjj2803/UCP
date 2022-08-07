#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
	void* value;
	struct LinkedListNode* next;
}LinkedListNode;

typedef struct
{
	LinkedListNode* head;
	int count;
}LinkedList;

typedef void (*listFunc)(void* data);


#endif