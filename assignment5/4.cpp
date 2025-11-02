#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to append a node at the end
void append(struct Node** head_ref, int data) {
    struct Node* temp = newNode(data);
    if (*head_ref == NULL) {
        *head_ref = temp;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse link
        prev = curr;         // move prev ahead
        curr = next;         // move curr ahead
    }

    return prev; // new head of the reversed list
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating linked list: 1->2->3->4->NULL
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Original List: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
