// LIBRARIES AND HEADER FILES
#include "binaryNode.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

// FUNCTION IMPLEMENTATION
BinaryNode::BinaryNode()
{
   // set default data and set child pointers to NULL
   data = -1;
   leftChild = NULL;
   rightChild = NULL;
}

BinaryNode::BinaryNode( const int item )
{   
   // set data to parameter and set child pointers to NULL
   data  = item;
   leftChild = NULL;
   rightChild = NULL;
}

BinaryNode::BinaryNode( const int item,
                        BinaryNode* left, BinaryNode* right )
{
   // set data and children pointers to specified parameters
   data = item;
   leftChild = left;
   rightChild = right;
}

BinaryNode::~BinaryNode()
{
   // set left and right children to NULL
   leftChild = NULL;
   rightChild = NULL;
}

void BinaryNode::setItem( const int item )
{
   // set data
   data = item;
}

int BinaryNode::getItem() const
{
   // get data
   return data;
}

bool BinaryNode::isLeaf() const
{
   // check if both children of node are NULL
   if( leftChild == NULL && rightChild == NULL )
   {
      return true;
   }
   else
   {
      return false;
   }
}