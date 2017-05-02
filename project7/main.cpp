// include libraries and header files
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "overview.cpp"
#include "suit.h"
#include "player.cpp"

using namespace std;

void readPlayerName( ifstream& fin, Player& player );
void readOverview( ifstream& fin, Player& player );
void prime( ifstream& fin );

// main function
int main()
{
   char temp;
   Player playerOne, playerTwo;
   string name;
   
   ifstream fin;
   
   fin.clear();
   fin.open( "PlayerStatistics.json" );
   
   readPlayerName( fin, playerOne );
   readOverview( fin, playerOne );
   
   fin.close();

   // return successful program execution
   return EXIT_SUCCESS;
}

void readPlayerName( ifstream& fin, Player& player )
{
   char temp;
   string name;
   
   prime( fin );
   fin >> temp;
   
   getline( fin, name, '\"');
   
   player.setName( name );
   
   fin >> temp;
}

void readOverview( ifstream& fin, Player& player )
{
   char temp;
   int value;
   
   prime( fin );
   prime( fin );
   fin >> value;
   player.all.setGamesWon( value );
   
   prime( fin );
   fin >> value;
   player.all.setWinRate( value );
   
   prime( fin );
   fin >> value;
   player.all.setGamesPlayed( value );
   
   prime( fin );
   fin >> value;
   player.all.setFastestWin( value );
   
   prime( fin );
   fin >> value;
   player.all.setFewestMoves( value );
   
   prime( fin );
   fin >> value;
   player.all.setTopScore( value );
}

void prime( ifstream& fin )
{
   char temp;
   
   fin >> temp;
   
   while( temp != ':' )
   {
      fin >> temp;
      
      // // IFTP
      // cout << temp << endl;
      // 
      // system("pause");
   }
}