#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int arr[n-1]; // array of size n-1

    cout << "Enter the elements of the array (sorted, 1 to n with one missing): ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    // Find missing element
    int flag = 0;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != i + 1) {
            cout << "Missing element is " << i + 1 << endl;
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        cout << "Missing element is " << n << endl;
    }

    // Binary search
    cout << "-----BINARY SEARCH-----" << endl;
    int key;
    cout << "Enter the value to be searched: ";
    cin >> key;

    int left = 0, right = n - 2, mid;
    bool found = false;

    while (left <= right) {
        mid = left + (right - left) / 2; // corrected formula
        if (arr[mid] == key) {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Element not found" << endl;
    }

    return 0;
}
