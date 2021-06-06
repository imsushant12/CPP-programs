#include <bits/stdc++.h>
using namespace std;

//Can be solved using frequency array or HashMap but space and time complexity will be O(n)

/*
//Time Complexity = O(n) and Space Complexity = O(n)
void countFrequency(int a[] , int n)
{
    int i=0;
    while(i < n)
    {
        //if value is 0 or negative, it shows either
        //the index is encountered or having a frequency.
        if(a[i] <= 0)
        {
            i++;
            continue;
        }

        //as we are considering index from 1 not 0
        //so using index variable to indicate it.
        //Ex: a[2] will be stored at 1st index in original array.
        int index = a[i]-1;

        if( a[index] > 0 )
        {
            a[i] = a[index];
            a[index] = -1;
        }
        else
        {

            a[index]--;
            a[i] = 0;
            i++;
            //work of this index is now done. So assign 0 and move to next index.
        }
    }

    cout<<"Frequency of each element is :"<<endl;
    for(int i=0 ; i<n ; i++)
        cout<<i+1<<" -> "<<abs(a[i])<<endl;
}
*/

//Approach-2
//Time Complexity = O(n) and Space Complexity = O(n)
void countFrequency(int a[] , int n)
{
    //decreasing value of every element because
    //indexing of array is from 0 not 1.
    for(int i=0 ; i<n ; i++)
        a[i]--;

    //Every element of a[i] as index and add 'n' to each
    //element present at ( a[i] % n ) to keep track of count.
    for(int i=0 ; i<n ; i++)
        a[ a[i]%n ] = a[ a[i]%n ] + n;

    cout<<"Frequency of each element is :"<<endl;
    for(int i=0 ; i<n ; i++)
        cout<<i+1<<" ->  "<<a[i]/n<<endl;
}


int main()
{
    int a[] = {2 , 3 , 3 , 2 , 5};
    int n = sizeof(a) / sizeof(a[0]);

    countFrequency(a , n);

    return 0;
}
