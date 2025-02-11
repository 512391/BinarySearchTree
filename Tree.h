#include<iostream>
#include<vector>
#include "BinaryNode.h"

class Tree
{
 private:
  const int AMOUNT_OF_SPACES = 5;
  BinaryNode* getSuccesor(BinaryNode* node);
  int findHeight(BinaryNode* node);
  void printLine(BinaryNode** nodes, int arrSize, int height, int currHeight, int lineSize, int prevSideIndent);
  void printCorrectSpaces(int num);
 public:
  BinaryNode* root;
  void add(int i, BinaryNode* node);
  bool search(BinaryNode* node, int i);
  BinaryNode* remove(BinaryNode* nodeParent, BinaryNode* node, int i);
  void print();
};
