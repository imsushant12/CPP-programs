#include<bits/stdc++.h>
using namespace std;

void inorder(int a[], vector<int> &v, int n, int index)
{
    if(index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);

    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}

int minSwaps(vector<int> &v)
{
    vector <pair <int , int>> result(v.size());

    int counter = 0;
    for(int i = 0; i < v.size(); i++)
    {
        result[i].first = v[i];
        result[i].second = i;
    }

    sort(result.begin() , result.end());
    for(int i=0 ; i < result.size() ; i++)
    {
        if(i == result[i].second)
            continue;
        else
        {
            swap(result[i].first , result[result[i].second].first);
            swap(result[i].second , result[result[i].second].second);
        }

        if(i != result[i].second)
            i--;

        counter++;
    }
    return counter;
}

int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    inorder(a, v, n, 0);

    cout<<"Minimum swaps needed = "<<minSwaps(v);

    return 0;
}


