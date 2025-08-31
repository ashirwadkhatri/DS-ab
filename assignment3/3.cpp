#include <iostream>
#include <string>
using namespace std;

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    char stack[100];   // stack array (max size 100)
    int top = -1;
    bool balanced = true;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        // If closing bracket → check match
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) { // no opening bracket
                balanced = false;
                break;
            }
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                balanced = false;
                break;
            }
        }
    }

    // If stack not empty → still unbalanced
    if (top != -1) balanced = false;

    if (balanced)
        cout << "Expression is Balanced.\n";
    else
        cout << "Expression is NOT Balanced.\n";

    return 0;
}
