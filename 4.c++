#include<iostream>
using namespace std;

int main() {
    // --- Reverse array ---
    int n, arr[100];
    cout << "Enter the number of elements in array: ";
    cin >> n;
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    cout << "The reverse of array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // --- Matrix multiplication ---
    int r1, c1, r2, c2;
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Invalid input: Cannot multiply\n";
    } else {
        int A[100][100], B[100][100], C[100][100];

        cout << "Enter the elements of first matrix:\n";
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                cin >> A[i][j];
            }
        }

        cout << "Enter the elements of second matrix:\n";
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                cin >> B[i][j];
            }
        }

        // Multiply
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                C[i][j] = 0;
                for (int k = 0; k < c1; k++) { // or k < r2 (same thing)
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "Matrix multiplication result:\n";
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) cout << C[i][j] << " ";
            cout << "\n";
        }
    }
 //transpose

    int r, c, m[100][100], t[100][100];

    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;

    cout << "Enter elements of matrix: \n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }

    // Transpose logic
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            t[j][i] = m[i][j];
        }
    }

    // Print transpose
    cout << "Transpose of matrix:\n";
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
