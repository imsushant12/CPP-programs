#include <bits/stdc++.h>
using namespace std;

class Interval
{
public:
    int start, end;
};

bool compare(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

void mergeIntervals(Interval a[], int n)
{
    if (n <= 0)
        return;

    sort(a, a + n, compare);

    stack<Interval> s;

    s.push(a[0]);

    for (int i = 1; i < n; i++)
    {
        Interval current = s.top();

        // Now check it with current Interval i.e. a[i].
        // IMPORTANT STEP.
        if (current.end < a[i].start)
            s.push(a[i]);

        else if (current.end < a[i].end)
        {
            current.end = a[i].end;
            s.pop();
            s.push(current);
        }
    }

    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}

int main()
{
    Interval a[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    int n = sizeof(a) / sizeof(a[0]);
    mergeIntervals(a, n);

    return 0;
}
