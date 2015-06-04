#ifndef CARDBINARYNODE_H
#define CARDBINARYNODE_H
#include "Card.h"

class CardBinaryNode {
  private:
	Card *value;
	CardBinaryNode *left;
	CardBinaryNode *right;

  public:
	CardBinaryNode(Card *);
	CardBinaryNode();

	void setValue(Card *);
	void setLeft(CardBinaryNode *l);
	void setRight(CardBinaryNode *r);
	Card *getValue();
	CardBinaryNode *getLeft();
	CardBinaryNode *getRight();

	void printCardBinaryNode(FILE *f);
};
#endif
