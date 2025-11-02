#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next)
            printf("->");
        head = head->next;
    }
    printf("\n");
}

// Function to reverse k nodes
struct Node* reverseKGroup(struct Node* head, int k) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;

    // Step 1: Check if there are at least k nodes left
    struct Node* temp = head;
    int nodeCount = 0;
    while (temp != NULL && nodeCount < k) {
        temp = temp->next;
        nodeCount++;
    }
    if (nodeCount < k)
        return head;  // Less than k nodes, no reversal

    // Step 2: Reverse first k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 3: Recursively reverse remaining list
    if (next != NULL)
        head->next = reverseKGroup(next, k);

    // prev is new head of the reversed group
    return prev;
}

// Main function
int main() {
    struct Node* head = NULL;

    // Create linked list: 1->2->3->4->5->6->7->8
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);

    int k = 3;

    printf("Original List: ");
    printList(head);

    head = reverseKGroup(head, k);

    printf("Reversed in groups of %d: ", k);
    printList(head);

    return 0;
}
