#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    queue<char> q;
    int freq[256] = {0};  // frequency of all characters

    cout << "First non-repeating characters: ";

    for (char ch : str) {
        if (ch == ' ') continue; // ignore spaces

        freq[ch]++;      // increase frequency
        q.push(ch);      // add to queue

        // remove characters from front if repeated
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // print first non-repeating or -1
        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << -1 << " ";
    }

    cout << endl;
    return 0;
}
