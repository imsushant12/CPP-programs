#include <bits/stdc++.h>
using namespace std;

void calculate(int code, int amount)
{
	switch (code)
	{
	case 1:
		cout << amount << " USD = " << amount * 65 << " INR." << endl;
		break;
	case 2:
		cout << amount << " Pound = " << amount * 96 << " INR." << endl;
		break;
	case 3:
		cout << amount << " Franc = " << amount * 67 << " INR." << endl;
		break;
	case 4:
		cout << amount << " Euro = " << amount * 74 << " INR." << endl;
		break;
	case 5:
		cout << amount << " RMB = " << amount * 11 << " INR." << endl;
		break;

	default:
		cout << "Couldn't convert it!";
	}
}

int main()
{
	int code, amount;
	cin >> code >> amount;
	calculate(code, amount);

	return 0;
}
