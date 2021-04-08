#include <bits/stdc++.h>
#include <string>
using namespace std;

int countWords(string s)
{
    int counter = 0;
    for(int i=0 ; i<s.length() ; i++)
    {
        if(s[i] == ' ' && s[i+1] != ' ')
            counter++;
    }
    return counter+1;
}

void reverseWords(string words[] , int n)
{
    for(int i=0 ; i<n/2 ; i++)
    {
        string temp = words[i];
        words[i] = words[n-1-i];
        words[n-1-i] = temp;
    }

    for(int i=0 ; i<n ; i++)
        cout<<words[i]<<" ";
}

int main()
{
    string word = "He is a good boy";
    string words[] = {"He" , "is" , "a" , "good" , "boy"};

    reverseWords(words , countWords(word));

    /*Getting word by word entry from user :
    int n;

    cout<<"Enter number of words";
    cin>>n;

    string words[n];

    cout<<"Enter sentence (word-by-word) : ";
    for(int i=0 ; i<n ; i++)
        cin>>words[i];

    reverseWords(words , n);
    */
    return 0;
}
