#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Queue;

struct Customer
{
   Customer( const int aTime, const int dTime, Customer* next );
   int arrivalTime;
   int departureTime;
   Customer* link;

   friend ostream& operator <<( ostream& out, const Queue& object ); // NOT SURE IF THIS IS NEEDED
};

class Queue
{
   public:
      Queue();
      ~Queue();
      bool push( int const aTime, const int dTime );
      bool pop();
      int getFrontArrivalTime();
      int getFrontDepartureTime();
      bool isEmpty();

      friend ostream& operator <<( ostream& out, const Queue& object );

   private:
      Customer* front;
      Customer* rear;
};

#endif // QUEUE_H