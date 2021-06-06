#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class shape
{

private:

    int w;
    int h;

public:

    int getw()
    {
        cout<<"enter the width : ";
        cin>>w;
        return w;
    }

    int geth()
    {
        cout<<"enter the height : ";
        cin>> h;
        return h;
    }
};

class rectangle: private shape
{

public:

    void display ()
    {
        int a = getw();
        int b = geth();
        cout<< "Area of the rectangle is : "<<a*b;
    }

};

int main()
{
    rectangle r;
    r.display();
    return 0;
}


















/*

================================================

PUBLIC  MODE:

class shape
{
public:

    int w;
    int h;
    void getw()
    {
        cout<<"enter the width : ";
        cin>>w;
    }

    void geth()
    {
        cout<<"enter the height : ";
        cin>> h;
    }
};

class rectangle: public shape
{

public:

    // int getw();              cannot access private data
    // int geth();              cannot access private data

    void display ()
    {
        getw();
        geth();
        cout<< "Area of the rectangle is : "<<w*h;
    }

};

int main()
{
    rectangle r;
    r.display();
    return 0;
}

*/

