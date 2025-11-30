#include <iostream>
using namespace std;

// Node class (no struct used)
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
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

// Function to print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Function to find and print the middle element
void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Move fast 2 steps, slow 1 step
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << endl;
}

// Main
int main() {
    Node* head = nullptr;

    // Create linked list: 1->2->3->4->5
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    cout << "Linked List: ";
    printList(head);

    findMiddle(head);

    return 0;
}
