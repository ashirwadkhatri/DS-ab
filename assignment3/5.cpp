#include <iostream>
#include <string>
#include <cmath>   // for pow()
using namespace std;

int main() {
    string postfix;
    cout << "Enter postfix expression (operands should be single-digit): ";
    cin >> postfix;

    int stack[100];
    int top = -1;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        // If operand (digit), push to stack
        if (ch >= '0' && ch <= '9') {
            stack[++top] = ch - '0';   // convert char to int
        }
        // If operator, pop 2 values and apply
        else {
            int val2 = stack[top--];
            int val1 = stack[top--];
            int result;

            if (ch == '+') result = val1 + val2;
            else if (ch == '-') result = val1 - val2;
            else if (ch == '*') result = val1 * val2;
            else if (ch == '/') result = val1 / val2;
            else if (ch == '^') result = pow(val1, val2);

            stack[++top] = result;
        }
    }

    cout << "Result = " << stack[top] << endl;
    return 0;
}
