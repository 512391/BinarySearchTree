#include<iostream>
#include<vector>
#include "BinaryNode.h"

class Tree
{
 private:
  const int AMOUNT_OF_SPACES = 5;
  BinaryNode* getSuccesor(BinaryNode* node);
  int findHeight(BinaryNode* node);
  void make2dTree(BinaryNode*** finalNodes, BinaryNode** currentNodes, int arrSize, int height, int currHeight, int lineSize, int prevSideIndent);
  void printCorrectSpaces(int num);
  void trimPrintArray(int width, int height, BinaryNode*** nodes, int* bottomTopIndicies);
 public:
  BinaryNode* root;
  void add(int i, BinaryNode* node);
  bool search(BinaryNode* node, int i);
  BinaryNode* remove(BinaryNode* nodeParent, BinaryNode* node, int i);
  void print();
};
