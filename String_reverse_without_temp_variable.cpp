#include <bits/stdc++.h>
using namespace std;

string reversingString(string s, int start, int end)
{
	while(start < end)
	{
		//XOR for swapping the variable
		s[start] ^= s[end];
		s[end] ^= s[start];
		s[start] ^= s[end];

		++start;
		--end;
	}

	return s;
}

int main()
{
	string s;
	cout<<"Enter the string : ";
	cin>>s;

	cout<<"Reversed string is : "<<reversingString(s , 0 , s.length()-1);
	return 0;
}
