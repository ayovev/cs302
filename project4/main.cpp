/* COMPILE WITH C++11 */

// HEADER FILES & LIBRARIES
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>
#include <vector>
#include <utility>
#include <ctime>

using namespace std;

// FUNCTION PROTOTYPES
int randomNumberGenerator();
void delay();
void generateFile( int numValues );
void loadVector( vector<int>& vec, int numValues );
void bubbleSort( vector<int>& vec,
                 unsigned long long int& comparisons, unsigned long long int& swaps );
void quickSort( vector<int>& vec, int first, int last,
                unsigned long long int& comparisons, unsigned long long int& swaps );
int partition( vector<int>& vec, int first, int last,
               unsigned long long int& comparisons, unsigned long long int& swaps );
void radixSort( vector<int>& vec );
double run( string sort, vector<int>& vec, int numValues,
            unsigned long long int& comparisons, unsigned long long int& swaps );

// MAIN PROGRAM
int main()
{
   // declare and initialize variables
   int numValues;
   unsigned long long int comparisons = 0, swaps = 0;
   vector<int> vec1, vec2, vec3;
   double averageTime = 0;
   int numRuns = 10;
   clock_t t1, t2, t3;

   // run loop 3 times, once for 1 000, once for 10 000, once for 100 000
   for( int i = 1, count = 0; count < 3; i *= 10, count++ )
   {
      // set numValues in the beginning of every loop
      numValues = i * 1000;

      // generate a file with the previously specified number of values
      generateFile( numValues );

      // if the number of values is 100 000
      if( numValues == 100000 )
      {
         // set the number of runs equal to 3 for bubble sort to save time
         numRuns = 2;
      }

      // active output to inform user of what is going on
      cout << endl << "Running bubble sort " << numRuns << " times with " << numValues << " values..." << endl;

      for( int i = 0; i < numRuns; i++ )
      {
         // run specified sort n times
         averageTime += run( "Bubble Sort", vec1, numValues, comparisons, swaps );
      }
      // display average results to user
      cout << "Average sorting time of " << numRuns << " runs for bubble sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
      cout << "Average number of comparisons of " << numRuns << " runs for bubble sort: " << comparisons / numRuns << endl;
      cout << "Average number of swaps of " << numRuns << " runs for bubble sort: " << swaps / numRuns << endl << endl;

      // reset comparisons, swaps, and averageTime to 0
      averageTime = 0, comparisons = 0, swaps = 0;

      // set numRuns to 10
      numRuns = 10;

      // active output to inform user of what is going on
      cout << endl << "Running quick sort " << numRuns << " times with " << numValues << " values..." << endl;

      for( int i = 0; i < numRuns; i++ )
      {
         // run specified sort n times
         averageTime += run( "Quick Sort", vec2, numValues, comparisons, swaps );
      }
      // display average results to user
      cout << "Average sorting time of " << numRuns << " runs for quick sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
      cout << "Average number of comparisons of " << numRuns << " runs for quick sort: " << comparisons / numRuns << endl;
      cout << "Average number of swaps of " << numRuns << " runs for quick sort: " << swaps / numRuns << endl << endl;

      // reset comparisons, swaps, and averageTime to 0
      averageTime = 0, comparisons = 0, swaps = 0;

      // active output to inform user of what is going on
      cout << endl << "Running radix sort " << numRuns << " times with " << numValues << " values..." << endl;

      for( int i = 0; i < numRuns; i++ )
      {
         // run specified sort n times
         averageTime += run( "Radix Sort", vec3, numValues, comparisons, swaps );
      }
      // display average results to user
      cout << "Average sorting time of " << numRuns << " runs for radix sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
      cout << "Average number of comparisons of " << numRuns << " runs for radix sort: " << comparisons / numRuns << endl;
      cout << "Average number of swaps of " << numRuns << " runs for radix sort: " << swaps / numRuns << endl << endl;
   }

   run( "Bubble Sort", vec1, 10000, comparisons, swaps );

   // reset comparisons, swaps, and averageTime to 0
   averageTime = 0, comparisons = 0, swaps = 0;
   t1 = clock();
   bubbleSort( vec1, comparisons, swaps );
   t2 = clock();

   t3 = t2 - t1;

   cout << "Bubble sort realized the vector was already sorted in " << ( (double)t3 / CLOCKS_PER_SEC ) << " seconds" << endl;

   run( "Quick Sort", vec2, 10000, comparisons, swaps );

   // reset comparisons, swaps, and averageTime to 0
   averageTime = 0, comparisons = 0, swaps = 0;
   t1 = clock();
   quickSort( vec2, 0, vec2.size(), comparisons, swaps );
   t2 = clock();

   t3 = t2 - t1;

   cout << "Quick sort realized the vector was already sorted in " << ( (double)t3 / CLOCKS_PER_SEC ) << " seconds" << endl;

   run( "Radix Sort", vec3, 10000, comparisons, swaps );

   // reset comparisons, swaps, and averageTime to 0
   averageTime = 0, comparisons = 0, swaps = 0;
   t1 = clock();
   radixSort( vec3 );
   t2 = clock();

   t3 = t2 - t1;

   cout << "Radix sort realized the vector was already sorted in " << ( (double)t3 / CLOCKS_PER_SEC ) << " seconds" << endl << endl;

// TEST OUTPUT TO VERIFY THAT VECTOR HAS BEEN SORTED - INSERT ANYWHERE TO VIEW
// CONTENTS OF ANY VECTOR

   // for( int index = 0; index < numValues; index++ )
   // {
   //    cout << index + 1 << ". " << vec1[index] << endl;
   // }

   // exit program successfully
   return EXIT_SUCCESS;
}

