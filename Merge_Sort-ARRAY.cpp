#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n * log(n)) in all cases.
// Space Complexity = O(n).

void mergeAlgo(int *a, int startIndex, int midIndex, int endIndex)
{
    int n = endIndex - startIndex + 1;
    // Helping array to temporarily store sorted results.
    int helper[n];

    // i represents starting index of first half of the array.
    // j represents starting index of second half of the array.
    // k represents starting index of helper array.
    int i = startIndex;
    int j = midIndex + 1;
    int k = 0;

    while (i <= midIndex and j <= endIndex)
    {
        if (a[i] <= a[j])
            helper[k++] = a[i++];
        else
            helper[k++] = a[j++];
    }

    // Merging elements left to be merged.
    while (i <= midIndex)
        helper[k++] = a[i++];
    while (j <= endIndex)
        helper[k++] = a[j++];

    // Copying back the elements to the original array.
    for (int i = startIndex; i <= endIndex; i++)
        a[i] = helper[i - startIndex];
}

void mergeSort(int *a, int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        // Divide
        mergeSort(a, startIndex, midIndex);
        mergeSort(a, midIndex + 1, endIndex);
        // Conquer
        mergeAlgo(a, startIndex, midIndex, endIndex);
    }
}

int main()
{
    int a[] = {3, 5, 1, 2, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int startIndex = 0, endIndex = n - 1;

    mergeSort(a, startIndex, endIndex);

    // Printing the sorted array.
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    return 0;
}
