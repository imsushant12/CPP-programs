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
        a=0;
        b=0;
    }

    Complex(int x)
    {
        a=x;
        b=1;
    }

    Complex(int x , int y)
    {
        a=x;
        b=y;
    }

    Complex(Complex &obj)
    {
        a=obj.a;
        b=obj.b;
    }

    void printdata()
    {
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl<<endl;
    }


};

int main()
{
    Complex c;                       //default Constructor
    c.printdata();


    Complex c1(55);                  //parametrized Constructor
    c1.printdata();


    Complex c11;
    c11=65;                          //parametrized Constructor and other way to call c1
    c11.printdata();


    Complex c2(10,20);               //parametrized Constructor
    c2.printdata();


    Complex c3=c2;                    //Copy Constructor
    c3.printdata();

}
