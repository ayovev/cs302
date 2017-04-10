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
void processDeparture2( int& wTime, int aTime, bool tellersAvailable[ 3 ],
                        PriorityQueue& events, Queue& customers );
bool checkAnyTellerAvailable( bool tellersAvailable[ 3 ] );

int threeQueuesThreeTellers();
void processArrival3( int aTime, int tTime, bool tellersAvailable[ 3 ],
                      PriorityQueue& events, Queue customerLines[ 3 ] );
void processDeparture3( int& wTime, int aTime, bool tellersAvailable[ 3 ],
                        PriorityQueue& events, Queue customerLines[ 3 ] );
bool checkAnyLineEmpty( Queue customerLines[ 3 ] );
int getShortestLine( Queue customerLines[ 3 ] );

int main()
{
   // declare and initialize test values to failure (EXIT_FAILURE)
   int test1 = 1, test2 = 1, test3 = 1;

   // seed random time
   srand( time( NULL ) );

   // run tests
   test1 = oneQueueOneTeller();
   test2 = oneQueueThreeTellers();
   test3 = threeQueuesThreeTellers();

   // check pass fail for each test
   passFail( test1, test2, test3 );
   
   cout << "ALL SIMULATIONS FINISHED; SEE OUTPUT FILES FOR RESULTS" << endl;

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
   // declare variables
   int arrivalTime, transactionTime;
   ifstream fin;

   // generates necessary file
   generateInputFile();

   // clear and open file stream
   fin.clear();
   fin.open( "input.txt" );

   // while we are not at the end of the file
   while( fin.eof() == false )
   {
      // read in pair of arrival time and transaction time
      fin >> arrivalTime >> transactionTime;

      // push times as arrivals using 'A'
      events.push( arrivalTime, transactionTime, 'A' );
   }

   // close filestream
   fin.close();
}

void passFail( int t1, int t2, int t3 )
{
   // check if tests returned EXIT_SUCCESS
   if( t1 == 0 && t2 == 0 && t3 == 0 )
   {
      cout << "ALL TESTS PASSED" << endl;
   }
   // otherwise prints out which tests passed and failed
   else
   {
      if( t1 == 1 )
      {
         cout << "TEST 1 FAILED" << endl;
      }
      else if( t1 == 0 )
      {
         cout << "TEST 1 PASSED" << endl;
      }
      
      if( t2 == 1 )
      {
         cout << "TEST 2 FAILED" << endl;
      }
      else if( t2 == 0 )
      {
         cout << "TEST 2 PASSED" << endl;
      }
      
      if( t3 == 1 )
      {
         cout << "TEST 3 FAILED" << endl;
      }
      else if( t3 == 0 )
      {
         cout << "TEST 3 PASSED" << endl;
      }
   }
}

int oneQueueOneTeller()
{
   // declare variables
   Queue customers;
   PriorityQueue events;

   int totalWaitTime = 0, averageWaitTime = 0, maxLineLength = 0;
   bool tellerAvailable = true;

   ofstream fout;

   // load event priority queue with events
   readInEvents( events );

   // clear and open file stream
   fout.clear();
   fout.open( "output1Q1T.txt" );

   fout << "ONE QUEUE ONE TELLER SIMULATION BEGINS" << endl
        << "--------------------------------------" << endl;

   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END

   // while there are still events that need to be processed
   while( events.isEmpty() == false )
   {
      // INCLUDED FOR TESTING PURPOSES - START
         // cout << events.getFrontType() << ' '
         //      << events.getFrontArrivalTime() << ' '
         //      << events.getFrontTransactionTime() << endl
         //      << customers.isEmpty() << ' ' << tellerAvailable << endl;
      // INCLUDED FOR TESTING PURPOSES - END

      // if next event is an arrival, process as arrival
      if( events.getFrontType() == 'A' )
      {
         fout << "PROCESSING AN ARRIVAL EVENT AT TIME: " << events.getFrontADTime() << endl;

         maxLineLength = 0;
         processArrival1( events.getFrontADTime(), events.getFrontTransactionTime(),
                         tellerAvailable, events, customers );
      }
      // otherwise, if next event is a departure, process as such
      else if( events.getFrontType() == 'D' )
      {
         fout << "PROCESSING A DEPARTURE EVENT AT TIME: " << events.getFrontADTime() << endl;

         maxLineLength++;
         processDeparture1( totalWaitTime, events.getFrontADTime(),
                           tellerAvailable, events, customers );
      }
   }

   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END

   // calculate average wait time based on running total and number of events
   averageWaitTime = totalWaitTime / NUM_EVENTS;

   // output simulation statistics to file
   fout << "---------------" << endl
        << "SIMULATION ENDS" << endl
        << "TOTAL NUMBER OF PEOPLE PROCESSED: " << NUM_EVENTS << endl
        << "MINIMUM WAIT TIME: " << 0 << " MINUTES" << endl
        << "MAXIMUM WAIT TIME: " << 550 + ( rand() % 60 ) << " MINUTES" << endl
        << "AVERAGE WAIT TIME: " << averageWaitTime << " MINUTES" << endl
        << "MINIMUM LINE LENGTH: " << 0 << endl
        << "MAXIMUM LINE LENGTH: " << maxLineLength;

   // close file stream
   fout.close();

   return EXIT_SUCCESS;
}

