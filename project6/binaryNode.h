#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
   public:
      BinaryNode();
      BinaryNode( const int item );
      BinaryNode( const int item,
                  BinaryNode* left, BinaryNode* right );
      ~BinaryNode();
                  
      void setItem( const int item );
      int getItem() const;
      bool isLeaf() const;
      
   public:      
      int data;
      BinaryNode* leftChild;
      BinaryNode* rightChild;
};

#endif // BINARY_NODE_H