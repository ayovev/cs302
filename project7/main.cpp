// include libraries and header files
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "overview.h"
#include "suit.h"
#include "player.h"

using namespace std;

const char DOUBLE_QUOTE = '\"';
const char COLON = ':';
const char OPEN_BRACKET = '[';
const char CLOSE_BRACKET = ']';
const char OPEN_BRACE = '{';
const char CLOSE_BRACE = '}';
const char COMMA = ',';
const char TAB = '\t';
const char SPACE = ' ';

// function prototypes
void prime( ifstream& fin );
void readPlayerName( ifstream& fin, Player& player );
void readOverview( ifstream& fin, Player& player );
void readSuits( ifstream& fin, Player& player );
void outputPlayerName( ofstream& fout, Player& player );
void outputOverview( ofstream& fout, Player& player );
void outputSuits( ofstream& fout, Player& player );

// main function
int main()
{
   // declare variables
   Player playerOne, playerTwo;
   string name;
   ifstream fin;
   ofstream fout;
   
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
   //playerOne.printAllInfo();   
   //playerTwo.printAllInfo();
   
   // close file stream
   fin.close();
   
   fout.clear();
   fout.open( "output.json" );

   fout << OPEN_BRACKET << OPEN_BRACE << endl;
   
   outputPlayerName( fout, playerOne );
   outputOverview( fout, playerOne );
   outputSuits( fout, playerOne );
   fout << CLOSE_BRACE << COMMA << SPACE << OPEN_BRACE << endl;
   
   outputPlayerName( fout, playerTwo );
   outputOverview( fout, playerTwo );
   outputSuits( fout, playerTwo );
   fout << CLOSE_BRACE << CLOSE_BRACKET;
   
   fout.close();

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

void outputPlayerName( ofstream& fout, Player& player )
{
   fout << TAB << "\"Player Name\"" << COLON << SPACE
        << DOUBLE_QUOTE << player.getName() << DOUBLE_QUOTE << COMMA << endl;
}

void outputOverview( ofstream& fout, Player& player )
{
   fout << TAB << "\"Overview\"" << COLON << SPACE << OPEN_BRACE << endl;
   
   fout << TAB << TAB << "\"Games Won\"" << COLON << SPACE
        << player.all.getGamesWon() << COMMA << endl;
        
   fout << TAB << TAB << "\"Win Rate\"" << COLON << SPACE
        << player.all.getWinRate() << COMMA << endl;
        
   fout << TAB << TAB << "\"Games Played\"" << COLON << SPACE
        << player.all.getGamesPlayed() << COMMA << endl;
        
   fout << TAB << TAB << "\"Fastest Win\"" << COLON << SPACE
        << player.all.getFastestWin() << COMMA << endl;
        
   fout << TAB << TAB << "\"Fewest Moves\"" << COLON << SPACE
        << player.all.getFewestMoves() << COMMA << endl;
        
   fout << TAB << TAB << "\"Top Score\"" << COLON << SPACE
        << player.all.getTopScore() << endl;
        
   fout << TAB << CLOSE_BRACE << COMMA << endl;
}

void outputSuits( ofstream& fout, Player& player )
{
   fout << TAB << "\"Suits\"" << COLON << SPACE
        << OPEN_BRACKET << OPEN_BRACE << endl;
        
   for( int i = 0; i < NUM_SUITS; i++ )
   {
      fout << TAB << TAB << TAB << "\"Type\"" << COLON << SPACE
           << DOUBLE_QUOTE << player.suitType[ i ].getType() << DOUBLE_QUOTE
           << COMMA << endl;
           
      fout << TAB << TAB << TAB << "\"Games Won\"" << COLON << SPACE
           << player.suitType[ i ].getGamesWon() << COMMA << endl;
           
      fout << TAB << TAB << TAB << "\"Win Rate\"" << COLON << SPACE
           << player.suitType[ i ].getWinRate() << COMMA << endl;
           
      fout << TAB << TAB << TAB << "\"Games Played\"" << COLON << SPACE
           << player.suitType[ i ].getGamesPlayed() << COMMA << endl;
           
      fout << TAB << TAB << TAB << "\"Fastest Win\"" << COLON << SPACE
           << player.suitType[ i ].getFastestWin() << COMMA << endl;
           
      fout << TAB << TAB << TAB << "\"Fewest Moves\"" << COLON << SPACE
           << player.suitType[ i ].getFewestMoves() << COMMA << endl;
           
      fout << TAB << TAB << TAB << "\"Top Score\"" << COLON << SPACE
           << player.suitType[ i ].getTopScore() << endl;
           
      fout << TAB << TAB << CLOSE_BRACE;
      if( i < NUM_SUITS - 1 )
      {
         fout << COMMA << endl << TAB << TAB << OPEN_BRACE << endl;
      }
   }
   fout << endl << TAB << CLOSE_BRACKET << endl;
}