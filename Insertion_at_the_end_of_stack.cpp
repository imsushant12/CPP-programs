#include <bits/stdc++.h>
using namespace std;

stack<int> insertUtil(stack<int> s, int N)
{
    if (s.empty())
        s.push(N);

    else
    {
        int X = s.top();
        s.pop();

        s = insertUtil(s, N);
        s.push(X);
    }
    return s;
}

void insertToBottom(stack<int> s, int N)
{
    s = insertUtil(s, N);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}



int main()
{
    stack<int> S;
    S.push(5);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);

    int N = 7;

    insertToBottom(S, N);

    return 0;
}
