#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void displayCircularList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.";
        return;
    }

    Node* temp = head;

    // Traverse the circular list
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    // Repeat head node value once more
    cout << head->data << endl;
}

int main() {
    // Creating nodes manually
    Node n1, n2, n3, n4, n5;

    n1.data = 20;  n2.data = 100;  n3.data = 40;  
    n4.data = 80;  n5.data = 60;

    // Linking nodes
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n1;  // Circular link

    Node* head = &n1;

    cout << "Circular Linked List: ";
    displayCircularList(head);

    return 0;
}
