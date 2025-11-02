#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to check if the linked list is circular
bool isCircular(Node* head) {
    if (head == nullptr)
        return false;  // Empty list is not circular

    Node* temp = head->next;

    // Traverse the list
    while (temp != nullptr && temp != head)
        temp = temp->next;

    // If temp becomes NULL → not circular
    // If temp == head → circular
    return (temp == head);
}

int main() {
    // Creating nodes manually
    Node n1, n2, n3;

    n1.data = 10;
    n2.data = 20;
    n3.data = 30;

    // Link nodes to form a circular list
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n1; // ✅ circular connection (last points to head)

    Node* head = &n1;

    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is NOT circular." << endl;

    return 0;
}
