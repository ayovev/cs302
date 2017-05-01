#ifndef SUITS_H
#define SUITS_H

#include "overview.h"

using namespace std;

class Suit : public Overview
{
   public:
      void setType( string t );
      string getType();
      
   private:
      string type;
};

#endif // SUIT_H