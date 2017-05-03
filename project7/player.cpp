// include library and header file
#include <iostream>
#include "player.h"

using namespace std;

// set player name
void Player::setName( const string name )
{
   playerName = name;
}

// get player name
string Player::getName()
{
   return playerName;
}

// print only the player name
void Player::printName()
{
   cout << endl << "Player Name: " << playerName << endl;
}

// print all information from overview section for player
void Player::printOverview()
{
   cout << endl 
        << "Player Overview" << endl
        << "---------------" << endl
        << "Games Won: " << all.getGamesWon() << endl
        << "Win Rate: " << all.getWinRate() << endl
        << "Games Played: " << all.getGamesPlayed() << endl
        << "Fastest Win: " << all.getFastestWin() << endl
        << "Fewest Moves: " << all.getFewestMoves() << endl
        << "Top Score: " << all.getTopScore() << endl
        << endl;
}

// print all information from suits section for player
void Player::printSuits()
{
   for( int j = 0; j < NUM_SUITS; j++ )
   {
      cout << suitType[ j ].getType() << endl
           << suitType[ j ].getGamesWon() << endl
           << suitType[ j ].getWinRate() << endl
           << suitType[ j ].getGamesPlayed() << endl
           << suitType[ j ].getFastestWin() << endl
           << suitType[ j ].getFewestMoves() << endl
           << suitType[ j ].getTopScore() << endl << endl;
   }
}

// print all info about player
void Player::printAllInfo()
{
   printName();
   printOverview();
   printSuits();
}