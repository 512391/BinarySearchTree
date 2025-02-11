#include<iostream>
#include<vector>
#include "BinaryNode.h"

class Tree
{
 private:
  BinaryNode* getSuccesor(BinaryNode* node);
  int findHeight(BinaryNode* node);
  void printLine(BinaryNode** nodes, int arrSize, int height, int currHeight, int lineSize, int prevSideIndent);
  
 public:
  BinaryNode* root;
  void add(int i, BinaryNode* node);
  bool search(BinaryNode* node, int i);
  BinaryNode* remove(BinaryNode* nodeParent, BinaryNode* node, int i);
  void print();
};
