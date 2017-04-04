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

int oneQueueOneTeller();
void generateInputFile();
void processArrival( PriorityQueue events, Queue customers );
void processDeparture(...);

int main()
{
   int test1 = 1;

   srand( time( NULL ) );

   test1 = oneQueueOneTeller();

   if( test1 == 0 )
   {
      cout << "TEST 1 PASSED" << endl;
   }
   else
   {
      cout << "TEST 1 FAILED" << endl;
   }

   return EXIT_SUCCESS;
}

int oneQueueOneTeller()
{
   Queue customers;
   PriorityQueue events;

   int currentTime, arrivalTime, transactionTime, newEventATime, newEventTTime;

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

   fin.close();

   while( events.isEmpty() == false )
   {
      newEventATime = events.getFrontArrivalTime();
      newEventTTime = events.getFrontTransactionTime();

      currentTime = newEventATime;

      cout << currentTime << endl;

      if( events.getFrontType() == 'A' )
      {
         // processArrival(...)
      }
      else if( events.getFrontType() == 'D' )
      {
         // processDeparture(...)
      }
      events.pop();
   }

// INCLUDED FOR TESTING PURPOSES - START
   // cout << events << endl;
   //
   // cout << events.getFrontType() << ' ' << events.getFront() << endl;
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