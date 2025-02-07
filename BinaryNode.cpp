#include<iostream>
#include"BinaryNode.h"

BinaryNode::BinaryNode(int i)
{
  //sets data in constructot
  BinaryNode::data = i;
  BinaryNode::left = nullptr;
  BinaryNode::right = nullptr;
}
void BinaryNode::setData(int i)
{
  //sets the data
  BinaryNode::data = i;
}
int BinaryNode::getData()
{
  //returns the data
  return BinaryNode::data;
}
void BinaryNode::setLeft(BinaryNode* node)
{
  //sets the left
  BinaryNode::left = node;
}
void BinaryNode::setRight(BinaryNode* node)
{
  //sets the right
  BinaryNode::right = node;
}
BinaryNode* BinaryNode::getRight()
{
  //gets the right
  return BinaryNode::right;
}
BinaryNode* BinaryNode::getLeft()
{
  //gets the left
  return BinaryNode::left;
}

