// include libraries and header files
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "overview.cpp"
#include "suit.cpp"
#include "player.cpp"

using namespace std;

const int NUM_SUITS = 3;

void prime( ifstream& fin );
void readPlayerName( ifstream& fin, Player& player );
void readOverview( ifstream& fin, Player& player );
void readSuits( ifstream& fin, Player& player );


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
   readSuits( fin, playerOne );
   
   // playerOne.printName();
   // playerOne.printOverview();
   // playerOne.printAllInfo();
   
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
      
      // // IFTP
      // cout << temp << endl;
      // 
      // system("pause");
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
   
   // // IFTP
   // for( int j = 0; j < NUM_SUITS; j++ )
   // {
   //    cout << player.suitType[ j ].getType() << endl
   //         << player.suitType[ j ].getGamesWon() << endl
   //         << player.suitType[ j ].getWinRate() << endl
   //         << player.suitType[ j ].getGamesPlayed() << endl
   //         << player.suitType[ j ].getFastestWin() << endl
   //         << player.suitType[ j ].getFewestMoves() << endl
   //         << player.suitType[ j ].getTopScore() << endl << endl;
   //         
   //    system("pause");
   }
}