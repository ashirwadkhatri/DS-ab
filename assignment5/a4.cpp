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

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("\n");
}

// Function to rotate linked list left by k nodes
struct Node* rotateLeft(struct Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    struct Node* curr = head;

    // Step 1: Count total nodes
    int count = 1;
    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }

    // Step 2: Make the list circular
    curr->next = head;

    // Step 3: Find new head after k rotations
    k = k % count;  // Handle k > count
    int stepsToNewHead = k;

    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;

    // Step 4: Break the circular link
    newTail->next = NULL;

    return newHead;
}

// Main function
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 2;

    printf("Original List: ");
    printList(head);

    head = rotateLeft(head, k);

    printf("List after rotating left by %d: ", k);
    printList(head);

    return 0;
}
