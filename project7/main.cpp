// include libraries and header files
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "overview.h"
#include "suit.h"
#include "player.h"

using namespace std;

// function prototypes
void prime( ifstream& fin );
void readPlayerName( ifstream& fin, Player& player );
void readOverview( ifstream& fin, Player& player );
void readSuits( ifstream& fin, Player& player );

// main function
int main()
{
   // declare variables
   Player playerOne, playerTwo;
   string name;
   ifstream fin;
   
   // clear and open file stream
   fin.clear();
   fin.open( "PlayerStatistics.json" );
   
   // parse through various parts of JSON file for player one
   readPlayerName( fin, playerOne );
   readOverview( fin, playerOne );
   readSuits( fin, playerOne );
   
   // parse through various parts of JSON file for player two
   readPlayerName( fin, playerTwo );
   readOverview( fin, playerTwo);
   readSuits( fin, playerTwo );
   
   // print all info for both players
   playerOne.printAllInfo();   
   playerTwo.printAllInfo();
   
   // close file stream
   fin.close();

   // return successful program execution
   return EXIT_SUCCESS;
}

void prime( ifstream& fin )
{
   // declare variable
   char temp;
   
   // prime while loop
   fin >> temp;
   
   // check if character is not a semicolon
   while( temp != ':' )
   {
      // get next character
      fin >> temp;
   }
}

void readPlayerName( ifstream& fin, Player& player )
{
   // declare variables
   char temp;
   string name;
   
   // prime file stream in JSON file
   prime( fin );
   fin >> temp;
   
   // read in name
   getline( fin, name, '\"');
   
   // set players name to value that was read in
   player.setName( name );
}

void readOverview( ifstream& fin, Player& player )
{
   // declare variable
   int value;
   
   // prime file stream, read in data, set attribute to data
   prime( fin );
   prime( fin );
   fin >> value;
   player.all.setGamesWon( value );
   
   // prime file stream, read in data, set attribute to data
   prime( fin );
   fin >> value;
   player.all.setWinRate( value );
   
   // prime file stream, read in data, set attribute to data
   prime( fin );
   fin >> value;
   player.all.setGamesPlayed( value );
   
   // prime file stream, read in data, set attribute to data
   prime( fin );
   fin >> value;
   player.all.setFastestWin( value );
   
   // prime file stream, read in data, set attribute to data
   prime( fin );
   fin >> value;
   player.all.setFewestMoves( value );
   
   // prime file stream, read in data, set attribute to data
   prime( fin );
   fin >> value;
   player.all.setTopScore( value );
}

void readSuits( ifstream& fin, Player& player )
{
   // declare variables
   char temp;
   int value;
   string type;
   
   // prime file stream
   prime( fin );
   
   // loop for the number of suits
   for( int i = 0; i < NUM_SUITS; i++ )
   {
      // prime file stream, read first double quote
      prime( fin );
      fin >> temp;
      
      // get suit type, up to but not including the second double quote
      getline( fin, type, '\"');
      
      // set attribute to getline() data
      player.suitType[ i ].setType( type );
      
      // prime file stream, read in data, set attribute to data
      prime( fin );
      fin >> value;
      player.suitType[ i ].setGamesWon( value );    
      
      // prime file stream, read in data, set attribute to data
      prime( fin );
      fin >> value;
      player.suitType[ i ].setWinRate( value );
      
      // prime file stream, read in data, set attribute to data
      prime( fin );
      fin >> value;
      player.suitType[ i ].setGamesPlayed( value );
      
      // prime file stream, read in data, set attribute to data
      prime( fin );
      fin >> value;
      player.suitType[ i ].setFastestWin( value );
      
      // prime file stream, read in data, set attribute to data
      prime( fin );
      fin >> value;
      player.suitType[ i ].setFewestMoves( value );
      
      // prime file stream, read in data, set attribute to data
      prime( fin );
      fin >> value;
      player.suitType[ i ].setTopScore( value );
   }
}