#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    set<char> seen;
    bool possible = false;

    for (char c : s) {
        if (seen.count(c)) {
            possible = true;
            break;
        }
        seen.insert(c);
    }

    if (possible) {
        cout << "Yes, possible to split\n";
    } else {
        cout << "No, not possible\n";
    }

    return 0;
}
