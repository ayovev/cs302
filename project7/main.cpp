// include libraries and header files
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "overview.h"
#include "suit.h"
#include "player.cpp"

using namespace std;

void readInBeginning( ifstream& fin );
void readPlayerName( ifstream& fin, Player& player );

// main function
int main()
{
   Player playerOne, playerTwo;
   string name;
   
   ifstream fin;
   
   fin.clear();
   fin.open( "PlayerStatistics.json" );
   
   readInBeginning( fin );
   readPlayerName( fin, playerOne );
   
   fin.close();

   // return successful program execution
   return EXIT_SUCCESS;
}

void readInBeginning( ifstream& fin )
{
   char temp;
   
   fin >> temp;
   
   while( temp != ':' )
   {
      fin >> temp;
   }   
   fin >> temp;
}

void readPlayerName( ifstream& fin, Player& player )
{
   string name;
   
   getline( fin, name, '\"');
   
   player.setName( name );
   
   cout << player.getName() << endl;
}