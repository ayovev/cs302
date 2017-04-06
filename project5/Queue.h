#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Queue;

struct Customer
{
   Customer( const int aTime, const int tTime, Customer* next );
   int arrivalTime;
   int transactionTime;
   Customer* link;

   friend ostream& operator <<( ostream& out, const Queue& object );
};

class Queue
{
   public:
      Queue();
      ~Queue();
      bool push( int const aTime, const int dTime );
      bool pop();
      int getFrontArrivalTime();
      int getFrontTransactionTime();
      bool isEmpty();

      friend ostream& operator <<( ostream& out, const Queue& object );

   private:
      Customer* front;
      Customer* rear;
};

#endif // QUEUE_H