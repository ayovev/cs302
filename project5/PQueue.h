#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

using namespace std;

class PriorityQueue;

struct PNode
{
   PNode( const int item, const int prio, PNode* next );
   int priority;
   int data;
   PNode* link;

   friend ostream& operator <<( ostream& out, const PriorityQueue& object ); // NOT SURE IF THIS IS NEEDED
};

class PriorityQueue
{
   public:
      PriorityQueue();
      ~PriorityQueue();
      bool push( const int item, const int priority );
      bool pop();
      int getFront();
      bool isEmpty();

      friend ostream& operator <<( ostream& out, const PriorityQueue& object );

   private:
      PNode* front;
      PNode* rear;
};

#endif // PRIORITY_QUEUE_H