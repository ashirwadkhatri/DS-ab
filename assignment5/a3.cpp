#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to detect and remove loop using Floyd's Cycle Detection algorithm
void removeLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Step 1: Detect loop using Floyd's algorithm
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast)
            break;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // Step 2: If the loop starts at head
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } else {
            // Step 3: Move both pointers until fast->next == slow->next
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 4: Break the loop
        fast->next = NULL;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Creating a loop: 5->next = 3
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    printf("Linked List after removing loop:\n");
    printList(head);

    return 0;
}
