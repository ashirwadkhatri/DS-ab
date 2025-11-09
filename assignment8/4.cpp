#include <iostream>
#include <climits>
using namespace std;

// Node structure for binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Helper function to check BST property
bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (root == nullptr)
        return true;

    // If current node violates min/max constraint → not BST
    if (root->data <= minVal || root->data >= maxVal)
        return false;

    // Check subtrees recursively with updated constraints
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

// Function to check if tree is BST
bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

// Sample driver code
int main() {
   

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    if (isBST(root))
        cout << "The given binary tree is a BST.\n";
    else
        cout << "The given binary tree is NOT a BST.\n";

    return 0;
}
