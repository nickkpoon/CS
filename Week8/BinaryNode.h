#ifndef BINARYNODE_H
#define BINARYNODE_H

class BinaryNode {
 public:
  const char *question;
  BinaryNode *left;
  BinaryNode *right;
  BinaryNode(const char *question): question(question), left(NULL), right(NULL)
    {}
};

#endif
