#include <iostream>
using namespace std;

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

// A stable counting sort used by Radix Sort
void countingSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int count[10] = {0}; // count array for digits 0–9

    // Count occurrences of each digit at the current place (exp)
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert count[] to cumulative count[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array in reverse order (to maintain stability)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output[] back to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main Radix Sort function
void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);

    // Apply counting sort to each digit (exp = 1, 10, 100, ...)
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, n);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
