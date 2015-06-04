#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "BST.h"
using namespace std;


BST::BST()
{
	root = NULL;
}

int BST::countBottomNode(BinaryNode *n)
{
	if (n == NULL)
		return 0;
	
	if (n->getLeft() == NULL && n->getRight() == NULL)
		return 1;
	else
		return countBottomNode(n->getLeft()) + countBottomNode(n->getRight());
		
	
}

int BST::countBottomNode()
{
	if (root == NULL)	
		return 0;
	else
		return countBottomNode(root);
}

int BST::countNodes(BinaryNode *n)
{
	if (n == NULL)
		return 0;
		
	return 1 + countNodes(n->getLeft()) + countNodes(n->getRight());

}

int BST::countNodes()
{
	if (root == NULL)
		return 0;
	else
		return countNodes(root);
}

void BST::insertNode(BinaryNode *n, int v) //im going to add prioritizing left
{
		
	/*_______________________________________BST INSERT______________________________________
	BinaryNode *cNode = new BinaryNode(v);
	if (n->getLeft() == NULL && n->getRight() == NULL)//no children
	{	if (v < (n->getValue()))
			n->setLeft(cNode);
		else 
			n->setRight(cNode);
	}
	
	else if (n->getLeft() == NULL || n->getRight() == NULL)	//one child
	{	
		if (n->getRight() == NULL) //left child
		{
			if (v>(n->getValue()))
				n->setRight(cNode);
			else
				insertNode(n->getLeft(), v);
		}
		else if (n->getLeft() == NULL)//right child
		{
			if (v<(n->getValue()))
				n->setLeft(cNode);
			else
				insertNode(n->getRight(), v);
		}


	}
	else //two children
	{ 

		if (v<(n->getValue()))
			insertNode(n->getLeft(), v);
		
		else if (v>(n->getValue()))
			insertNode(n->getRight(), v);
	
	}		

	
	
	
/*_____________________________BinaryTree:____________________________

	static int count = 0;
	BinaryNode *node = new BinaryNode(v);
	if(n->getRight() == NULL && n->getLeft() == NULL) //no children
	{
		n->setLeft(node);
		return;
	}
	if (n->getRight() != NULL && n->getLeft() == NULL) //right has children
	{
		n->setLeft(node);
		return;
	}		
	
	if (n->getRight() == NULL && n->getLeft() != NULL) //left has children
	{
		n->setRight(node);
		return;
	}		
	
	if (n->getRight() != NULL && n->getLeft() != NULL)
	{
		if(count%2 == 0)
		{
			insertNode(n->getLeft(), v);
			count++;
		}
		
		else
		{
			insertNode(n->getRight(), v);
			count++;
		}

	}*/
}
void BST::insertNode(int n)
{
	BinaryNode *cNode = new BinaryNode(n);
	
	if(root == NULL) //root has nothing
		root = cNode;
	
	else
		insertNode(root, n);

	/*__________________binaryTree__________________
	if(root == NULL)
		root = cNode;
	
	else
		insertNode(root, n);
	*/
}

int BST::addBottomNode(BinaryNode *n)
{
	int count;
	if (n == NULL)
		return 0;
	//else count = 1;
	
	if (n->getLeft() == NULL && n->getRight() == NULL)
		return n->getValue();
	else
		return addBottomNode(n->getLeft()) + addBottomNode(n->getRight());
		
	
}

int BST::addBottomNode()
{
	if (root == NULL)	
		return 0;
	else
		return addBottomNode(root);
}

int BST::findMax(BinaryNode *n)
{
	
	if(n == NULL)
		return 0;
	if(n->getLeft() == NULL and n->getRight() == NULL)
		return n->getValue();
		
	return findMax(n->getRight());
	
	
	/*______________________BinaryTree___________________________
	int r = findMax(n->getRight());
	int l = findMax(n->getLeft());
	if(n->getValue()>r &&n->getValue()>l)
		return n->getValue();
	else 
	{
		if(r>l)
			return r;
		else
			return l;
	}*/
	
}

int BST::findMax()
{
	if (root == NULL)
		return 0;
	return findMax(root);
}

int BST::findMin(BinaryNode *n)
{
	if(n == NULL)
		return 0;
		
	if(n->getLeft() == NULL and n->getRight() == NULL)
		return n->getValue();
		
	return findMin(n->getLeft());
		
	/*____________________________BinaryTree____________________________
	int r = findMin(n->getRight());
	int l = findMin(n->getLeft());
	if(n->getValue()<r &&n->getValue()<l)
		return n->getValue();
	else 
	{
		if(r<l)
			return r;
		else
			return l;
	}*/

}

int BST::findMin()
{
	if (root == NULL)
		return 0;
	return findMin(root);
}

int BST::sum(BinaryNode *n)
{
	if (n == NULL)
		return 0;
	int r = sum(n->getRight());
	int l = sum(n->getLeft());
	
	return r + l + n->getValue();

}

int BST::sum()
{
	if (root == NULL)
		return 0;
	return sum(root);
}

int BST::lessThan(BinaryNode *n, int v)
{
	int count;
	if (n == NULL)
		return 0;
		
	if(n->getValue() < v)
	return 1 + lessThan(n->getLeft(), v) + lessThan(n->getRight(), v);
	
	return lessThan(n->getLeft(), v) + lessThan(n->getRight(), v);
}

int BST::lessThan(int n)
{
	if (root == NULL)
		return 0;
	return lessThan(root, n);
}

int BST::equal(BinaryNode *n, int v)
{
	if (n == NULL)
		return 0;
	if (n->getValue() == v)
		return 1 + equal(n->getLeft(), v) + equal(n->getRight(), v);
	
	return equal(n->getLeft(), v) + equal(n->getRight(), v);
}

int BST::equal(int n)
{
	if (root == NULL)
		return 0;
	
	return equal(root, n);
}

int BST::height(BinaryNode *n)
{
	if (n == NULL)
		return 0;
	int r = height(n->getRight());
	int l = height(n->getLeft());

	if (r>l)
		return r+1;
	return l+1;
}

int BST::height()
{
	if (root == NULL)
		return 0;
	
	return height(root);
}

bool BST::contains(BinaryNode *n, int v)
{
	if (n == NULL)
		return false;
	
	bool r = contains(n->getRight(), v);
	bool l = contains(n->getLeft(), v);
	
	if (n->getValue() == v)
		return true;
	
	return (r||l);

}

bool BST::contains(int v)
{
	if (root == NULL)
		return 0;
		
	return contains(root, v);
}