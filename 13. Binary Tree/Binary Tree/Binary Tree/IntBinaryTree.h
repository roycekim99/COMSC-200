///**********************************************************************************
/// Description: Binary Tree header
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: May 13, 2019
/// Status : Complete 
///***********************************************************************************

// Specification file for the IntBinaryTree class
#include <iostream>
#include <string>
#include <vector>
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree
{
private:
    struct Trunk {
    Trunk *prev;
    std::string str;

    Trunk(Trunk *prev, std::string str) {
        this->prev = prev;
        this->str = str;
    }
};
   struct TreeNode
   {
      int value;         // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   TreeNode *root;       // Pointer to the root node
   
   // Private member functions
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(int, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;
   

   void storeBSTNodes(TreeNode* root, std::vector<TreeNode*> &nodes) {
       // Base case
       if (root == NULL)
           return;

       // Store nodes in Inorder 
       storeBSTNodes(root->left, nodes);
       nodes.push_back(root);
       storeBSTNodes(root->right, nodes);
   }

   TreeNode* buildTreeUtil(std::vector<TreeNode*> &nodes, int start, int end) {

       // base case
       if (start > end)
           return nullptr;

       //get middle
       int mid = (start + end) / 2;
       TreeNode *root = nodes[mid];

       root->left = buildTreeUtil(nodes, start, mid - 1);
       root->right = buildTreeUtil(nodes, mid + 1, end);

       return root;
   }

   // private function to convert to balanced BST
   TreeNode* toBalancedInternal(TreeNode* root) {
       std::vector<TreeNode*> nodes;
       storeBSTNodes(root, nodes);

       // Constucts BST from nodes
       int n = nodes.size();
       return buildTreeUtil(nodes, 0, n - 1);
   }

   TreeNode* newNode(int data) {
       TreeNode* node = new TreeNode;
       node->value = data;
       node->left = node->right = nullptr;
       return (node);
   }


public:
   // Constructor
   IntBinaryTree()
      { root = nullptr; }
      
   // Destructor
   ~IntBinaryTree()
      { destroySubTree(root); }
      
   // Binary tree operations
   void insertNode(int);
   bool searchNode(int);
   void remove(int);
   
   void displayInOrder() const
      {  displayInOrder(root); }
      
   void displayPreOrder() const
      {  displayPreOrder(root); }
      
   void displayPostOrder() const
      {  displayPostOrder(root); }

   void clear();

   //DISPLAY FUNCTINO FROM LAB
   void showTrunks(Trunk *p) {
       if (p == nullptr)
           return;

       showTrunks(p->prev);

       std::cout << p->str;
   }

   //recursive displayFunction
   void printTree(TreeNode *root, Trunk *prev, bool isLeft) {
       if (root == nullptr)
           return;

       std::string prev_str = "    ";
       Trunk *trunk = new Trunk(prev, prev_str);

       printTree(root->right, trunk, true);

       if (!prev)
           trunk->str = "---";
       else if (isLeft) {
           trunk->str = "+---";
           prev_str = "   |";
       }
       else {
           trunk->str = "+---";
           prev->str = prev_str;
       }

       showTrunks(trunk);
       std::cout << root->value << std::endl;

       if (prev)
           prev->str = prev_str;
       trunk->str = "   |";

       printTree(root->left, trunk, false);
   }
   
   //MAIN DISPLAY FUNCTION
   void displayTree() {
       printTree(root, nullptr, false);
   }
   //END DISPLAY FUNCTIONS

   void toBalanced() {
       root = toBalancedInternal(root);
   }
   

};
#endif