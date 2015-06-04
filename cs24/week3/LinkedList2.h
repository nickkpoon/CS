#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <cstdio>
using namespace std;
class Node {
  private:
   int data;    
   Node *next;  
 public:
  Node();        // default constructor 
  Node(int d);   

  // setters and getters
  void setData(int d) { data = d; }
  void setNext(Node *n) { next = n; }
  int getData() const { return data;}
  Node *getNext() const { return next;}
}; // end of Node

class LinkedList {
 private:
   Node *head;

 public:
  LinkedList();
 
  void addHead(int); 
  void printList(FILE *) const;
  //int length() const; // problem3
  //bool deleteFourth(); // problem3

};

#endif

