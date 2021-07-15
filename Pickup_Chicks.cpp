#include <bits/stdc++.h>
using namespace std;

int main()
{
    int time, chicks, k, barn;

    cout << "Enter total number of chicks and chicks needed affter the barn : ";
    cin >> chicks;

    cout << "Enter total number of chicks needed affter the barn : ";
    cin >> k;

    cout << "Enter time and coordinate of barn : ";
    cin >> time;

    cout << "Enter the coordinate of barn : ";
    cin >> barn;

    vector<int> velocity;
    vector<int> distance;

    cout << "Enter the coordinates of chicks and its velocity: ";
    for (int i = 0; i < chicks; i++)
    {
        int x, v;
        cin >> x >> v;
        distance.push_back(x);
        velocity.push_back(v);
    }

    // count denotes number of chicks that can reach the barn, swaps denotes total swaps needed.
    // not_possible are the number of chicks that cannot reach the barn.
    int count = 0, swaps = 0, not_possible = 0;
    for (int i = chicks - 1; i >= 0; i--)
    {
        // Distance needed by current chick to cross the barn.
        int distance_needed = barn - distance[i];

        // Maximum distance the chick can travel in the given time.
        int max_distance = velocity[i] * time;

        if (distance_needed <= max_distance)
        {
            count++;
            // Important STEP**
            if (not_possible > 0)
                swaps += not_possible;
        }

        else
            not_possible++;

        if (count >= k)
            break;
    }

    if (count >= k)
        cout << "Total swaps needed is : " << swaps;
    else
        cout << "It is not possible for " << k << " chicks to cross the barn.";

    return 0;
}