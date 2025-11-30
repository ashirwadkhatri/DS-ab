#include <iostream>
using namespace std;

// Node class (no struct)
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to append a node at the end
void append(Node*& head, int data) {
    Node* temp = new Node(data);

    if (head == nullptr) {
        head = temp;
        return;
    }

    Node* last = head;
    while (last->next != nullptr)
        last = last->next;

    last->next = temp;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;   // Store next node
        curr->next = prev;   // Reverse the link
        prev = curr;         // Move prev
        curr = next;         // Move curr
    }

    return prev; // New head of reversed list
}

// Main function
int main() {
    Node* head = nullptr;

    // Creating linked list: 1->2->3->4->NULL
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
