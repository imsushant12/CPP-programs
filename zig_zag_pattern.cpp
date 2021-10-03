#include <bits/stdc++.h>
using namespace std;

int main()
{
    int rows;
    cin >> rows;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= rows; j++)
        {
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0))
                cout << "*  ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    return 0;
}