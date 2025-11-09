#include <iostream>
#include <vector>
using namespace std;

// Heapify function to maintain heap property
void heapify(vector<int>& arr, int n, int i, bool ascending) {
    int extreme = i;        // Index of largest (for ascending) or smallest (for descending)
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // For ascending order → build a max-heap
    if (ascending) {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } 
    // For descending order → build a min-heap
    else {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    // If root is not the extreme element, swap and continue heapifying
    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, ascending);
    }
}

// Heap Sort function
void heapSort(vector<int>& arr, bool ascending = true) {
    int n = arr.size();

    // Build initial heap (max-heap or min-heap)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to end
        heapify(arr, i, 0, ascending);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    // Sort in increasing order
    heapSort(arr, true);
    cout << "Sorted in increasing order:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    // Sort in decreasing order
    heapSort(arr, false);
    cout << "Sorted in decreasing order:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
