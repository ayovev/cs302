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
   int numValues;
   unsigned long long int comparisons = 0, swaps = 0;
   vector<int> vec1, vec2, vec3;
   double averageTime = 0;
   int numRuns = 10;

   for( int i = 1, count = 0; count < 3; i *= 10, count++ )
   {
      numValues = i * 1000;

      generateFile( numValues );

      if( numValues == 100000 )
      {
         numRuns = 3;
      }

      cout << endl << "Running bubble sort " << numRuns << " times with " << numValues << " values..." << endl;

      for( int i = 0; i < numRuns; i++ )
      {
         averageTime += run( "Bubble Sort", vec1, numValues, comparisons, swaps );
      }
      cout << "Average sorting time of " << numRuns << " runs for bubble sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
      cout << "Average number of comparisons of " << numRuns << " runs for bubble sort: " << comparisons / numRuns << endl;
      cout << "Average number of swaps of " << numRuns << " runs for bubble sort: " << swaps / numRuns << endl << endl;

      averageTime = 0, comparisons = 0, swaps = 0;

      numRuns = 10;

      cout << endl << "Running quick sort " << numRuns << " times with " << numValues << " values..." << endl;

      for( int i = 0; i < numRuns; i++ )
      {
         averageTime += run( "Quick Sort", vec2, numValues, comparisons, swaps );
      }
      cout << "Average sorting time of " << numRuns << " runs for quick sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
      cout << "Average number of comparisons of " << numRuns << " runs for quick sort: " << comparisons / numRuns << endl;
      cout << "Average number of swaps of " << numRuns << " runs for quick sort: " << swaps / numRuns << endl << endl;

      averageTime = 0, comparisons = 0, swaps = 0;

      cout << endl << "Running radix sort " << numRuns << " times with " << numValues << " values..." << endl;

      for( int i = 0; i < numRuns; i++ )
      {
         averageTime += run( "Radix Sort", vec3, numValues, comparisons, swaps );
      }
      cout << "Average sorting time of " << numRuns << " runs for radix sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " seconds" << endl;
      cout << "Average number of comparisons of " << numRuns << " runs for radix sort: " << comparisons / numRuns << endl;
      cout << "Average number of swaps of " << numRuns << " runs for radix sort: " << swaps / numRuns << endl << endl;
   }

// TEST OUTPUT TO VERIFY THAT VECTOR HAS BEEN SORTED - INSERT ANYWHERE TO VIEW
// CONTENTS OF ANY VECTOR

   // for( int index = 0; index < numValues; index++ )
   // {
   //    cout << index + 1 << ". " << vec1[index] << endl;
   // }

   return EXIT_SUCCESS;
}

// FUNCTION IMPLEMENTATION
int randomNumberGenerator()
{
   unsigned seed = chrono::system_clock::now().time_since_epoch().count();

   default_random_engine dre( seed ); // [1,2147483646]
   mt19937 mt( seed ); // [0,4294967295]

   uniform_int_distribution<int> dist(0, 1000000);

   return dist( mt );
}

void delay()
{
   for( int i = 0; i < 1000; i++ )
   {
      for( int j = 0; j < 1000; j++ )
      {}
   }
}

void generateFile( int numValues )
{
   int counter;
   ofstream fout;

   fout.clear();
   fout.open( "values.txt" );

   cout << "Generating " << numValues << " random values..." << endl << endl;

   for( counter = 0; counter < numValues; counter++ )
   {
      fout << randomNumberGenerator() << endl;
      delay();
   }

   fout.close();
}

void loadVector( vector<int>& vec, int numValues )
{
   int index, number;
   ifstream fin;

   fin.clear();
   fin.open( "values.txt" );

   for( index = 0; index < numValues; index++ )
   {
      fin >> number;
      vec[ index ] = number;
   }

   fin.close();
}

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

double run( string sort, vector<int>& vec, int numValues,
            unsigned long long int& comparisons, unsigned long long int& swaps )
{
   clock_t t1, t2, t3;

   vec.clear();

   vec.resize( numValues );

   loadVector( vec, numValues );

   comparisons = 0, swaps = 0;

   if( sort == "Bubble Sort" )
   {
      t1 = clock();
      bubbleSort( vec, comparisons, swaps );
      t2 = clock();

      t3 = t2 - t1;
   }
   else if( sort == "Quick Sort" )
   {
      t1 = clock();
      quickSort( vec, 0, vec.size(), comparisons, swaps );
      t2 = clock();

      t3 = t2 - t1;
   }
   else if( sort == "Radix Sort" )
   {
      t1 = clock();
      radixSort( vec );
      t2 = clock();

      t3 = t2 - t1;
   }

   return (double)t3;
}
