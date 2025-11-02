#include <stdio.h>

#define MAX 10

struct Node {
    int data;
    struct Node *next;
};

struct Node nodes[MAX];   // static memory
struct Node *freeList = NULL; 
struct Node *head = NULL;

// Initialize the free list
void initialize() {
    for (int i = 0; i < MAX - 1; i++)
        nodes[i].next = &nodes[i + 1];
    nodes[MAX - 1].next = NULL;
    freeList = &nodes[0];
}

// Get a free node
struct Node* getNode() {
    if (freeList == NULL) {
        printf("No free nodes available!\n");
        return NULL;
    }
    struct Node *temp = freeList;
    freeList = freeList->next;
    temp->next = NULL;
    return temp;
}

// Free a node (return it to free list)
void freeNode(struct Node *node) {
    node->next = freeList;
    freeList = node;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node *newNode = getNode();
    if (newNode == NULL) return;
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

// Delete a node by value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List empty!\n");
        return;
    }

    struct Node *curr = head, *prev = NULL;

    do {
        if (curr->data == value) {
            if (curr == head) {
                struct Node *last = head;
                while (last->next != head)
                    last = last->next;

                if (head->next == head)
                    head = NULL;
                else {
                    head = head->next;
                    last->next = head;
                }
            } else {
                prev->next = curr->next;
            }
            freeNode(curr);
            printf("Deleted %d.\n", value);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    printf("Node %d not found!\n", value);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    initialize();

    int choice, data;

    while (1) {
        printf("\n--- Circular Linked List (Static with ->) ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete Node\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteNode(data);
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
