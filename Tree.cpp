#include<iostream>
#include<cmath>
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
      cout << "null" << endl;
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

  cout << "Current number: " << node->getData() << endl;
  
  if(node->getData() == i)
    {
      cout << "removing something: " << i << endl;
      
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
	  if(node->getLeft() != success)
	    {
	      success->setLeft(node->getLeft());
	    }
	  if(node->getRight() != success)
            {
	      success->setRight(node->getRight());
	    }
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

  if(node->getData() < i)
    {
      Tree::remove(node, node->getRight(), i);
    }
  else
    {
      Tree::remove(node, node->getLeft(), i);
    }
}

int Tree::findHeight(BinaryNode* node)
{
  if(node == nullptr)
    {
      return -1;
    }

  int left = findHeight(node->getLeft());
  int right = findHeight(node->getRight());

  return max(left, right)+1;
}

void Tree::printCorrectSpaces(int num)
{
  int digits = 0;
  
  if(num == -1)
    {
      cout << " ";
    }

  while(num != 0)
    {
      num = num/10;

      digits++;
    }
  
  int spaces = AMOUNT_OF_SPACES-digits;

  for(int i = 0; i < spaces; i++)
    {
      cout << " ";
    }
}

void Tree::printLine(BinaryNode** nodes, int arrSize, int height, int currHeight, int lineSize, int prevSideIndent)
{  
  if(height == currHeight)
    {
      bool shouldPrint = true;
      for(int i = 0; i < lineSize; i++)
	{
	  if(shouldPrint)
	    {
	      if(nodes[i/2] != nullptr)
		{
		  cout << nodes[i/2]->getData();
		  printCorrectSpaces(nodes[i/2]->getData());
		}
	      else
		{
		  cout << "N";
		  printCorrectSpaces(1);
		}
	      shouldPrint = false;
	    }
	  else
	    {
	      printCorrectSpaces(-1);

	      shouldPrint = true;
	    }
	}

      cout << endl;
      
      return;
    }

  int midIndent = prevSideIndent;
  int sideIndent = floor(prevSideIndent/2);

  BinaryNode** newNodeArray = new BinaryNode*[arrSize*2];

  int newNodeArrayIndex = 0;
  
  for(int i = 0; i < sideIndent; i++)
    {
      printCorrectSpaces(-1);
    }

  for(int i = 0; i < arrSize; i++)
    {
      if(nodes[i] != nullptr)
	{
	  cout << nodes[i]->getData();
	  printCorrectSpaces(nodes[i]->getData());

	  if(nodes[i]->getLeft() != nullptr)
	    {
	      newNodeArray[newNodeArrayIndex] = nodes[i]->getLeft();
	    }
	  newNodeArrayIndex++;
	  if(nodes[i]->getRight() != nullptr)
            {
              newNodeArray[newNodeArrayIndex] = nodes[i]->getRight();
            }
          newNodeArrayIndex++;
	}
      else
	{
	  cout << "N";
	  printCorrectSpaces(1);
	  newNodeArrayIndex += 2;
	}
      for(int i = 0; i < midIndent; i++)
	{
	  printCorrectSpaces(-1);
	}
    }

  cout << endl << endl << endl;

  printLine(newNodeArray, arrSize*2, height, currHeight+1, lineSize, sideIndent);
}

void Tree::print()
{
  BinaryNode** rootArr = new BinaryNode*[1];
  rootArr[0] = Tree::root;

  int height = findHeight(Tree::root)+1;
  
  printLine(rootArr, 1, height, 1, pow(2, height)-1, pow(2, height)-1);
}
