// include libraries and header files
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "overview.h"
#include "suit.h"
#include "player.h"

using namespace std;

void prime( ifstream& fin );
void readPlayerName( ifstream& fin, Player& player );
void readOverview( ifstream& fin, Player& player );
void readSuits( ifstream& fin, Player& player );

// main function
int main()
{
   Player playerOne, playerTwo;
   string name;
   
   ifstream fin;
   
   fin.clear();
   fin.open( "PlayerStatistics.json" );
   
   readPlayerName( fin, playerOne );
   readOverview( fin, playerOne );
   readSuits( fin, playerOne );
   
   readPlayerName( fin, playerTwo );
   readOverview( fin, playerTwo);
   readSuits( fin, playerTwo );
   
   playerOne.printAllInfo();   
   playerTwo.printAllInfo();
   
   fin.close();

   // return successful program execution
   return EXIT_SUCCESS;
}

void prime( ifstream& fin )
{
   char temp;
   
   fin >> temp;
   
   while( temp != ':' )
   {
      fin >> temp;
   }
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

void readSuits( ifstream& fin, Player& player )
{
   char temp;
   int value;
   string type;
   
   prime( fin );
   
   for( int i = 0; i < NUM_SUITS; i++ )
   {
      prime( fin );
      fin >> temp;
      
      getline( fin, type, '\"');
      
      player.suitType[ i ].setType( type );
      
      prime( fin );
      fin >> value;
      player.suitType[ i ].setGamesWon( value );    
      
      prime( fin );
      fin >> value;
      player.suitType[ i ].setWinRate( value );
      
      prime( fin );
      fin >> value;
      player.suitType[ i ].setGamesPlayed( value );
      
      prime( fin );
      fin >> value;
      player.suitType[ i ].setFastestWin( value );
      
      prime( fin );
      fin >> value;
      player.suitType[ i ].setFewestMoves( value );
      
      prime( fin );
      fin >> value;
      player.suitType[ i ].setTopScore( value );
   }
}