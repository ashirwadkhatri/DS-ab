#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to split a circular linked list into two halves
void splitCircularList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (head == nullptr)
        return;

    Node* slow = head;
    Node* fast = head;

    // Use slow and fast pointers to find mid
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For odd number of nodes, move fast one step further
    if (fast->next->next == head)
        fast = fast->next;

    // Set the heads of the two halves
    *head1_ref = head;
    *head2_ref = slow->next;

    // Make first half circular
    slow->next = *head1_ref;

    // Make second half circular
    fast->next = *head2_ref;
}

// Function to print a circular linked list
void printList(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    // Create circular linked list: 10->20->30->40->50->60->(back to 10)
    Node* head = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    Node* third = new Node{30, nullptr};
    Node* fourth = new Node{40, nullptr};
    Node* fifth = new Node{50, nullptr};
    Node* sixth = new Node{60, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = head; // circular link

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    splitCircularList(head, &head1, &head2);

    cout << "First Circular List: ";
    printList(head1);

    cout << "Second Circular List: ";
    printList(head2);

    return 0;
}
