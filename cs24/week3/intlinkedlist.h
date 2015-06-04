#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H

typedef struct _node {
	int value;
	struct _node *next;
} node;

typedef struct _linkedlist {
	node *head;
} linkedlist;


linkedlist *createAndInitializeLinkedList();
void addHead(linkedlist *, int);
void printList(linkedlist *, FILE *);

#endif

