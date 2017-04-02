#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Queue.cpp"
#include "PQueue.cpp"

using namespace std;

int main()
{
   Queue line;

   line.push( 1 );
   cout << line.getFront() << endl;
   line.push( 2 );
   cout << line.getFront() << endl;
   line.push( 3 );
   cout << line.getFront() << endl;
   line.push( 4 );
   cout << line.getFront() << endl;

   cout << line << endl << endl;

   PriorityQueue linee;

   return EXIT_SUCCESS;
}