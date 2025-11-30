#include <iostream>
using namespace std;

// Node class for polynomial linked list
class Node {
public:
    int coeff;  // Coefficient
    int pow;    // Power
    Node* next;

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = nullptr;
    }
};

// Function to add two polynomials
Node* addPolynomial(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (poly1 != nullptr && poly2 != nullptr) {
        Node* temp = nullptr;

        if (poly1->pow > poly2->pow) {
            temp = new Node(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            temp = new Node(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else { // Same power → add coefficients
            temp = new Node(poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (result == nullptr) {
            result = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Add remaining terms
    while (poly1 != nullptr) {
        tail->next = new Node(poly1->coeff, poly1->pow);
        tail = tail->next;
        poly1 = poly1->next;
    }

    while (poly2 != nullptr) {
        tail->next = new Node(poly2->coeff, poly2->pow);
        tail = tail->next;
        poly2 = poly2->next;
    }

    return result;
}

// Function to print polynomial
void printPoly(Node* poly) {
    while (poly != nullptr) {
        cout << poly->coeff << "x^" << poly->pow;
        if (poly->next != nullptr)
            cout << " + ";
        poly = poly->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // First polynomial: 5x^2 + 4x + 2
    Node* poly1 = new Node(5, 2);
    poly1->next = new Node(4, 1);
    poly1->next->next = new Node(2, 0);

    // Second polynomial: 5x^3 + 2x + 1
    Node* poly2 = new Node(5, 3);
    poly2->next = new Node(2, 1);
    poly2->next->next = new Node(1, 0);

    cout << "Polynomial 1: ";
    printPoly(poly1);
    cout << "Polynomial 2: ";
    printPoly(poly2);

    Node* sum = addPolynomial(poly1, poly2);

    cout << "Sum: ";
    printPoly(sum);

    return 0;
}
