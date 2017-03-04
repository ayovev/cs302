#include <cstdlib>
#include <iostream>
#include <ctime>
#include <chrono>
#include <random>

int randomNumberGenerator();
void delay();

using namespace std;

int main()
{
   int numValues;

   cout << "How many values would you like to test? ";
   cin >> numValues;

   int arr[ numValues ];

   for( int i = 0; i < numValues; i++ )
   {
      arr[i] = randomNumberGenerator();
      delay();
   }

   for( int i = 0; i < numValues; i++ )
   {
      cout << arr[i] << endl;
   }

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