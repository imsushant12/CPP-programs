#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Constructor
{
    int a,b;

public:

    Constructor()                               //default constructor
    {
        a=0;
        b=0;
    }

    Constructor(int x , int y)                  //parametrized constructor
    {
        a = x;
        b = y;
    }

    Constructor( Constructor &old_c1,int p)           //Copy constructor
    {
        a = old_c1.a;                           //a of c1 is copied to new object's a
        b = p;                           //b of c1 is copied to new object's b
    }

    void printdata()
    {
        cout<<a<<endl;
        cout<<b<<endl<<endl;
    }

};

int main()
{
    int p;
    Constructor c;
    c.printdata();

    Constructor c1(10,20);
    c1.printdata();

    cout<<"Enter some value for b : ";
    cin>>p;

    Constructor c3 = c1;                    //Copy Constructor calling
    c3.printdata();

    //c3 is calling the copy constructor made by compiler as per the c1

    Constructor c4 (c1,p);                  //other way to use copy constructor
    c4.printdata();
}


/*
#include <iostream>
using namespace std;
class Rational
{
private:
    int numerator,denominator;
public:
    Rational()
    {
        numerator=0;
        denominator=0;
    }
    Rational(int a,int b)
    {
        numerator=a;
        denominator=b;
        if(b==0)
        {
            numerator=0;
            denominator=0;
            cout<<"Not Defined"<<endl;
        }
    }
    void check()
    {
        if(numerator > denominator)
            cout<<"Greater number is : "<<numerator;
        else if(denominator > numerator)
            cout<<"Greater number is : "<<denominator;
        else if(numerator == 0 && denominator==0)
            cout<<endl;
        else
            cout<<"Both are same\n";
    }
};
int main()
{
    int a,b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    Rational r1(a,b);
    r1.check();
    return 0;
}
*/
