#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Function to rotate linked list left by k nodes
Node* rotateLeft(Node* head, int k) {
    if (head == nullptr || k == 0)
        return head;

    Node* curr = head;

    // Step 1: Count total nodes
    int count = 1;
    while (curr->next != nullptr) {
        curr = curr->next;
        count++;
    }

    // Step 2: Make the list circular
    curr->next = head;

    // Step 3: Find new head after k rotations
    k = k % count;  // Handle k > count
    int stepsToNewHead = k;

    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++)
        newTail = newTail->next;

    Node* newHead = newTail->next;

    // Step 4: Break the circular link
    newTail->next = nullptr;

    return newHead;
}

// Main function
int main() {
    // Create linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;

    cout << "Original List: ";
    printList(head);

    head = rotateLeft(head, k);

    cout << "List after rotating left by " << k << ": ";
    printList(head);

    return 0;
}
