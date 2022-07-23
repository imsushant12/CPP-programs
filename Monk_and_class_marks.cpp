/*
Problem Statement:
-----------------
Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. And if two students have the same marks, they should be arranged in lexicographical manner.

Help Monk prepare the same!

Input format:
On the first line of the standard input, there is an integer N, denoting the number of students. N lines follow, which contain a string and an integer, denoting the name of the student and his marks.

Output format:
You must print the required list.

Sample Input
3
Eve 78
Bob 99
Alice 78

Sample Output
Bob 99
Alice 78
Eve 78
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // We will create a map having marks as key and names as set of strings. Set will store names in lexicographical order.
    map<int, multiset<string>> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int marks;
        string name;
        cin >> name >> marks;
        m[marks].insert(name);
    }

    // accessing vales in reverse order so that maximum marks can be gained.
    auto it = --m.end();

    while (1)
    {
        auto &marks = it->first;
        auto &names = it->second;

        // iterating overthe set of names.
        for(auto student : names)
            cout<<student << " " << marks << endl;

        // breaking the loop when we have reached the starting of map as we were iterating from the last.
        if(it == m.begin())
            break;

        // else decrement the iterator.
        it--;
    }

    return 0;
}