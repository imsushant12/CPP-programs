#include<bits/stdc++.h>
using namespace std;

void SearchMatrix(int a[][4] , int n , int x)
{
    int i = 0;
    int j= n-1;

    while( i<n && j>=0)
    {
        if(a[i][j] == x)
        {
            cout<<"Element found at : "<<i<<","<<j;
            return;
        }
        else if(a[i][j] > x)
        {
            //exclude last row
            j--;
        }
        else
        {
            //exclude first row
            i++;
        }
    }
    cout<<"Element not found"<<endl;
    return;
}


int main()
{
    int a[4][4] = { { 10, 20, 30, 40 },
                    { 15, 25, 35, 45 },
                    { 27, 29, 37, 48 },
                    { 32, 33, 39, 50 } };
    SearchMatrix(a , 4 , 29);

    return 0;
}
