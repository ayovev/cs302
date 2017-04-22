// LIBRARIES AND HEADER FILES
#include "binarySearchTree.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::swap;

// FUNCTION IMPLEMENTATION
BinarySearchTree::BinarySearchTree()
{  
   // set root equal to null to show empty tree 
   root = NULL;
}

BinarySearchTree::BinarySearchTree( const int rootItem )
{   
   // assign data to root node
   root->data = rootItem;
}

BinarySearchTree::~BinarySearchTree()
{
   // call clear function to destroy tree
   clear( root );
}

bool BinarySearchTree::isEmpty() const
{
   // check if the root is equal to null
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
   // check if subtree is empty
   if( subTree == NULL )
   {
      return 0;
   }
   
   // find max between heights of left and right subtrees
   return 1 + max( getHeight( subTree->leftChild ), getHeight( subTree->rightChild ) );
}

int BinarySearchTree::getNumberOfNodes( BinaryNode* subTree ) const
{
   // declare and initialize variables
   int count = 1;
   
   // check if subtree is empty
   if( subTree == NULL )
   {
      return 0;
   }
   // otherwise, add counts and return final count
   else
   {
      count += getNumberOfNodes( subTree->leftChild );
      count += getNumberOfNodes( subTree->rightChild );
      
      return count;
   }
}

int BinarySearchTree::getRootData() const
{
   // return data in root node
   return root->data;
}

void BinarySearchTree::setRootData( const int item )
{
   // set data in root node to item passed in
   root->data = item;
}

bool BinarySearchTree::add( const int item )
{
   // declare temporary node pointer with item
   BinaryNode* temp = new BinaryNode( item );
   
   // check if tree is empty
   if( root == NULL )
   {
      root = temp;
      
      return true;
   }
   // otherwise find where to place root using leader and follower
   else
   {
      BinaryNode* current = root;
      BinaryNode* parent = root;
      
      // check whether to go right or left
      if( temp->data < current->data )
      {
         current = current->leftChild;
      }
      else
      {
         current = current->rightChild;
      }
      
      // check whether to go right or left
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
      
      // check whether to go right or left
      if( temp->data < parent->data )
      {
         parent->leftChild = temp;
      }
      else
      {
         parent->rightChild = temp;
      }
      
      // return successful add operation
      return true;
   }
}

BinaryNode* BinarySearchTree::remove( BinaryNode* subTree, const int item )
{
   // check if subtree is false
   if( subTree == NULL )
   {
      return NULL;
   }
   // check if item is less than subtree data
   else if( item < subTree->data )
   {
      subTree->leftChild = remove( subTree->leftChild, item );
   }
   // check if item is greater than subtree data
   else if( item > subTree->data )
   {
      subTree->rightChild = remove( subTree->rightChild, item );
   }
   // otherwise determine case of subtree (number of children, if any)
   else
   {
      // if subtree has no children
      if( subTree->leftChild == NULL && subTree->rightChild == NULL )
      {
         delete subTree;
         subTree = NULL;
      }
      // if subtree only has a left child
      else if( subTree->rightChild == NULL )
      {
         delete subTree;
         subTree = NULL;
      }
      // if subtree only has a right child
      else if( subTree->leftChild == NULL )
      {
         delete subTree;
         subTree = NULL;
      }
      // otherwise if subtree has two children
      else
      {
         BinaryNode* current = subTree->leftChild;
         
         // find max value
         while( current->rightChild != NULL )
         {
            current = current->rightChild;
         }
         
         // replace data
         subTree->data = current->data;
         
         // set left child node to removed node
         subTree->leftChild = remove( subTree->leftChild, current->data );
      }
   }
   // return pointer to subtree
   return subTree;
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