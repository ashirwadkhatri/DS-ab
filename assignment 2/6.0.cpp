#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of non-zero elements in the matrix: ";
    cin >> n;

    int A[n][3], T[n][3];

    cout << "Enter row, column, value for each non-zero element:\n";
    for(int i = 0; i < n; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    // Transpose
    for(int i = 0; i < n; i++) {
        T[i][0] = A[i][1];
        T[i][1] = A[i][0];
        T[i][2] = A[i][2];
    }

    cout << "Transpose of the matrix (triplets):\n";
    for(int i = 0; i < n; i++) {
        cout << T[i][0] << " " << T[i][1] << " " << T[i][2] << endl;
    }

    return 0;
}
