#include <cstdlib>
#include <iostream>
#include "Queue.h"

using namespace std;

Customer::Customer( const int aTime, const int tTime, Customer* next )
{
   arrivalTime = aTime;
   transactionTime = tTime;
   link = next;
}

Queue::Queue()
{
   front = NULL;
   rear = NULL;
}

Queue::~Queue()
{
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

int Queue::getFrontTransactionTime()
{
   return front->transactionTime;
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

int Queue::getLength()
{
   Customer* temp = front;
   int length = 0;
   
   while( temp != NULL )
   {
      length++;
      temp = temp->link;
   }
   
   return length;   
}

ostream& operator <<( ostream& out, const Queue& object )
{
   Customer* temp = object.front;

   while( temp != NULL )
   {
      out << temp->arrivalTime << ' ' << temp->transactionTime << endl;
      temp = temp->link;
   }
   return out;
}