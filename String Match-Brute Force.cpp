#include <bits/stdc++.h>
#include <string.h>
using namespace std;

//Brute Force - Complexity : O(n^2)
int findMatch(string super, string sub)
{
    int i,j;
    int n = super.length();
    int m = sub.length();

    for(int i=0 ; i<=(n-m) ; i++)
    {
        for(j=0 ;  j<m ; j++)
            if(super[i+j] != sub[j])
                break;

        if (j == m)
            return i;
    }
    return -1;
}

int main()
{
    string super,sub;

    cout<<"Enter main string : ";
    cin>>super;
    cout<<"Enter sub string : ";
    cin>>sub;

    int answer = findMatch(super , sub);

    if(answer == -1)
        cout<<"Sub-string is not found.";
    else
        cout<<"Sub-string is found on index : "<<answer;

    return 0;
}
