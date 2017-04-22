#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binaryNode.h"

class BinarySearchTree
{
   public:
      BinarySearchTree();
      BinarySearchTree( const int rootItem );
      ~BinarySearchTree();
      
      bool isEmpty() const;
      int getHeight( BinaryNode* subTree ) const;
      int getNumberOfNodes( BinaryNode* subTree ) const;
      int getRootData() const;
      void setRootData( const int item );
      bool add( const int item );
      BinaryNode* remove( BinaryNode* subTree, const int item );
      void clear( BinaryNode* subTree );
      int getEntry( BinaryNode* subTree, const int entry );
      bool contains( BinaryNode* subTree, const int item ) const;
      
      void preorderTraverse( BinaryNode* subTree ) const;
      void inorderTraverse( BinaryNode* subTree ) const;
      void postorderTraverse( BinaryNode* subTree ) const;
      
   public:
      BinaryNode* root;
};

#endif // BINARY_SEARCH_TREE_H