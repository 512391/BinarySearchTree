#include<iostream>
#include "BinaryNode.h"

class Tree
{
 private:
  BinaryNode* getSuccesor(BinaryNode* node);
  
 public:
  BinaryNode* root;
  void add(int i, BinaryNode* node);
  bool search(BinaryNode* node, int i);
  BinaryNode* remove(BinaryNode* nodeParent, BinaryNode* node, int i);
  void print();
};
