#include <cstdlib>
#include <cstdio>
using namespace std;
#include "LinkedList.h"


int main(int argc, char *argv[])
{

	int iArray1[] = {5,7,3,1,9,6,3,0,7,5,7,2};
	int results;
	int i;
	

	LinkedList *list = new LinkedList();
	printf("Start with an empty list\n");
	list->printList(stdout);

	printf("Insert value 10\n");
	list->addTail(10);

	printf("Insert 15 in back\n");
	list->addTail(15);

	printf("Insert 3 in front\n");
	list->addHead(3);
	list->printList(stdout);

	printf("adding a bunch of 7's, 8's and 3's\n");
	list->addHead(8);
	list->addHead(3);
	list->addHead(3);
	list->addHead(7);
	list->addHead(3);
	list->addHead(7);
	list->addHead(7);
	list->addHead(3);
	list->addHead(3);
	list->addHead(7);
	list->addHead(7);
	list->addHead(7);
	list->addHead(8);
	list->addHead(8);
	list->addHead(9);
	list->addHead(8);
	list->addHead(3);
	list->addHead(3);
	list->addHead(7);
	list->addHead(8);

	list->printList(stdout);
	int num5s = list->countOccurrencesMoreThan(5);
	int num10s = list->countOccurrencesMoreThan(10);
	printf("There are %d > 5's and %d > 10's\n",
		num5s,num10s);
	
	num5s = list->countOccurrencesMoreThanRec(5);
	num10s = list->countOccurrencesMoreThanRec(10);
	printf("Recursive method says there are %d > 5's and %d > 10's\n",
		num5s,num10s);
	
	int max = list->findMax();
	printf("The max is %d \n", max);
	
	int sum = list->findSum();
	printf("The sum is %d \n", sum);
	
	int index = list->findIndex(3);
	printf("the number 3 is at index %d", index);
	
	int count = list->
	/*
	// now let's remove the tail a few times
	printf("Removing a bunch of nodes with iterative removeNextToLast\n");
	for(i=0;i<15;i++)
	{
		list->removeNextToLast();
		list->printList(stdout);
	}

	printf("Removing a few with recursive remove next to last\n");
	printf("Removed %d\n",list->removeNextToLastRec());
	list->printList(stdout);
	printf("Removed %d\n",list->removeNextToLastRec());
	list->printList(stdout);
	printf("Removed %d\n",list->removeNextToLastRec());
	list->printList(stdout);
	printf("Removed %d\n",list->removeNextToLastRec());
	list->printList(stdout);
	printf("Removed %d\n",list->removeNextToLastRec());
	list->printList(stdout);
	printf("Removed %d\n",list->removeNextToLastRec());
	list->printList(stdout);
	printf("Removed %d\n",list->removeNextToLastRec());
	list->printList(stdout);

	printf("Inserting in some different locations (iteratively)\n");
	list->addNth(-1,9);
	printf("Inserted 9 in location -1\n");
	printf("head: %i, tail: %i", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->addNth(0,11);
	printf("Inserted 11 in location 0\n");
	printf("head: %i, tail: %i", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->addNth(1,19);
	printf("Inserted 19 in location 1\n");
	printf("head: %i, tail: %i", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->addNth(7,19);
	printf("Inserted 19 in location 7\n");
	printf("head: %i, tail: %i", list->peekHead(), list->peekTail());
	list->printList(stdout);

	printf("Inserting in some different locations (recursively)\n");
	list->addNthRec(0,9);
	printf("Inserted 9 in location 3\n");
	list->printList(stdout);
	list->addNthRec(5,11);
	printf("Inserted 11 in location 5\n");
	list->printList(stdout);
	list->addNthRec(1,19);
	printf("Inserted 19 in location 1\n");
	list->printList(stdout);
	list->addNthRec(100,19);
	printf("Inserted 19 in location 100\n");
	list->printList(stdout);
	
	printf("R'ed in some different locations (recursively)\n");
	list->removeNth(3);
	printf("R'ed in location 3\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->removeNth(5);
	printf("R'ed in location 5\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->removeNth(1);
	printf("R'ed in location 1\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->removeNth(4);
	printf("R'ed in location 4\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->removeNth(3);
	printf("R'ed in location 3\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->removeNth(3);
	printf("R'ed in location 3\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->removeNth(4);
	printf("R'ed in location 4\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->removeNth(2);
	printf("R'ed in location 2\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->removeNth(1);
	printf("R'ed in location 1\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	list->removeNth(5);
	printf("R'ed in location 5\n");
	printf("head: %i, tail: %i\n", list->peekHead(), list->peekTail());
	list->printList(stdout);
	

	printf("deleting list\n");
	delete(list);
	printf("Exiting\n");
	*/
}

