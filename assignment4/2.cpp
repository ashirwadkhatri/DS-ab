//here the rare goes from end to first  to check if there is empty to not waste space like linear
#include <iostream>
using namespace std;

int main() {
    int SIZE;
    cout << "Enter the size of the circular queue: ";
    cin >> SIZE;

    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
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
                if ((rear + 1) % SIZE == front) {/* Queue array: [10, 20, 30, 40, _]front = 1 (points to 20)rear = 0 (wrap-around, last element 10)Next insert position: (rear + 1) % SIZE = (0 + 1) % 5 = 1But front = 1 → cannot insert → queue is full*/
                    cout << "Queue is Full!\n";
                } else {
                    cout << "Enter value: ";
                    cin >> value;
                    if (front == -1) { // first element
                        front = rear = 0;
                    } else {
                        rear = (rear + 1) % SIZE;
                    }
                    queue[rear] = value;
                    cout << value << " enqueued.\n";
                }
                break;

            case 2: // Dequeue
                if (front == -1) {
                    cout << "Queue is Empty!\n";
                } else {
                    cout << queue[front] << " dequeued.\n";
                    if (front == rear) {
                        front = rear = -1; // queue becomes empty
                    } else {
                        front = (front + 1) % SIZE;
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
                    int i = front;
                    while (true) {
                        cout << queue[i] << " ";
                        if (i == rear) break;
                        i = (i + 1) % SIZE;
                    }
                    cout << endl;
                }
                break;

            case 5: // Check if Empty
                if (front == -1)
                    cout << "Queue is Empty\n";
                else
                    cout << "Queue is not Empty\n";
                break;

            case 6: // Check if Full
                if ((rear + 1) % SIZE == front)
                    cout << "Queue is Full\n";
                else
                    cout << "Queue is not Full\n";
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
