#include <bits/stdc++.h>
using namespace std;

/*Helper Function that prints the maximum
number of multiplication needed for given matrices*/
void MCM(int P[] , int n)
{
    int C[n][n] = {0};    //table to contain the multiplications
    int K[n][n] = {0};    //table to obtain proper place for the parenthesis
    int q,minimum,i,j,k,d;

    for(d=1 ; d<n-1 ; d++)
    {
        for(i=1 ; i<n-d ; i++)
        {
            j = d+i;
            minimum = 32767;
            for(k=1 ; k<=j-1 ; k++)
            {
                q = C[i][k] + C[k+1][j] + P[i-1] * P[k] * P[j];
                if(q < minimum)
                {
                    minimum = q;
                    K[i][j] = k;
                }
            }
            C[i][j] = minimum;
        }
    }
    cout<<"Minimum number of multiplications : "<<C[1][n-1]<<endl;

    /*
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
            cout<<C[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
            cout<<K[i][j]<<"  ";
        cout<<endl;
    }
    */
}

/*Driver Program*/
int main()
{
    int P[] = {3,2,4,2,5};
    MCM(P , 5);

    return 0;
}
