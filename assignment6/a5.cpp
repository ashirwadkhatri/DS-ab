#include <iostream>
#include <vector>
using namespace std;

// Define structure for 4-way node
struct Node {
    int data;
    Node* right;
    Node* left;
    Node* up;
    Node* down;
    Node(int val) {
        data = val;
        right = left = up = down = nullptr;
    }
};

// Function to convert 2D matrix into 4-way linked list
Node* convertToLinkedList(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return nullptr;

    int m = mat.size();
    int n = mat[0].size();
    vector<vector<Node*>> nodes(m, vector<Node*>(n, nullptr));

    // Step 1: Create nodes
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }

    // Step 2: Link the nodes (4 directions)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) nodes[i][j]->left = nodes[i][j - 1];
            if (j < n - 1) nodes[i][j]->right = nodes[i][j + 1];
            if (i > 0) nodes[i][j]->up = nodes[i - 1][j];
            if (i < m - 1) nodes[i][j]->down = nodes[i + 1][j];
        }
    }

    // Return pointer to the top-left node (head)
    return nodes[0][0];
}

// Function to print the linked list row-wise
void printLinkedList(Node* head, int rows, int cols) {
    Node* rowStart = head;
    for (int i = 0; i < rows; i++) {
        Node* temp = rowStart;
        for (int j = 0; j < cols; j++) {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
        rowStart = rowStart->down;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = convertToLinkedList(mat);

    cout << "Doubly Linked 2D List (row-wise traversal):\n";
    printLinkedList(head, 3, 3);

    return 0;
}
