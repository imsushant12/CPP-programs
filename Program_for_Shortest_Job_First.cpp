#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> a, vector<int> b)
{
    // If arrival time is same.
    if (a[1] == b[1])
    {
        // checking burst time.
        if (a[2] == b[2])
            // Then return the lesser ID.
            return a[0] < b[0];
        else
            // Return the lesser burst time program.
            return a[2] < b[2];
    }
    // Else the arrival times are different so return lesser arrival time program.
    return a[1] < b[1];
}

int main()
{
    int n;
    cout << "Enter number of programs : ";
    cin >> n;

    vector<vector<int>> v(n);
    vector<int> answer;

    cout << "Enter the arrival time and the burst time  of each programs : " << endl;
    for (int i = 0; i < n; i++)
    {
        // first pushing the job ID.
        v[i].push_back(i + 1);
        for (int j = 1; j < 3; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    // Sorting the provided programs as per the arrival time.
    // If arrival times are same then a/c their bust time else as per their IDs.
    sort(v.begin(), v.end(), comparator);

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // Pushing the programs as per their burst time in the min heap.
    pq.push({v[0][2], v[0][1], v[0][0]});

    int i = 1;
    int time = 0; // current time.

    while (!pq.empty())
    {
        int burst_time = pq.top()[0];
        int id = pq.top()[2];
        pq.pop();
        answer.push_back(id);

        time += burst_time;

        while (1)
        {
            if (i < n and v[i][1] <= time)
            {
                pq.push({v[i][2], v[i][1], v[i][0]});
                i++;
            }
            else
                break;
        }
    }

    cout << "Scheduling of the programs as per their IDs : ";
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << "  ";

    return 0;
}