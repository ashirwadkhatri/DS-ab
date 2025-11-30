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

// Function to detect and remove loop using Floyd's Cycle Detection algorithm
void removeLoop(Node* head) {
    Node *slow = head, *fast = head;

    // Step 1: Detect loop using Floyd's algorithm
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast)
            break;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // Step 2: If the loop starts at head
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } else {
            // Step 3: Move both pointers until fast->next == slow->next
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 4: Break the loop
        fast->next = nullptr;
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a loop: 5->next = 3
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    cout << "Linked List after removing loop:" << endl;
    printList(head);

    return 0;
}
