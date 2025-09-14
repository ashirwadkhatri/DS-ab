#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool canBeSorted(vector<int>& A) {
    int n = A.size();
    stack<int> st;
    int expected = 1; // smallest number we want in sorted B

    for (int i = 0; i < n; i++) {
        // Step 1: push current element of A into stack
        st.push(A[i]);

        // Step 2: pop from stack if it matches the next expected number
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }

    // If we managed to place all numbers in order
    return st.empty();
}

int main() {
    // Example input
    vector<int> A = {2, 3, 1};

    if (canBeSorted(A)) {
        cout << "Yes, it is possible to sort into B." << endl;
    } else {
        cout << "No, it is NOT possible to sort into B." << endl;
    }

    return 0;
}
