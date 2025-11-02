#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to count number of nodes in a Circular Linked List
int getSizeCircular(Node* head) {
    if (head == nullptr)
        return 0;

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    // Create a Circular Linked List: 5 -> 10 -> 15 -> 5
    Node n1, n2, n3;
    n1.data = 5;  n2.data = 10;  n3.data = 15;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n1;  // Circular link

    Node* head = &n1;

    cout << "Size of Circular Linked List: " << getSizeCircular(head) << endl;

    return 0;
}
