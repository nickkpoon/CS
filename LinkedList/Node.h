#ifndef NODE_H
#define NODE_H
#include <cstdio>
#include <cstdlib>

class Node {
  private:
	int value;
	Node *next;
	static int count;

  public:
	Node(int v)
	{
	value = v; 
	next = NULL;
	}

	void setValue(int v){value = v;}
	void setNext(Node *n){next = n;}
	int getValue(){return value;}
	Node *getNext(){return next;}
	static int getCount(){return count;}

	void printNode(FILE *f){fprintf(f,"%d",value);}
};

#endif
