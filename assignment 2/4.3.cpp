// reverse of string
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cout<<"enetr a string";
    cin>>str;
    for(int i=str.length()-1;i>=0;i--)//str.lenght()is a array so strlength()-1 is last value also i>=0 is because it starts from last index to first index and i-- decreases it frm last to first
    {
        cout<<str[i];
    } 
    return 0;
}
