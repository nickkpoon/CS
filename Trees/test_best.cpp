#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include "BST.h"

BST::BST()
{
	root = NULL;
}

int BST::countNode(BinaryNode *n)
{
	int count;
	if (n == NULL)
		return 0;
	else count = 1;
	if (n->getLeft() == NULL && n->getRight() == NULL)
		return 1;		
	/*if (n->getRight()!= NULL)		
		count += cardCount(n->getRight());
	if (n->getLeft()!= NULL)
		count += cardCount(n->getLeft());
	return count;*/
	else count+= cardCount(n->getRight())+ cardCount(n->getLeft());
	return count;
	
}

int BST::cardCount()
{
	if (root == NULL)	
		return 0;
	else
		return cardCount(root);
}

void BST::insertCard(CardBinaryNode *n, Card *c)
{
	
	CardBinaryNode *cNode = new CardBinaryNode(c);
	if (n->getLeft() == NULL && n->getRight() == NULL)//no children
	{	if (c->compare(*(n->getValue())) == -1)
			n->setLeft(cNode);
		else // compare == 1 or 0
			n->setRight(cNode);
	}
	else if (n->getLeft() == NULL || n->getRight() == NULL)	//one child
	{	
		if (n->getRight() == NULL) //left child
		{
			if (c->compare(*(n->getValue())) >= 0)
				n->setRight(cNode);
			else
				insertCard(n->getLeft(), c);
		}
		else if (n->getLeft() == NULL)//right child
		{
			if (c->compare(*(n->getValue())) == -1)
				n->setLeft(cNode);
			else
				insertCard(n->getRight(), c);
		}


	}
	

		/*CardBinaryNode *cNode = new CardBinaryNode(c);

	if (n == NULL)
	{	
		n = cNode;
	
	}*/
	else {

	if (c->compare(*(n->getValue())) == -1)
		insertCard(n->getLeft(), c);
		
	if  (c->compare(*(n->getValue())) >= 0)
		insertCard(n->getRight(), c);
	
	}		

}

void BST::insertCard(Card *c)
{
		CardBinaryNode *cNode = new CardBinaryNode(c);

	if(root == NULL)
		root = cNode;
	else
		return insertCard(root, c);
	
}

Card* BST::maxCard(CardBinaryNode *n)
{
	/*if (n->getLeft() == NULL && n->getRight() == NULL)
		return n -> getValue();
	Card max = maxCard
	return NULL;*/
	if (n->getRight() != NULL)
		return maxCard(n->getRight());
	
	/*while (n->getRight() != NULL)
		n = n->getRight();*/
	
	return n->getValue();


}

Card* BST::maxCard()
{
	if (root == NULL)
		return NULL;
	else
		return maxCard(root);
}
