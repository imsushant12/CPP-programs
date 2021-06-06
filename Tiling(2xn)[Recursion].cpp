#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/

int tilingRecur(int n)
{
    //when length of tile is same as floor, we have only one option
    if(n == 1)
        return 1;

    //when length of floor is twice breadth, we have two options
    else if(n == 2)
        return 2;

    //other cases
    else
        return(tilingRecur(n-1) + tilingRecur(n-2));
}

int main()
{
    int n;
    cout<<"Enter the length of the floor : ";
    cin>>n;

    cout<<"Number of ways to tile the floor is : "<<tilingRecur(n)<<endl;
    return 0;
}
