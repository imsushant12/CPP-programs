#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class student
{

private:                                                                  //can be protected

    int id;
    char name[20];

public:

    void getstudent()
    {
        cout<<"\nEnter name : ";cin>>name;
        cout<<"\nEnter id : ";cin>>id;
    }

    void putstudent()
    {
        cout<<"\nName is "<<name;
        cout<<"\nID is "<<id;
    }
};

class marks
{

protected:

    int m1,m2,m3;

public:

    void getmarks()
    {
        cout<<"\nEnter marks of subject one : ";
        cin>>m1;

        cout<<"\nEnter marks of subject two : ";
        cin>>m2;

        cout<<"\nEnter marks of subject three : ";
        cin>>m3;
    }

};

class result : public student , public marks
{

private:

    int total;

public:

    void showresult()
    {
        total = m1 + m2 + m3;
        cout<<"\nTotal marks obtained = "<<total<<endl;
    }
};

int main()
{
    result r;
    r.getstudent();
    r.getmarks();
    r.putstudent();
    r.showresult();
    return 0;
}
