#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // (a) Insert at Beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    // (b) Insert at End
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at the end.\n";
    }

    // (c) Insert Before/After a Specific Node
    void insertBeforeAfter(int target, int value, bool insertAfter) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        // If inserting before the head node
        if (!insertAfter && head->data == target) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << value << " before " << target << ".\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node " << target << " not found.\n";
            delete newNode;
            return;
        }

        if (insertAfter) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " after " << target << ".\n";
        } else {
            newNode->next = temp;
            prev->next = newNode;
            cout << "Inserted " << value << " before " << target << ".\n";
        }
    }

    // (d) Delete from Beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted node with value " << temp->data << " from beginning.\n";
        delete temp;
    }

    // (e) Delete from End
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == NULL) {
            cout << "Deleted node with value " << head->data << " from end.\n";
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        cout << "Deleted node with value " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = NULL;
    }

    // (f) Delete a Specific Node
    void deleteSpecific(int value) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node with value " << value << ".\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node " << value << " not found.\n";
            return;
        }

        prev->next = temp->next;
        cout << "Deleted node with value " << value << ".\n";
        delete temp;
    }

    // (g) Search a Node
    void search(int value) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << value << " not found.\n";
    }

    // (h) Display all Nodes
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Current Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, target;
    bool after;

    do {
        cout << "\n--- Singly Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete a Specific Node\n";
        cout << "7. Search a Node\n";
        cout << "8. Display All Nodes\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter existing node value: ";
            cin >> target;
            cout << "Enter new value: ";
            cin >> val;
            cout << "Insert (1) After or (0) Before " << target << "? ";
            cin >> after;
            list.insertBeforeAfter(target, val, after);
            break;
        case 4:
            list.deleteFromBeginning();
            break;
        case 5:
            list.deleteFromEnd();
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteSpecific(val);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            list.search(val);
            break;
        case 8:
            list.display();
            break;
        case 9:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}