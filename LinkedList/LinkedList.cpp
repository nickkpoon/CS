#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

/* destructor
 *
 */
LinkedList::~LinkedList()
{
	Node *tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->getNext();
		delete(tmp);
	}
}


/* addHead
 * add an item to the front of the linked list
 */

void LinkedList::addHead(int v)
{
	// create a new Link and put v into that Link
	Node *n = new Node(v);
	// if the list is empty, this node is the only thing in it
	// all we need to do is point head to the node
	if (head == NULL)
	{
		head = n;
		tail = n;
	}
	// if there is already something there, we point this new node
	// to the old head of the list.  Then, when we point head to this
	// Link, it becomes the beginning of the list, and the old beginning
	// is now 2nd.
	else
	{
		n->setNext(head);
		head = n;
	}
}

/* addTail
 * add an element to the end of the linked list
 * TODO: properly update the tail pointer
 * make code more efficient if tail pointer helps
 */

void LinkedList::addTail(int v)
{
	// make a new node for the new item
	Node *n = new Node(v);
	// if the list is empty, this is the only one
	if (head == NULL)
	{
		head = n;
		tail = n;
	}
	// otherwise, we need to go to the back and add the node
	else
	{
		tail->setNext(n);
		tail = n;
	}
}

/* removeHead
 * remove the first element in a linked list
 * TODO: update tail pointer
 */

int LinkedList::removeHead()
{
	// if the list is empty, return 0
	if (head == NULL)
		return 0;
	// set a temporary pointer to head
	Node *tmp = head;
	// advance head so it points to the next one
	head = head->getNext();
	// record the return value before deleting the Link
	int retval = tmp->getValue();
	// delete the Link
	delete tmp;
	// return the value
	return retval;
}

/* removeTail
 * remove the last element of a linked list
 * make code more efficient if tail pointer helps
 */
int LinkedList::removeTail()
{
	// if the list is empty, return 0
	if (head == NULL)
		return 0;
	// if there is only one item, remove it
	if (head->getNext() == NULL)
	{
		// record the value to return
		int retval = head->getValue();
		// delete the Link
		delete head;
		// set head to NULL, indicating an empty list
		head = NULL;
		tail = NULL;
		// return the value from that Link
		return retval;
	}
	// advance to the next to last node
	Node *tmp;
	for(tmp = head;tmp->getNext()->getNext() != NULL; tmp = tmp->getNext())
		;
	
	// record the return value
	int retval = tail->getValue();
	// delete the Node
	delete tail;
	// set this node to be pointing to null, removing the Link
	tmp->setNext(NULL);
	tail = tmp;
	
	// return the value
	return retval;
}

/* removeNextToLast
 * remove the next to last element of a linked list
 * make code more efficient if tail pointer helps
 */
int LinkedList::removeNextToLast()
{
	// if the list is empty, return 0
	if (head == NULL)
		return 0;
	// if there is only one item, remove it
	if (head->getNext() == NULL)
	{
		return 0;
	}
	// if there are two items, then head is changing
	if (head->getNext() == tail)
	{
		// record the value to return
		int retval = head->getValue();
		// delete the Link
		delete head;
		// now head points to tail
		head = tail;
		return retval;
	}
	// advance to the next to next to last node
	Node *tmp, *tmp2;
	for(tmp = head;tmp->getNext()->getNext() != tail; tmp = tmp->getNext());
	
	tmp2 = tmp->getNext(); // point to the next to last node
	// record the return value
	int retval = tmp2->getValue();
	// delete the Node
	delete tmp2;
	// set this node to be pointing to null, removing the Link
	tmp->setNext(tail);
	
	// return the value
	return retval;
}

/* removeNextToLastRec
 *
 * public method for recursive implementation
 * TODO: fill in the code
 */
int LinkedList::removeNextToLastRec()
{
	// first do the base cases that do not require recursion
	if (head == NULL)
		return 0;
	if (head->getNext() == NULL)
	{
		return 0;
	}

	if (head->getNext() == tail)
	{
		// record the value to return
		int retval = head->getValue();
		// delete the Link
		delete head;
		// now head points to tail
		head = tail;
		return retval;
	}

	// if none of those were true, call the recursive helper method
	return removeNextToLastRec(head);
}

int LinkedList::removeNextToLastRec(Node *h)
{
	// check for the base case(s)
	if (h == NULL)
		return 0;
	if (h->getNext()->getNext()->getNext() == NULL)
	{
		Node *tmp;
		tmp = h->getNext();
		int retval = tmp->getValue();
		// delete the Node
		delete tmp;
		// set this node to be pointing to null, removing the Link
		h->setNext(tail);
	
		// return the value
		return retval;
	}
	// else call the recursive method
	else
	{
		return removeNextToLastRec(h->getNext());
	}
}

/* countOccurrencesMoreThan
 * 
 * iterative implementation of countOccurrencesMoreThan
 */
int LinkedList::countOccurrencesMoreThan(int m)
{
	int sum = 0; // return value from base case
	Node *tmp;
	for(tmp = head;  // initial call into the private recursive func
			tmp != NULL;  // similar to base case if stmt
			tmp = tmp->getNext()) // smaller case input arg
		if (tmp->getValue() > m) // general case
			sum++;	// general case
	return sum;
	
}

/* countOccurrencesMoreThanRec
 *
 * public method that calls the recursive method
 * TODO: fill in this code
 */
 
int LinkedList::findMax()
{
	if (head == NULL)
		return 0;
		
	return findMax(head);

}

int LinkedList::findMax(Node *h)
{
	if (h == NULL)
		return 0;
	int max = findMax(h->getNext());
	if (max > h->getValue())
		return max;
	else
		return h->getValue();
		
}

