#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// Function to append node at the end
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to detect and correct the wrong pointer
void correctRandomPointer(Node* head) {
    unordered_set<Node*> visited;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp) {
        if (visited.find(temp) != visited.end()) {
            // Found a repeated node — this means a wrong link
            cout << "Random pointer detected at node " << prev->data << endl;

            // Break the wrong link
            prev->next = nullptr;
            return;
        }
        visited.insert(temp);
        prev = temp;
        temp = temp->next;
    }
    cout << "No random pointer detected." << endl;
}

int main() {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    // Introduce a wrong link: node 3 points to node 2 instead of node 4
    head->next->next->next = head->next;  // 3->next = 2

    cout << "Before correction: " << endl;
    printList(head);  // this may print incorrectly or infinitely if traversed blindly

    correctRandomPointer(head);

    cout << "After correction: " << endl;
    printList(head);

    return 0;
}
