#include "overview.h"

void Overview::setGamesWon( const int gw )
{
   gamesWon = gw;
}

int Overview::getGamesWon()
{
   return gamesWon;
}

void Overview::setWinRate( const double wr )
{
   winRate = wr;
}

double Overview::getWinRate()
{
   return winRate;
}

void Overview::setGamesPlayed( const int gp )
{
   gamesPlayed = gp;
}

int Overview::getGamesPlayed()
{
   return gamesPlayed;
}

void Overview::setFastestWin( const double fw )
{
   fastestWin = fw;
}

double Overview::getFastestWin()
{
   return fastestWin;
}

void Overview::setFewestMoves( const int fm )
{
   fewestMoves = fm;
}

int Overview::getFewestMoves()
{
   return fewestMoves;
}

void Overview::setTopScore( const int ts )
{
   topScore = ts;
}

int Overview::getTopScore()
{
   return topScore;
}