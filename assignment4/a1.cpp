#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string current = q.front();
        q.pop();

        cout << current << " ";

        q.push(current + "0");
        q.push(current + "1");
    }

    cout << endl;
    return 0;
}
