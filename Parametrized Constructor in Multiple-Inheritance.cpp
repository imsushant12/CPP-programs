#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

class student
{

private:                                                                  //can be protected as well

    int id;
    char name[20];

public:
    student(int id , char name[20])
    {
        this->id = id ;
        strcpy(this->name , name);
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

    marks(int m1 , int m2 , int m3)
    {
        this->m1 = m1;
        this->m2 = m2;
        this->m3 = m3;
    }
};

class result : public student , public marks
{

private:

    int total;

public:

    result(int id, char name[] , int m1 , int m2 , int m3 , int total):student(id,name),marks(m1,m2,m3)
    {

        this->total = total;
    }

    void showresult()
    {
        total = m1 + m2 + m3;
        cout<<"\nTotal marks obtained = "<<total<<endl;
    }
};

int main()
{
    result r(1,"Aman",100,95,100,0);
    r.putstudent();
    r.showresult();
    return 0;
}
