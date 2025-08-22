//binary search
#include<iostream>
using namespace std;
int main()
{
    int a[100],n,i,left,right,middle,key;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"enter the elements in sorted order";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the elements to be searched";
    cin>>key;
    left=0;
    right=n-1;
    while (left<=right)
    {
        middle=left+(right-left)/2;
        if(a[middle]==key)
        {
            cout<<"Element found at index "<<middle;
            break;
        }
        else if(a[middle]<key)
        {
            left=middle+1;
        }
        else
        {
            right=middle-1;
        }
    }
    return 0;
}
