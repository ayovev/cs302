#ifndef OVERVIEW_H
#define OVERVIEW_H

class Overview
{
   public:
      void setGamesWon( const int gw );
      int getGamesWon();
      
      void setWinRate( const double wr );
      double getWinRate();
      
      void setGamesPlayed( const int gp );
      int getGamesPlayed();
      
      void setFastestWin( const double fw );
      double getFastestWin();
      
      void setFewestMoves( const int fm );
      int getFewestMoves();
      
      void setTopScore( const int ts );
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