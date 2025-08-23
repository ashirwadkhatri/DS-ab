//concatenation of two strings
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2;
    cout<<"Enter first string: ";
    getline(cin,str1);//so that it can take spaces also
    cout<<"Enter second string: ";
    getline(cin,str2);
    string result=str1+str2;//concatenation also string also string is like int or float
    cout<<"After concatenation: "<<result <<endl;
    return 0;

}
