#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

using namespace std;

class PriorityQueue;

struct PNode
{
   PNode( const int prio, const int item, const char eventType, PNode* next );
   int arrivalTime;
   int transactionTime;
   char eventType;
   PNode* link;

   friend ostream& operator <<( ostream& out, const PriorityQueue& object ); // NOT SURE IF THIS IS NEEDED
};

class PriorityQueue
{
   public:
      PriorityQueue();
      ~PriorityQueue();
      bool push( const int priority, const int data, const char type );
      bool pop();
      int getFrontArrivalTime();
      int getFrontTransactionTime();
      char getFrontType();
      bool isEmpty();

      friend ostream& operator <<( ostream& out, const PriorityQueue& object );

   private:
      PNode* front;
      PNode* rear;
};

#endif // PRIORITY_QUEUE_H