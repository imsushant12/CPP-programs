#include <bits/stdc++.h>
using namespace std;

int sum = 0;

void findMinMax(queue<int> &q, int k)
{
    int minElement = q.front();
    int maxElement = q.front();

    q.pop();
    k--;

    while (k--)
    {
        int data = q.front();
        q.pop();

        if (data < minElement)
            minElement = data;

        if (data > maxElement)
            maxElement = data;

        q.push(data);
    }

    cout<<"sum is: "<<sum<<endl;
    sum = sum + (minElement + maxElement);
}

void SumOfKsubArray(int a[], int n, int k)
{
    queue<int> q;

    for(int i=0 ; i<k-1 ; i++)
        q.push(a[i]);

    for (int i = k-1; i < n; i++)
    {
        q.push(a[i]);
        findMinMax(q, k);
    }
}

int main()
{
    int a[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;

    SumOfKsubArray(a, n, k);
    cout << sum;

    return 0;
}
