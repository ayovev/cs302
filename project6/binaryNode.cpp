#include "binaryNode.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

BinaryNode::BinaryNode()
{
   cout << "Node Default Constructor" << endl; // INCLUDED FOR TESTING PURPOSES
   
   item = 0; // MIGHT REMOVE?
   leftChild = NULL;
   rightChild = NULL;
}

BinaryNode::BinaryNode( const int data )
{
   cout << "Node Parameterized Constructor" << endl; // INCLUDED FOR TESTING PURPOSES
   
   item  = data;
   leftChild = NULL;
   rightChild = NULL;
}

BinaryNode::BinaryNode( const int data,
                        BinaryNode* left, BinaryNode* right )
{
   cout << "Node Parameterized Constructor" << endl; // INCLUDED FOR TESTING PURPOSES
   
   item = data;
   leftChild = left;
   rightChild = right;
}

BinaryNode::~BinaryNode()
{
   leftChild = NULL;
   rightChild = NULL;
}

void BinaryNode::setItem( const int data )
{
   item = data;
}

int BinaryNode::getItem() const
{
   return item;
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