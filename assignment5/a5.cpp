#include <stdio.h>
#include <stdlib.h>

// Structure for a node in polynomial linked list
struct Node {
    int coeff;  // coefficient
    int pow;    // power
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int coeff, int pow) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = coeff;
    temp->pow = pow;
    temp->next = NULL;
    return temp;
}

// Function to add two polynomials
struct Node* addPolynomial(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        struct Node* temp = NULL;

        if (poly1->pow > poly2->pow) {
            temp = newNode(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            temp = newNode(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else { // Same power → add coefficients
            temp = newNode(poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (result == NULL) {
            result = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        tail->next = newNode(poly1->coeff, poly1->pow);
        tail = tail->next;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        tail->next = newNode(poly2->coeff, poly2->pow);
        tail = tail->next;
        poly2 = poly2->next;
    }

    return result;
}

// Function to print polynomial
void printPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    // First polynomial: 5x^2 + 4x + 2
    struct Node* poly1 = newNode(5, 2);
    poly1->next = newNode(4, 1);
    poly1->next->next = newNode(2, 0);

    // Second polynomial: 5x^3 + 2x + 1
    struct Node* poly2 = newNode(5, 3);
    poly2->next = newNode(2, 1);
    poly2->next->next = newNode(1, 0);

    printf("Polynomial 1: ");
    printPoly(poly1);
    printf("Polynomial 2: ");
    printPoly(poly2);

    struct Node* sum = addPolynomial(poly1, poly2);

    printf("Sum: ");
    printPoly(sum);

    return 0;
}
