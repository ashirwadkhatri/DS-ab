#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to count number of nodes in a Doubly Linked List
int getSizeDoubly(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    // Create a simple Doubly Linked List: 10 <-> 20 <-> 30
    Node n1, n2, n3;

    n1.data = 10; n1.prev = nullptr; n1.next = &n2;
    n2.data = 20; n2.prev = &n1; n2.next = &n3;
    n3.data = 30; n3.prev = &n2; n3.next = nullptr;

    Node* head = &n1;

    cout << "Size of Doubly Linked List: " << getSizeDoubly(head) << endl;

    return 0;
}
