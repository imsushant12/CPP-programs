#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int> &v) 
{
    int n = v.size()-1;
        int compare = v[n];
        for(int i=n-1 ; i>=0 ; i--)
        {
            int temp = v[i];
            v[i] = compare;
            compare = max(compare , temp);
        }
        v[n] = -1;
        return v;
}

int main()
{
    vector<int> v;
    int data;
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i=0 ; i<n ; i++)
    {
        cin>>data;
        v.push_back(data);
    }

    cout<<"\nArray after modifications : ";
    v = replaceElements(v);
    for(int i=0 ; i<n ; i++)
        cout<<v[i]<<"  ";

    return 0;
}