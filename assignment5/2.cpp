#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Insert at end
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

// Print list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Delete all occurrences of key
int deleteKey(Node*& head, int key) {
    Node* current = head;
    Node* prev = nullptr;
    int count = 0;

    while (current != nullptr) {
        if (current->data == key) {
            count++;

            // If deleting head
            if (prev == nullptr) {
                head = current->next;
                delete current;
                current = head;
            } 
            else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }

    return count;
}

int main() {
    Node* head = nullptr;

    // Create linked list: 1->2->1->2->1->3->1
    append(head, 1);
    append(head, 2);
    append(head, 1);
    append(head, 2);
    append(head, 1);
    append(head, 3);
    append(head, 1);

    cout << "Original List: ";
    printList(head);

    int key = 1;
    int count = deleteKey(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    printList(head);

    return 0;
}
