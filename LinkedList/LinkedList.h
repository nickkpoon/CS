#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
  private:
	Node *head;
	Node *tail; // add this tail
	// private recursive helper methods
	int countOccurrencesMoreThan(Node *,int m);
	int removeNextToLastRec(Node *);
	// private recursive helper methods for problems
	void addNthRec(Node *, int n, int v);
	int removeNthRec(Node *, int n);
	int findMax(Node *);
	int findSum(Node *);
	int findIndex(Node *, int n);

  public:
	LinkedList();
	// implement the copy constructor
	LinkedList(LinkedList &otherlist);
	// implement the destructor
	~LinkedList();

	void addHead(int v);
	void addTail(int v);
	int removeHead();
	int peekTail();
	int peekHead();
	int removeTail();
	// provided for warmup
	int removeNextToLast();
	int countOccurrencesMoreThan(int m);
	void printList(FILE *f);
	// iterative versions for problems (you must implement)
	void addNth(int n, int v);
	int removeNth(int n);

	// recursive methods to add for warmup
	int countOccurrencesMoreThanRec(int m);
	int removeNextToLastRec();
	int findMax();
	int findSum();
	int findIndex(int n);
	// recursive methods to add for problems
	void addNthRec(int n, int v);
	int removeNthRec(int n);
};

#endif
