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
void loadBST( BinarySearchTree& tree );
void isBstEmpty( const BinarySearchTree& tree );

int main()
{
   srand( time( NULL ) );

   BinarySearchTree tree1;
   BinarySearchTree tree2;
   bool found = false;
   int count = 0;
   
   generateInputFile( 100 );
   
   loadBST( tree1 );
   
   cout << endl << "Height of BST1: " 
        << tree1.getHeight( tree1.root ) << endl;
        
   cout << endl << "Inorder traversal of BST1: ";
   tree1.inorderTraverse( tree1.root );
   cout << endl << endl;
   
   generateInputFile( 10 );
   
   loadBST( tree2 );
   
   cout << endl << "Preorder traversal of BST2: ";
   tree2.preorderTraverse( tree2.root );
   cout << endl << endl;
   
   cout << "Inorder traversal of BST2: ";
   tree2.inorderTraverse( tree2.root );
   cout << endl << endl;
   
   cout << "Postorder traversal of BST2: ";
   tree2.postorderTraverse( tree2.root );
   cout << endl << endl;
   
   for( found = false, count = 0; count < 200; count++ )
   {
      if( tree2.contains( tree2.root, count ))
      {
         found = true;
      }
      if( found == true )
      {
         // tree1.remove( tree1.root, count );
      }
      found = false;
   }
   
   cout << "Height of modified BST1: " 
        << tree1.getHeight( tree1.root ) << endl << endl;
        
   cout << "Number of nodes in modified BST1: "
        << tree1.getNumberOfNodes( tree1.root ) << endl << endl;
        
   cout << "Inorder traversal of modified BST1: ";
   tree1.inorderTraverse( tree1.root );
   cout << endl << endl;
   
   cout << "BST1 empty? ";
   isBstEmpty( tree1 );
   cout << endl;
   
   cout << "BST2 empty? ";
   isBstEmpty( tree2 );
   cout << endl;
   
   tree1.clear( tree1.root );
   tree2.clear( tree2.root );
   
   cout << "BST1 empty? ";
   isBstEmpty( tree1 );
   cout << endl;
   
   cout << "BST2 empty? ";
   isBstEmpty( tree2 );
   cout << endl;
   
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
      if( count == numbers.size() - 1 )
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

void loadBST( BinarySearchTree& tree )
{
   ifstream fin;
   int value;
   
   fin.clear();
   fin.open( "input.txt" );
   
   while( fin.eof() == false )
   {
      fin >> value;
      cout << "Adding value " << value << " to binary search tree." << endl;
      tree.add( value );
   }
   
   fin.close();
}

void isBstEmpty( const BinarySearchTree& tree )
{
   if( tree.isEmpty() == false )
   {
      cout << "False";
   }
   else if( tree.isEmpty() == true )
   {
      cout << "True";
   }
}