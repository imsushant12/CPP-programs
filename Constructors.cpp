// Copy Constructor //
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

    Constructor( Constructor &old_c1)           //Copy constructor
    {
        a = old_c1.a;                           //a of c1 is copied to new object's a
        b = old_c1.b;                           //b of c1 is copied to new object's b
    }

    void printdata()
    {
        cout<<a<<endl;
        cout<<b<<endl<<endl;
    }

};

int main()
{
    Constructor c;
    c.printdata();

    Constructor c1(10,20);
    c1.printdata();


    Constructor c3 = c1;                  //Copy Constructor calling
    c3.printdata();
    Constructor c4 (c1);                  //other way to use copy constructor
    c4.printdata();

    Constructor c5;
    c5 = c;
    c5.printdata();                       //this is assignment not copy constructor calling
}









/*


// Parametrized Constructor //

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Constructor
{
    int a,b;

public:
    Constructor()
    {
        a=0;
        b=0;
    }

    Constructor(int x , int y)
    {
        a = x;
        b = y;
    }

    void printdata()
    {
        cout<<a<<endl;
        cout<<b<<endl<<endl;
    }
};

int main()
{
    Constructor c;          //default constructor will be called
    c.printdata();




    Constructor c1(10,20);     //parametrized constructor will be called
    c1.printdata();

    // Other way to call and initialize the Constructor

    Constructor c2 = Constructor(300,400);
    c2.printdata();
}


*/





/*

// Default Constructor //

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Constructor
{
    int x;
    int y;

public:

    //  Constructor()
    //  {}

    Constructor()
    {
        x=10;
        y=20;
    }
    void printdata()
    {
        cout<<x<<endl;
        cout<<y<<endl;
    }
};

int main()
{
    Constructor c;
    c.printdata();
}


*/
