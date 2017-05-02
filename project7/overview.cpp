#include "overview.h"

void Overview::setGamesWon( int gw )
{
   gamesWon = gw;
}

int Overview::getGamesWon()
{
   return gamesWon;
}

void Overview::setWinRate( double wr )
{
   winRate = wr;
}

double Overview::getWinRate()
{
   return winRate;
}

void Overview::setGamesPlayed( int gp )
{
   gamesPlayed = gp;
}

int Overview::getGamesPlayed()
{
   return gamesPlayed;
}

void Overview::setFastestWin( double fw )
{
   fastestWin = fw;
}

double Overview::getFastestWin()
{
   return fastestWin;
}

void Overview::setFewestMoves( int fm )
{
   fewestMoves = fm;
}

int Overview::getFewestMoves()
{
   return fewestMoves;
}

void Overview::setTopScore( int ts )
{
   topScore = ts;
}

int Overview::getTopScore()
{
   return topScore;
}