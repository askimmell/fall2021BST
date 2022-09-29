//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "tree.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string searchKey, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL)
      return false;

   // Data value found 
   else if (Tree->searchKey == searchKey)
   {
       cout << " Address found!" << endl;
       cout << " " << Tree->number<< " "<< Tree->street<< " "<< Tree->city<< " "<< Tree->state<< " "<< Tree->zip<< endl;
      //return true;
      
   }

   // Recursively search for data value
   else if (Tree->searchKey > searchKey)
      return (SearchHelper(searchKey, Tree->Left));
   else if (Tree->searchKey < searchKey)
      return (SearchHelper(searchKey, Tree->Right));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(string searchKey)
{
   // Call tree searching function
   return (SearchHelper(searchKey, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(string searchKey, string number, string street, string city, string state, string zip, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->searchKey = searchKey;
      Tree->number = number;
      Tree->street = street;
      Tree->city = city;
      Tree->state = state;
      Tree->zip = zip;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Data value already inserted
   else if (Tree->searchKey == searchKey)
      return false;     



   // Recursively search for insertion position
   else if (Tree->searchKey > searchKey)
      return (InsertHelper(searchKey, number, street, city, state, zip, Tree->Left));
   else if (Tree->searchKey < searchKey)
      return (InsertHelper(searchKey, number, street, city, state, zip, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(string searchKey, string number, string street, string city, string state, string zip)
{
   // Call tree insertion function
   return (InsertHelper(searchKey, number, street, city, state, zip, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
    
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      dout << " " << Tree->number<< " "<< Tree->street<< " "<< Tree->city<< " "<< Tree->state<< " "<< Tree->zip<< endl;

      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
    
    dout.open("sorted_address.txt");
    // Call tree printing function
    PrintHelper(Root);
    dout << endl;
}


int BinaryTree::tree_height(Node* Tree) {
    if(Tree == NULL) 
    {
        return 0;
    }
    int countLeft = tree_height(Tree->Left);
    int countRight = tree_height(Tree->Right);
    
    if(countLeft > countRight)
    {
        return(countLeft + 1);
    }
    else
    {
        return(countRight + 1);
    }
}

int BinaryTree::helper()
{
    return tree_height(Root);
}










