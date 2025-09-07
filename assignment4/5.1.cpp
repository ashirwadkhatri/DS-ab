#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q1, q2;

    // Push elements
    q1.push(10);
    q1.push(20);
    q1.push(30);

    cout << "Stack after pushing 10, 20, 30:\n";

    // Show top
    queue<int> temp = q1;
    while (temp.size() > 1) temp.pop();
    cout << "Top element: " << temp.front() << endl;

    // Pop element
    while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }
    cout << "Popped: " << q1.front() << endl;
    q1.pop();

    // Swap queues
    swap(q1, q2);

    // Show top after pop
    temp = q1;
    while (temp.size() > 1) temp.pop();
    cout << "Top element after pop: " << temp.front() << endl;

    return 0;
}
