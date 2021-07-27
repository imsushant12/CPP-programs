#include <bits/stdc++.h>
using namespace std;

bool checkRedundancy(string &str)
{
    stack<char> s;
    int counter = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ')')
            s.push(str[i]);
        else
        {
            // If we found an opening bracket just after closing one.
            // Then the bracket pair had no content. Hence, redundant.
            if(s.top() == '(')    
                return true;
            
            else
            {
                while(s.top() != '(')
                {
                    s.pop();
                    counter++;
                }
                s.pop();    // Removing the opening bracket.

                // This basically means that bracket is around an single element only. 
                if(counter <= 1)
                    return true;
            }
        }
    }
    return false;
}

void findRedundant(string &str)
{
    bool answer = checkRedundancy(str);
    if (answer == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    string str = "((a+b))";
    findRedundant(str);

    str = "(a+(b)/c)";
    findRedundant(str);

    str = "(a+b*(c-d))";
    findRedundant(str);

    return 0;
}
