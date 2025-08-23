//delete all vowels from a string
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int i;
    
    string str,result=" ";
    cout<<"Enter a string: ";
    getline(cin,str);
    for(i=0;i<str.length();i++)
    {
        char c = str[i];
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        {
            // vowel, do nothing
        }
        else
        {
            result += c;
        }
    }
    cout<<"String after removing vowels: "<<result<<endl;
    return 0;
}
