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

using namespace std;

// WORKING FUNCTION PROTOTYPES
int randomNumberGenerator();
void delay();
void generateFile( int numValues );
void loadVector( vector<int>& vec );
void logStuff( ofstream& fout, string sort, const int comparisons, const int swaps );
void bubbleSort( vector<int>& vec, int& comparisons, int& swaps );
void quickSort( vector<int>& vec, int first, int last, int& comparisons, int& swaps );
int partition( vector<int>& vec, int first, int last, int& comparisons, int& swaps );
void radixSort( vector<int>& vec, int& comparisons, int& swaps );


// MAIN PROGRAM
int main()
{
   int numValues, comparisons, swaps;
   vector<int> vec1, vec2, vec3;
   ofstream fout;

   fout.clear();
   fout.open( "log.txt" );

   numValues = 1000;

   vec1.resize( numValues );
   vec2.resize( numValues );
   vec3.resize( numValues );

   generateFile( numValues );

   loadVector( vec1 );
   loadVector( vec2 );
   loadVector( vec3 );

   comparisons = 0, swaps = 0;
   cout << "Sorting Vector 1 With Bubble Sort" << endl;
   bubbleSort( vec1, comparisons, swaps );
   logStuff( fout, "Bubble Sort", comparisons, swaps );

   comparisons = 0, swaps = 0;
   cout << "Sorting Vector 2 With Quick Sort" << endl;
   quickSort( vec2, 0, vec2.size(), comparisons, swaps );
   logStuff( fout, "Quick Sort", comparisons, swaps );

   comparisons = 0, swaps = 0;
   cout << "Sorting Vector 3 With Radix Sort" << endl;
   radixSort( vec3, comparisons, swaps );
   logStuff( fout, "Radix Sort", comparisons, swaps );

// TEST OUTPUT TO VERIFY THAT VECTOR HAS BEEN SORTED - INSERT ANYWHERE TO VIEW
// CONTENTS OF VECTOR
/*
   for( int index = 0; index < numValues; index++ )
   {
      cout << index + 1 << ". " << vec1[index] << endl;
   }
*/

   cout << endl;

   fout.close();

   return EXIT_SUCCESS;
}

// FUNCTION IMPLEMENTATION
int randomNumberGenerator()
{
   unsigned seed = chrono::system_clock::now().time_since_epoch().count();

   default_random_engine dre(seed); // [1,2147483646]
   mt19937 mt(seed); // [0,4294967295]

   uniform_int_distribution<int> dist(0, 1000000);

   return dist( mt );
}

void delay()
{
   for( int i = 0; i < 1500; i++ )
   {
      for( int j = 0; j < 1500; j++ )
      {}
   }
}

void generateFile( int numValues )
{
   int counter;
   ofstream fout;

   cout  << "Generating " << numValues << " Random Values..." << endl;

   fout.clear();
   fout.open( "values.txt" );

   for( counter = 0; counter < numValues; counter++ )
   {
      fout << randomNumberGenerator() << endl;
      delay();
   }

   fout.close();
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

void logStuff( ofstream& fout, const string sort, const int comparisons, const int swaps )
{
   fout << sort << " took "
        << comparisons << " comparisons and "
        << swaps << " swaps." << endl;
}

void loadVector( vector<int>& vec )
{
   int index, number;
   ifstream fin;

   cout << "Loading Vector With Random Values..." << endl;

   fin.clear();
   fin.open( "values.txt" );

   for( index = 0; fin.good() == true; index++ )
   {
      fin >> number;
      vec[ index ] = number;
   }

   fin.close();
}

void radixSort( vector<int>& vec, int& comparisons, int& swaps )
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
