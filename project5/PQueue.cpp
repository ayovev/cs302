#include <cstdlib>
#include <iostream>
#include "PQueue.h"

using namespace std;

PNode::PNode( const int item, const int prio, const char eventType, PNode* next )
{
   data = item;
   priority = prio;
   type = eventType;
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

bool PriorityQueue::push( const int item, const int priority, const char type )
{
   PNode* temp1 = new PNode( item, priority, type, NULL );

   if( front == NULL || temp1->priority < front->priority )
   {
      temp1->link = front;
      front = temp1;

      return true;
   }
   else
   {
      PNode* temp2 = front;

      while( temp2->link != NULL && temp2->link->priority <= temp1->priority )
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
      PNode* temp = front;
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

int PriorityQueue::getFront()
{
   return front->data;
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
   PNode* temp = object.front;

   while( temp != NULL )
   {
      out << temp->data << ' ';
      temp = temp->link;
   }
   return out;
}