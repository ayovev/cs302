// include libraries and header files
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "overview.h"
#include "suit.h"
#include "player.h"

using namespace std;

// global constants (for outputting)
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
void simulate( Player& player );

// main function
int main()
{
   // declare variables
   Player playerOne, playerTwo;
   string name;
   ifstream fin;
   ofstream fout;
   
   // clear and open input file stream
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
   
   // close input file stream
   fin.close();
   
   // perform simulations on 
   simulate( playerOne );
   
   // clear and open output file stream
   fout.clear();
   fout.open( "PlayerStatistics.json" );
   
   // output beginning characters of JSON file
   fout << OPEN_BRACKET << OPEN_BRACE << endl;
   
   // output all the various parts of player one
   outputPlayerName( fout, playerOne );
   outputOverview( fout, playerOne );
   outputSuits( fout, playerOne );
   fout << CLOSE_BRACE << COMMA << SPACE << OPEN_BRACE << endl;
   
   // output all the various parts of player two
   outputPlayerName( fout, playerTwo );
   outputOverview( fout, playerTwo );
   outputSuits( fout, playerTwo );
   fout << CLOSE_BRACE << CLOSE_BRACKET;
   
   // close output file stream
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
   double value;
   
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
   double value;
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
   // output player name in specified format
   fout << TAB << "\"Player Name\"" << COLON << SPACE
        << DOUBLE_QUOTE << player.getName() << DOUBLE_QUOTE << COMMA << endl;
}

void outputOverview( ofstream& fout, Player& player )
{
   // set precision to 2 decimal places using fixed notation
   fout.precision( 2 );
   fout << fixed;
   
   // output section title
   fout << TAB << "\"Overview\"" << COLON << SPACE << OPEN_BRACE << endl;
   
   // output all parts pertaining to overview section of JSON file
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
   
   // output section ending characters     
   fout << TAB << CLOSE_BRACE << COMMA << endl;
}

void outputSuits( ofstream& fout, Player& player )
{
   // set precision to 2 decimal places using fixed notation
   fout.precision( 2 );
   fout << fixed;
   
   // output section title
   fout << TAB << "\"Suits\"" << COLON << SPACE
        << OPEN_BRACKET << OPEN_BRACE << endl;
   
   // use for loop to loop through array of suits
   for( int i = 0; i < NUM_SUITS; i++ )
   {
      // output all parts pertaining to suit section in specified format
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
      
      // output section ending characters     
      fout << TAB << TAB << CLOSE_BRACE;
      if( i < NUM_SUITS - 1 )
      {
         fout << COMMA << endl << TAB << TAB << OPEN_BRACE << endl;
      }
   }
   fout << endl << TAB << CLOSE_BRACKET << endl;
}

void simulate( Player& player )
{
   // set various player attributes as per project specifications and perform
   // necessary calculations to output correct data, this is done on a suit
   // by suit basis then adding it all up in the overview in the end
   player.suitType[ 0 ].setGamesWon( 5 );
   player.suitType[ 0 ].setGamesPlayed( 5 );
   player.suitType[ 0 ].setWinRate( (double)player.suitType[ 0 ].getGamesWon() / 
                                    (double)player.suitType[ 0 ].getGamesPlayed() );
   
   player.suitType[ 1 ].setGamesWon( 2 );
   player.suitType[ 1 ].setGamesPlayed( 5 );
   player.suitType[ 1 ].setWinRate( (double)player.suitType[ 1 ].getGamesWon() / 
                                    (double)player.suitType[ 1 ].getGamesPlayed() );
   
   player.suitType[ 2 ].setGamesWon( 0 );
   player.suitType[ 2 ].setGamesPlayed( 5 );
   player.suitType[ 2 ].setWinRate( (double)player.suitType[ 2 ].getGamesWon() / 
                                    (double)player.suitType[ 2 ].getGamesPlayed() );
   
   player.all.setGamesPlayed( player.suitType[ 0 ].getGamesPlayed() + 
                              player.suitType[ 1 ].getGamesPlayed() +
                              player.suitType[ 2 ].getGamesPlayed() );
                              
   player.all.setGamesWon( player.suitType[ 0 ].getGamesWon() +
                           player.suitType[ 1 ].getGamesWon() +
                           player.suitType[ 2 ].getGamesWon() );
                           
   player.all.setWinRate( (double)player.all.getGamesWon() / 
                          (double)player.all.getGamesPlayed() );                         
}