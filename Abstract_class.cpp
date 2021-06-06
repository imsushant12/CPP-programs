#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class shape
{
protected:
    float d1,d2;
public:
    void getdim()
    {
        cin>>d1>>d2;
    }

    virtual float area() = 0;
};

class triangle : public shape
{
public:
    virtual float area()
    {
        return (0.5 * d1 * d2);
    }
};

class rectangle : public shape
{
public:
    virtual float area()
    {
        return (d1 * d2);
    }
};

int main()
{
    //shape s;                                                             -->ERROR as abstract class cannot have object

    triangle t;
    cout<<"\nEnter triangle's base and height : ";
    t.getdim();
    cout<<"Area of triangle = "<<t.area();

    rectangle r;
    cout<<"\n\nEnter rectangle's length and breadth : ";
    r.getdim();
    cout<<"Area of rectangle = "<<r.area();
}

