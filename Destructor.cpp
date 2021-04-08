#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Complex
{

private:

    int a,b;

public:

    Complex()
    {
        a = 0;
        b = 0;
        cout<<"Constructor is called"<<endl;
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl<<endl;
    }

    ~Complex()
    {
        cout<<"Destructor is called"<<endl;
    }
};

int main()
{
    Complex c;

    return 0;
}
