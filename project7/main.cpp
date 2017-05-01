// include libraries and header files
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "overview.h"
#include "suit.h"
#include "player.h"

using namespace std;

// main function
int main()
{
   ifstream fin;
   
   fin.clear();
   fin.open( "PlayerStatistics.json" );
   
   fin.close();
   
   Player first;

   // return successful program execution
   return EXIT_SUCCESS;
}