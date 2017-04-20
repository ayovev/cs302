#include "binarySearchTree.h"
#include "binaryNode.h"
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void generateInputFile( const unsigned int numValues );

int main()
{
   srand( time( NULL ) );
   
   BinarySearchTree tree1;
   cout << "BINARY SEARCH TREE CONSTRUCTED" << endl; // IFTP
   
   generateInputFile( 100 );
   cout << "INPUT FILE GENERATED" << endl; // IFTP
   
   cout << "INITIAL BST HEIGHT: " << tree1.getHeight( tree1.root ) << endl; // IFTP
   
   tree1.add( 10 );
   cout << "ADDING NODE WITH VALUE 10" << endl;
   cout << "BST HEIGHT: " << tree1.getHeight( tree1.root ) << endl;
   cout << "NUMBER OF NODES: " << tree1.getNumberOfNodes( tree1.root ) << endl;
   
   tree1.add( 20 );
   cout << "ADDING NODE WITH VALUE 20" << endl;
   cout << "BST HEIGHT: " << tree1.getHeight( tree1.root ) << endl;
   cout << "NUMBER OF NODES: " << tree1.getNumberOfNodes( tree1.root ) << endl;
   
   tree1.add( 5 );
   cout << "ADDING NODE WITH VALUE 5" << endl;
   cout << "BST HEIGHT: " << tree1.getHeight( tree1.root ) << endl;
   cout << "NUMBER OF NODES: " << tree1.getNumberOfNodes( tree1.root ) << endl;
   
   tree1.add( 18 );
   cout << "ADDING NODE WITH VALUE 18" << endl;
   cout << "BST HEIGHT: " << tree1.getHeight( tree1.root ) << endl;
   cout << "NUMBER OF NODES: " << tree1.getNumberOfNodes( tree1.root ) << endl;
   
   tree1.add( 6 );
   cout << "ADDING NODE WITH VALUE 6" << endl;
   cout << "BST HEIGHT: " << tree1.getHeight( tree1.root ) << endl;
   cout << "NUMBER OF NODES: " << tree1.getNumberOfNodes( tree1.root ) << endl;
   
   //cout << "CLEARING BST..." << endl << endl;
   //tree1.clear( tree1.root );
   
   // cout << "BST HEIGHT: " << tree1.getHeight( tree1.root ) << endl;
   // cout << "NUMBER OF NODES: " << tree1.getNumberOfNodes( tree1.root ) << endl;
   // cout << "ADDRESS OF ROOT NODE: " << &tree1.root << endl;
   // cout << "ROOT NODE DATA: " << tree1.getRootData() << endl;
   
   cout << tree1.contains( tree1.root, 0 ) << endl;
   
   system("pause");
   
   return EXIT_SUCCESS;
}

void generateInputFile( const unsigned int numValues )
{
   ofstream fout;
   unsigned int count = 0;
   vector<int> numbers;
   
   unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
   
   for( count = 0; count < numValues; count++ )
   {
       numbers.push_back( count + 1 );
   }
   
   shuffle( numbers.begin(), numbers.end(), default_random_engine( seed ) );
   
   fout.clear();
   fout.open( "input.txt" );
   
   for( count = 0; count < numbers.size(); count++ )
   {
      if( count == 99 )
      {
         fout << numbers.at( count );
      }
      else
      {
         fout << numbers.at( count ) << endl;
      }
   }
   
   fout.close();
}