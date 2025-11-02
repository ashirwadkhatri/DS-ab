#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = nullptr;
    return temp;
}

// Utility function to check BST property
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    // Current node must be greater than min and smaller than max
    if (root->data <= minVal || root->data >= maxVal)
        return false;

    // Recursively check left and right subtrees
    return (isBSTUtil(root->left, minVal, root->data) &&
            isBSTUtil(root->right, root->data, maxVal));
}

// Main function to check if binary tree is BST
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Helper to print result
void checkBST(Node* root) {
    if (isBST(root))
        cout << "The given tree is a Binary Search Tree (BST)" << endl;
    else
        cout << "The given tree is NOT a Binary Search Tree" << endl;
}

// Example usage
int main() {
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    checkBST(root);

    return 0;
}
