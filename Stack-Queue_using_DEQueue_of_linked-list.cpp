#include <bits/stdc++.h>
using namespace std;

bool checkPermutation(int push[], int pop[], int n)
{
    stack<int> s;

    // 'j' is pointing to pop array and 'i' pointing to the push array.
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        s.push(push[i]);

        // Checking the top of stack with popped array's current array.
        while (!s.empty() and s.top() == pop[j])
        {
            s.pop();
            j++;
        }
    }

    return j == n;
}

int main()
{
    int push[] = {1, 2, 3, 4, 5};
    int pop[] = {4, 3, 5, 1, 2};

    int n = 3;

    if (checkPermutation(push, pop, n))
        cout << "Yes, it is valid stack-permutation";
    else
        cout << "No, it is not a valid stack-permutation";

    return 0;
}