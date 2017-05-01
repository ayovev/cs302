#ifndef OVERVIEW_H
#define OVERVIEW_H

class Overview
{
   public:
      void setGamesWon( int gw );
      int getGamesWon();
      
      void setWinRate( double wr );
      double getWinRate();
      
      void setGamesPlayed( int gp );
      int getGamesPlayed();
      
      void setFastestWin( double fw );
      double getFastestWin();
      
      void setFewestMoves( int fm );
      int getFewestMoves();
      
      void setTopScore( int ts );
      int getTopScore();
      
   private:
      int gamesWon;
      double winRate;
      int gamesPlayed;
      double fastestWin;
      int fewestMoves;
      int topScore;
};

#endif // OVERVIEW_H