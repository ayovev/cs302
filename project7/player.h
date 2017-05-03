#ifndef PLAYER_H
#define PLAYER_H

#include "overview.h"
#include "suit.h"
#include <string>

using namespace std;

const int NUM_SUITS = 3;

class Player
{
   public:
      void setName( const string name );
      string getName();
      
      void printName();
      void printOverview();
      void printSuits();
      
      void printAllInfo();
      
   public:
      string playerName;
      Overview all;
      Suit suitType[ NUM_SUITS ];
};

#endif // PLAYER_H