int LinkedList::findSum(Node *h)
{
	if (h == NULL)
		return 0;
	else
		return findSum(h->getNext()) + h->getValue();
		

}

int LinkedList::findSum()
{
	if (head == NULL)
		return 0;
		
	return findSum(head);
}

int LinkedList::findIndex(int n)
{
	if (head == NULL)
		return 0;
		
	return findIndex(head, n);
}

int LinkedList::findIndex(Node *h, int n)
{
	if (h == NULL)
		return 0;
	if (h->getValue() == n)
		return 0;
	return findIndex(h->getNext(), n)+1;
}

int LinkedList::countOccurrencesMoreThanRec(int m)
{
	
	// first do the base cases that do not require recursion
	if (head == NULL)
	{
		return 0;
	}
	// if none of those were true, call the recursive helper method
	return countOccurrencesMoreThan(head, m);
}

/* countOccurrencesMoreThan
 *
 * private recursive method.  
 * TODO: fill in this method
 */

int LinkedList::countOccurrencesMoreThan(Node *h, int m)
{
	if(h == NULL)
		return 0;
	if(h->getValue() > m)
		return countOccurrencesMoreThan(h->getNext(), m) + 1;
	else
		return countOccurrencesMoreThan(h->getNext(), m);
		

       

}
void LinkedList::printList(FILE *f)
{
	Node *tmp;
	fprintf(f,"Printing iteratively forwards: ");
	fprintf(f,"List: ");
	for(tmp = head; tmp != NULL; tmp = tmp->getNext())
	{
		tmp->printNode(f);
		fprintf(f,", ");
	}
	fprintf(f,"\n");
}

/* addNth
 *
 * ITERATIVE implementation
 */
void LinkedList::addNth(int n, int v)
{
	if ( n < 0)
		return;

	Node *addedNode, *tmp;
	addedNode = new Node(v);
	if(head==NULL)
	{
		addHead(v);
		return;
	}	
	
	if(n == 0)
	{
		addedNode->setNext(head);
		head = addedNode;
		return;
	}
	
	for(tmp = head; n >1 && tmp->getNext()!=NULL; tmp = tmp->getNext(), n--);
	if ( tmp -> getNext() == NULL)
	{
		tmp -> setNext(addedNode);
		tail = addedNode;   
	}
	else //
	{
		addedNode->setNext(tmp->getNext());
		tmp->setNext(addedNode);
		
	}
	
}

/* addNth
 *
 * RECURSIVE public implementation of addNth
*/
void LinkedList::addNthRec(int n, int v)
{

	// base case(s) outside of recursive call
	if ( n < 0)
		return;
	if(head==NULL)
	{
		addHead(v);
		return;
	}	
	if(n == 0)
	{	
		Node *addedNode = new Node(v);
		addedNode->setNext(head);
		head = addedNode;
		return;
	}
	
	// call recursive method
	return addNthRec(head, n, v);

}

void LinkedList::addNthRec(Node *h, int n, int v)
{

	// base case(s)
	if (n == 1 || h->getNext()==NULL)
	{
		Node *addedNode = new Node(v);
		addedNode->setNext(h->getNext());
		h->setNext(addedNode);
		return;
	}

	// smaller case
	h = h->getNext();
	n = n-1;	


	// general case
	return addNthRec(h,n, v);
}

/* removeNth
 *
 * ITERATIVE implementation
 */
int LinkedList::removeNth(int n)
{
	if ( n < 0 || head==NULL)
		return 0;

	Node *tmp, *tmp2;
	int retval;
	
	if(head==tail)
	{
		if(n==0)
		{	
			retval = head->getValue();
			removeHead();
			return retval;
		}
		else
			return 0;
	}

	if(n == 0)
	{		
		
		tmp2 = head;
		retval = head->getValue();
		head = head->getNext();
		delete tmp2;
		return retval;
	}
	
	for(tmp = head; n >1 && tmp->getNext()->getNext()!=NULL; tmp = tmp->getNext(), n--);
	//if(tmp->getNext()==NULL)
	//	return 0;	
	if ( tmp -> getNext()->getNext() == NULL)
	{
		if (n>1)
			return 0;
			
		tmp2 = tmp->getNext();
		tail = tmp;		
		retval = tmp2->getValue();	
		tmp->setNext(NULL);		
		delete tmp2;
		return retval;
	}
	else //
	{
		tmp2 = tmp->getNext();
		retval = tmp2->getValue();
		tmp->setNext(tmp->getNext()->getNext());
		delete tmp2;
		return retval;
		
	}
}

/* removeNth
 *
 * RECURSIVE public implementation of removeNth
*/
int LinkedList::removeNthRec(int n)
{

	// base case(s) outside of recursive call
	if ( n < 0 || head==NULL)
		return 0;		

	Node *tmp2;
	int retval;

	if(n == 0)
	{		
		
		tmp2 = head;
		retval = head->getValue();
		head = head->getNext();
		delete tmp2;
		return retval;
	}
	
	// call recursive method
	return removeNthRec(head,n);

}

int LinkedList::removeNthRec(Node *h, int n)
{
	
	if (h->getNext()== NULL)
		return 0;
	// base case(s)
	if (n ==1 || h->getNext()->getNext()==NULL)
	{
		if (n>1)
			return 0;
		if (h->getNext()->getNext()==NULL)
			tail = h;
		Node *tmp2;
		int retval;
		
		tmp2 = h->getNext();

		retval = tmp2->getValue();
		h->setNext(h->getNext()->getNext());
		delete tmp2;
		return retval;
	}

	// smaller case
	h = h->getNext();
	n = n-1;


	// general case
	return removeNthRec(h,n);
}

int LinkedList::peekTail()
{
	return tail->getValue();

}

int LinkedList::peekHead()
{
	return head->getValue();
}
