#include <bits/stdc++.h>
using namespace std;

void replaceSpaces(string input , string rep)
{
    for(int i=0 ; i<input.length() ; i++)
    {
        if(input[i] == ' ')
            input.replace(i,1,rep);
    }

    cout<<"Replaced String : "<<input;
}

int main()
{
    string input = "Mr John Smith";
    string rep = "%20%";

    cout<<"Original String : "<<input<<endl;
    cout<<"To be replaced with : "<<rep<<endl;

    replaceSpaces(input , rep);

    return 0;
}

