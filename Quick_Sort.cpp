#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n log(n)).
// Space Complexity = O(1).

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int pIndex = low; // pIndex is pivotIndex.

    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    // Finally swapping the pivot element.
    swap(a[pIndex], a[high]);

    return pIndex;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(a, low, high);

        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

int main()
{
    int a[] = {3, 4, 1, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int low = 0;
    int high = n - 1;
    quickSort(a, low, high);

    // Printing the sorted array:
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";

    return 0;
}
