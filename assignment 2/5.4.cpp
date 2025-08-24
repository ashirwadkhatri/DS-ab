//used low trinagular because the formula is much simpler than upper
#include <iostream>
using namespace std;

int main() {
    int n,i,j;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    // Total elements needed = n(n+1)/2
    int size = (n * (n + 1)) / 2;//removbed excess elements w;ep eun of 1st n natural nunber
    int symm[size]; // 1D array to store only lower triangle

    cout << "Enter elements of the symmetric matrix:\n";
    // Store only lower triangular elements (i >= j)
    int k = 0;
    for ( i = 0; i < n; i++) {
        for ( j = 0; j <= i; j++) {
            cin >> symm[k++];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>=j)
            {
                cout<<symm[(i*(i+1)/2)+j] << " ";// 1 2 3 4 ....i+1 (also sum of 1st n natural number) and +j because if we conver 2*2 to 1 d array we get 0,1,2,3 so to access 2nd row 1st column we need to add 1 i.e if i(i+1)/2 gets 2 then for column if +1 is added it shows that index 21 in 1d array
            }
            else
            {
                cout<<symm[(j*(j+1)/2)+i] << " ";//for upper triangle column is now priortized so j is fiilled
            }
        }
        cout<<endl;
    }
    return 0;
}