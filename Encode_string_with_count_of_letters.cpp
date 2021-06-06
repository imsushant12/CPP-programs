#include <bits/stdc++.h>
using namespace std;

void encodedLength(string str)
{
    int n = str.length();
    for(int i=0 ; i<n ; i++)
    {
        int counter = 1;
        while (i < (n-1) && str[i] == str[i+1])
        {
            counter++;
            i++;
        }
        cout<<str[i]<<counter;
    }
}

int main()
{
    string input = "wwwwaaadexxxxxx";
    encodedLength(input);

    return 0;
}

