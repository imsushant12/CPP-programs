#include <bits/stdc++.h>
using namespace std;

#define d 256   //the number of characters in the input alphabet
#define PRIME 101

void Rabin_Karp(char sub[] , char super[])
{
	int M = strlen(sub);
	int N = strlen(super);
	int i, j;
	int p = 0;  //hash value for sub
	int t = 0;  //hash value for super
	int h = 1;

	//The value of h would be "pow(d, M-1)%prime"
	for(i = 0 ; i<M-1 ; i++)
		h = (h*d) % PRIME;

	//Calculate the hash value of sub and first
	//window of super
	for(i=0 ; i<M ; i++)
	{
		p = (d * p + sub[i]) % PRIME;
		t = (d * t + super[i]) % PRIME;
	}

	//Slide the sub over super one by one
	for(i = 0 ; i<(N-M+1) ; i++)
	{
		//Check the hash values of current window of super and sub.
		//If the hash values match then check for characters on by one.
		if (p == t)
		{
			// Checking the characters one by one
			for (j=0 ; j<M ; j++)
			{
				if (super[i+j] != sub[j])
					break;
			}
			if (j == M)
				cout<<"Pattern found at index "<<i<<endl;
		}
		//Calculating hash value for next window of super-
		//Remove leading digit, add trailing digit
		if(i < N-M)
		{
			t = (d*(t - super[i]*h) + super[i+M])%PRIME;
			// We might get negative value of t, converting it
			// to positive
			if (t < 0)
			t = (t + PRIME);
		}
	}
}

int main()
{
	char super[] = "GEEKS FOR GEEKS";
	char sub[] = "GEEK";
	Rabin_Karp(sub , super);
	return 0;
}

