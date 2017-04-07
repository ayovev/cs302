#include <cstdlib>
#include <iostream>
#include "PQueue.h"

using namespace std;

Event::Event( const int prio, const int item, const char type, Event* next )
{
   adTime = prio;
   transactionTime = item;
   eventType = type;
   link = next;
}

PriorityQueue::PriorityQueue()
{
   cout << "Priority Queue Constructor" << endl; // INCLUDED FOR TESTING PURPOSES

   front = NULL;
   rear = NULL;
}

PriorityQueue::~PriorityQueue()
{
   cout << "Priority Queue Destructor" << endl; // INCLUDED FOR TESTING PURPOSES

   while( front != NULL )
   {
      rear = front->link;
      delete front;
      front = rear;
   }
}

bool PriorityQueue::push( const int priority, const int item, const char type )
{
   Event* temp1 = new Event( priority, item, type, NULL );

   if( front == NULL || temp1->adTime < front->adTime )
   {
      temp1->link = front;
      front = temp1;

      return true;
   }
   else
   {
      Event* temp2 = front;

      while( temp2->link != NULL && temp2->link->adTime <= temp1->adTime )
      {
         temp2 = temp2->link;
      }
      temp1->link = temp2->link;
      temp2->link = temp1;

      return true;
   }
   return false;
}

bool PriorityQueue::pop()
{
   if( front == NULL )
   {
      return false;
   }
   else
   {
      Event* temp = front;
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

int PriorityQueue::getFrontADTime()
{
   return front->adTime;
}

int PriorityQueue::getFrontTransactionTime()
{
   return front->transactionTime;
}

char PriorityQueue::getFrontType()
{
   return front->eventType;
}

bool PriorityQueue::isEmpty()
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

ostream& operator <<( ostream& out, const PriorityQueue& object )
{
   Event* temp = object.front;

   while( temp != NULL )
   {
      out << temp->eventType << ' ' << temp->adTime << ' ' << temp->transactionTime << endl;
      temp = temp->link;
   }
   return out;
}