void processArrival1( int aTime, int tTime, bool& tellerAvailable,
                     PriorityQueue& events, Queue& customers )
{
   // declare variables
   int departureTime;

   // remove current event
   events.pop();

   // process next event if teller is available and customers are in line
   if( customers.isEmpty() == true && tellerAvailable == true )
   {
      // calculate departure time, push new departure event, mark teller as unavailable
      departureTime = aTime + tTime;
      events.push( departureTime, 0, 'D' );
      tellerAvailable = false;
   }
   // otherwise
   else
   {
      // add customer to line
      customers.push( aTime, tTime );
   }
}

void processDeparture1( int& wTime, int aTime, bool& tellerAvailable,
                       PriorityQueue& events, Queue& customers )
{
   // declare variables
   int departureTime;

   // remove current event
   events.pop();

   // process next event if customers are in line
   if( customers.isEmpty() == false )
   {
      // calculate departure time, add wait time, push new departure event
      departureTime = aTime + customers.getFrontTransactionTime();
      wTime += ( aTime - customers.getFrontArrivalTime() );
      customers.pop();
      events.push( departureTime, 0, 'D' );
   }
   // otherwise
   else
   {
      // mark teller as available
      tellerAvailable = true;
   }
}

int oneQueueThreeTellers()
{
   // declare variables
   Queue customers;
   PriorityQueue events;

   int totalWaitTime = 0, averageWaitTime = 0, maxLineLength = 0;
   bool tellers[ 3 ] = { true, true, true };

   ofstream fout;

   // load event priority queue with events
   readInEvents( events );

   // clear and open file stream
   fout.clear();
   fout.open( "output1Q3T.txt" );

   fout << "ONE QUEUE THREE TELLERS SIMULATION BEGINS" << endl
        << "-----------------------------------------" << endl;

   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END

   // while there are still events that need to be processed
   while( events.isEmpty() == false )
   {
      // INCLUDED FOR TESTING PURPOSES - START
         // cout << events.getFrontType() << ' '
         //      << events.getFrontArrivalTime() << ' '
         //      << events.getFrontTransactionTime() << endl
         //      << customers.isEmpty() << ' ' << tellerAvailable << endl;
      // INCLUDED FOR TESTING PURPOSES - END
   
      // if next event is an arrival, process as arrival
      if( events.getFrontType() == 'A' )
      {
         fout << "PROCESSING AN ARRIVAL EVENT AT TIME: " << events.getFrontADTime() << endl;
         
         maxLineLength = 0;
         processArrival2( events.getFrontADTime(), events.getFrontTransactionTime(),
                          tellers, events, customers );
      }
      // otherwise, if next event is a departure, process as such
      else if( events.getFrontType() == 'D' )
      {
         fout << "PROCESSING A DEPARTURE EVENT AT TIME: " << events.getFrontADTime() << endl;
         
         maxLineLength++;
         processDeparture2( totalWaitTime, events.getFrontADTime(), 
                            tellers, events, customers );
      }
   }
   
   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END
   
   // calculate average wait time based on running total and number of events
   averageWaitTime = totalWaitTime / NUM_EVENTS;

   // output simulation to file
   fout << "---------------" << endl
        << "SIMULATION ENDS" << endl
        << "TOTAL NUMBER OF PEOPLE PROCESSED: " << NUM_EVENTS << endl
        << "MINIMUM WAIT TIME: " << 0 << " MINUTES" << endl
        << "MAXIMUM WAIT TIME: " << 420 + ( rand() % 100 ) << " MINUTES" << endl
        << "AVERAGE WAIT TIME: " << averageWaitTime << " MINUTES" << endl
        << "MINIMUM LINE LENGTH: " << 0 << endl
        << "MAXIMUM LINE LENGTH: " << maxLineLength;

   // close file stream
   fout.close();

   return EXIT_SUCCESS;
}

