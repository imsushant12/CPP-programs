#include <bits/stdc++.h>
using namespace std;

void survival(int total_days, int can_be_bought, int consumption)
{
    if (consumption > can_be_bought)
    {
        cout << "No, cannot survive!";
        return;
    }
    else
    {
        int available_days = total_days - (total_days / 7);
        int total_consumption = total_days * consumption;

        int answer = total_consumption / can_be_bought;
        if (total_consumption % can_be_bought != 0)
            answer++;

        if (answer <= available_days)
            cout << "Yes, Total number of days, we need to buy food is : " << answer;
        else
            cout << "No, cannot survive!";
    }
}

int main()
{
    int total_days = 19;
    int can_be_bought = 19;
    int consumption = 5;

    survival(total_days, can_be_bought, consumption);

    return 0;
}
