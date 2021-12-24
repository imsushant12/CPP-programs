#include <bits/stdc++.h>
using namespace std;

string answer = "";

void print_longest_subsequence(string inputString, string outputString)
{
	if (inputString.length() == 0)
	{
		if (outputString.length() > answer.length())
		{
			answer = outputString;
			return;
		}
		else
			return;
	}

	char currentCharacter = inputString[0];

	print_longest_subsequence(inputString.substr(1), outputString + currentCharacter);
}

int main()
{
	string inputString = "abc";
	string outputString = "";

	print_longest_subsequence(inputString, outputString);
	cout << answer;

	return 0;
}
