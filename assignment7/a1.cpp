#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    // 1️ Find the maximum and minimum values in the array
    int maxVal = arr[0];
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }

    int range = maxVal - minVal + 1;

    // 2️ Create and initialize the count array
    vector<int> count(range, 0);

    // 3️ Store frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i] - minVal]++;

    // 4️ Modify count array so that each element stores cumulative counts
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // 5️ Build the output array (in sorted order)
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // 6️ Copy the output array back to the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    countingSort(arr, n);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
