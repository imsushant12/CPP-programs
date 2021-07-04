#include <bits/stdc++.h>
using namespace std;

class Meeting
{
public:
    int start;
    int end;
    int pos;
};

bool comparator(Meeting m1, Meeting m2)
{
    return (m1.end < m2.end);
}

void maxMeeting(int s[], int f[], int n)
{
    vector<int> v;
    Meeting m[n];

    for (int i = 0; i < n; i++)
    {
        m[i].start = s[i];
        m[i].end = f[i];
        m[i].pos = i + 1;
    }

    int count = 0;

    // sorting the meetings as per their finish time.
    sort(m, m + n, comparator);

    // initially first meeting is always selected.
    v.push_back(m[0].pos);

    int current_ending_time = m[0].end;
    for (int i = 1; i < n; i++)
    {
        if (m[i].start > current_ending_time)
        {
            current_ending_time = m[i].end;
            count++;
            v.push_back(m[i].pos);
        }
    }

    cout << "Scheduled meetings are:";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "  ";
}

int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(s) / sizeof(s[0]);

    maxMeeting(s, f, n);

    return 0;
}
