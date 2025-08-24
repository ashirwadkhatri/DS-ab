//A[i][k] multiplies only with the element in row k of B → B[k][j] //
//If A[i][k] or B[k][j] is zero → contributes nothing to sum
#include <iostream>
using namespace std;

int main() {
    int nA, nB;
    cout << "Enter number of non-zero elements in Matrix A: ";
    cin >> nA;
    int A[nA][3];
    cout << "Enter row, column, value for Matrix A:" << endl;
    for(int i=0;i<nA;i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter number of non-zero elements in Matrix B: ";
    int B[nB][3];
    cout << "Enter row, column, value for Matrix B:" << endl;
    for(int i=0;i<nB;i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    int C[nA*nB][3]; // maximum possible triplets
    int k=0; // counter for result

    // Multiply non-zero elements
    for(int i=0;i<nA;i++){
        for(int j=0;j<nB;j++){
            if(A[i][1]==B[j][0]){ // column of A == row of B
                C[k][0] = A[i][0];       // row in result
                C[k][1] = B[j][1];       // column in result
                C[k][2] = A[i][2]*B[j][2]; // multiply values
                k++;
            }
        }
    }

    cout << "Resultant Matrix in Triplet form:" << endl;
    for(int i=0;i<k;i++)
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;

    return 0;
} 