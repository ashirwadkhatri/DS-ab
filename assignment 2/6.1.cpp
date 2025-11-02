#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter number of non-zero elements in Matrix A: ";
    cin >> n1;
    int A[n1][3];//3 is for row column value and not only for column and n is no of non zero elements
    cout << "Enter row, column, value for Matrix A:" << endl;
    for(int i=0;i<n1;i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter number of non-zero elements in Matrix B: ";
    cin >> n2;
    int B[n2][3];
    cout << "Enter row, column, value for Matrix B:" << endl;
    for(int i=0;i<n2;i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    int C[n1+n2][3]; // max triplets // contains result of addition of A and B i.e triplets of n1 and n2 and triplets can be found by row-index, column-index and value format of any matrix of m*n
    int k=0; // tracks how many elements is in c (row column and value )

    // Copy A into C
    for(int i=0;i<n1;i++){
        C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2];//for 34g 4*5
        k++;
    }

    // Copy B into C
    for(int i=0;i<n2;i++){
        C[k][0]=B[i][0]; C[k][1]=B[i][1]; C[k][2]=B[i][2];
        k++;
    }

    cout << "Resultant Matrix in Triplet form:" << endl;
    for(int i=0;i<k;i++)//since i goes from 0-something so i<k if we do i<=k it will print an exttra row with garbage values and since k goes from 1 to something 
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;

    return 0;
}
