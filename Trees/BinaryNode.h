#ifndef BINARYNODE_H
#define BINARYNODE_H

class BinaryNode {
  private:
	int value;
	BinaryNode *left;
	BinaryNode *right;

  public:
	BinaryNode(int value);
	BinaryNode();

	void setValue(int v	);
	void setLeft(BinaryNode *l);
	void setRight(BinaryNode *r);
	int getValue();
	BinaryNode *getLeft();
	BinaryNode *getRight();

};
#endif

