#include <bits/stdc++.h>
using namespace std;

long long int findMinSum(int a[], int b[], int n)
{
	long long int answer = 0;

    sort(a , a+n);
    sort(b, b+n);

    for(int i=0 ; i<n ; i++)
        answer += (abs(a[i] - b[i]));

    return answer;
}

int main()
{
	int a[] = {4, 1, 8, 7};
	int b[] = {2, 3, 6, 5};
	int n = sizeof(a)/sizeof(a[0]);

    cout<< "Maximum Sum of absolute difference of all the pairs is : " << findMinSum(a , b , n);

	return 0;
}