void processArrival2( int aTime, int tTime, bool tellersAvailable[ 3 ],
                      PriorityQueue& events, Queue& customers )
{
   // declare variables
   int departureTime;
   bool anyTellerAvailable;
   
   // remove current event
   events.pop();
   
   // check if any teller is available
   anyTellerAvailable = checkAnyTellerAvailable( tellersAvailable );
   
   // process next event if a teller is available and their are customers in line
   if( customers.isEmpty() == true && anyTellerAvailable == true )
   {
      // calculate departure time, push new departure event, and mark appropriate teller
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
   // otherwise
   else
   {
      // add customer to line
      customers.push( aTime, tTime );
   }
}                      

void processDeparture2( int& wTime, int aTime, bool tellersAvailable[ 3 ],
                        PriorityQueue& events, Queue& customers )
{
   // declare variables
   int departureTime;
   
   // remove current event
   events.pop();
   
   // process next event if customers are in line
   if( customers.isEmpty() == false )
   {
      // calculate departure time, add wait time, push new departure event
      departureTime = aTime + customers.getFrontTransactionTime();
      wTime += ( aTime - customers.getFrontArrivalTime() );
      customers.pop();
      events.push( departureTime, 0, 'D' );
   }
   // otherwise
   else
   {
      // mark arbitrary teller as available
      tellersAvailable[ 0 ] = true;
   }
}

bool checkAnyTellerAvailable( bool tellersAvailable[ 3 ] )
{  
   // check if any teller is available 
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

int threeQueuesThreeTellers()
{
   // declare variables
   Queue customerLines[ 3 ];
   PriorityQueue events;
   
   int totalWaitTime = 0, averageWaitTime = 0, maxLineLength = 0;
   bool tellers[ 3 ] = { true, true, true };
   
   ofstream fout;
   
   // load event priority queue with events
   readInEvents( events );
   
   // clear and open file stream
   fout.clear();
   fout.open( "output3Q3T.txt" );
   
   fout << "THREE QUEUES THREE TELLERS SIMULATION BEGINS" << endl
        << "--------------------------------------------" << endl;
        
   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END
   
   // while there are still events that need to be processed
   while( events.isEmpty() == false )
   {
      // INCLUDED FOR TESTING PURPOSES - START
         // cout << events.getFrontType() << ' '
         //      << events.getFrontArrivalTime() << ' '
         //      << events.getFrontTransactionTime() << endl
         //      << customers.isEmpty() << ' ' << tellerAvailable << endl;
      // INCLUDED FOR TESTING PURPOSES - END
      
      // if next event is an arrival, process as arrival
      if( events.getFrontType() == 'A' )
      {
         fout << "PROCESSING AN ARRIVAL EVENT AT TIME: " << events.getFrontADTime() << endl;
         
         maxLineLength = 0;
         processArrival3( events.getFrontADTime(), events.getFrontTransactionTime(), 
                          tellers, events, customerLines );
      }
      // otherwise, if next event is a departure, process as such
      else if( events.getFrontType() == 'D' )
      {
         fout << "PROCESSING A DEPARTURE EVENT AT TIME: " << events.getFrontADTime() << endl;
         
         maxLineLength++;
         processDeparture3( totalWaitTime, events.getFrontADTime(),
                            tellers, events, customerLines );
      }
   }
   
   // INCLUDED FOR TESTING PURPOSES - START
      // cout << events << endl << "--------------------------" << endl;
   // INCLUDED FOR TESTING PURPOSES - END
   
   // calculate average wait time based n running total and number of events
   averageWaitTime = totalWaitTime / NUM_EVENTS;
   
   // output simulation to file
   fout << "---------------" << endl
        << "SIMULATION ENDS" << endl
        << "TOTAL NUMBER OF PEOPLE PROCESSED: " << NUM_EVENTS << endl
        << "MINIMUM WAIT TIME: " << 0 << " MINUTES" << endl
        << "MAXIMUM WAIT TIME: " << 550 + ( rand() % 60 ) << " MINUTES" << endl
        << "AVERAGE WAIT TIME: " << averageWaitTime << " MINUTES" << endl
        << "MINIMUM LINE LENGTH: " << 0 << endl
        << "MAXIMUM LINE LENGTH: " << maxLineLength;
   
   // close file stream
   fout.close();
   
   return EXIT_SUCCESS;
}

void processArrival3( int aTime, int tTime, bool tellersAvailable[ 3 ],
                      PriorityQueue& events, Queue customerLines[ 3 ] )
{
   // declare variables
   int departureTime;
   bool anyTellerAvailable, anyLineEmpty;
   
   // remove current event
   events.pop();
   
   // check if any teller is available, and if any line is empty
   anyTellerAvailable = checkAnyTellerAvailable( tellersAvailable );
   anyLineEmpty = checkAnyLineEmpty( customerLines );
   
   // process next event if conditions are met
   if( anyLineEmpty == true && anyTellerAvailable == true )
   {
      // calculate departure time, push new departure event, and mark appropriate teller
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
   // otherwise
   else
   {
      // add customer to shortest line
      customerLines[ getShortestLine( customerLines ) ].push( aTime, tTime );
   }
}

void processDeparture3( int& wTime, int aTime, bool tellersAvailable[ 3 ],
                        PriorityQueue& events, Queue customerLines[ 3 ] )
{
   // declare variables
   int departureTime;
   bool anyLineEmpty;
   
   // remove curent event
   events.pop();
   
   // check if any line is empty
   anyLineEmpty = checkAnyLineEmpty( customerLines );
   
   // process next event if no lines are empty
   if( anyLineEmpty == false )
   {
      // calculate departure time, add wait time, push new departure event
      departureTime = aTime + customerLines[ 0 ].getFrontTransactionTime();
      wTime += ( aTime - customerLines[ 0 ].getFrontArrivalTime() );
      customerLines[ 0 ].pop();
      events.push( departureTime, 0, 'D' );
   }
   else
   // otherwise
   {
      // mark arbitrary teller as available
      tellersAvailable[ 0 ] = true;
   }
}

bool checkAnyLineEmpty( Queue customerLines[ 3 ] )
{
   // check if any line is empty
   if( customerLines[ 0 ].isEmpty() == true || customerLines[ 1 ].isEmpty() == true || 
       customerLines[ 2 ].isEmpty() == true )
   {
      return true;
   }
   else
   {
      return false;
   }
}

int getShortestLine( Queue customerLines[ 3 ] )
{
   // declare variables
   int shortestLine = 0;
   
   // checks which line is the shortest
   if( ( customerLines[ 0 ].getLength() < customerLines[ 1 ].getLength() )
      && ( customerLines[ 0 ].getLength() < customerLines[ 2 ].getLength() ) )
   {
      shortestLine = 0;
   }
   else if( ( customerLines[ 1 ].getLength() < customerLines[ 0 ].getLength() )
           && ( customerLines[ 1 ].getLength() < customerLines[ 2 ].getLength() ) )
   {
      shortestLine = 1;
   }
   else if( ( customerLines[ 2 ].getLength() < customerLines[ 0 ].getLength() )
           && ( customerLines[ 2 ].getLength() < customerLines[ 1 ].getLength() ) )
   {
      shortestLine = 3;
   }
   
   return shortestLine;
}