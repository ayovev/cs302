#include "binarySearchTree.cpp"
#include "binaryNode.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void generateInputFile( const int numValues );

int main()
{
   srand( time( NULL ) );
   
   BinarySearchTree tree1;
   cout << "BINARY SEARCH TREE CONSTRUCTED" << endl; // IFTP
   
   generateInputFile( 100 );
   cout << "INPUT FILE GENERATED" << endl; // IFTP
   
   
   return EXIT_SUCCESS;
}

void generateInputFile( const int numValues )
{
   ofstream fout;
   int count = 0;
   
   fout.clear();
   fout.open( "input.txt" );
   
   for( count = 0; count < numValues; count++ )
   {
      if( count == 99 )
      {
         fout << ( rand() % 200 ) + 1;
      }
      else
      {
         fout << ( rand() % 200 ) + 1 << endl;
      }
   }
   
   fout.close();
}