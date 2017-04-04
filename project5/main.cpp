#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <array>
#include <algorithm>
#include "Queue.cpp"
#include "PQueue.cpp"

using namespace std;

const int NUM_EVENTS = 100;

void generateInputFile();
int oneQueueOneTeller();

int main()
{
   int test1;

   srand( time( NULL ) );

   test1 = oneQueueOneTeller();

   cout << test1 << endl << endl;

   system( "pause" );

// INCLUDED FOR TESTING PURPOSES - START
   // Queue line;
   //
   // line.push( 1 );
   // cout << line.getFront() << endl;
   // line.push( 2 );
   // cout << line.getFront() << endl;
   // line.push( 3 );
   // cout << line.getFront() << endl;
   // line.push( 4 );
   // cout << line.getFront() << endl;
   //
   // cout << line << endl << endl;
   //
   // PriorityQueue linee;
   //
   // linee.push( 1, 10 );
   // cout << linee.getFront() << endl;
   // linee.push( 2, 3 );
   // cout << linee.getFront() << endl;
   // linee.push( 3, 5 );
   // cout << linee.getFront() << endl;
   // linee.push( 4, 20 );
   // cout << linee.getFront() << endl;
   // linee.push( 5, 10 );
   // cout << linee.getFront() << endl;
   // linee.push( 6, 1 );
   // cout << linee.getFront() << endl;
   // linee.push( 7, 2 );
   // cout << linee.getFront() << endl;
   // linee.push( 8, 99 );
   // cout << linee.getFront() << endl;
   //
   // cout << linee << endl << endl;
// INCLUDED FOR TESTING PURPOSES - END

   return EXIT_SUCCESS;
}

void generateInputFile()
{
   // declare output file stream and index
   ofstream fout;
   int index;

   // declare structures for storing generated event data
   array<int, NUM_EVENTS> startTime;
   array<int, NUM_EVENTS> duration;

   // loop through for the number of events
   for( index = 0; index < NUM_EVENTS; index++ )
   {
      // generate and store event data
      startTime.at( index ) = ( rand() % 540 ) + 1;
      duration.at( index ) = ( rand() % 20 ) + 1;
   }

   // sort start time data (smallest to largest)
   sort( startTime.begin(), startTime.end() );

   // clear and open file stream
   fout.clear();
   fout.open( "input.txt" );

   // loop through for the number of events
   for( index = 0; index < NUM_EVENTS; index++ )
   {
      // check if last pass
      if( index == 99 )
      {
         // output event data in a slightly modified format (no endline)
         fout << startTime.at( index ) << ' ' << duration.at( index );
      }
      else
      {
         // output event data in specific format
         fout << startTime.at( index ) << ' ' << duration.at( index ) << endl;
      }
   }

   // close file stream
   fout.close();
}

int oneQueueOneTeller()
{
   Queue customers;
   PriorityQueue events;

   int arrivalTime, transactionTime;

   ifstream fin;

   generateInputFile();

   fin.clear();
   fin.open( "input.txt" );

   // event-driven, not time-driven
   while( fin.eof() == false )
   {
      fin >> arrivalTime >> transactionTime;

      events.push( arrivalTime, transactionTime, 'A' );
   }

   // while( events.isEmpty() == false )
   // {
   //    // do stuff
   // }

// INCLUDED FOR TESTING PURPOSES - START
   cout << events << endl;
   //
   // cout << events.getFrontType() << ' ' << events.getFront() << endl;
// INCLUDED FOR TESTING PURPOSES - END

   return EXIT_SUCCESS;
}