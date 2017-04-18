#include "binarySearchTree.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

BinarySearchTree::BinarySearchTree()
{
   cout << "Binary Search Tree Default Constructor" << endl;
   
   root = NULL;
}

BinarySearchTree::BinarySearchTree( const int rootItem )
{
   cout << "Binary Search Tree Parameterized Constructor" << endl;
   
   root->data = rootItem;
}

BinarySearchTree::BinarySearchTree( const BinarySearchTree& tree )
{
   cout << "Binary Search Tree Copy Constructor" << endl;
}

BinarySearchTree::~BinarySearchTree()
{
   clear();
}

bool BinarySearchTree::isEmpty() const
{
   if( root == NULL )
   {
      return true;
   }
   else
   {
      return false;
   }
}

int BinarySearchTree::getHeight() const
{
   
}

int BinarySearchTree::getNumberOfNodes() const
{
   
}

int BinarySearchTree::getRootData() const
{
   return root->data;
}

void BinarySearchTree::setRootData( const int item )
{
   root->data = item;
}

bool BinarySearchTree::add( const int item )
{
   
}

bool BinarySearchTree::remove( const int item )
{
   
}

void BinarySearchTree::clear()
{
   
}

int BinarySearchTree::getEntry( const int entry )
{
   
}

bool BinarySearchTree::contains( const int item ) const
{
   
}

void BinarySearchTree::preorderTraverse() const
{
   
}

void BinarySearchTree::inorderTraverse() const
{
   
}

void BinarySearchTree::postorderTraverse() const
{
   
}