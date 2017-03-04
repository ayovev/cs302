#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>
#include <vector>

void generateFile( int numValues );
int randomNumberGenerator();
void delay();

using namespace std;

int main()
{
   int index, number, numValues;
   ifstream fin;
   vector<int> vec;

   cout << "How many values would you like to test? ";
   cin >> numValues;

   vec.resize( numValues );
   generateFile( numValues );

   fin.clear();
   fin.open("values.txt");

   for( index = 0; fin.eof() == false; index++ )
   {
      fin >> number;
      vec[ index ] = number;
   }

   for( index = 0; index < numValues; index++ )
   {
      cout << vec[index] << endl;
   }

   cout << endl;

   return EXIT_SUCCESS;
}

int randomNumberGenerator()
{
   unsigned seed = chrono::system_clock::now().time_since_epoch().count();

   default_random_engine dre(seed); // [1,2147483646]
   mt19937 mt(seed); // [0,4294967295]

   uniform_int_distribution<int> dist(1, 1000000);

   return dist( dre );
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