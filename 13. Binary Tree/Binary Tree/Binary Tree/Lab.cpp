///**********************************************************************************
/// Description: Binary Search Tree Lab
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: May 13, 2019
/// Status : Complete 
///***********************************************************************************
#include <iostream>
#include <string>
#include <sstream>

struct node {
    int key;
    struct node *left, *right;
};

//DISPLAY
struct Trunk {
    Trunk *prev;
    std::string str;

    Trunk(Trunk *prev, std::string str) {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p) {
    if (p == nullptr)
        return;

    showTrunks(p->prev);

    std::cout << p->str;
}

void printTree(node *root, Trunk *prev, bool isLeft) {
    if (root == nullptr)
        return;

    std::string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->left, trunk, true);

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
    std::cout << root->key << std::endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->right, trunk, false);
}
//------END DISPLAY

//Node constructor kinda
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

//search function
struct node* search(struct node* root, int key) {
    // Base Cases: root is null or key is present at root 
    if (root == nullptr || root->key == key)
        return root;

    // Key is greater than root's key 
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key 
    return search(root->left, key);
}

//insert a node into tree
struct node* insert(struct node* node, int key) {
    //WHEN EMPTY:
    if (node == nullptr) {
        return newNode(key);
    }
    //traverse
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    //return unchanged
    return node;
}

//driver MAIN FUNCTION
int main() {
    std::string userInput;
    std::string token;
    std::stringstream ss, switcher;
    int data;

    struct node *root = nullptr;

    std::cout << "Enter a list of numbers: ";
    std::getline(std::cin, userInput);
    ss << userInput;

    std::getline(ss, token, ',');
    switcher << token;
    switcher >> data;
    
    for (root = insert(root, data); std::getline(ss, token, ','); switcher.clear()) {
        switcher << token;
        switcher >> data;

        insert(root, data);
    }
    
    printTree(root, nullptr, false);

    return 0;
}
