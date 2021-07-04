#include <bits/stdc++.h>
using namespace std;

#define n 2 //number of platforms
#define m 5 //number of trains

int maxStop(int a[][3])
{
	// declaring trains for each platform and then
	// calculating maximum trains for each each platform.
	vector <pair <int, int>> trains[n + 1];

	for (int i = 0; i < m; i++)
	{
		int platform = a[i][2];
		// storing as departure-time, arrival-time
		trains[platform].push_back({a[i][1], a[i][0]});
	}

	// sorting the each vector as per departure time.
	for (int i = 0; i <= n; i++)
		sort(trains[i].begin(), trains[i].end());


	int count = 0;
	for (int i = 0; i <= n; i++)
	{
		if (trains[i].size() == 0)
			continue;

		int x = 0;
		count++;			//because first train is always selected for each platform.

		for (int j = 1; j < trains[i].size(); j++)
		{
			// The important (ACTIVITY SELECTION STEP)
			if (trains[i][j].second >= trains[i][x].first)
			{
				x = j;
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int trains[m][3] = {1000, 1030, 1,
						1010, 1020, 1,
						1025, 1040, 1,
						1130, 1145, 2,
						1130, 1140, 2};

	cout << "Maximum trains that can be stopped is : " << maxStop(trains);

	return 0;
}
