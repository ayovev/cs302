#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

struct PNode
{
   PNode( int item, int prio, PNode* next );
   int priority;
   int data;
   PNode* link;
};

class PriorityQueue
{
   public:
      PriorityQueue();
      ~PriorityQueue();
      bool push( int item, int priority );
      bool pop();
      int getFront();
      bool isEmpty();

   private:
      PNode* front;
      PNode* rear;
};

#endif // PRIORITY_QUEUE_H