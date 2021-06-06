#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class student
{
private:

    int id;
    char name[20];

public:

    void getstudent()
    {
        cout<<"Enter student name : ";cin>>name;
        cout<<"\nEnter student ID : ";cin>>id;
    }
};

class marks : public student
{
protected:

    int m1 , m2 , m3;

public:


    void getmarks()
    {
        cout<<"\nEnter marks of the three subjects : ";cin>>m1>>m2>>m3;
    }
};

class sports
{
protected:

    int smark;

public:

    void getsportsmarks()
    {
        cout<<"\nEnter marks obtained in sports : ";cin>>smark;
    }
};

class result : public marks , public sports
{
private:

    int total;
    float average;

public:

    void showresult()
    {
        total = (m1 + m2 + m3 + smark);
        average = (total / 4.0);
        cout<<"\nTotal marks obtained = "<<total;
        cout<<"\nAverage marks obtained = "<<average<<endl;
    }
};

int main()
{
    result r;
    r.getstudent();
    r.getmarks();
    r.getsportsmarks();
    r.showresult();
    return 0;
}
