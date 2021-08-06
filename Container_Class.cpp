#include <bits/stdc++.h>
using namespace std;

class Birthday;

class People
{
public:
    string name;
    friend class Birthday;
};

class Birthday : public People
{
    int day, month, year;

public:
    void getname(string temp)
    {
        name = temp;
    }

    void getbirth()
    {
        cout << "Enter birth day,month and year : ";
        cin >> day >> month >> year;
    }

    void printdetails()
    {
        cout << "\n"
             << name << " was born on : " << day << " / " << month << " / " << year << endl;
    }
};

int main()
{
    Birthday b;
    b.getname("Aman");
    b.getbirth();
    b.printdetails();
    return 0;
}
