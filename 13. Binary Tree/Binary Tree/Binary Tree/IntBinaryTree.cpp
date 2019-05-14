///**********************************************************************************
/// Description: Binary Tree Driver Class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: May 13, 2019
/// Status : Complete 
///***********************************************************************************

// Implementation file for the IntBinaryTree class
#include "IntBinaryTree.h"
#include <sstream>
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void IntBinaryTree::insertNode(int num)
{
   TreeNode *newNode = nullptr;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = num;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool IntBinaryTree::searchNode(int num)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == num)
         return true;
      else if (num < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void IntBinaryTree::remove(int num)
{
   deleteNode(num, root);
}


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr = nullptr;

   if (nodePtr == nullptr)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

void IntBinaryTree::clear() {
    destroySubTree(root);
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

void display() {
    //MAIN MENU
    cout << "--- Integer Binary Search Tree ---" << endl;
    cout << "\tB - to Batch enter Tree" << endl <<
        "\tb - to balance Tree" << endl <<
        "\tC - to clear Tree" << endl <<
        "\tD - to Display Tree(2D)" << endl <<
        "\t1 - to Pre order Traversal" << endl <<
        "\t2 - to In Order Traversal" << endl <<
        "\t3 - to Post Order Traversal" << endl <<
        "\tm - menu" << endl <<
        "\tQ - to Quit" << endl;
}

int main()


{
    int data;
    string userInput = "NA", token, userList;
    stringstream ss, switcher;
    IntBinaryTree tree;


    display();

    while (toupper(userInput.at(0)) != 'Q') {
        //GET USER INPUT
        cout << "Enter your command: ";
        getline(cin, userInput);

        switch (userInput.at(0)) {
        case 'B': //Batch enter Tree
        {
            cout << "Enter a list of number separated by a comma (,): ";
            getline(cin, userList);
            ss << userList;

            for (; getline(ss,token, ','); switcher.clear()) {
                switcher << token;
                switcher >> data;

                tree.insertNode(data);
            }
            cout << endl;
            break;
        }
        case 'b'://balance Tree
        {
            tree.toBalanced();
            break;
        }
        case 'C'://clear Tree
        {
            tree.clear();
            break;
        }
        case 'd':
        case 'D'://display tree
        {
            cout << endl;
            tree.displayTree();
            cout << endl << endl;
            break;
        }
        case '1'://pre order transversal
        {
            tree.displayPreOrder();
            break;
        }
        case '2'://in order transversal
        {
            tree.displayInOrder();
            break;
        }
        case '3'://post order transversal
        {
            tree.displayPostOrder();
            break;
        }
        case 'm'://menu
        {
            display();
            break;

        }
        case 'Q'://quit
        {
            continue;
        }
        default:
            cout << "INVALID INPUT" << endl;
            break;
        }
        cout << endl;
    }
    




    return 0;
}




