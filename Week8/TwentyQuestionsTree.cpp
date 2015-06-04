#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctype.h>
#include <limits.h>
#include <iostream>

#include "TwentyQuestionsTree.h"
#include "BinaryNode.h"
using namespace std;

TwentyQuestionsTree::TwentyQuestionsTree(FILE *fp)
{
  // TODO Implement the constructor that builds the initial tree from the file
	//char question1[1000];
	//char question2[1000];

	
	int i = 0;	
	char ch, buffer, line[256];
	//get root question
	fgets(line, INT_MAX ,fp); 
	char *ch1 = new char[100];
	char *ch2 = new char[100];
	char *ch3 = new char[100];
	char *c1 = new char[100];
	char *c2 = new char[100];
	char *c3 = new char[100];
	ch1 = strtok(line, ",");
	strcpy(c1, ch1);
	//printf("%s\n", c1);
	root = new BinaryNode(c1);	
	
	ch2 = strtok(NULL, ",");
	strcpy(c2, ch2);
	//printf("%s\n", c2);
	
	ch3 = strtok(NULL, "\n");
	strcpy(c3, ch3);
	//printf("%s\n", c3);
	insert(root, c1, c2, c3);
	
	//char *parent;
	//strcpy(parent, c2);	
	
	while(fgets(line, 256 ,fp)!=NULL)
	{

		char *ch1 = new char[100];
		char *ch2 = new char[100];
		char *ch3 = new char[100];
		char *c1 = new char[100];
		char *c2 = new char[100];
		char *c3 = new char[100];
		ch1 = strtok(line, ",");
		strcpy(c1, ch1);
		if (c1 == '\0')
			break;
		//printf("%s\n", c1);
		
		ch2 = strtok(NULL, ",");
		strcpy(c2, ch2);
		//printf("%s\n", c2);

		ch3 = strtok(NULL, "\n");
		strcpy(c3, ch3);
		//printf("%s\n", c3);
		insert(root, c1, c2, c3);
		
	}
}

// Default constructor - creates a tree that asks no questions - it merely
// guesses that it was a platypus.
TwentyQuestionsTree::TwentyQuestionsTree()
{
  root = new BinaryNode("Is it a platypus?");
}

/* insert
 * This inserts two questions into the tree - the children of the parent.
 * This is used when building the tree from scratch.
 * The assumption is that the parent is already in the tree, and we are
 * merely adding the left and right children.
 *
 * First, this *finds* the parent.  Then it inserts the left and right
 * child into the tree.
 */
bool TwentyQuestionsTree::insert(BinaryNode *r, const char *parent,
                                 const char *left, const char *right)
{
  // TODO - make sure you read the description, especially the assumption
  // about what is already in the tree!!!!!
	if (strcmp(r->question, parent)==0) //base case
	{
		r->left = new BinaryNode(left);
		r->right = new BinaryNode(right);
		return true;
	}
	else
	{
		if (r->left != NULL)
			insert(r->left, parent, left, right);
		if (r->right != NULL)
			insert(r->right, parent, left, right);
		return true;
	}



  return false;
}

/* modifyAndInsert
 *
 * This modifies the tree as a result of the game being incorrect.  Either
 * the left child or right child is already in the tree.  This method replaces
 * that existing one with the new parent and creates new left and right
 * children.
 *
 * First this *finds* either the left or right child.  Then it replaces that
 * node with the parent and adds two new nodes - left and right.
 */
bool TwentyQuestionsTree::modifyAndInsert(BinaryNode *n, const char *parent,
                                          const char *left, const char *right)
{
	
	if (strcmp(n->right->question, left)==0 || strcmp(n->right->question, right)==0) //base case - found last question
	{
		BinaryNode *nNode = new BinaryNode(parent);
		nNode->left = new BinaryNode(left);
		nNode->right = new BinaryNode(right);
		//printf("got into if statement modifyandinsert");
		n->right = nNode;
		return true;
	}
	else if (strcmp(n->left->question, left)==0 || strcmp(n->left->question, right)==0) //base case - found last question
	{
		BinaryNode *nNode = new BinaryNode(parent);
		nNode->left = new BinaryNode(left);
		nNode->right = new BinaryNode(right);
		//printf("got into if statement modifyandinsert");
		n->left = nNode;
		return true;
	}

	else
	{
		if (n->left->left != NULL)
			modifyAndInsert(n->left, parent, left, right);
		if (n->right->left != NULL)
			modifyAndInsert(n->right, parent, left, right);
		//printf("got into else statement of modifyandinsert");
		return true;
	}
}

/* public version of modifyAndInsert */
void TwentyQuestionsTree::modifyAndInsert(const char *parent, const char *left,
                                          const char *right)
{	
	if (root==NULL)
		return;
	if (root->left==NULL || root->right==NULL)
	{
		BinaryNode *nNode = new BinaryNode(parent);
		if (strcmp(root->question, left)==0 || strcmp(root->question, right)==0)
		{		
			nNode->left = new BinaryNode(left);
			nNode->right = new BinaryNode(right);
			root = nNode;
		}
	}
	else 
		modifyAndInsert(root, parent, left, right);
}

/* reset
 *
 * This resets the iterator to the beginning of the game
 */
void TwentyQuestionsTree::reset()
{
	iterator = root;
}

/* currentQuestions
 *
 * This has been provided for you.  This looks at the current position of
 * the iterator and returns the question stored in that BinaryNode.
 */
const char *TwentyQuestionsTree::currentQuestion()
{
  if (iterator == NULL)
    return NULL;
  else
    return iterator->question;
}

/* recordAnswer
 *
 * This advances the iterator.  If the answer was yes (1), go right.  If
 * no (0), go left.
 */
void TwentyQuestionsTree::recordAnswer(int answer)
{
	if (answer == 1)
		iterator = iterator->right;
	else if (answer == 0)
		iterator = iterator->left;
}

/* storeTree
 *
 * This writes the tree out to the file in the same format as the
 * sample input file was.
 */
void TwentyQuestionsTree::storeTree(BinaryNode *n,FILE *fp)
{
	if (n->left==NULL)
	{		
		return;
	}
	else
	{		
		fprintf(fp, "%s,", n->question);
		fprintf(fp, "%s,", n->left->question);
		fprintf(fp, "%s\n", n->right->question);
	
		storeTree(n->left, fp);
		storeTree(n->right, fp);
		return;
	}
}
void TwentyQuestionsTree::storeTree(FILE *fp)
{
	
	
	if (fp==NULL || root==NULL)		
	{	
		return;
	}
	
	else
		return storeTree(root, fp);
}

/*void TwentyQuestionsTree::printTree(BinaryNode *n)
{
	if (n==NULL)
		return;
	printTree(n->left);
	cout << n->question << endl;
	printTree(n->right);		
}*/

