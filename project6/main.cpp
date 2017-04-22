// LIBRARIES AND HEADER FILES
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

// FUNCTION PROTOTYPES
void generateInputFile( const unsigned int numValues );
void loadBST( BinarySearchTree& tree );
void isBstEmpty( const BinarySearchTree& tree );

// MAIN FUNCTION
int main()
{
   // seed random function
   srand( time( NULL ) );

   // construct binary search trees, declare and initializes variables
   BinarySearchTree tree1;
   BinarySearchTree tree2;
   bool found = false;
   int count = 0;
   
   // generate input file with 100 values
   generateInputFile( 100 );
   
   // load first binary search tree with generated values
   loadBST( tree1 );
   
   // output height of first binary search tree
   cout << endl << "Height of BST1: " 
        << tree1.getHeight( tree1.root ) << endl;
        
   // print inorder traversal of first binary search tree     
   cout << endl << "Inorder traversal of BST1: ";
   tree1.inorderTraverse( tree1.root );
   cout << endl << endl;
   
   // generate new input file with 10 values
   generateInputFile( 10 );
   
   // load second binary search tree with newly generated overlapping values
   loadBST( tree2 );
   
   // print preorder traversal of second binary search tree
   cout << endl << "Preorder traversal of BST2: ";
   tree2.preorderTraverse( tree2.root );
   cout << endl << endl;
   
   // print inorder traversal of second binary search tree
   cout << "Inorder traversal of BST2: ";
   tree2.inorderTraverse( tree2.root );
   cout << endl << endl;
   
   // print postorder traversal of second binary search tree
   cout << "Postorder traversal of BST2: ";
   tree2.postorderTraverse( tree2.root );
   cout << endl << endl;

   // loop through range of possibly generated values
   for( found = false, count = 0; count < 200; count++ )
   {
      // check if second binary search tree contains current loop value
      if( tree2.contains( tree2.root, count ))
      {
         found = true;
      }
      // if value is found, remove it from first binary search tree
      if( found == true )
      {
         tree1.remove( tree1.root, count );
      }
      // reset flag
      found = false;
   }
   
   // print new height of modified first binary search tree
   cout << "Height of modified BST1: " 
        << tree1.getHeight( tree1.root ) << endl << endl;
   
   // print number of node in the modified first binary search tree
   cout << "Number of nodes in modified BST1: "
        << tree1.getNumberOfNodes( tree1.root ) << endl << endl;
        
   // print new inorder traversal of modified first binary search tree
   cout << "Inorder traversal of modified BST1: ";
   tree1.inorderTraverse( tree1.root );
   cout << endl << endl;
   
   // print whether first binary search tree is empty before clearing
   cout << "BST1 empty? ";
   isBstEmpty( tree1 );
   cout << endl;
   
   // print whether second binary search tree is empty before clearing
   cout << "BST2 empty? ";
   isBstEmpty( tree2 );
   cout << endl;
   
   // clear both binary search trees
   tree1.clear( tree1.root );
   tree2.clear( tree2.root );
   
   // print whether first binary search tree is empty after clearing
   cout << "BST1 empty? ";
   isBstEmpty( tree1 );
   cout << endl;
   
   // print whether second binary search tree is empty after clearing
   cout << "BST2 empty? ";
   isBstEmpty( tree2 );
   cout << endl;
   
   return EXIT_SUCCESS;
}

// FUNCTION IMPLEMENTATION
void generateInputFile( const unsigned int numValues )
{
   // declate / initialize variables
   ofstream fout;
   unsigned int count = 0;
   vector<int> numbers;
   
   // generate seed
   unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
   
   // push numbers 1-200 into vector
   for( count = 0; count < 200; count++ )
   {
       numbers.push_back( count + 1 );
   }
   
   // shuffle numbers around
   shuffle( numbers.begin(), numbers.end(), default_random_engine( seed ) );
   
   // clear and open output file stream
   fout.clear();
   fout.open( "input.txt" );
   
   // output shuffled number in vector
   for( count = 0; count < numValues; count++ )
   {
      if( count == numValues - 1 )
      {
         fout << numbers.at( count );
      }
      else
      {
         fout << numbers.at( count ) << endl;
      }
   }
   
   // close file stream
   fout.close();
}

void loadBST( BinarySearchTree& tree )
{
   // declare variables
   ifstream fin;
   int value;
   
   // clear and open input file stream
   fin.clear();
   fin.open( "input.txt" );
   
   // while there is still data in the file
   while( fin.eof() == false )
   {
      // get value from input file and add it to the tree
      fin >> value;
      cout << "Adding value " << value << " to binary search tree." << endl;
      tree.add( value );
   }
   
   // close input file stream
   fin.close();
}

void isBstEmpty( const BinarySearchTree& tree )
{
   // output true of false based on boolean value
   if( tree.isEmpty() == false )
   {
      cout << "False";
   }
   else if( tree.isEmpty() == true )
   {
      cout << "True";
   }
}