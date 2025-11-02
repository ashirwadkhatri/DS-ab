#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* newNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = nullptr;
    return temp;
}

// Function to check if a node is a leaf
bool isLeaf(Node* node) {
    return (node != nullptr && node->left == nullptr && node->right == nullptr);
}

// Function to find sum of all left leaves
int sumOfLeftLeaves(Node* root) {
    if (root == nullptr)
        return 0;

    int sum = 0;

    // Check if the left child is a leaf
    if (isLeaf(root->left))
        sum += root->left->data;
    else
        sum += sumOfLeftLeaves(root->left);

    // Recurse for right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

// Example usage
int main() {

    Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    cout << "Sum of all left leaves: " << sumOfLeftLeaves(root) << endl;

    return 0;
}
