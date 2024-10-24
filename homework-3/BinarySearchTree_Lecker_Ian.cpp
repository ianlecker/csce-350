// Copyright 2024 Ian Lecker
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct Node {
  int value;
  Node* leftChild;
  Node* rightChild;

  Node(int entry) : value(entry), leftChild(nullptr), rightChild(nullptr) {}
};

class BinarySearchTree {
public:

    // wrapper for overloaded function in private
    void getSmallestValue() {
        cout << "Smallest Value:" << endl;
        cout << getSmallestValue(root) << endl;
    }

    // wrapper for overloaded function in private
    void getLargestValue() {
        cout << "Largest Value:" << endl;
        cout << getLargestValue(root) << endl;
    }

    // wrapper for overloaded function in private
    void insert(int entry) {
        cout << "Inserting: " << entry << endl;
        root = insert(root, entry);
        display(root);
    }

    // wrapper for overloaded function in private
    void search(int entry) {
        cout << "Searching for: " << entry << endl;
        if(search(root, entry)) {
            cout << "Value found." << endl;
        }
        else {
            cout << "Value not found." << endl;
        }
        display(root);
    }

    // deletes a node from the bst
    void deleteNode(int entry) {
        cout << "Deleting node: " << entry << endl;
        deleteNode(root, entry);
        display(root);
    }

    // prints out the bst in order
    void inorderTraversal(Node* node) {
        if (!node) return; // Base case: empty node
        inorderTraversal(node->leftChild); // Traverse left subtree
        cout << node->value << " "; // Visit current node
        inorderTraversal(node->rightChild); // Traverse right subtree
    }

    // wrapper for the display function
    void display(Node* node) {
        cout << "BST Nodes: ";
        inorderTraversal(node);
        cout << endl;
    }

private:
    Node* root = nullptr;

    // logic for inserting a node
    Node* insert(Node* node, int entry) {
        if(!node) return new Node(entry); // Case: no root node
        if(entry < node->value) { // Case: entry is less than the root, or current node
            node->leftChild = insert(node->leftChild, entry);
        }
        else if(entry > node->value) { // Case: entry is greater than the root, or current node
            node->rightChild = insert(node->rightChild, entry);
        }
        else if(entry == node->value){ // Case: entry is equal than the root, or current node
            cout << "Duplicate Node: " << entry << endl;
        }
        return node;
    }

    // logic for deleting a node
    bool search(Node* node, int entry) {
        if(!node) return false; // Case: node not found

        if (entry == node->value) return true; // Case: value found

        else if(entry < node->value) { // Case: entry is less than the root, or current node
            return search(node->leftChild, entry);
        }

        else { // Case: entry is greater than the root, or current node
            return search(node->rightChild, entry);
        }
    }

    // logic for deleting a node
    Node* deleteNode(Node* node, int entry) {
        if(!node) return nullptr; // Case: node not found

        if(entry < node->value) { // traverse left
            node->leftChild = deleteNode(node->leftChild, entry);
        }

        else if(entry > node->value) { // traverse right
            node->rightChild = deleteNode(node->rightChild, entry);
        }

        else { // node to delete is found

            // Case: less than 2 children
            if(!node->leftChild) {
                Node* temp = node->rightChild;
                delete node;
                return temp;
            }
            if(!node->rightChild) {
                Node* temp = node->leftChild;
                delete node;
                return temp;
            }

            // Case: 2 children
            Node* nextNode = node->rightChild;
            while(nextNode->leftChild) { // loop to find left most node 
                nextNode = nextNode->leftChild;
            }
            node->value = nextNode->value;
            node->rightChild = deleteNode(node->rightChild, nextNode->value);
        }

        return node;
    }

    // returns the largest value from with respect to a node in the bst
    int getSmallestValue(Node* node) {
        if(!node->leftChild) return node->value;
        return getSmallestValue(node->leftChild);
    }

    // returns the largest value from with respect to a node in the bst
    int getLargestValue(Node* node) {
        if(!node->rightChild) return node->value;
        return getLargestValue(node->rightChild);
    }

};

int main() {
    BinarySearchTree bst;

    int menuInput;
    int entryInput;
    while (true) {
        cout << "1. Insert 2. Search 3. Delete 4. Smallest Value 5. Largest Value 6. Exit" << endl;
        cin >> menuInput;
        switch (menuInput) {
        case 1: // Insert
            cin >> entryInput;
            bst.insert(entryInput);
            break;
        case 2: // Search
            cin >> entryInput;
            bst.search(entryInput);
            break;
        case 3: // Delete
            cin >> entryInput;
            bst.deleteNode(entryInput);
            break;
        case 4: // Get smallest value
            bst.getSmallestValue();
            break;
        case 5: // Get largest value
            bst.getLargestValue();
            break;
        case 6: // Exit
            return 0;
        default:
            break;
        }
    }

    return 0;
}