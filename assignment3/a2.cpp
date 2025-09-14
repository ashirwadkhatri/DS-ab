#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;   // stack to store elements or encoded values
    int minEle;      // current minimum
    int n;

    cout << "How many elements do you want to push? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter element " << i+1 << ": ";
        cin >> x;

        if (st.empty()) {
            st.push(x);    // first element
            minEle = x;    // initialize min
        } else if (x >= minEle) {
            st.push(x);    // normal push
        } else {
            st.push(2*x - minEle); // encoded push
            minEle = x;    // update min
        }

        cout << "Current minimum: " << minEle << endl;
    }

    // Example: pop one element and show min
    if (!st.empty()) {
        int t = st.top();
        st.pop();
        if (t < minEle) minEle = 2*minEle - t;

        cout << "Minimum after one pop: " << minEle << endl;
    }

    // Top element
    if (!st.empty()) {
        int t = st.top();
        if (t >= minEle) cout << "Top element: " << t << endl;
        else cout << "Top element: " << minEle << endl;
    }

    return 0;
}
