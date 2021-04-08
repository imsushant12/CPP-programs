#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
class bank
{
private:
    string name;
    int accno;
    char type;
    int amount=0;
    int tot=0;
public:
    void setvalue()
    {
        cout<<"Enter name\n";
        cin>>name;
        cout<<"Enter account number\n";
        cin>>accno;
        cout<<"Enter account type\n";
        cin>>type;
    }
    void showdata()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Account No:"<<accno<<endl;
        cout<<"Account type:"<<type<<endl;
    }
    void total()
    {
        cout<<"\nEnter amount\n";
        cin>>amount;
    }
    void showbal()
    {
        tot=tot+amount;
        cout<<"Total balance is: "<<tot;
    }
} ;
int main()
{
    bank b;
    int choice;
    while(1)
    {
        cout<<"\nEnter your choice\n";
        cout<<"\t1. Enter name,account number,account type\n";
        cout<<"\t2. Show the data\n";
        cout<<"\t3. Enter amount\n";
        cout<<"\t4. Show total balance\n";
        cout<<"\t5. To exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            b.setvalue();
            break;
        case 2:
            b.showdata();
            break;
        case 3:
            b.total();
            break;
        case 4:
            b.showbal();
            break;
        case 5:
            exit(1);
            break;
        default:
            cout<<"\nInvalid choice\n";
        }
    }
}








/*



#include<iostream>
#include<stdlib.h>
#include<string>
#include<math.h>
using namespace std;
class account
{
    string name;
    int accno;
    char type[10];
public:
    void getdata()
    {
        cout<<"Enter name\n";
        cin>>name;
        cout<<"Enter account number\n";
        cin>>accno;
        cout<<"Enter account type\n";
        cin>>type;
    }
    void showdata()
    {
        cout<<"\nName:"<<name<<endl;
        cout<<"Account No:"<<accno<<endl;
        cout<<"Account type:"<<type<<endl;
    }
} ;
class current : public account
{
    int balance;
    int amount;
 public:
     current()
     {
         balance=0;
         amount=0;
     }
    void getdata()
    {
        account::getdata();
        cout<<"Enter amount to be deposited : ";cin>>amount;
    }
    void total()
    {
        balance=balance+amount;
        cout<<"Total balance is :"<<balance;
    }
    void showdata()
    {
        account::showdata();
        current::total();
        cout<<"\nCheck book is available."<<endl;
        cout<<"No interest is available."<<endl;
        cout<<"Minimum balance should be Rs. 500."<<endl;
    }

};
class saving : public account
{
private:
    int amount,rate,time;
    double CI;
 public:
     saving()
     {
         amount=0;
         rate=10;
         time=0;
         CI=0.0;
     }
    void getdata()
    {
        account::getdata();
        cout<<"Enter amount to be added : "<<endl;
        cin>>amount;
        cout<<"Enter time : "<<endl;
        cin>>time;
    }
    void cint()
    {
         CI = amount*(pow((1+rate/100),time));
         cout <<"\nCompound interest is " << CI;
    }
    void showdata()
    {
        account::showdata();
        saving::cint();
        cout<<"\nNo check-book facility for this account"<<endl;
    }
};
int main()
{
    saving s;
    s.getdata();
    s.showdata();
    return 0;
}


*/
