#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
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

// Function to insert node at end
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
        if (head->next != NULL) printf("->");
        head = head->next;
    }
    printf("\n");
}

// Function to count and delete all occurrences of key
int deleteKey(struct Node** head_ref, int key) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    int count = 0;

    while (current != NULL) {
        if (current->data == key) {
            count++;
            // Deleting current node
            if (prev == NULL) {
                // deleting head node
                *head_ref = current->next;
                free(current);
                current = *head_ref;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
    return count;
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating linked list: 1->2->1->2->1->3->1
    append(&head, 1);
    append(&head, 2);
    append(&head, 1);
    append(&head, 2);
    append(&head, 1);
    append(&head, 3);
    append(&head, 1);

    int key = 1;
    printf("Original Linked List: ");
    printList(head);

    int count = deleteKey(&head, key);

    printf("Count: %d\n", count);
    printf("Updated Linked List: ");
    printList(head);

    return 0;
}
