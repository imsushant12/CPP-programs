#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class student
{

public:

    ~student()                                                                   //destructor
    {
        cout<<"Base class destructor"<<endl;
    }
};

class marks : public student
{

public:

    ~marks()
    {
        cout<<"Derived class destructor"<<endl;
    }
    //~student::student();                                                        --> ERROR

};


int main()
{
    marks m;
    return 0;
}
