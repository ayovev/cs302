#include <cstdlib>
#include <iostream>
#include "Queue.h"

using namespace std;

Customer::Customer( const int aTime, const int dTime, Customer* next )
{
   arrivalTime = aTime;
   departureTime = dTime;
   link = next;
}

Queue::Queue()
{
   cout << "Queue Constructor" << endl; // INCLUDED FOR TESTING PURPOSES

   front = NULL;
   rear = NULL;
}

Queue::~Queue()
{
   cout << "Queue Destructor" << endl; // INCLUDED FOR TESTING PURPOSES

   while( front != NULL )
   {
      rear = front->link;
      delete front;
      front = rear;
   }
}

bool Queue::push( const int aTime, const int dTime )
{
   if( rear == NULL )
   {
      rear = new Customer( aTime, dTime, NULL );
      front = rear;
      return true;
   }
   else
   {
      rear->link = new Customer( aTime, dTime, NULL );
      rear = rear->link;
      return true;
   }
   return false;
}

bool Queue::pop()
{
   if( front == NULL )
   {
      return false;
   }
   else
   {
      Customer* temp = front;
      front = front->link;

      temp->link = NULL;
      delete temp;
      temp = NULL;

      if( front == NULL )
      {
         rear = NULL;
      }
      return true;
   }
   return false;
}

int Queue::getFrontArrivalTime()
{
   return front->arrivalTime;
}

int Queue::getFrontDepartureTime()
{
   return front->departureTime;
}

bool Queue::isEmpty()
{
   if( front == NULL )
   {
      return true;
   }
   else
   {
      return false;
   }
}

ostream& operator <<( ostream& out, const Queue& object )
{
   Customer* temp = object.front;

   while( temp != NULL )
   {
      out << temp->arrivalTime << ' ';
      temp = temp->link;
   }
   return out;
}