#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Push elements: 10, 20, 30
    int values[] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        int n = q.size();
        q.push(values[i]);
        for (int j = 0; j < n; j++) {
            q.push(q.front());
            q.pop();
        }
    }

    cout << "Stack after pushing 10, 20, 30:\n";
    cout << "Top element: " << q.front() << endl;

    // Pop element
    cout << "Popped: " << q.front() << endl;
    q.pop();

    // Show top after pop
    cout << "Top element after pop: " << q.front() << endl;

    return 0;
}
