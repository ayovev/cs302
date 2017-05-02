#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
   public:
      void setName( string name );
      string getName();
      
      void printName();
      void printOverview();
      
      void printAllInfo();
      
   public:
      string playerName;
      Overview all;
      Suit suitType[ 3 ];
};

#endif // PLAYER_H