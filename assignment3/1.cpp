#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;   // maximum size of stack
    int stack[SIZE];
    int top = -1;         // top of stack
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: // Push
                if (top == SIZE - 1) {
                    cout << "Stack is Full (Overflow)!\n";
                } else {
                    cout << "Enter value to push: ";
                    cin >> value;
                    top++;
                    stack[top] = value;
                    cout << value << " pushed into stack.\n";
                }
                break;

            case 2: // Pop
                if (top == -1) {
                    cout << "Stack is Empty (Underflow)!\n";
                } else {
                    cout << stack[top] << " popped from stack.\n";
                    top--;
                }
                break;

            case 3: // isEmpty
                if (top == -1)
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is not Empty.\n";
                break;

            case 4: // isFull
                if (top == SIZE - 1)
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is not Full.\n";
                break;

            case 5: // Display
                if (top == -1) {
                    cout << "Stack is Empty.\n";
                } else {
                    cout << "Stack elements (top to bottom): ";
                    for (int i = top; i >= 0; i--) {
                        cout << stack[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 6: // Peek
                if (top == -1) {
                    cout << "Stack is Empty.\n";
                } else {
                    cout << "Top element is: " << stack[top] << endl;
                }
                break;

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
