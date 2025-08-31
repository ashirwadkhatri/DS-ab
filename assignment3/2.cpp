#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int n = str.length();
    char stack[100];   // stack array (assuming max 100 length)
    int top = -1;

    // Push all characters into stack
    for (int i = 0; i < n; i++) {
        top++;
        stack[top] = str[i];
    }

    // Pop all characters and print reversed string
    cout << "Reversed string: ";
    while (top != -1) {
        cout << stack[top];
        top--;
    }
    cout << endl;

    return 0;
}
