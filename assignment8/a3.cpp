#include <iostream>
using namespace std;

// Structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find maximum depth of binary tree
int maxDepth(Node* root) {
    if (root == nullptr)
        return 0; // Empty tree has depth 0

    // Recursively find depth of left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Add 1 for the current node
    return 1 + max(leftDepth, rightDepth);
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Maximum Depth of Binary Tree: " << maxDepth(root) << endl;

    return 0;
}
