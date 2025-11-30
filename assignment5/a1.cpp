#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to find intersection point
Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB)
        return nullptr;

    Node *a = headA, *b = headB;

    // Loop until both pointers meet or become NULL
    while (a != b) {
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
    }

    return a;  // Intersection node OR nullptr
}

// Function to print list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Create merged node sequence: 8->4->5
    Node* newNode8 = new Node(8);
    newNode8->next = new Node(4);
    newNode8->next->next = new Node(5);

    // List A: 4->1->(8->4->5)
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = newNode8;

    // List B: 5->6->1->(8->4->5)
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = newNode8;

    Node* intersection = getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection at node with data = " << intersection->data << endl;
    else
        cout << "No intersection found\n";

    return 0;
}
