#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
   public:
      BinaryNode();
      BinaryNode( const int data );
      BinaryNode( const int data,
                  BinaryNode* left, BinaryNode* right );
                  
      void setItem( const int data );
      int getItem() const;
      bool isLeaf() const;
      
      int item;
      BinaryNode* leftChild;
      BinaryNode* rightChild;
};

#endif // BINARY_NODE_H