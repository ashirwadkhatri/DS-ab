#include <iostream>
using namespace std;

#define MAX 10

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node *next;
    };

    Node nodes[MAX];     // static memory
    Node *freeList;      // free node list
    Node *head;          // start of circular list

public:
    // Constructor initializes free list and head
    CircularLinkedList() {
        for (int i = 0; i < MAX - 1; i++)
            nodes[i].next = &nodes[i + 1];
        nodes[MAX - 1].next = NULL;

        freeList = &nodes[0];
        head = NULL;
    }

    // Allocate node from free list
    Node* getNode() {
        if (freeList == NULL) {
            cout << "No free nodes available!\n";
            return NULL;
        }
        Node *temp = freeList;
        freeList = freeList->next;
        temp->next = NULL;
        return temp;
    }

    // Return node to free list
    void freeNode(Node *node) {
        node->next = freeList;
        freeList = node;
    }

    // Insert at end
    void insertAtEnd(int data) {
        Node *newNode = getNode();
        if (newNode == NULL) return;

        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            head->next = head;   // circular link
        } else {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Delete node by value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }

        Node *curr = head, *prev = NULL;

        do {
            if (curr->data == value) {
                if (curr == head) {
                    Node *last = head;
                    while (last->next != head)
                        last = last->next;

                    if (head->next == head) {
                        // Only one node
                        head = NULL;
                    } else {
                        head = head->next;
                        last->next = head;
                    }
                } 
                else {
                    prev->next = curr->next;
                }

                freeNode(curr);
                cout << "Deleted " << value << ".\n";
                return;
            }

            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Node " << value << " not found!\n";
    }

    // Display circular list
    void display() {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }

        Node *temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }
};

int main() {
    CircularLinkedList cll;

    int choice, data;

    while (true) {
        cout << "\n--- Circular Linked List (Static with ->) ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Delete Node\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
