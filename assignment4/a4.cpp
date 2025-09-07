#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students/sandwiches: ";
    cin >> n;

    queue<int> students;
    vector<int> sandwiches(n);

    cout << "Enter student preferences (0=circle, 1=square): ";
    for (int i = 0; i < n; i++) {
        int pref;
        cin >> pref;
        students.push(pref);
    }

    cout << "Enter sandwiches stack (top to bottom, 0=circle, 1=square): ";
    for (int i = 0; i < n; i++) {
        cin >> sandwiches[i];
    }

    int top = 0; // index of top sandwich
    int count = 0; // number of students passed without taking sandwich

    while (!students.empty() && count < students.size()) {
        if (students.front() == sandwiches[top]) {
            // Student takes sandwich
            students.pop();
            top++;
            count = 0; // reset counter
        } else {
            // Move student to end
            int s = students.front();
            students.pop();
            students.push(s);
            count++;
        }
    }

    cout << "Number of students unable to eat: " << students.size() << endl;
    return 0;
}
