#ifndef SUITS_H
#define SUITS_H

#include "overview.h"
#include <string>

using namespace std;

class Suit : public Overview
{
   public:
      void setType( const string t );
      string getType();
      
   private:
      string type;
};

#endif // SUIT_H