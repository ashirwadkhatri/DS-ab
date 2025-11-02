#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    queue<char> q;
    int freq[256] = {0};  // all ascii value total

    cout << "First non-repeating characters: ";

    for (char ch : str) {//for (element_type element : container) { ... }

        if (ch == ' ') continue; // ignore spaces

        freq[ch]++;      // increase frequency or aski value is found
        q.push(ch);      // add to queue

        // remove characters from front if repeated
        while (!q.empty() && freq[q.front()] > 1) {//freq [qfront ]count the no of times the character at front of queue has appeared
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
