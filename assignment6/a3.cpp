#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert node at the end
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to reverse every group of k nodes
Node* reverseKGroup(Node* head, int k) {
    if (!head) return nullptr;

    Node* curr = head;
    Node* newHead = nullptr;
    Node* nextNode = nullptr;
    int count = 0;

    // Reverse first k nodes
    while (curr != nullptr && count < k) {
        nextNode = curr->next;
        curr->next = curr->prev;
        curr->prev = nextNode;
        newHead = curr;
        curr = nextNode;
        count++;
    }

    // Recur for the remaining nodes
    if (curr != nullptr) {
        Node* restHead = reverseKGroup(curr, k);
        head->next = restHead;
        if (restHead != nullptr)
            restHead->prev = head;
    }

    return newHead;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int k = 3;

    // Create the doubly linked list
    for (int i = 1; i <= 8; i++)
        insertEnd(head, i);

    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
