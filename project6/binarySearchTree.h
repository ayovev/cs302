#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binaryNode.h"

class BinarySearchTree
{
   public:
      BinarySearchTree();
      BinarySearchTree( const int rootItem );
      BinarySearchTree( const BinarySearchTree& tree );
      ~BinarySearchTree();
      
      bool isEmpty() const;
      int getHeight() const;
      int getNumberOfNodes() const;
      int getRootData() const;
      void setRootData( const int data );
      bool add( const int data );
      bool remove( const int data );
      void clear();
      int getEntry( const int entry );
      bool contains( const int data ) const;
      
      
      
   private:
      BinaryNode* root;
}