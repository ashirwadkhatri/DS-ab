#include<iostream>
#include<string>
#include<vector>//because vector can decrease or increase size unlike array and we can use .begin() and .end() function for easy traversal
#include<algorithm>//to use sort function 
using namespace std;
int main()
{
    int n,i;
    cout<<"enetr the number of strings";
    cin>>n;
    cin.ignore();//if i use int and then getline it will take the int value and a new line which is a string will be ignored so to avoid that we use cin.ignore()
    vector<string> string(n);//this will create a vector of size n so we can assign any value to it if n=3 then it will create a vector of size 3 "" "" "" where any string of any no of characters can be assigned unlike array where size is fixed arr[100]
    cout<<"enter the strings";
    for(i=0;i<n;i++)
    {
    getline(cin,string[i]);
    }
    sort(string.begin(),string.end());//this will sort the strings in order alphabetically
    cout<<"strings in sorted order are";
    for(int i=0;i<n;i++)
    {
        cout<<string[i]<<endl;
    }
    return 0;
    }