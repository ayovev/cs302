#include <cstdlib>
#include <iostream>
#include "Queue.h"

using namespace std;

Node::Node( int item, Node* next )
{
   data = item;
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

bool Queue::push( int item )
{
   if( rear == NULL )
   {
      rear = new Node( item, NULL );
      front = rear;
      return true;
   }
   else
   {
      rear->link = new Node( item, NULL );
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
      Node* temp = front;
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

int Queue::getFront()
{
   return front->data;
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
   Node* temp = object.front;

   while( temp != NULL )
   {
      out << temp->data << ' ';
      temp = temp->link;
   }
   return out;
}