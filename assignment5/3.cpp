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

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("\n");
}

// Function to find and print the middle element
void findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Move fast by 2 steps and slow by 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element: %d\n", slow->data);
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating linked list: 1->2->3->4->5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Linked List: ");
    printList(head);

    findMiddle(head);

    return 0;
}
