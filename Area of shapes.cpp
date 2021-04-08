#include<iostream>
using namespace std;
class shape
{
protected:
    double a,b;
public:
    void getdata()
    {
        a=b=0;
    }
    virtual void showarea()=0;
};
class triangle : public shape
{
public:
    void getdata()
    {
        cout<<"\nEnter sides of triangle\n";
        cin>>a>>b;
    }
    virtual void showarea()
    {
        cout<<"Area is  "<<(0.5*a*b);
    }

};
class rectangle : public shape
{
public:
    void getdata()
    {
        cout<<"Enter sides of rectangle\n";
        cin>>a>>b;
    }
    virtual void showarea()
    {
        cout<<"Area is  "<<a*b;
    }
};
class circle : public shape
{
private:
    int r;
public:
    void getdata()
    {
        cout<<"\nEnter radius\n";
        a=b=0;
        cin>>r;
        cout<<"Area is : "<<(3.14*r*r);
    }
    virtual void showarea()
    {
        circle::getdata();
    }

};
int main()
{
    rectangle r;
    triangle t;
    circle c1;
    r.getdata();
    r.showarea();
    t.getdata();
    t.showarea();
    c1.getdata();
    return 0;
}
