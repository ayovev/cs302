#include <cstdlib>
#include <iostream>
#include "PQueue.h"

using namespace std;

PNode::PNode( int item, int prio, PNode* next )
{
   data = item;
   priority = prio;
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

bool PriorityQueue::push( int item, int priority )
{
   return 0; // TEMPORARY RETURN VALUE
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
}

int PriorityQueue::getFront()
{
   return front->data; // TEMPORARY RETURN VALUE
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