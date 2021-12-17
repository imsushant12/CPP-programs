#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n^2).
// Space Complexity = O(1).

void selectionSort(int a[], int n)
{
    // outer loop will run (n-1) times
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIndex = i;
        bool isSwapped = false;     // useful if array is already sorted
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[smallestIndex])
            {
                smallestIndex = j;
                isSwapped = true;
            }
        }

        if(isSwapped == false)
            break;

        swap(a[i], a[smallestIndex]);
    }

    // Printing the sorted array.
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
}

int main()
{
    int a[] = {3, 4, 1, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    selectionSort(a, n);
    return 0;
}
