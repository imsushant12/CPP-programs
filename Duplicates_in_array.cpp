#include <bits/stdc++.h>
using namespace std;

//Using Hashing : O(n)
class Chaining
{
private:
    list <int> hashTable[10];
    int SIZE = 10;

public:
    list <int> :: iterator it;

    int insertChaining(int data)
    {
        int index = data % SIZE;
        hashTable[index].push_back(data);
        hashTable[index].sort();
    }

    int removeDuplicate()
    {
        for(int i=0 ; i<SIZE ; i++)
            hashTable[i].unique();
    }

    void displayTable()
    {
        for(int i=0 ; i<SIZE ; i++)
        {
            cout << i;
            for (auto x : hashTable[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

void removeDuplicate(int a[] , int k , int n)
{
    for(int i=k ; i<n ; i++)
    {
        a[i] = a[i+1];
    }
}

/*
//Brute Force : O(n^2)
int deleteDuplicate(int a[] , int n)
{
    int m=n;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(a[i] == a[j])
            {
                int temp = a[j];
                removeDuplicate(a , j , n);
                a[n-1] = temp;
                m--;
            }
        }
    }
    return (n-m);
}
*/

/*
//Using sorting : O(n*(log n))
int deleteDuplicateSort(int a[] , int n)
{
    int m=n;

    sort(a,a+n);

    for(int i=0 ; i<n ; i++)
        if(a[i] == a[i+1])
        {
            removeDuplicate(a, i , n);
            m--;
        }

    return (n-m);
}
*/

int main()
{
    int n,i;
    cout<<"Enter size of array : ";
    cin>>n;

    int a[n];
    cout<<"Enter array :"<<endl;
    for(i=0 ; i<n ; i++)
        cin>>a[i];


    //Using Hashing:
    Chaining c;
    for(i=0 ; i<n ; i++)
        c.insertChaining(a[i]);
    c.removeDuplicate();
    cout<<"\nUpdated array with no duplicates : "<<endl;
    c.displayTable();

    /*
    //Using Sorting:
    int m = deleteDuplicateSort(a , n);
    cout<<"\nUpdated array with no duplicates : ";
    for(i=0 ; i<m ; i++)
        cout<<a[i]<<"  ";
    */


    /*
    //Brute Force Approach:
    int m = deleteDuplicate(a , n);
    cout<<"\nUpdated array with no duplicates : ";
    for(i=0 ; i<m ; i++)
        cout<<a[i]<<"  ";
    */

    return 0;
}
