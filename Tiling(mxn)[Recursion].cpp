#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/

int tilingRecur(int n , int m)
{
    if(n<m)
        return 1;
    else if(n == m)
        return 2;
    else
        return(tilingRecur(n-1 , m) + tilingRecur(n-m , m));
}

int main()
{
    int n;
    cout<<"Enter the length of the floor : ";
    cin>>n;

    int m;
    cout<<"Enter the width of the floor : ";
    cin>>m;

    cout<<"Number of ways to tile the floor is : "<<tilingRecur(n , m)<<endl;
    return 0;
}
