#ifndef TWENTYQUESTIONSTREE_H
#define TWENTYQUESTIONSTREE_H

#include "BinaryNode.h"

class TwentyQuestionsTree {
 public:
  BinaryNode *root;
  BinaryNode *iterator;


  // inserts two new questions to be children of an existing parent
  bool insert(BinaryNode *r, const char *parent, const char *left,
              const char *right);

  // recursive helper functions
  bool modifyAndInsert(BinaryNode *n, const char *p, const char *l,
                       const char *r);
  void storeTree(BinaryNode *n,FILE *fp);

 //public:
  TwentyQuestionsTree(FILE *fp); // read in file to build tree
  TwentyQuestionsTree();  // initialize it to ask "Is it a platypus?"

  // inserts two new questions - either left or right is already
  // in the tree.  That node will be replaced with parent, and
  // there will be new left and right children.
  void modifyAndInsert(const char *parent, const char *left, const char *right);


  // to play the game, you need an iterator of sorts:
  void reset(); // reset the iterator
  const char *currentQuestion(); // return the current question.  If game
                                 // is over, return NULL
  void recordAnswer(int answer); // yes = 1, no = 0 - advance iterator
                                 // to proper place
                                 // 0 = left child, 1 = right child

  void storeTree(FILE *fp); // write out tree to file
	
  void printTree(BinaryNode *n);
};

#endif
