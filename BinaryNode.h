#ifndef BINARY_H
#define BINARYNODE_H

#include<iostream>

class BinaryNode
{
  private:
  int data;
  BinaryNode* left;
  BinaryNode* right;
  
public:
  BinaryNode(int i);
  //sets the data
  void setData(int i);
  //gets the data
  int getData();
  //sets the left
  void setLeft(BinaryNode* node);
  //sets the right
  void setRight(BinaryNode* node);
  //gets the left
  BinaryNode* getLeft();
  //gets the right
  BinaryNode* getRight();
};

#endif
