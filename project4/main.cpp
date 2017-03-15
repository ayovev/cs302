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

// WORKING FUNCTION PROTOTYPES
int randomNumberGenerator();
void delay();
void generateFile( int numValues );
void loadVector( vector<int>& vec, int numValues );
void logStuff( string sort, const int comparisons, const int swaps );
void bubbleSort( vector<int>& vec, int& comparisons, int& swaps );
void quickSort( vector<int>& vec, int first, int last, int& comparisons, int& swaps );
int partition( vector<int>& vec, int first, int last, int& comparisons, int& swaps );
void radixSort( vector<int>& vec, int& swaps );
double run( string sort, vector<int>& vec, int numValues, int& comparisons, int& swaps );

// MAIN PROGRAM
int main()
{
   int numValues, comparisons, swaps;
   vector<int> vec1, vec2, vec3;
   double averageTime = 0;

   numValues = 1000;

   for( int i = 0; i < 5; i++ )
   {
      averageTime += run( "Bubble Sort", vec1, numValues, comparisons, swaps );
   }
   cout << "Average sorting time: " << ( averageTime / CLOCKS_PER_SEC ) / 5 << endl;

   system("pause");

   run( "Bubble Sort", vec1, numValues, comparisons, swaps );
   run( "Quick Sort", vec2, numValues, comparisons, swaps );
   run( "Radix Sort", vec3, numValues, comparisons, swaps );

// TEST OUTPUT TO VERIFY THAT VECTOR HAS BEEN SORTED - INSERT ANYWHERE TO VIEW
// CONTENTS OF VECTOR

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

   cout << "Generating " << numValues << " Random Values..." << endl;

   fout.clear();
   fout.open( "values.txt" );

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

void logStuff( const string sort, const int comparisons, const int swaps )
{
   cout << sort << " took "
        << comparisons << " comparisons and "
        << swaps << " swaps." << endl;
}

void bubbleSort( vector<int>& vec, int& comparisons, int& swaps )
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

void quickSort( vector<int>& vec, int first, int last, int& comparisons, int& swaps )
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

int partition( vector<int>& vec, int first, int last, int& comparisons, int& swaps )
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

void radixSort( vector<int>& vec, int& swaps )
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
      swaps++;
      vec.insert(vec.end(), oneBucket.begin(), oneBucket.end());
      swaps++;
      vec.insert(vec.end(), zeroBucket.begin(), zeroBucket.end());
    }
    else
    {
      swaps++;
      vec.insert(vec.end(), zeroBucket.begin(), zeroBucket.end());
      swaps++;
      vec.insert(vec.end(), oneBucket.begin(), oneBucket.end());
    }
  }
}

double run( string sort, vector<int>& vec, int numValues, int& comparisons, int& swaps )
{
   clock_t t1, t2, t3;

   vec.clear();

   vec.resize( numValues );

   generateFile( numValues );

   loadVector( vec, numValues );

   comparisons = 0, swaps = 0;

   if( sort == "Bubble Sort" )
   {
      t1 = clock();
      bubbleSort( vec, comparisons, swaps );
      t2 = clock();
      logStuff( "Bubble Sort", comparisons, swaps );

      t3 = t2 - t1;

      cout << "It took " << ( (double)t3 / CLOCKS_PER_SEC ) << " seconds to sort a vector with bubble sort." << endl << endl;
   }
   else if( sort == "Quick Sort" )
   {
      t1 = clock();
      quickSort( vec, 0, vec.size(), comparisons, swaps );
      t2 = clock();
      logStuff( "Quick Sort", comparisons, swaps );

      t3 = t2 - t1;

      cout << "It took " << ( (double)t3 / CLOCKS_PER_SEC ) << " seconds to sort a vector with quick sort." << endl << endl;
   }
   else if( sort == "Radix Sort" )
   {
      t1 = clock();
      radixSort( vec, swaps );
      t2 = clock();
      logStuff( "Radix Sort", comparisons, swaps );

      t3 = t2 - t1;

      cout << "It took " << ( (double)t3 / CLOCKS_PER_SEC ) << " seconds to sort a vector with radix sort." << endl << endl;
   }

   return (double)t3;
}
