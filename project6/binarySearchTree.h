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
      int getHeight( BinaryNode* subTree ) const;
      int getNumberOfNodes() const;
      int getRootData() const;
      void setRootData( const int item );
      bool add( const int item );
      bool remove( const int item );
      void clear( BinaryNode* subTree );
      int getEntry( const int entry );
      bool contains( const int item ) const;
      
      void preorderTraverse() const;
      void inorderTraverse() const;
      void postorderTraverse() const;
      
   private:
      BinaryNode* root;
};

#endif // BINARY_SEARCH_TREE_H