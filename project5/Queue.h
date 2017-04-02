#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Queue;

struct Node
{
   Node( int item, Node* next );
   int data;
   Node* link;

   friend ostream& operator <<( ostream& out, const Queue& object ); // NOT SURE IF THIS IS NEEDED
};

class Queue
{
   public:
      Queue();
      ~Queue();
      bool push( int item );
      bool pop();
      int getFront();
      bool isEmpty();

      friend ostream& operator <<( ostream& out, const Queue& object );

   private:
      Node* front;
      Node* rear;
};

#endif // QUEUE_H