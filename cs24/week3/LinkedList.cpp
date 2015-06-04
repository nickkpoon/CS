#include <cstdio>
#include <cstdlib>

#include "LinkedList.h"

/* Node constructor
 *
 */
Node::Node()
{
	data = 0;
	next = NULL;
}

Node::Node(int d)
{
	data = d;
	next = NULL;
}

/* LinkedList constructor
 *
 * This sets the initial values to make an empty linked list
 */

LinkedList::LinkedList()
{
	*head = NULL;

	// initialize instance variable in the constructor

}

/* addHead
 *
 * This function takes one parameter - an int.
 * This creates a node for the linked list and connects the int to the 
 * node.  Then it adds the node to the head of the linked list.
 */

void LinkedList::addHead(int f)
{	
	if (head == NULL)
	{
		head = new Node(data, NULL);
	}
	else
	{
		node *temp;
		temp = new LinkedList();
		temp->setNext(head);
		temp->setData(f);
		next = temp;
	}
	
	// create a node and put the int in it
	
	// if the list is empty

	// this link is the entire list
	
	// if the list is not empty
	// make the new link's next pointer point to
	// the first link in the list

	//  make the head pointer point to the new link
}

/*
 * printList
 *
 * This steps down through each of the nodes in a linked list and 
 * prints out the information stored in the int to which the node points.
 * Instead of automatically printing to the screen, it prints to the 
 * file pointer passed in.  If the programmer wants to print to the screen,
 * he/she will pass in stdout.
 */
// Note: I have provided the string part of the printf so that your output
// will match what is expected.
void LinkedList::printList(FILE *fp) const
{
	

	// for each node, print out the int attached to it
		// assign f to the int of the right node
		// print the int out
		//fprintf(,"%d, ",); 
			
	//fprintf(,"\n");
}

/*
 * length
 *
 * This steps down the list to determine how many nodes are in the 
 * linked list.  It returns that value.
 */



/*
 * deleteFourth
 *
 * This deletes the fourth node.  If there are not already four nodes,
 * it does nothing and returns false.
 *
 * Remember to draw before and after pictures if you are having trouble
 * designing the code or debugging it.
 */

