//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

// Data node definition
class Node
{
   public:
   int Value;
   string searchKey;
   string number;
   string street;
   string city;
   string state;
   string zip;
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the binary tree class interface. 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool Search(string searchKey);
   bool Insert(string searchKey, string number, string street, string city, string state, string zip);
   bool Delete(int Value);
   void Print();
   
   void Store();
   
   int tree_height(Node* Tree);
   int helper();

 private:
   // Helper functions
   bool SearchHelper(string searchKey, Node * Tree);
   bool InsertHelper(string searchKey, string number, string street, string city, string state, string zip, Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(int Value, Node * &Tree);
   void PrintHelper(Node * Tree);

   // Tree pointer
   Node *Root;
   
   int num;
   ofstream dout;
};