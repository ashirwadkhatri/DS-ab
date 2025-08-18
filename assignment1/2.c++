/*
) Design the logic to remove the duplicate elements from an Array and after the
deletion the array should containtheunique elements.

*/
#include<iostream>
using namespace std;
int main()
{
    int arr[100],n,i,j,k;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";`
    for(i=0;i<n;i++)
     {

        cin>>arr[i];
     }
     for(i=0;i<n;i++)
     {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                for(k=j;k<n-1;k++)
                {
                    arr[k]=arr[k+1];

                }
                n--;
        j--;
            }
        }
     }
      cout<<"array after removing duplicates: ";
      for(i=0;i<n;i++) 
      {
            cout<<arr[i]<<" ";
      }
      return 0;  
}