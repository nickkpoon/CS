#ifndef BST_H
#define BST_H
#include "BinaryNode.h"

class BST {
  private:
	BinaryNode *root;

	// private recursive helpers
	int countBottomNode(BinaryNode *);
	int countNodes(BinaryNode *);
	int findMax(BinaryNode *);
	void insertNode(BinaryNode *, int n);
	int addBottomNode(BinaryNode*);
	int findMin(BinaryNode *);
	int sum(BinaryNode *);
	int lessThan(BinaryNode *, int n);
	int equal(BinaryNode *, int n);
	int height(BinaryNode *);
	bool contains(BinaryNode *, int n);

  public:
	BST();

	// these are provided in the pre-compiled file BSTProvided.o
	//void insert(Card *);
	//void printTree(FILE *f);

	// method to add
	int countBottomNode();
	int countNodes();
	void insertNode(int n);
	int findMax();
	int addBottomNode();
	int findMin();
	int sum();
	int lessThan(int n);
	int equal(int n);
	int height();
	bool contains(int n);
};

#endif
