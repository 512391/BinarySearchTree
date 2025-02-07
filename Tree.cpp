#include<iostream>
#include"Tree.h"

using namespace std;

void Tree::add(int i, BinaryNode* node)
{
  if(Tree::root == nullptr)
    {
      Tree::root = new BinaryNode(i);
      return;
    }
 
  if(node->getData() > i)
    {
      if(node->getLeft() != nullptr)
	{
	  Tree::add(i, node->getLeft());
	}
      else
	{
	  node->setLeft(new BinaryNode(i));
	}
    }
  else
    {
      if(node->getRight() != nullptr)
        {
          Tree::add(i, node->getRight());
        }
      else
        {
          node->setRight(new BinaryNode(i));
        }
    }
}


bool Tree::search(BinaryNode* node, int i)
{
  if(node == nullptr)
    {
      return false;
    }

  cout << "data: " << node->getData() << endl;
  
  if(node->getData() == i)
    {
      return true;
    }

  if(node->getData() < i)
    {
      Tree::search(node->getRight(), i);
    }
  else
    {
      Tree::search(node->getLeft(), i);
    }
}

BinaryNode* Tree::getSuccesor(BinaryNode* node)
{
  BinaryNode* currentNode = node->getRight();

  while(currentNode->getLeft() != nullptr)
    {
      currentNode = currentNode->getLeft();
    }

  return currentNode;
}

BinaryNode* Tree::remove(BinaryNode* nodeParent, BinaryNode* node, int i)
{
  if(Tree::root == nullptr || node == nullptr)
    {
      return nullptr;
    }

  if(node->getData() == i)
    {
      BinaryNode* toReturn  = new BinaryNode(node->getData());
      if(nodeParent == nullptr)
	{
	  if(node->getLeft() != nullptr && node->getRight() != nullptr)
	    {
	  BinaryNode* left = Tree::root->getLeft();
	  Tree::root = Tree::root->getRight();
	  Tree::root->setLeft(left);
	    }
	  else if(node->getLeft() != nullptr)
	    {
	    Tree:root = node->getLeft();
	    }
	  else if(node->getRight() != nullptr)
	    {
	      Tree::root = node->getRight();
	    }
	  else
	    {
	      Tree::root = nullptr;
	    }
	}
      else if(node->getLeft() != nullptr && node->getRight() != nullptr)
	{
	  BinaryNode* success = Tree::getSuccesor(node);
	  
	  if(nodeParent->getRight() == node)
	    {
	      nodeParent->setRight(success);
	    }
	  else
	    {
	      nodeParent->setLeft(success);
	    }
	  success->setLeft(node->getLeft());
	  success->setRight(node->getRight());
	}
      else if(node->getLeft() != nullptr)
	{
	  nodeParent->setLeft(node->getLeft());
	}
      else
	{
	  nodeParent->setRight(node->getRight());
	}
      delete node;
      return toReturn;
    }

  if(node->getData() > i)
    {
      Tree::remove(node, node->getRight(), i);
    }
  else
    {
      Tree::remove(node, node->getLeft(), i);
    }
}

void Tree::print()
{
  
}
