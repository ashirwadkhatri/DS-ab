#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

struct CNode {
    int data;
    CNode* next;
};

// Function to remove even nodes from a Doubly Linked List
void removeEvenDLL(DNode*& head) {
    DNode* curr = head;

    while (curr != nullptr) {
        if (curr->data % 2 == 0) {  // Even node
            DNode* temp = curr;

            if (curr->prev != nullptr)
                curr->prev->next = curr->next;
            else
                head = curr->next;  // If head is even, move head

            if (curr->next != nullptr)
                curr->next->prev = curr->prev;

            curr = curr->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}

// Function to display Doubly Linked List
void displayDLL(DNode* head) {
    DNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to remove even nodes from a Circular Singly Linked List
void removeEvenCLL(CNode*& head) {
    if (head == nullptr)
        return;

    CNode* curr = head;
    CNode* prev = nullptr;

    // Handle even nodes at the start
    while (head != nullptr && head->data % 2 == 0) {
        // Find the last node (to reconnect circularly)
        CNode* last = head;
        while (last->next != head)
            last = last->next;

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        CNode* temp = head;
        head = head->next;
        last->next = head;
        delete temp;

        curr = head;
    }

    prev = head;
    curr = head->next;

    while (curr != head) {
        if (curr->data % 2 == 0) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// Function to display Circular Singly Linked List
void displayCLL(CNode* head) {
    if (head == nullptr) {
        cout << "List empty\n";
        return;
    }

    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Main function
int main() {
    // ---------- Doubly Linked List ----------
    DNode* headDLL = new DNode{10, nullptr, nullptr};
    headDLL->next = new DNode{15, headDLL, nullptr};
    headDLL->next->next = new DNode{20, headDLL->next, nullptr};
    headDLL->next->next->next = new DNode{25, headDLL->next->next, nullptr};

    cout << "Original Doubly Linked List: ";
    displayDLL(headDLL);

    removeEvenDLL(headDLL);

    cout << "After removing even nodes (DLL): ";
    displayDLL(headDLL);

    // ---------- Circular Linked List ----------
    CNode* headCLL = new CNode{5, nullptr};
    headCLL->next = new CNode{10, nullptr};
    headCLL->next->next = new CNode{15, nullptr};
    headCLL->next->next->next = new CNode{20, nullptr};
    headCLL->next->next->next->next = headCLL;  // Make circular

    cout << "\nOriginal Circular Linked List: ";
    displayCLL(headCLL);

    removeEvenCLL(headCLL);

    cout << "After removing even nodes (CLL): ";
    displayCLL(headCLL);

    return 0;
}
