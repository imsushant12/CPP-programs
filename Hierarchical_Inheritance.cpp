#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class AccNum
{
private:

    int accno;
    char name[20];

public:

    void getaccount()
    {
        cout<<"\nEnter name : ";cin>>name;
        cout<<"\nEnter account number : ";cin>>accno;
    }
    void putaccount()
    {
        cout<<"\nName is "<<name;
        cout<<"\nAccount number is "<<accno;
    }
};

class Saving : public AccNum
{
private:

    int balance;

public:

    void getbalance()
    {
        cout<<"\nEnter balance : ";cin>>balance;
    }
    void putbalance()
    {
        if(balance < 500)
            cout<<"\nInsufficient Balance"<<endl;
        else
            cout<<"\nAccount is created"<<endl;
    }
};

class Current : public AccNum
{
private:

    int balance2;

public:

    void getbalance2()
    {
        cout<<"\nEnter balance : ";cin>>balance2;
    }
    void putbalance2()
    {
        if(balance2 < 1000)
            cout<<"\nInsufficient Balance"<<endl;
        else
            cout<<"\nAccount is created"<<endl;
    }
};

int main()
{
    int choice;
    cout<<"1. Savings Account."<<endl;
    cout<<"2. Current Account."<<endl;
    cin>>choice;

    if(choice == 1)
    {
        Current c;
        c.getaccount();
        c.getbalance2();
        c.putaccount();
        c.putbalance2();
    }
    else if(choice == 2)
    {
        Saving s;
        s.getaccount();
        s.getbalance();
        s.putaccount();
        s.putbalance();
    }
    else
    {
        cout<<"\nInvalid Choice"<<endl;
    }
    return 0;
}
