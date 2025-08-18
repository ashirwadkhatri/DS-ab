#include<iostream>
using namespace std;
int main()
{
    int n,i,j,arr[20][20],rsum[20]={0},csum[20]={0}; 
    cout<<"Enter the number of rows and columns of the matrix: ";
    cin>>n;

    cout<<"Enter the elements of the matrix:\n";
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    // calculate row and column sums
    for(i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            rsum[i]+=arr[i][j]; 
            csum[j]+=arr[i][j]; 
        }
    }

    cout << "Sum of each row:\n";
    for (i = 0; i < n; i++) {
        cout << "Row " << i+1 << ": " << rsum[i] << "\n";
    }

    cout << "Sum of each column:\n";
    for (j = 0; j < n; j++) {
        cout << "Column " << j+1 << ": " << csum[j] << "\n";
    }

    return 0;
}
