#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, h, n;
    cout << "Enter width and height of the box : ";
    cin >> w >> h;
    cout << "Enter number of towers : ";
    cin >> n;

    vector<int> width;
    vector<int> height;

    // Initially putting 0 in both the vectors to calculate differences.
    width.push_back(0);
    height.push_back(0);

    cout << "Enter position of the towers : \n";
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        width.push_back(x);
        height.push_back(y);
    }
    // Lastly putting width and height in both the vectors respectively to calculate differences.
    width.push_back(w + 1);
    height.push_back(h + 1);

    // Sorting the vectors to get sequential differences.
    sort(width.begin(), width.end());
    sort(height.begin(), height.end());

    int maxH = 0, maxW = 0;

    for (int i = 0; i < width.size() - 1; i++)
    {
        maxW = max(maxW, abs(width[i] - width[i + 1]) - 1);
        maxH = max(maxH, abs(height[i] - height[i + 1]) - 1);
    }

    cout << "Maximum penalty of the given position : " << maxH * maxW;

    return 0;
}