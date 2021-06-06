#include <bits/stdc++.h>
using namespace std;

int LCS(string s1 , string s2 , int n , int m)
{
    //if any one or both the string is empty
    if(m == 0 || n == 0)
        return 0;

    if(s1[n-1] == s2[m-1])
        return (1 + LCS(s1 , s2 , n-1 , m-1));

    else
        return max(LCS(s1 , s2 , n , m-1) , LCS(s1 , s2 , n-1 , m));
}

int main()
{
    string s1,s2;

    cout<<"Enter first string : ";
    cin>>s1;
    cout<<"Enter second string : ";
    cin>>s2;

    int n = s1.length();
    int m = s2.length();

    cout<<"\nLongest Common Subsequence is of length : "<<LCS(s1 , s2 , n , m)<<endl;

    return 0;
}


