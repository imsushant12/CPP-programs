#include <bits/stdc++.h>
using namespace std;

int stringDuplicates(string s)
{
    int counter = 0;
    unordered_set <char> uset;

    for(int i=0 ; i<s.size() ; i++)
    {
        if(uset.find(s[i]) == uset.end())
            uset.insert(s[i]);

        else
        {
            counter++;
            cout<<"Repeated character : "<<s[i]<<endl;
        }
    }
    return counter;
}

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    cout<<"\nNumber of duplicate characters are : "<<stringDuplicates(s)<<endl;

    return 0;
}
