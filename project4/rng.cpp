#include <cstdlib>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

/*
int main()
{
   srand(time(0));

   cout << rand() % 1000000 << endl;

   cout << endl;

   return EXIT_SUCCESS;
}
*/

int main()
{
    random_device seed; // [0,4294967295]
    default_random_engine engine; // [1,2147483646]
    mt19937 mt(seed()); // [0,4294967295]
    uniform_int_distribution<int> dist(1, 10);

    cout << "Minimum: " << seed.min() << endl
         << "Maximum: " << seed.max() << endl << endl;

    cout << "Minimum: " << engine.min() << endl
         << "Maximum: " << engine.max() << endl << endl;

    cout << "Minimum: " << mt.min() << endl
         << "Maximum: " << mt.max() << endl << endl;

    cout << "Random value from random_device: " << seed() % 1000000 << endl
         << "Random value from default_random_engine: " << engine() % 1000000 << endl
         << "Random value from mt19937: " << mt() % 1000000 << endl << endl;

    return EXIT_SUCCESS;
}
