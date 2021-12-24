#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n^2).
// Space Complexity = O(1).

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int currentElement = a[i];
        int j = i - 1;

        while (j >= 0 and currentElement < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = currentElement;
    }

    // Printing the sorted array.
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
}

int main()
{
    int a[] = {3, 4, 1, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    insertionSort(a, n);
    return 0;
}
