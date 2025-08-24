#include <iostream>
using namespace std;

int main() {
    int n,i,j;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int lower[n-1], mainD[n], upper[n-1];

    cout << "Enter main diagonal (" << n << " elements):\n";
    for (int i=0; i<n; i++) cin >> mainD[i];

    cout << "Enter lower diagonal (" << n-1 << " elements):\n";
    for (int i=0; i<n-1; i++) cin >> lower[i];

    cout << "Enter upper diagonal (" << n-1 << " elements):\n";
    for (int i=0; i<n-1; i++) cin >> upper[i];
     cout <<"tridiagnol matrix is :\n";
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (i==j){
                cout<<mainD[i]<<" ";
            }
            else if(i==j+1){
                cout<<lower[j]<<" ";//shifts to down 
            }
            else if(j==i+1){
                cout<<upper[i]<<" ";//shifts to right
            }
            else{
                cout<<"0 ";
            }
            }
        
        cout<<endl;
    }
        return 0;

    }