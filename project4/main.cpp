#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>
#include <vector>
#include <utility>

using namespace std;

int randomNumberGenerator();
void delay();
void generateFile( int numValues );
void bubbleSort( vector<int>& vec );
void quickSort( vector<int>& vecE, int firstE, int lastE );
//void part( vector<int>& vec );
int part( vector<int>& vec, int first, int last );

int main()
{
   int index, number, numValues;
   vector<int> vec1, vec2, vec3;
   ifstream fin;

   numValues = 1000;

   vec1.resize( numValues );
   vec2.resize( numValues );
   vec3.resize( numValues );

   generateFile( numValues );

   fin.clear();
   fin.open("values.txt");

   for( index = 0; fin.good() == true; index++ )
   {
      fin >> number;
      vec1[ index ] = number;
      vec2[ index ] = number;
      vec3[ index ] = number;
   }

   bubbleSort( vec1 );
   quickSort( vec2, vec2.front(), vec2.back() );

   for( index = 0; index < numValues; index++ )
   {
      cout << index + 1 << ". " << vec2[index] << endl;
   }

   cout << endl;

   return EXIT_SUCCESS;
}

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
   for( int i = 0; i < 1200; i++ )
   {
      for( int j = 0; j < 1200; j++ )
      {}
   }
}

void generateFile( int numValues )
{
   int counter;
   ofstream fout;

   fout.clear();
   fout.open("values.txt");

   for( counter = 0; counter < numValues; counter++ )
   {
      fout << randomNumberGenerator() << endl;
      delay();
   }

   fout.close();
}

void bubbleSort( vector<int>& vec )
{
   bool sorted = false;
   int count, index;

   for( count = 1; ( count < vec.size() ) && sorted == false; count++ )
   {
      sorted = true;

      for( index = 0; index < vec.size() - count; index++ )
      {
         if( vec[ index ] > vec[ index + 1 ] )
         {
            swap( vec[ index ], vec[ index + 1 ] );
            sorted = false;
         }
      }
   }
}

void quickSort( vector<int>& vecE, int firstE, int lastE )
{
   int middle;

   if( firstE < lastE )
   {
      cout << "HOPEFULLY THIS WORKS" << endl;
      middle = part( vecE, vecE.front(), vecE.back() );
      cout << "WELL THIS WORKED" << endl;
      quickSort( vecE, firstE, middle );
      quickSort( vecE, middle + 1, lastE );
   }
}

/*
void part( vector<int>& vec )
{
   int pivot = vec[0];
   int left, right;

   for( left = 1, right = vec.size() - 1; left < right; )
   {
      if( vec[ left ] > pivot && vec[ right ] <= pivot )
      {
         swap( vec[ left ], vec[ right ] );
      }
      if( vec[ left ] <= pivot )
      {
         left++;
      }
      if( vec[ right ] > pivot )
      {
         right--;
      }
   }
}
*/

int part( vector<int>& vec, int first, int last )
{
   int pivot = vec[ first ];

   while( first != last )
   {
      if( vec[ first ] > vec[ last ] )
      {
         swap( vec[ first ], vec[ last ] );
      }
      if( pivot == vec[ first ] )
      {
         last--;
      }
      else
      {
         first++;
      }
   }

   return first;
}