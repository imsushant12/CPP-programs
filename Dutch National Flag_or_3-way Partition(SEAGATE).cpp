#include<bits/stdc++.h>
using namespace std;

void Seagate(int a[] , int n)
{
    int l=0 , m = 0 , h = (n-1);

    while(m <= h)
    {
        //L should point to 0
        if(a[m] == 0)
        {
            swap(a[l] , a[m]);
            l++;
            m++;
        }

        //Skip as m should point to 1
        else if(a[m] == 1)
        {
            m++;
        }

        //H should point to 2  :  if(a[m] == 2)
        else
        {
            swap(a[m] , a[h]);
            h--;
        }
    }

    cout<<"Seagated array = ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";
}

int main()
{
    int a[] = {0 , 1 , 2 , 0 , 1 , 2};
    int n = sizeof(a) / sizeof(a[0]);

    Seagate(a , n);

    return 0;
}
