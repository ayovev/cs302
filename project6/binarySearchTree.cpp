#include "binarySearchTree.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

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
   clear( root );
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

int BinarySearchTree::getHeight( BinaryNode* subTree ) const
{   
   if( subTree == NULL )
   {
      return 0;
   }
   
   return 1 + max( getHeight( subTree->leftChild ), getHeight( subTree->rightChild ) );
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

void BinarySearchTree::clear( BinaryNode* subTree )
{
   if( subTree != NULL )
   {
      clear( subTree->leftChild );
      clear( subTree->rightChild );
      
      subTree = NULL;
   }
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