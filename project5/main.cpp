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

   linee.push( 1, 10 );
   cout << linee.getFront() << endl;
   linee.push( 2, 3 );
   cout << linee.getFront() << endl;
   linee.push( 3, 5 );
   cout << linee.getFront() << endl;
   linee.push( 4, 20 );
   cout << linee.getFront() << endl;
   linee.push( 5, 10 );
   cout << linee.getFront() << endl;
   linee.push( 6, 1 );
   cout << linee.getFront() << endl;
   linee.push( 7, 2 );
   cout << linee.getFront() << endl;
   linee.push( 8, 99 );
   cout << linee.getFront() << endl;

   cout << linee << endl << endl;

   return EXIT_SUCCESS;
}