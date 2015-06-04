#include <stdio.h>
#include <iostream>
using namespace std;
#include "BinaryNode.h"

BinaryNode::BinaryNode(int n)
{
	value = n;
	left = NULL;
	right = NULL;
}

BinaryNode::BinaryNode()
{
	value = 0;
	left = NULL;
	right = NULL;
}

void BinaryNode::setValue(int v)
{
	value = v;
}

void BinaryNode::setLeft(BinaryNode *l)
{
	left = l;
}

void BinaryNode::setRight(BinaryNode *r)
{
	right = r;
}

int BinaryNode::getValue()
{
	return value;
}

BinaryNode *BinaryNode::getLeft()
{
	return left;
}

BinaryNode *BinaryNode::getRight()
{
	return right;
}

	