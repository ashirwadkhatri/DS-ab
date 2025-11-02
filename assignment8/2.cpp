#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node *left, *right;
};

// Create new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node in BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// (a) Search Recursive
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (a) Search Non-Recursive
Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// (b) Maximum element
Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// (c) Minimum element
Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != NULL)
        return findMin(node->right);
    Node* succ = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != NULL)
        return findMax(node->left);
    Node* pred = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

// Utility: Inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Driver Code
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int key = 60;
    Node* result = searchRecursive(root, key);
    cout << "Search (Recursive) for " << key << ": "
         << (result ? "Found" : "Not Found") << endl;

    result = searchNonRecursive(root, key);
    cout << "Search (Non-Recursive) for " << key << ": "
         << (result ? "Found" : "Not Found") << endl;

    Node* maxNode = findMax(root);
    Node* minNode = findMin(root);
    cout << "Maximum Element: " << (maxNode ? maxNode->data : -1) << endl;
    cout << "Minimum Element: " << (minNode ? minNode->data : -1) << endl;

    Node* node = searchRecursive(root, 60);
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);
    cout << "Inorder Successor of 60: " << (succ ? succ->data : -1) << endl;
    cout << "Inorder Predecessor of 60: " << (pred ? pred->data : -1) << endl;

    return 0;
}
