#include "binarySearchTree.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::swap;

BinarySearchTree::BinarySearchTree()
{   
   root = NULL;
}

BinarySearchTree::BinarySearchTree( const int rootItem )
{   
   root->data = rootItem;
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

int BinarySearchTree::getNumberOfNodes( BinaryNode* subTree ) const
{
   int count = 1;
   
   if( subTree == NULL )
   {
      return 0;
   }
   else
   {
      count += getNumberOfNodes( subTree->leftChild );
      count += getNumberOfNodes( subTree->rightChild );
      
      return count;
   }
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
   BinaryNode* temp = new BinaryNode( item );
   
   if( root == NULL )
   {
      root = temp;
      
      return true;
   }
   else
   {
      BinaryNode* current = root;
      BinaryNode* parent = root;
      
      if( temp->data < current->data )
      {
         current = current->leftChild;
      }
      else
      {
         current = current->rightChild;
      }
      
      while( current != NULL )
      {
         parent = current;
         
         if( temp->data < current->data )
         {
            current = current->leftChild;
         }
         else
         {
            current = current->rightChild;
         }
      }
      
      if( temp->data < parent->data )
      {
         parent->leftChild = temp;
      }
      else
      {
         parent->rightChild = temp;
      }
      
      return true;
   }
}

bool BinarySearchTree::remove( BinaryNode* subTree, const int item )
{
   if( subTree == NULL )
   {
      return false;
   }
   else if( item < subTree->data )
   {
      remove( subTree->leftChild, item );
   }
   else if( item > subTree->data )
   {
      remove( subTree->rightChild, item );
   }
   else if( item == subTree->data )
   {
      if( subTree->leftChild == NULL )
      {
         BinaryNode* temp = subTree->rightChild;
         delete subTree;
         
         return true;
      }
      else if( subTree->rightChild == NULL )
      {
         BinaryNode* temp = subTree->leftChild;
         delete subTree;
         
         return true;
      }
      
      BinaryNode* current = subTree->rightChild;
      
      while( current->leftChild != NULL )
      {
         current = current->leftChild;
      }
      
      subTree->data = current->data;
      
      remove( subTree->rightChild, current->data );
   }
   return true;
}

void BinarySearchTree::clear( BinaryNode* subTree )
{
   if( subTree != NULL )
   {
      clear( subTree->leftChild );
      clear( subTree->rightChild );
      
      subTree->leftChild = NULL;
      subTree->rightChild = NULL;
      
      delete subTree;
      subTree = NULL;
   }
   root = NULL;
}

int BinarySearchTree::getEntry( BinaryNode* subTree, const int entry )
{
   if( subTree == NULL )
   {
      return -1;
   }
   else if( subTree->data == entry )
   {
      return entry;
   }
   else if( entry < subTree->data )
   {
      return getEntry( subTree->leftChild, entry );
   }
   else if( entry > subTree->data )
   {
      return getEntry( subTree->rightChild, entry );
   }
   return EXIT_FAILURE; // INDICATES INCORRECT EXECUTION
}

bool BinarySearchTree::contains( BinaryNode* subTree, const int item ) const
{
   if( subTree == NULL )
   {
      return false;
   }
   else if( subTree->data == item )
   {
      return true;
   }
   else if( item < subTree->data )
   {
      return contains( subTree->leftChild, item );
   }
   else if( item > subTree->data )
   {
      return contains( subTree->rightChild, item );
   }
   return EXIT_FAILURE; // INDICATES INCORRECT EXECUTION
}

void BinarySearchTree::preorderTraverse( BinaryNode* subTree ) const
{
   if( subTree != NULL )
   {
      cout << subTree->data << ' ';
      preorderTraverse( subTree->leftChild );
      preorderTraverse( subTree->rightChild );
   }
}

void BinarySearchTree::inorderTraverse( BinaryNode* subTree ) const
{
   if( subTree != NULL )
   {
      inorderTraverse( subTree->leftChild );
      cout << subTree->data << ' ';
      inorderTraverse( subTree->rightChild );
   }
}

void BinarySearchTree::postorderTraverse( BinaryNode* subTree ) const
{
   if( subTree != NULL )
   {
      postorderTraverse( subTree->leftChild );
      postorderTraverse( subTree->rightChild );
      cout << subTree->data << ' ';
   }
   
}