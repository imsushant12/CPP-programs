#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n)
{
    vector<int> v;
    sort(a, a + n);

    int sum = 0;

    // Alternatively inserting smallest and largest element 
    // to vector to get a zig-zag kind of array.
    for (int i = 0; i < n / 2; i++)
    {
        v.push_back(a[i]);
        v.push_back(a[n - i - 1]);
    }

    // if number of elements are odd then inserting middle element.
    if(n %2 != 0)
        v.push_back(a[n/2]);

    for(int i=0 ; i<n ; i++)
    {
        if(i == n-1)
            sum += (abs(v[i] - v[0]));
        else
            sum += (abs(v[i] - v[i+1]));
    }

    return sum;
}

int main()
{
    int a[] = {1, 2, 4, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Maximum sum of absolute difference of any permutation is : " << MaxSumDifference(a, n);
}
