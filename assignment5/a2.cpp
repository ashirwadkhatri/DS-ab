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

// Function to print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Function to reverse k nodes
Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    // Step 1: Check if there are at least k nodes left
    Node* temp = head;
    int nodeCount = 0;
    while (temp != nullptr && nodeCount < k) {
        temp = temp->next;
        nodeCount++;
    }
    if (nodeCount < k)
        return head;  // Less than k nodes, no reversal

    // Step 2: Reverse first k nodes
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 3: Recursively reverse remaining list
    if (next != nullptr)
        head->next = reverseKGroup(next, k);

    // prev is new head of the reversed group
    return prev;
}

// Main function
int main() {
    // Create linked list: 1->2->3->4->5->6->7->8
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;

    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
