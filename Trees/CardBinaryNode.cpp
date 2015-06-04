#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include "CardBinaryNode.h"



/* This is the constructor that will most often be used.
 */
CardBinaryNode::CardBinaryNode(Card *v)
{
	value = v;
	left = NULL;
	right = NULL;
}

/* here is another constructor in case someone wants to make the 
 * link before they know what value it will have.
 * You can have multiple constructors as long as each has a different
 * set of input parameter types.  The names don't matter.
 */
CardBinaryNode::CardBinaryNode()
{
	value = NULL;
	left = NULL;
	right = NULL;
}


void CardBinaryNode::setValue(Card *v)
{
	value = v;
}
void CardBinaryNode::setLeft(CardBinaryNode *l)
{
	left = l;
}

void CardBinaryNode::setRight(CardBinaryNode *r)
{
	right = r;
}

Card *CardBinaryNode::getValue()
{
	return value;
}
CardBinaryNode* CardBinaryNode::getLeft()
{
	return left;
}
CardBinaryNode* CardBinaryNode::getRight()
{
	return right;
}

void CardBinaryNode::printCardBinaryNode(FILE *f)
{
	getValue()->print_card(f);
}

