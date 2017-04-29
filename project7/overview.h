#ifndef OVERVIEW_H
#define OVERVIEW_H

class Overview
{
   public:
      void setGamesWon();
      int getGamesWon();
      
      void setWinRate();
      double getWinRate();
      
      void setGamesPlayed();
      int getGamesPlayed();
      
      void setFastestWin();
      double getFastestWin();
      
      void setFewestMoves();
      int getFewestMoves();
      
      void setTopScore();
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