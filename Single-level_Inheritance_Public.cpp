#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class student
{

public:

    int id;
    char name[20];

    void getstudent()
    {
        cout<<"\nEnter name : ";cin>>name;
        cout<<"\nEnter id : ";cin>>id;
    }

    /*
    void putstudent()
    {
        cout<<"\nName is "<<name;
        cout<<"\nID is "<<id;
    }
    */

};

class physical : public student
{
    float weight,height;

public:

    void getphysical()
    {
        cout<<"\nEnter weight : ";
        cin>>weight;
        cout<<"\nEnter height : ";
        cin>>height;
    }

    void putphysical()
    {
        cout<<"\nName is "<<name;
        cout<<"\nID is "<<id;
        cout<<"\nHeight is "<<weight;
        cout<<"\nWeight is "<<height;
    }

};

int main()
{
    physical p;
    p.getstudent();
    p.getphysical();
    //p.putstudent();
    p.putphysical();

    return 0;
}




/*
=======================================================
PRIVATE MODE:

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class student
{
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

class physical : private student
{
    float weight,height;
public:
    void getphysical()
    {
        getstudent();
        cout<<"\nEnter weight : ";cin>>weight;
        cout<<"\nEnter height : ";cin>>height;
    }
    void putphysical()
    {
        putstudent();
        cout<<"\nHeight is "<<weight;
        cout<<"\nWeight is "<<height;
    }
};

int main()
{
    physical p;
    p.getphysical();
    p.putphysical();

    return 0;
}

*/
