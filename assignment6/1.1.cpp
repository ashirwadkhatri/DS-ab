#include <iostream>
using namespace std;

#define MAX 10

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node *next;
        Node *prev;
    };

    Node nodes[MAX];      // Static node pool
    Node *freeList;       // Free list pointer
    Node *head;           // Head of DLL

public:
    // Constructor initializes free list
    DoublyLinkedList() {
        for (int i = 0; i < MAX - 1; i++)
            nodes[i].next = &nodes[i + 1];
        nodes[MAX - 1].next = NULL;

        freeList = &nodes[0];
        head = NULL;
    }

    // Allocate a node from free list
    Node* getNode() {
        if (freeList == NULL) {
            cout << "No free nodes available!\n";
            return NULL;
        }
        Node *temp = freeList;
        freeList = freeList->next;
        temp->next = temp->prev = NULL;
        return temp;
    }

    // Return a node to free list
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
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete node by value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }

        Node *curr = head;

        while (curr != NULL && curr->data != value)
            curr = curr->next;

        if (curr == NULL) {
            cout << "Node " << value << " not found!\n";
            return;
        }

        if (curr->prev != NULL)
            curr->prev->next = curr->next;
        else
            head = curr->next;

        if (curr->next != NULL)
            curr->next->prev = curr->prev;

        freeNode(curr);
        cout << "Deleted " << value << ".\n";
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }

        Node *temp = head;
        cout << "Doubly Linked List (Forward): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;

    int choice, data;

    while (true) {
        cout << "\n--- Doubly Linked List (Static with ->) ---\n";
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
            dll.insertAtEnd(data);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> data;
            dll.deleteNode(data);
            break;
        case 3:
            dll.display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
