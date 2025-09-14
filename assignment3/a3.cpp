#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> nge(n, -1); // initialize NGE array with -1
    stack<int> st;           // stack stores indices

    // Compute Next Greater Element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    // Print the NGE array using normal for loop
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}
