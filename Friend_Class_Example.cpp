#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Forward Declaration
class Calculator;

class Complex
{

private :

    int a,b;
    friend class Calculator;

public:

    void setnumber(int x , int y)
    {
        a = x;
        b = y;
    }

    void printnumber()
    {
        cout<<"Your number is = "<<a<<" + "<<b<<"i"<<endl;                                                 // basically a+bi;
    }

};

class Calculator
{

public :

    int  real_SumComplex(Complex o1 , Complex o2)
    {
        cout<<"Sum of real part is = "<<(o1.a + o2.a)<<endl;
    }

    int comp_SumComplex(Complex o1 , Complex o2)
    {
        cout<<"Sum of complex pa rt is = "<<(o1.b + o2.b)<<endl;
    }

};


int main()
{
    Complex c1 , c2;
    Calculator calc1 , calc2;

    c1.setnumber(11 , 22);
    c2.setnumber(33 , 44);

    c1.printnumber();
    c2.printnumber();

    calc1.real_SumComplex(c1 , c2);
    calc2.comp_SumComplex(c1 , c2);
    return 0;
}


































/*
======================================= WITHOUT USE OF FRIEND CLASS ==========================================

//Forward Declaration
class Complex;
class Calculator
{
public:
    int add(int a , int b)
    {
        return (a + b);
    }
    int real_SumComplex (Complex , Complex);
    int comp_SumComplex (Complex , Complex);
};
class Complex
{
    int a,b;
public:
    void setnumber(int x , int y)
    {
        a = x;
        b = y;
    }
    void printnumber()
    {
        cout<<"Your number is = "<<a<<" + "<<b<<"i"<<endl;                               // basically a+bi;
    }

    friend int Calculator :: real_SumComplex(Complex , Complex);
    friend int Calculator :: comp_SumComplex(Complex , Complex);
};
int Calculator :: real_SumComplex(Complex o1 , Complex o2)
{
        cout<<"Sum of real part is = "<<(o1.a + o2.a)<<endl;
}
int Calculator :: comp_SumComplex(Complex o1 , Complex o2)
{
    cout<<"Sum of complex part is = "<<(o1.b + o2.b)<<endl;
}

int main()
{
    Complex c1,c2;
    Calculator calc1,calc2;
    c1.setnumber(10 , 20);
    c2.setnumber(20 , 40);
    c1.printnumber();
    c2.printnumber();
    calc1.add(10 , 20);
    calc2.add(20 , 40);
    calc1.real_SumComplex(c1 , c2);
    calc2.comp_SumComplex(c1 , c2);
    return 0;
}

*/