// FUNCTION IMPLEMENTATION

// generates a single random value when called
int randomNumberGenerator()
{
   // generate seed for random number engine
   unsigned seed = chrono::system_clock::now().time_since_epoch().count();

   // generate random number based on seed value
   default_random_engine dre( seed ); // [1,2147483646]
   mt19937 mt( seed ); // [0,4294967295]

   // define value distribution of integers
   uniform_int_distribution<int> dist(0, 1000000);

   // return a random number within the distribution generated by the engine
   return dist( mt );
}

// acts as a delay when generating random numbers
void delay()
{
   for( int i = 0; i < 1000; i++ )
   {
      for( int j = 0; j < 1000; j++ )
      { /*do nothing*/ }
   }
}

// generates a file of n random integers
void generateFile( int numValues )
{
   // declare variables
   int counter;
   ofstream fout;

   // clear and open file stream
   fout.clear();
   fout.open( "values.txt" );

   cout << "Generating " << numValues << " random values..." << endl << endl;

   // generate n values using a loop with delay function
   for( counter = 0; counter < numValues; counter++ )
   {
      // output random value to file
      fout << randomNumberGenerator() << endl;
      delay();
   }
   // close file stream
   fout.close();
}

// fills vector with random integers from file generated
void loadVector( vector<int>& vec, int numValues )
{
   // declare variables
   int index, number;
   ifstream fin;

   // clear and open file stream
   fin.clear();
   fin.open( "values.txt" );

   // fill vector with all values in file
   for( index = 0; index < numValues; index++ )
   {
      fin >> number;
      vec[ index ] = number;
   }
   // close file stream
   fin.close();
}

// O(n^2) sorting algorithm
void bubbleSort( vector<int>& vec,
                 unsigned long long int& comparisons, unsigned long long int& swaps )
{
   bool sorted = false;
   unsigned int count, index;

   for( count = 1; ( count < vec.size() ) && sorted == false; count++ )
   {
      sorted = true;

      for( index = 0; index < vec.size() - count; index++ )
      {
         comparisons++;
         if( vec[ index ] > vec[ index + 1 ] )
         {
            swaps++;
            swap( vec[ index ], vec[ index + 1 ] );
            sorted = false;
         }
      }
   }
}

// O(n*log(n)) sorting algorithm
void quickSort( vector<int>& vec, int first, int last,
                unsigned long long int& comparisons, unsigned long long int& swaps )
{
    int middle;

    comparisons++;
    if( first < last )
    {
        middle = partition( vec, first, last, comparisons, swaps );
        quickSort( vec, first, middle, comparisons, swaps );
        quickSort( vec, middle + 1, last, comparisons, swaps );
    }
}

// quicksort helper function for partitioning vectors
int partition( vector<int>& vec, int first, int last,
               unsigned long long int& comparisons, unsigned long long int& swaps )
{
    int x = vec[ first ];
    int y = first;
    int z;

    for( z = first + 1; z < last; z++ )
    {
        comparisons++;
        if( vec[ z ] <= x )
        {
            y++;
            swaps++;
			   swap( vec[ y ], vec[ z ] );
        }
    }
    swaps++;
    swap( vec[ y ], vec[ first ] );

    return y;
}

// O(n) sorting algorithm
void radixSort( vector<int>& vec )
{
  for (int i = 0; i < 32; ++i)
  {
    vector<int> zeroBucket;
    vector<int> oneBucket;

    for ( unsigned int j = 0; j < vec.size(); ++j)
    {
      int bit = ( vec[j] >> i ) & 1;

      if ( bit == 1 )
      {
        oneBucket.push_back(vec[j]);
      }
      else
      {
        zeroBucket.push_back(vec[j]);
      }
    }

    vec.clear();

    if (i == 31)
    {
      vec.insert(vec.end(), oneBucket.begin(), oneBucket.end());
      vec.insert(vec.end(), zeroBucket.begin(), zeroBucket.end());
    }
    else
    {
      vec.insert(vec.end(), zeroBucket.begin(), zeroBucket.end());
      vec.insert(vec.end(), oneBucket.begin(), oneBucket.end());
    }
  }
}

// run function containing all logistical and timing functionality, to be called in main
double run( string sort, vector<int>& vec, int numValues,
            unsigned long long int& comparisons, unsigned long long int& swaps )
{
   // declare clock variables
   clock_t t1, t2, t3;

   // clear contents of vector
   vec.clear();

   // resize vector in advance
   vec.resize( numValues );

   // load randomly generated values into the vector
   loadVector( vec, numValues );

   // reset comparisons and swaps back to 0
   comparisons = 0, swaps = 0;

   // check which sort should be run based on the argument that was passed in
   if( sort == "Bubble Sort" )
   {
      // begin clock
      t1 = clock();
      // run sort
      bubbleSort( vec, comparisons, swaps );
      // end clock
      t2 = clock();

      // subtract difference between two clocks to find duration of the sort
      t3 = t2 - t1;
   }
   else if( sort == "Quick Sort" )
   {
      // begin clock
      t1 = clock();
      // run sort
      quickSort( vec, 0, vec.size(), comparisons, swaps );
      // end clock
      t2 = clock();

      // subtract difference between two clocks to find duration of the sort
      t3 = t2 - t1;
   }
   else if( sort == "Radix Sort" )
   {
      // begin clock
      t1 = clock();
      // run sort
      radixSort( vec );
      // end clock
      t2 = clock();

      // subtract difference between two clocks to find duration of the sort
      t3 = t2 - t1;
   }

   // return duration of the sort cast as a double
   return (double)t3;
}
