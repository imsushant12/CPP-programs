#include <bits/stdc++.h>
using namespace std;

#define MAX 256

void minLengthWindow(string input , string pattern)
{
    int shouldFind[MAX] = {0,} , hasfound[MAX] = {0,};
    int j=0 ,cnt=0, start=0 ,finish, minwindow = INT_MAX;
    int charlen = pattern.length() , iplen = input.length();

    for(int i=0 ; i<charlen ; i++)
        shouldFind[pattern[i]] += 1;
    finish = iplen;

    for(int i=0 ; i<iplen ; i++)
    {
        if(!shouldFind[input[i]])
            continue;
        hasfound[input[i]] += 1;
        if(shouldFind[input[i]] >= hasfound[input[i]])
            cnt++;
        if(cnt == charlen)
        {
            while(shouldFind[input[j]] == 0 || hasfound[input[j]] > shouldFind[input[j]])
            {
                if(hasfound[input[j]] > shouldFind[input[j]])
                    hasfound[input[j]]--;
                j++;
            }
            if(minwindow > (i-j+1))
            {
                minwindow = i- j + 1;
                finish = i;
                start = j;
            }
        }
    }

    cout<<"Desired window is : ";
    for(int i=start ; i<=finish ; i++)
        cout<<input[i];
}

int main()
{
    string input = "abbacbaa";
    string pattern = "aab";
    minLengthWindow(input , pattern);

    return 0;
}
