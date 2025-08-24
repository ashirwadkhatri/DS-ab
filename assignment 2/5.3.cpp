#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    // Only store the non-zero elements
    int size = n * (n + 1) / 2; // number of elements in matrix so that only neccessary is stored like in n=4 insted of 16 only 10 elements are stored to save space
    int arr[size];

    cout << "Enter " << size << " elements for the lower triangle:\n";
    for (int i = 0; i < size; i++) cin >> arr[i];

    int k = 0; // index in arr[]
    cout << "Lower Triangular Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                cout << arr[k++] << " "; // k starts from 0 then when condition is met it increases since we sote it in 1 d aray at first and k access that 1 d array from arr[0] to arr[n] 
            } else {
                cout << "0 ";           // above main diagonal
            }
        }
        cout << endl;
    }

    return 0;
}
