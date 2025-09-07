#include <iostream>
using namespace std;

int main() {
    int SIZE;
    cout << "Enter the size of the queue: ";
    cin >> SIZE;

    int queue[SIZE];  // Variable Length Array (depends on user input)
    int front = -1, rear = -1;
    int choice, value;

    do {
        cout << "\n--- Queue Operations Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Enqueue
                if (rear == SIZE - 1) {
                    cout << "Queue is Full!\n";
                } else {
                    cout << "Enter value: ";
                    cin >> value;
                    if (front == -1) front = 0;//if first element is empty then front becomes 0 i.e it isnt empty anymore
                    queue[++rear] = value;
                    cout << value << " enqueued.\n";
                }
                break;

            case 2: // Dequeue
                if (front == -1) {
                    cout << "Queue is Empty!\n";
                } else {
                    cout << queue[front] << " dequeued.\n";
                    if (front == rear) {
                        front = rear = -1; // if there is only one element remove it and make queue empty
                    } else {
                        front++;//since in que we dont remove elements we just increment front so it is ignored
                    }
                }
                break;

            case 3: // Peek
                if (front == -1) {
                    cout << "Queue is Empty!\n";
                } else {
                    cout << "Front element: " << queue[front] << endl;
                }
                break;

            case 4: // Display
                if (front == -1) {
                    cout << "Queue is Empty!\n";
                } else {
                    cout << "Queue elements: ";
                    for (int i = front; i <= rear; i++) {
                        cout << queue[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 5: // Check if Empty
                cout << (front == -1 ? "Queue is Empty\n" : "Queue is not Empty\n");
                break;

            case 6: // Check if Full
                cout << (rear == SIZE - 1 ? "Queue is Full\n" : "Queue is not Full\n");
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
