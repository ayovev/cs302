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
void passFail( int t1, int t2, int t3 );

int oneQueueOneTeller();
void processArrival1( int aTime, int tTime, bool& tellerAvailable,
                     PriorityQueue& events, Queue& customers );
void processDeparture1( int& wTime, int aTime, bool& tellerAvailable,
                       PriorityQueue& events, Queue& customers );
                       
int oneQueueThreeTellers();
void processArrival2( int aTime, int tTime, bool tellersAvailable[ 3 ],
                      PriorityQueue& events, Queue& customers );
void processDeparture2();
bool checkAnyTellerAvailable( bool tellersAvailable[ 3 ] );

int main()
{
   int test1 = 1, test2 = 1, test3 = 1;

   srand( time( NULL ) );

   test1 = oneQueueOneTeller();
   test2 = oneQueueThreeTellers();

   passFail( test1, test2, test3 );

   return EXIT_SUCCESS;
}

int oneQueueOneTeller()
{
   Queue customers;
   PriorityQueue events;

   int totalWaitTime = 0, averageWaitTime = 0;
   bool tellerAvailable = true;

   ofstream fout;

   readInEvents( events );

   fout.clear();
   fout.open( "output1Q1T.txt" );

   fout << "ONE QUEUE ONE TELLER SIMULATION BEGINS" << endl
        << "--------------------------------------" << endl;

   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END

   while( events.isEmpty() == false )
   {
   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events.getFrontType() << ' '
      //      << events.getFrontArrivalTime() << ' '
      //      << events.getFrontTransactionTime() << endl
      //      << customers.isEmpty() << ' ' << tellerAvailable << endl;
   // INCLUDED FOR TESTING PURPOSES - END

      if( events.getFrontType() == 'A' )
      {
         fout << "PROCESSING AN ARRIVAL EVENT AT TIME: " << events.getFrontADTime() << endl;

         processArrival1( events.getFrontADTime(), events.getFrontTransactionTime(),
                         tellerAvailable, events, customers );
      }
      else if( events.getFrontType() == 'D' )
      {
         fout << "PROCESSING A DEPARTURE EVENT AT TIME: " << events.getFrontADTime() << endl;

         processDeparture1( totalWaitTime, events.getFrontADTime(),
                           tellerAvailable, events, customers );
      }
   }

   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END

   averageWaitTime = totalWaitTime / NUM_EVENTS;

   fout << "---------------" << endl
        << "SIMULATION ENDS" << endl
        << "TOTAL NUMBER OF PEOPLE PROCESSED: " << NUM_EVENTS << endl
        << "AVERAGE WAIT TIME: " << averageWaitTime;

   fout.close();

   return EXIT_SUCCESS;
}

int oneQueueThreeTellers()
{
   Queue customers;
   PriorityQueue events;

   bool tellers[ 3 ] = { true, true, true };

   ofstream fout;

   readInEvents( events );

   fout.clear();
   fout.open( "output1Q3T.txt" );

   fout << "ONE QUEUE THREE TELLERS SIMULATION BEGINS" << endl
        << "--------------------------------------" << endl;

   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END

   while( events.isEmpty() == false )
   {
   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events.getFrontType() << ' '
      //      << events.getFrontArrivalTime() << ' '
      //      << events.getFrontTransactionTime() << endl
      //      << customers.isEmpty() << ' ' << tellerAvailable << endl;
   // INCLUDED FOR TESTING PURPOSES - END
   
      if( events.getFrontType() == 'A' )
      {
         fout << "PROCESSING AN ARRIVAL EVENT AT TIME: " << events.getFrontADTime() << endl;
         
         processArrival2( events.getFrontADTime(), events.getFrontTransactionTime(),
                          tellers, events, customers );
      }
      else if( events.getFrontType() == 'D' )
      {
         fout << "PROCESSING A DEPARTURE EVENT AT TIME: " << events.getFrontADTime() << endl;
         
         // processDeparture2(...)
      }
   }

   fout << "---------------" << endl
        << "SIMULATION ENDS" << endl
        << "TOTAL NUMBER OF PEOPLE PROCESSED: " << NUM_EVENTS << endl;

   fout.close();

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

void passFail( int t1, int t2, int t3 )
{
   if( t1 == 0 && t2 == 0 && t3 == 0 )
   {
      cout << "ALL TESTS PASSED" << endl;
   }
   else
   {
      if( t1 == 1 )
      {
         cout << "TEST 1 FAILED" << endl;
      }
      if( t2 == 1 )
      {
         cout << "TEST 2 FAILED" << endl;
      }
      if( t3 == 1 )
      {
         cout << "TEST 3 FAILED" << endl;
      }
   }
}

void processArrival1( int aTime, int tTime, bool& tellerAvailable,
                     PriorityQueue& events, Queue& customers )
{
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

void processDeparture1( int& wTime, int aTime, bool& tellerAvailable,
                       PriorityQueue& events, Queue& customers )
{
   int departureTime;

   events.pop();

   if( customers.isEmpty() == false )
   {
      departureTime = aTime + customers.getFrontTransactionTime();
      wTime += ( aTime - customers.getFrontArrivalTime() );
      customers.pop();
      events.push( departureTime, 0, 'D' );
   }
   else
   {
      tellerAvailable = true;
   }
}

void processArrival2( int aTime, int tTime, bool tellersAvailable[ 3 ],
                      PriorityQueue& events, Queue& customers )
{
   int departureTime;
   bool anyTellerAvailable;
   
   events.pop();
   
   anyTellerAvailable = checkAnyTellerAvailable( tellersAvailable );
   
   if( customers.isEmpty() == true && anyTellerAvailable == true )
   {
      departureTime = aTime + tTime;
      events.push( departureTime, 0, 'D' );
      
      if( tellersAvailable[ 0 ] == true )
      {
         tellersAvailable[ 0 ] = false;
      }
      else if( tellersAvailable[ 0 ] == false && tellersAvailable[ 1 ] == true )
      {
         tellersAvailable[ 1 ] = false;
      }
      else if( tellersAvailable[ 0 ] == false && tellersAvailable[ 1 ] == false )
      {
         tellersAvailable[ 2 ] = false;
      }
   }
   else
   {
      customers.push( aTime, tTime );
   }
   
   
   
}                      

void processDeparture2(...)
{
   
}

bool checkAnyTellerAvailable( bool tellersAvailable[ 3 ] )
{   
   if( tellersAvailable[ 0 ] == true || tellersAvailable[ 1 ] == true ||
       tellersAvailable[ 2 ] == true )
   {
      return true;
   }
   else
   {
      return false;
   }
}

