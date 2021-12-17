#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n^2).
// Space Complexity = O(1).

void bubbleSort(int a[], int n)
{
    // outer loop will run (n-1) times
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                isSwapped = true;
            }
        }
        // if we haven't swapped any element then the array is already sorted.
        if (isSwapped == false)
            break;
    }
    
    // Printing the sorted array.
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    
}

int main()
{
    int a[] = {3, 4, 1, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, n);
    return 0;
}
