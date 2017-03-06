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

   for( index = 0; index < numValues; index++ )
   {
      cout << index + 1 << ". " << vec1[index] << endl;
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