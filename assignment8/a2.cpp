#include <iostream>
#include <vector>
using namespace std;

// Define a node for the BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to create all BSTs between 'start' and 'end'
vector<Node*> createBST(int start, int end) {
    vector<Node*> result;

    // If start > end, it means empty tree
    if (start > end) {
        result.push_back(nullptr);
        return result;
    }

    // Pick each number as root
    for (int i = start; i <= end; i++) {
        // All possible left subtrees with values < i
        vector<Node*> leftTrees = createBST(start, i - 1);

        // All possible right subtrees with values > i
        vector<Node*> rightTrees = createBST(i + 1, end);

        // Combine each left and right subtree with the root i
        for (Node* left : leftTrees) {
            for (Node* right : rightTrees) {
                Node* root = new Node(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;
}

// Function to print preorder traversal of a tree
void preorder(Node* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    vector<Node*> allBSTs = createBST(1, n);

    cout << "Total unique BSTs for n = " << n << " are: " << allBSTs.size() << endl;

    // Display all trees in preorder form
    for (int i = 0; i < allBSTs.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        preorder(allBSTs[i]);
        cout << endl;
    }

    return 0;
}
