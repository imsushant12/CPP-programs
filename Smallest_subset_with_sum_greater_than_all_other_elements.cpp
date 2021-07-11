#include <bits/stdc++.h>
using namespace std;

int minElements(int a[], int n)
{
    int sum = 0;
    int current_sum = 0;
    int counter = 1;
    sort(a, a + n);

    // calculating the total sum of the elements.
    for (int i = 0; i < n; i++)
        sum += a[i];

    for (int i = n - 1; i > 0; i++)
    {
        current_sum += a[i];
        if ((sum - a[i]) > current_sum)
        {
            counter++;
            sum -= (sum - a[i]);
        }
        else
            break;
    }

    return counter;
}

int main()
{
    int a[] = {8, 9, 1, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Minimum elements needed to make sum greater than rest elements : " << minElements(a, n) << endl;
    return 0;
}
