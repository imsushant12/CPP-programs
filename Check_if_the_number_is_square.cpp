#include <bits/stdc++.h>
using namespace std;

// Helper Function
void checkSquare(int n)
{
    bool flag = true;
    for(int i=2 ; i*i<=n ; i++)
    {
        // if i*i is equal to our number, we have found its square-root
        // we will set the flag to false and exit the loop.
        if(i*i == n)
        {
            flag = false;
            cout<<n<<" is square of : "<<i<<endl;
        }
    }

    // if the flag is not set false, we have not found square-root
    if(flag)
        cout<<n<<" is not square of any number."<<endl;
}

// Driver Program
int main()
{
    int n1 = 16;
    int n2 = 15;
    int n3 = 256;
    int n4 = 56;

    checkSquare(n1);
    checkSquare(n2);
    checkSquare(n3);
    checkSquare(n4);

    return 0;
}
