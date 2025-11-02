#include <stdio.h>
#include <stdlib.h>

// Structure for a node
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

// Function to find intersection point
struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    if (!headA || !headB)
        return NULL;

    struct Node *a = headA, *b = headB;

    // Loop until both pointers meet or both become NULL
    while (a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }

    return a; // Either intersection node or NULL
}

// Helper function to print list
void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next)
            printf("->");
        head = head->next;
    }
    printf("\n");
}

// Driver code
int main() {
    // Create two linked lists
    // A: 4->1->8->4->5
    // B: 5->6->1->8->4->5
    struct Node* newNode8 = newNode(8);
    newNode8->next = newNode(4);
    newNode8->next->next = newNode(5);

    struct Node* headA = newNode(4);
    headA->next = newNode(1);
    headA->next->next = newNode8; // merge point

    struct Node* headB = newNode(5);
    headB->next = newNode(6);
    headB->next->next = newNode(1);
    headB->next->next->next = newNode8; // merge point

    struct Node* intersection = getIntersectionNode(headA, headB);

    if (intersection)
        printf("Intersection at node with data = %d\n", intersection->data);
    else
        printf("No intersection found\n");

    return 0;
}
