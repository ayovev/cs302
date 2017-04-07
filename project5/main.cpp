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
void readInEvents( PriorityQueue& events );
int oneQueueOneTeller();
void processArrival( int aTime, int tTime, bool& tellerAvailable,
                     PriorityQueue& events, Queue& customers );
void processDeparture( int aTime, int tTime, bool& tellerAvailable,
                       PriorityQueue& events, Queue& customers );

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

   bool tellerAvailable = true;

   readInEvents( events );

   // INCLUDED FOR TESTING PURPOSES - START
      cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END

   while( events.isEmpty() == false )
   {
   // INCLUDED FOR TESTING PURPOSES - START
      cout << events.getFrontType() << ' '
           << events.getFrontArrivalTime() << ' '
           << events.getFrontTransactionTime() << endl
           << customers.isEmpty() << ' ' << tellerAvailable << endl;
   // INCLUDED FOR TESTING PURPOSES - END

      if( events.getFrontType() == 'A' )
      {
         processArrival( events.getFrontArrivalTime(), events.getFrontTransactionTime(),
                         tellerAvailable, events, customers );

      // INCLUDED FOR TESTING PURPOSES - START
         // cout << events.getFrontType() << ' '
         //      << events.getFrontArrivalTime() << ' '
         //      << events.getFrontTransactionTime() << endl << endl;
         // system("pause");
      // INCLUDED FOR TESTING PURPOSES - END
      }
      else if( events.getFrontType() == 'D' )
      {
         processDeparture( events.getFrontArrivalTime(), events.getFrontTransactionTime(),
                           tellerAvailable, events, customers );
      }
   }

   // INCLUDED FOR TESTING PURPOSES - START
      cout << events << endl << "--------------------------" << endl;
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

void readInEvents( PriorityQueue& events )
{
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

   fin.close();
}

void processArrival( int aTime, int tTime, bool& tellerAvailable,
                     PriorityQueue& events, Queue& customers )
{
cout << "PROCESSING ARRIVAL" << endl << endl;
system("pause");
   int departureTime;

   events.pop();

   if( customers.isEmpty() == true && tellerAvailable == true )
   {
      departureTime = aTime + tTime;
      events.push( departureTime, 0, 'D' );
      tellerAvailable = false;
   }
   else
   {
      customers.push( aTime, tTime );
   }
}
void processDeparture( int aTime, int tTime, bool& tellerAvailable,
                       PriorityQueue& events, Queue& customers )
{
cout << "PROCESSING DEPARTURE" << endl << endl;
system("pause");
   int departureTime;

   events.pop();

   if( customers.isEmpty() == false )
   {
      departureTime = aTime + customers.getFrontTransactionTime();
      customers.pop();
      events.push( departureTime, 0, 'D' );
   }
   else
   {
      tellerAvailable = true;
   }
}