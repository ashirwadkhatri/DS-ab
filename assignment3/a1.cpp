#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    int G[n]; // array to store nearest smaller elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i])
            st.pop();

        if (st.empty())
            G[i] = -1;      // store result directly in array
        else
            G[i] = st.top(); // store nearest smaller in array

        st.push(A[i]);
    }

    cout << "Nearest smaller elements: ";
    for (int i = 0; i < n; i++) cout << G[i] << " ";
    cout << endl;

    return 0;
}
