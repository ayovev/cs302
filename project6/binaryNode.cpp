#include "binaryNode.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

BinaryNode::BinaryNode()
{   
   data = -1;
   leftChild = NULL;
   rightChild = NULL;
}

BinaryNode::BinaryNode( const int item )
{   
   data  = item;
   leftChild = NULL;
   rightChild = NULL;
}

BinaryNode::BinaryNode( const int item,
                        BinaryNode* left, BinaryNode* right )
{
   data = item;
   leftChild = left;
   rightChild = right;
}

BinaryNode::~BinaryNode()
{
   leftChild = NULL;
   rightChild = NULL;
}

void BinaryNode::setItem( const int item )
{
   data = item;
}

int BinaryNode::getItem() const
{
   return data;
}

bool BinaryNode::isLeaf() const
{
   if( leftChild == NULL && rightChild == NULL )
   {
      return true;
   }
   else
   {
      return false;
   }
}