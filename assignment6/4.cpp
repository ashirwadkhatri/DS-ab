#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

// Function to check if the doubly linked list is palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    Node* start = head;
    Node* end = head;

    // Move 'end' to the last node
    while (end->next != nullptr)
        end = end->next;

    // Compare characters from both ends
    while (start != end && start->prev != end) {
        if (start->data != end->data)
            return false;
        start = start->next;
        end = end->prev;
    }
    return true;
}

int main() {
    // Create a doubly linked list: R <-> A <-> D <-> A <-> R
    Node n1, n2, n3, n4, n5;

    n1.data = 'R'; n2.data = 'A'; n3.data = 'D'; n4.data = 'A'; n5.data = 'R';

    n1.prev = nullptr; n1.next = &n2;
    n2.prev = &n1; n2.next = &n3;
    n3.prev = &n2; n3.next = &n4;
    n4.prev = &n3; n4.next = &n5;
    n5.prev = &n4; n5.next = nullptr;

    Node* head = &n1;

    if (isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is NOT a palindrome." << endl;

    return 0;
}
