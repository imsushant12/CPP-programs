#include <bits/stdc++.h>
using namespace std;

//using the KMP
bool checkRotation(string s1 ,  string s2)
{
    string temp;

    //concatenating the string-1 to itself for further check
    temp = s1+s1;

    if(temp.find(s2) != string::npos)
        return true;
    else
        return false;
}

int main()
{
    string s1 , s2;

    cout<<"Enter the string-1 : ";
    cin>>s1;
    cout<<"Enter the string-2 : ";
    cin>>s2;

    if(checkRotation(s1 , s2))
        cout<<"String-2 is rotated form of String-1"<<endl;
    else
        cout<<"String-2 is not rotated form of String-1"<<endl;

    return 0;
}
