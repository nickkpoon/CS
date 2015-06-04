#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include "BST.h"
#include "BinaryNode.h"


int main(int argc, char *argv[])
{
	/*printf("Checking your BinaryNode class\n");
	BinaryNode *node = new BinaryNode();
	node->setValue(new Card(0, 5));
	BinaryNode *left = new BinaryNode(new Card(1, 2));
	BinaryNode *right = new BinaryNode(new Card(2, 8));
	node->setLeft(left);
	node->setRight(right);
	BinaryNode *check_left = node->getLeft();
	BinaryNode *check_right = node->getRight();
	printf("Your left card is ");
	check_left->printBinaryNode(stdout);
	printf("\n");
	printf("Your right card is ");
	check_right->printBinaryNode(stdout);
	printf("\n");
	printf("Your root card is ");
	node->getValue()->print_card(stdout);
	printf("\n");*/

	/*int values[] = {1, 6, 9, 3, 6, 2, 8, 4, 7, 0};
	int suit[] = {0, 1, 3, 2, 1, 2, 3, 0, 0, 3};
	int i;

	for (i=0; i<10; i++) {
		hand[i] = new Card(suit[i], values[i]);
	}*/

	BST *bstree = new BST();
	//BST *bstree2 = new BST();
	int array[] = {1,2,3,4,55,26,3,2,5};
	int size = sizeof array/sizeof(int);   
	printf("Testing insertCard method\n");	
	for (int i=0; i<size; i++) {
		bstree->insertNode(array[i]);
	}
	
	printf("Testing countNode method\n");
	printf("There are 10 cards. ");
	int num = bstree->countNodes();
	printf("Your countNode method says there are %d cards.\n", num);
	
	printf("Testing countBottomNode method\n");
	int bottom = bstree->countBottomNode();
	printf("Your countBottomNode method says there are %d cards.\n", bottom);
	
	printf("Testing addBottomNode method\n");
	int bottom1 = bstree->addBottomNode();
	printf("Your addBottomNode method says %d.\n", bottom1);
	
	printf("Testing findMax method\n");
	int max = bstree->findMax();
	printf("Your findMax method says %d.\n", max);
	
	printf("Testing findMin method\n");
	int min = bstree->findMin();
	printf("Your findMin method says %d.\n", min);

	printf("Testing sum method\n");
	int sum = bstree->sum();
	printf("Your sum method says %d.\n", sum);	

	printf("Testing lessThan method\n");
	int less = bstree->lessThan(10);
	printf("There are %d that are less than 10\n", less);	
	
	printf("Testing equal method\n");
	int equal = bstree->equal(1);
	printf("There are %d that are less than 10\n", equal);
	
	printf("Testing height method\n");
	int height = bstree->height();
	printf("The height is %d\n", height);
	
	printf("testing contains\n");
	if(bstree->contains(5))
		printf("There is a 5 in the tree");
	else
		printf("There is no 5 in the tree");
	
	/*printf("Testing maxCard method\n");
	printf("The maximum card is S 9. ");
	Card *c = bstree->maxCard();
	printf("Your maxCard method says the maximum card is ");
	c->print_card(stdout);
	printf("\n");*/

	return 0;
}

