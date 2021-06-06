#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s)
{
    for(int i=0 ; i<s.length() ; i++)
    {
        if(s[i] == s[i+1])
        {
            s.erase(i,2);
            s = removeDuplicate(s);
        }
    }
    return s;
}

int main()
{
    string s = "abccbcba";
    cout<<"Original String : "<<s<<endl;
    cout<<"Resultant string : "<<removeDuplicate(s)<<endl;

    return 0;
}

