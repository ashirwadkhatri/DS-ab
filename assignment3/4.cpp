#include <iostream>
#include <string>
using namespace std;

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    char stack[100];
    int top = -1;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If operand → directly add
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(' → push
        else if (ch == '(') {
            stack[++top] = ch;
        }
        // If ')' → pop until '('
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix += stack[top--];
            }
            top--; // remove '('
        }
        // If operator
        else {
            int prec;
            if (ch == '^') prec = 3;
            else if (ch == '*' || ch == '/') prec = 2;
            else if (ch == '+' || ch == '-') prec = 1;
            else prec = 0;

            int topPrec;
            while (top != -1) {
                if (stack[top] == '^') topPrec = 3;
                else if (stack[top] == '*' || stack[top] == '/') topPrec = 2;
                else if (stack[top] == '+' || stack[top] == '-') topPrec = 1;
                else topPrec = 0;

                if (topPrec >= prec) {
                    postfix += stack[top--];
                } else break;
            }
            stack[++top] = ch;
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix += stack[top--];
    }

    cout << "Postfix: " << postfix << endl;
    return 0;
}
