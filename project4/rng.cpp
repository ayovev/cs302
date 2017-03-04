#include <cstdlib>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int main()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    default_random_engine dre(seed); // [1,2147483646]
    mt19937 mt(seed); // [0,4294967295]

    uniform_int_distribution<unsigned long int> dist(1, 1000000);

    for( int i = 0; i < 5; i++ )
    {
      cout << "Random value from distribution using default_random_engine: " << dist(dre) << endl << endl;
    }

    for( int i = 0; i < 5; i++ )
    {
      cout << "Random value from distribution using mt19937: " << dist(mt) << endl << endl;
    }

    return EXIT_SUCCESS;
}
